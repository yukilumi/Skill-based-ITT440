import socket

import threading

import random

#List of quotes
quotes=[
"Just because something works doesn't mean it can't be improved. -Shuri in Black Panther",

"You shouldn't like things because people tell you you're supposed to. - Jonathan Byers in Stranger Things",

"Indifference is the best revenge. -Georgia in Ginny & Georgia", 

"You can't just give up! Is that what a dinosaur would do? - Joey Tribbiani",

"If you focus on what you left behind, you will never be able to see what lies ahead. - Gusteau in Ratatouille",
]

def handle_client(client_socket):

    # Get a random quote

    random_quote = random.choice(quotes)



    # Send the quote to the client

    client_socket.send(random_quote.encode())



    # Close the connection

    client_socket.close()



def main():

    host = "192.168.30.128"

    port = 8888



    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    server_socket.bind((host, port))

    server_socket.listen(5)



    print("The server is listening on {} : {}".format(host, port))



    while True:

        client_socket, addr = server_socket.accept()

        print("Connected client's IP address and port number: ", addr)



        # Start a new thread to handle the client request

        client_thread = threading.Thread(target=handle_client, args=(client_socket,))

        client_thread.start()



if __name__ == "__main__":

    main()


