//
// Created by Nitsan BenHanoch on 12/01/2020.
//

#include <thread>
#include "MySerialServer.h"
#include <iostream>
#include <unistd.h>
#include <sstream>
#include "string.h"

using namespace std;
const int MAX_CONNECTIONS = 1;
const int SIZE_BUFFER = 1024;

void loop(server_side::MySerialServer *self){
    while (!self->should_stop){
        char buffer[SIZE_BUFFER] = {0};
        int valread = read(self->client_socket , buffer, SIZE_BUFFER);
        const char *pointerToBuffer = buffer;
        //todo check what id the assigmnet
        const char *endLisenLinux = "end\r\n";
        const char *endLisenNotLinux = "end\n";
        if (strcmp(endLisenLinux, pointerToBuffer) == 0 || strcmp(endLisenNotLinux, pointerToBuffer) == 0) {
            self->should_stop = true;
        } else {
            istringstream inStream(string(buffer,SIZE_BUFFER));
            self->clientHandler->handle(inStream, cout);
        }
    }
}

void server_side::MySerialServer::start(int port, server_side::ClientHandler *clientHandler){
    this->clientHandler = clientHandler;
    connectToClient(port, MAX_CONNECTIONS);
    this->serverThread = new thread(loop, this);
}

void server_side::MySerialServer::stop(){
    this->should_stop = true;
    delete(this->serverThread);
    cout << "i stop" << endl;
    close(this->socketfd); // closing the listening socket
    close(this->client_socket);
}

server_side::MySerialServer::~MySerialServer(){
    this->serverThread->join();
    stop();
    cout << "i delete" << endl;
}