//
// Created by Nitsan BenHanoch on 12/01/2020.
//

#include <iostream>
#include "server_side.h"
#include "MySerialServer.h"
using namespace std;

class a: public server_side::ClientHandler {
    void handle(std::istream &in, std::ostream &out){
        char buffer[1024];
        in.read(buffer, 1024);
        cout << buffer << endl;
    }
};

int main()
{
    server_side::MySerialServer at;
    string b = "hello what ip jknjdknjkcx";
    at.start(5402, &b);
    cout << "hi " << endl;
}
