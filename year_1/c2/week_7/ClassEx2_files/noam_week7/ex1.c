#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

char* textModes[] = { "r", "w" };
char* binModes[] = { "rb", "wb" };
void txtCopy(FILE* src, FILE* destFilename);
void binCopy(FILE* src, FILE* dst);



int main(int argc, char *argv[]){
    //const char a[] = "c:/a/a.exe" ;
    //const char b[] = "d:/b/b.exe" ;
    FILE* inputFile = NULL;
    FILE* outootFile = NULL;

	char* sourceFilename = NULL;
	char* destFilename = NULL;

    char temp = 0 ;
    char ch = ' ';

    char ** modes = 0;
    
    void(*copyFunc)(FILE*, FILE*);

	int ans = 0;

    char *file = fopen(argv[3],"r");
    if((fopen(argv[3],"r"))!=NULL){
        printf("file is exists; do yo want to overwrite it(y/n)?\n");
        temp = getchar();
        if(temp == 'n'){
            printf("O.K exit program.\n");
            return 0;
        }
    }
    fclose(file);




	if (strcmp(argv[1], "textCopy") == 0)
	{
		modes = textModes;
		copyFunc = txtCopy; // pointer-to-function
	}
	else if (strcmp(argv[1], "binaryCopy") == 0)
	{
		modes = binModes;
		copyFunc = binCopy; // pointer-to-function
	}
	else
	{
		printf("Invalid execution.\n");
		printf("Usage: %s (textCopy|binaryCopy) <sourceFilename_filename> <destFilenameination_filename>\n", argv[0]);
		return -1; //error wrong parameters
	}

    sourceFilename = argv[2];
	destFilename = argv[3];


    inputFile  = fopen(sourceFilename, "r") ;

    if (!inputFile){
        printf( "imput file not found" ) ;
		return 1;
	}



    outootFile = fopen(argv[3], "r") ;


    if (!outootFile){
        fclose(outootFile);
		outootFile = fopen(destFilename, "w");
		if (!outootFile){
			printf("Error opening outpot file.\n");
			return 1;
		}

		if(strcmp(argv[1], "textCopy") == 0){
			txtCopy(inputFile ,outootFile);
		}
		else{
			binCopy(inputFile ,outootFile);
		}
		
		fclose(outootFile);
	}

	// Destination file exists, ask user what to do.
	else
	{
		fclose(outootFile);
		printf("Do you want to overwrite? 0 (no) / 1 (yes)\n");
		scanf("%d", &ans);
	
		if (ans)
		{
			// User approved, copy files
			outootFile = fopen(destFilename, "w");
			if (!outootFile)
			{
				printf("Error creating outpoot file.\n");
				return 1;
			}
			copyFunc(src, outootFile);
			fclose(outootFile);
		}
	}

	// Close the sourceFilename file
	fclose(inputFile);
	return 0; //successful end of program
}









void txtCopy(FILE* inputFile, FILE* outootFile){
	char ch = ' ';
	while ((ch = fgetc(inputFile)) != EOF)
	{
		fputc(ch, outootFile);
	}
	printf("Copy completed\n");

}

void binCopy(FILE* inputFile, FILE* outootFile){
	char buffer[1024] = { 0 };
	size_t num = 0;
	while (!feof(inputFile)){
		num = fread(buffer, sizeof(char), 1024, inputFile);
		fwrite(buffer, sizeof(char), num, outootFile);
	}
	printf("Copy completed\n");

}
