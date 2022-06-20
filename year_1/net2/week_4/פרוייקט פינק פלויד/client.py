import socket

HOST = "127.0.0.1"  # The server's hostname or IP address
PORT = 666  # The port used by the server



MENU = """




"""

def main():
    str = "none"
    print(MENU)
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST, PORT))

        try:
            answer = int(input("Enter option"))
        except:
            print("Please enter a valid answer")
            answer = int(input("Enter option"))

            if answer == 0 or 1 or 2:
               str = input("Please enter str")
        msg = "option:"+str(answer)+"&str:"+str(str)
        
        print(f"Received {data!r}")
        s.sendall(msg).encode()
        data = s.recv(1024)

main()