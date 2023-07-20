#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#include <unistd.h>

#include <arpa/inet.h>

#define PORT 8080



int generate_random_number() {

    return (rand() % 900) + 100; // Generates random number between 100 and 999

}



int main() {

    int server_fd, new_socket;

    struct sockaddr_in address;

    int addrlen = sizeof(address);



    srand(time(NULL)); // Seed the random number generator



    // Create a TCP socket

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {

        perror("Socket creation failed");

        exit(EXIT_FAILURE);

    }



    address.sin_family = AF_INET;

    address.sin_addr.s_addr = INADDR_ANY;

    address.sin_port = htons(PORT);



    // Bind the socket to the specified IP and port

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {

        perror("Bind failed");

        exit(EXIT_FAILURE);

    }



    // Listen for incoming connections

    if (listen(server_fd, 3) < 0) {

        perror("Listen failed");

        exit(EXIT_FAILURE);

    }



    printf("The server is listening on port %d\n", PORT);

    // Accept incoming connection

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {

        perror("Accept failed");

        exit(EXIT_FAILURE);

    }



    // Generate a random number

    int random_number = generate_random_number();



    // Send the random number to the client

    if (send(new_socket, &random_number, sizeof(random_number), 0) != sizeof(random_number)) {

        perror("Sending random number failed");

        exit(EXIT_FAILURE);

    }



    printf("The random number sent to the client is: %d\n", random_number);



    close(new_socket);

    close(server_fd);



    return 0;

}


