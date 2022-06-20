/*
MAGSHIMIM C2 MID-PROJECT ANTI_VIRUS
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h> 

#define FALSE 0
#define TRUE !FALSE

//Used to not get directories in the file list.
#define DIRECTORY_D_TYPE 16384

// parameters
#define FOLDER_PARAM 1
#define SIGNATURE_PARAM 2

// results
#define INFECTED_FIRST_20_PERCENT 3
#define INFECTED_LAST_20_PERCENT 2
#define INFECTED 1
#define NOT_INFECTED 0
#define READING_ERROR -1


// modes
#define NORMAL_SCAN_MODE 1
#define QUICK_SCAN_MODE 2
#define BEG_FILE_PERCENT 0.2
#define END_FILE_PERCENT 0.8

// strings
#define LOG_FILE_NAME "AntiVirusLog.txt"
#define BACKSLASH "/"

int showMenu(void);
int scanFile(char*, char*, int);
char** getFileNames(char*, int*);
void alphabetizeNames(char**, int);
int searchSignature(FILE*, FILE*, double, double);

void openLog(char*);
char* createLogPath(char*);
char* getResultString(int);
void updateLogScanResult(char*, int);
void updateLogMessage(char*);

int getFileSize(FILE * f);

char* logPath = "";

int main(int argc, char** argv) //argv[1,2]: Directory to scan, Signature
{
	int i = 0;
	int numFiles = 0;
	int infected = 0, filesScanned = 0, result = 0;
	int decision = 0;
	
	// Getting the files to check
	char** fileNames = getFileNames(argv[FOLDER_PARAM], &numFiles);
	alphabetizeNames(fileNames, numFiles);
	
	// Creating the log and updating it
	openLog(argv[FOLDER_PARAM]);
	updateLogMessage("Anti-virus began! Welcome!\n");
	updateLogMessage("Folder to scan: ");
	updateLogMessage(argv[FOLDER_PARAM]);
	updateLogMessage("Virus signature: ");
	updateLogMessage(argv[SIGNATURE_PARAM]);

	// Printing to screen
	printf("Welcome to my Virus Scan!\n\n");
	printf("Folder to scan: %s\n", argv[FOLDER_PARAM]);
	printf("Virus signature: %s\n\n", argv[SIGNATURE_PARAM]);
	decision = showMenu();

	printf("Scanning began...\nThis process may take several minutes...\n\n");
	printf("Scanning:\n");
	updateLogMessage("Results:");

	// Scanning the files
	for (i = 0; i < numFiles; i++)
	{
		infected = NOT_INFECTED;
		printf("%s - ", fileNames[i]);
		result = scanFile(fileNames[i], argv[SIGNATURE_PARAM], decision ? QUICK_SCAN_MODE : NORMAL_SCAN_MODE);
		printf("%s\n", getResultString(result));
		filesScanned++;
		updateLogScanResult(fileNames[i], result);
	}

	printf("Scan Completed.\n");
	printf("See log path for results: ");
	puts(logPath);

	// Releasing memory 
	for (i = 0; i < numFiles; i++)
	{
		free(fileNames[i]);
	}
	free(fileNames);
	free(logPath);

	argc = argc; // removing warning
	getchar();
	return 0;
}

/*
Present the menu to the user, and get his/her decision for scan option
input: none
output: user's decision
*/
int showMenu(void)
{
	int choice = 0;

	printf("Press 0 for a normal scan or any other key for a quick scan: ");
	scanf("%d", &choice);
	getchar(); // clear buffer, just in case

	updateLogMessage("\nScanning option:");
	if (choice)
	{
		updateLogMessage("Quick Scan\n");
	}
	else
	{
		updateLogMessage("Normal Scan\n");
	}
	return choice;
}

/*
This function gets a path to a file and a signature to look for in the file
and returns if it was found or not, or if any errors occurred.
input: file to scan, signature to check for, mode of scanning (quick / regular)
output: result of scan
*/
int scanFile(char* sourcePath, char* signPath, int mode)
{
	int result = NOT_INFECTED;
	FILE* source = fopen(sourcePath, "rb");
	FILE* sign = fopen(signPath, "rb");

	if (!source || !sign)
	{
		printf("Error opening file\n");
		return READING_ERROR;//The file couldn't be opened
	}

	if (mode == QUICK_SCAN_MODE)
	{
		if (searchSignature(source, sign, 0.0, BEG_FILE_PERCENT))
		{
			result = INFECTED_FIRST_20_PERCENT;
		}
		else if (searchSignature(source, sign, END_FILE_PERCENT, 1.0))
		{
			result = INFECTED_LAST_20_PERCENT;
		}
		else
		{
			// We can't start searching from 20%, but rather, from the middle of the beginning
			// The signature could have started there and went on to the middle of the file
			double ratio = (double)getFileSize(sign) / getFileSize(source);
			double newBeg = BEG_FILE_PERCENT - ratio;
			if (newBeg < 0)
			{
				newBeg = 0.0;
			}
			double newEnd = END_FILE_PERCENT + ratio;
			if (newEnd > 1)
			{
				newEnd = 1.0;
			}
			if (searchSignature(source, sign, newBeg, newEnd))
			{
				result = INFECTED;
			}
		}
	}
	else // Normal Scan
	{
		if (searchSignature(source, sign, 0.0, 1.0))
		{
			result = INFECTED;
		}
	}

	fclose(source);
	fclose(sign);
	return result;
}


