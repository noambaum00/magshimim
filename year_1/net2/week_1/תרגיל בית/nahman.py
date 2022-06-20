import requests
import string

def main():
    print(extract_password_from_site())


def extract_password_from_site():
    temp = input("enter option")
    if (temp == 1):
        return extract_password_from_site_one()
    elif (temp == 2):
        return extract_password_from_site_two()


def extract_password_from_site_one():
    links = []
    password = str()
    url = "http://webisfun.cyber.org.il/nahman/files/"
    for i in range(23):
      req = requests.get(url + '/' + "file"+ (i+15) +".ifo", stream = True)
      password.appand(req[100])
      a = input()
    return password


def extract_password_from_site_two():
  url = "http://webisfun.cyber.org.il/nahman/final_phase/words.txt"
  aa = requests.get(url).text
  print(aa)

    # Count the words in the file
  lines = requests.get(url).text.split()
  counts = {}
  table = str.maketrans("", "", string.punctuation)
  for line in lines:
      line = line.translate(table)
      for word in line.split():
          if word not in counts.keys():
              counts[word] = 1
          else:
              counts[word] += 1
  
  # Sort the dictionary by value
  sorted_counts = sorted(counts.items(), key = lambda t: t[1],   reverse = True)
  
  # print the top ten
  ansa = []
  for t in sorted_counts[:6]:
      print(t)
      ansa.append(t[0])
  return " ".join(ansa)
        
    
main()
