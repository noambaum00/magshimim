import requests

def main():
    extract_password_from_site()



def extract_password_from_site():
    links = []
    password = str()
    url = "http://webisfun.cyber.org.il/nahman/files/"
    for i in range(23):
      req = requests.get(url + '/' + "file"+ (i+15) +".ifo", stream = True)
      password.appand(req[100])
      a = input()
    return password
#if __name__ == "__main__":
main()
