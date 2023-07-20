import socket



def bar_to_atmosphere(pressure_bar):

    return pressure_bar * 0.986923



def main():

    host = "192.168.30.128" 

    port = 12345      



    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    server_socket.bind((host, port))

    server_socket.listen(1)



    print("The server is listening on {} : {}".format(host, port))



    conn, addr = server_socket.accept()

    print("Connected client's IP address and port number:", addr)



    while True:

        data = conn.recv(1024).decode()

        if not data:

            break



        try:

            pressure_bar = float(data)

            atmosphere_standard = bar_to_atmosphere(pressure_bar)

            conn.send(str(atmosphere_standard).encode())

        except ValueError:

            conn.send("Invalid input! Please enter a valid pressure value in bar.".encode())



    conn.close()



if __name__ == "__main__":

    main()


