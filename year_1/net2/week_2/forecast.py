import socket
from datetime import datetime, timedelta

def main():
    #print(check_forecast("Yeruham", "28/04/2022"))
    city = input("enter city: ")
    answer = input("enter option: ")
    date = apDete(answer)
    if (answer == "1"):
        taple = check_forecast(city, date)
        taple = ''.join(taple)
        print(date + ", Tempatur " + taple)
    else:
        for i in range(5):
            taple = check_forecast(city, date[i])
            taple = ''.join(taple)
            print(date[i] + ", Tempatur " + taple)



def apDete(option):
    date2 = datetime.now()
    if option == "1":
        date2 = date2.strftime("%d/%m/%Y")

        return date2
    else:
        for i in range(5):
            dateArr = [5]
            dateArr[i]  = date2 + timedelta(i)
            dateArr[i] = dateArr[i].strftime("%d/%m/%Y")
    return dateArr

def mytcpSocket(serverurl,port,size,msg):
    SERVER_IP = serverurl
    SERVER_PORT = port

    # Create a TCP/IP socket
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Connecting to remote computer 80
    server_address = (SERVER_IP, SERVER_PORT)
    sock.connect(server_address)

    server_msg = sock.recv(size)
    server_msg = server_msg.decode()
    print(server_msg)


    sock.sendall(msg.encode())
    server_msg = sock.recv(size)
    server_msg = server_msg.decode()
    return server_msg
    

def gematria(word):
  word = word.lower()
  alphabet = {"a":1, "b":2, "c":3, "d":4, "e":5, "f":6, "g":7, "h":8, "i":9, "j":10, "k":11, "l":12, "m":13, 
    "n":14, "o":15, "p":16, "q":17, "r":18, "s":19, "t":20, "u":21, "v":22, "w":23, "x":24, "y":25, "z":26, " ":0}
  word_gematria = 0
  for i in word:
      word_gematria += alphabet[i]
  return word_gematria 


def checsum(city, date):
    num = 0
    num2 = 0
    num = gematria(city)

    date = date.split('/')
    date= "".join(str(x) for x in date)

    for c2 in date:
        num2 += int(c2)
    return str(num) + "." + str(num2)

def check_forecast(city, date):
    citychacksum = checsum(city, date)
    msg = "100:REQUEST:city=" + city + "&date=" + date + "&checksum=" + citychacksum
    serMsg = mytcpSocket("34.218.16.79",77,1024,msg)
    return str(serMsg[45:50])+" " , serMsg[56:]



if __name__ == "__main__":
    main()