/*
Function checks for a signature in a file between certain percentages.
input: the file to scan, the signature to seek, beginning %, ending %
output: result of scan (infected / not infected)
*/
int searchSignature(FILE* file, FILE* sign, double beg, double end)
{
	int found = FALSE;

	int fileCh = 0;
	int signCh = 0;

	int signSize = getFileSize(sign);

	// Setting the beginning / end byte locations
	int fileSize = getFileSize(file);
	int startBit = (int)(fileSize * beg);
	int endBit = (int)(fileSize * end);

	// Go to the beginning of the section to scan
	int currFileLocation = startBit;

	while (currFileLocation <= endBit - signSize && !found)
	{
		// Go to the beginning of the file (where we should start the scan now)
		fseek(file, currFileLocation, SEEK_SET);
		currFileLocation++;

		// Go to beginning of signature
		fseek(sign, 0, SEEK_SET);

		found = TRUE; // until proven otherwise

		// Search for signature in file
		// while the bytes are the same, and we haven't read the entire signature
		while (signCh != EOF)
		{
			// read one byte of the file to scan
			fileCh = fgetc(file);
			// read one byte of the signature
			signCh = fgetc(sign);

			if (fileCh != signCh)
			{
				found = FALSE;
				break;
			}
		}
	}
	return found;
}

/*
This function gets a path of a directory and returns a string array of all files (not directories)
inside it. It also set the number of files in "size".
input: Path of the directory, size variable
output: list of files in the directory
*/
char** getFileNames(char* dirPath, int* size)
{
	DIR* d = 0;
	struct dirent* dir = 0;
	int numOfFiles = 0, fileNameLength = 0;
	int pathLen = strlen(dirPath);
	char** names = (char**)malloc(sizeof(char*));
	if (!names)
	{
		return NULL; // Error allocating memory.
	}
	d = opendir(dirPath);
	if (!d)
	{
		return NULL; // Error opening directory.
	}
	while ((dir = readdir(d)) != NULL)
	{
		if (strcmp(dir->d_name, ".") && strcmp(dir->d_name, "..") && dir->d_type != DIRECTORY_D_TYPE)
		{
			numOfFiles++;
			names = (char**)realloc(names, sizeof(char*) * numOfFiles);
			fileNameLength = strlen(dir->d_name);
			// Allocate room for the two paths + 2 (for the backslash and null terminator
			names[numOfFiles - 1] = (char*)calloc(pathLen + fileNameLength + 2, sizeof(char));
			strncpy(names[numOfFiles - 1], dirPath, pathLen);
			strncat(names[numOfFiles - 1], BACKSLASH, 1);
			strncat(names[numOfFiles - 1], dir->d_name, fileNameLength);
		}
	}
	*size = numOfFiles;
	closedir(d);
	return names;
}

/*
Function receives an array of strings (file names) and sorts it by alphabetical order. 
input: the list of strings
output: none
*/
void alphabetizeNames(char** fileNames, int numFiles)
{
	int i = 0, j = 0;
	char* temp = 0;

	for (i = 0; i < numFiles; i++) //bubble sort strings
	{
		for (j = 0; j < numFiles - 1; j++)
		{
			if (strcmp(fileNames[j], fileNames[i]) > 0) //dictionary comparison
			{
				//pointers swap
				temp = fileNames[i];
				fileNames[i] = fileNames[j];
				fileNames[j] = temp;
			}
		}
	}

}

/*
Function creates the log file
input: path of the log
output: none
*/
void openLog(char* path)
{
	logPath = createLogPath(path);
	FILE* logFile = fopen(logPath, "wb");
	// Log file created
	fclose(logFile);
}

/*
Function creates the full path of the log file
input: the path for the log file
output: the full path of the log file
*/
char* createLogPath(char* path)
{
	unsigned int pathLen = strlen(path);
	unsigned int logLen = strlen(LOG_FILE_NAME);
	// Allocate room for the two paths + 2 (for the backslash and null terminator
	char* logPath = (char*)calloc((pathLen + logLen + 2), sizeof(char));
	strncpy(logPath, path, pathLen);
	strncat(logPath, BACKSLASH, 1);
	strncat(logPath, LOG_FILE_NAME, logLen);
	return logPath;
}

/*
This function updates the log with the result of the scan
input: the file and the result of the scan
output: none
*/
void updateLogScanResult(char* fileName, int result)
{
	FILE* file = 0;
	file = fopen(logPath, "ab");

	if (file)
	{
		fputs(fileName, file);
		fprintf(file, "  %s\r\n", getResultString(result));
		fclose(file);
	}
}

/*
Returns string of the result of the scan. 
input: result
output: a string describing the result
*/
char* getResultString(int result)
{
	char* resultString = 0;
	switch (result)
	{
	case INFECTED_FIRST_20_PERCENT:
		resultString = "Infected! (first 20%)";
		break;
	case INFECTED_LAST_20_PERCENT:
		resultString = "Infected! (last 20%)";
		break;
	case INFECTED:
		resultString = "Infected!";
		break;
	case NOT_INFECTED:
		resultString = "Clean";
		break;
	case READING_ERROR:
		resultString = "Reading Error";
		break;
	default:
		resultString = "Unknown Result, please contact customer support";
		break;
	}
	return resultString;
}

/*
This function updates the log with a message
input: the file and the result of the scan
output: none
*/
void updateLogMessage(char* msg)
{
	FILE* file = 0;
	file = fopen(logPath, "ab");

	if (file)
	{
		fprintf(file, "%s\r\n", msg);
		fclose(file);
	}
}

/*
the function finds the file's size.
input: pointer to file.
output: file's size.
*/
int getFileSize(FILE * f)
{
	fseek(f, 0, SEEK_SET);
	int ch = 0, size = 0;
	while ((ch = fgetc(f)) != EOF)
	{
		size++;
	}
	rewind(f);
	return size;
}
