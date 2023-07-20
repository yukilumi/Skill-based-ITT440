import socket



def main():

    host = "192.168.30.128"

    port = 12345 



    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    client_socket.connect((host, port))



    while True:

        pressure_bar = input("Enter pressure value in bar (type 'end' to exit): ")

        if pressure_bar.lower() == 'end':

            break



        client_socket.send(pressure_bar.encode())

        atmosphere_standard = client_socket.recv(1024).decode()

        print("The atmosphere-standard value(atm) is: ", atmosphere_standard)



    client_socket.close()



if __name__ == "__main__":

    main()


