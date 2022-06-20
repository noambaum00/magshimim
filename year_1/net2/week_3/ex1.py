import socket

SERVER_IP = "54.71.128.194"
SERVER_PORT = 92
LISTEN_PORT = 9090


def main():
    # Create a TCP/IP socket
    listening_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Binding to local port 80
    server_address = ('', LISTEN_PORT)
    listening_sock.bind(server_address)

    # Listen for incoming connections
    listening_sock.listen(1)

    # Create a new conversation socket
    client_soc, client_address = listening_sock.accept()



    # Create a TCP/IP socket
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Connecting to remote computer 80
    server_address = (SERVER_IP, SERVER_PORT)
    sock.connect(server_address)


    

    client_msg = client_soc.recv(1024)#get message from clayent
    client_msg = client_msg.decode()

    print(client_msg)




    #repare message

    print(client_msg)

    msg = client_msg #send message to server
    sock.sendall(msg.encode())

    print("client message send ro server")

    #if ('France' in server_msg ):
    #    print('ERROR#"France is banned')
    #    msg = 'ERROR#"France is banned!"'
    #    client_soc.sendall(msg.encode())
    #    client_soc.sendall(msg.encode())
    if (1==2):
        print('ERROR#" math is kelled"')
    else:
        server_msg = sock.recv(1024) #get message from server
        server_msg = server_msg.decode()

        print(server_msg)

        #repare message
        #add . to the jpgx
        if "MOV" in server_msg:
            server_msg = server_msg[:-11] + "."  + server_msg[-11:]


        print(server_msg)
        msg = server_msg #send message to client
        client_soc.sendall(msg.encode())

    print("server message send ro claient")


if __name__ == '__main__':
    while True:
        main()