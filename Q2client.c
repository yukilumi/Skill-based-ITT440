#include <stdio.h>

#include <stdlib.h>

#include <arpa/inet.h>



#define PORT 8080

#define SERVER_IP "192.168.30.128" 



int main() {

    int sockfd;

    struct sockaddr_in server_addr;

    int random_number;



    // Create a TCP socket

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {

        perror("Socket creation failed");

        exit(EXIT_FAILURE);

    }



    server_addr.sin_family = AF_INET;

    server_addr.sin_port = htons(PORT);



    // Convert IPv4 and IPv6 addresses from text to binary form

    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {

        perror("Invalid address/ Address not supported");

        exit(EXIT_FAILURE);

    }



    // Connect to the server

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {

        perror("Connection failed");

        exit(EXIT_FAILURE);

    }



    // Receive the random number from the server

    if (recv(sockfd, &random_number, sizeof(random_number), 0) < 0) {

        perror("Receiving random number failed");

        exit(EXIT_FAILURE);

    }



    printf("The random number received from the server is: %d\n", random_number);



    close(sockfd);



    return 0;

}


