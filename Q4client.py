import socket



def main():

    host = "192.168.30.128"

    port = 8888



    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    client_socket.connect((host, port))



    # Receive the quote from the server

    quote = client_socket.recv(1024).decode()



    print("Quote of the Day: ")

    print(quote)



    client_socket.close()



if __name__ == "__main__":

    main()


