//
// Created by Nitsan BenHanoch on 12/01/2020.
//

#include <iostream>
#include "server_side.h"
#include "MySerialServer.h"
#include "FileCacheManager.h"
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include <FileCacheManager.cpp>
#include <StringReverser.cpp>
#include <MySerialServer.h>
#include <MyTestClientHandler.h>
#include <matrixSearchable.h>
using namespace std;



//string retrieve(string &problem){
//    vector<string> a;
//    string u = "/home/hodyah/CLionProjects/SearchingAlgoServer/testFile.txt";
//    a.push_back(u);
//    vector<string> optionalFilesOfHaseProblem = a;
//    vector<string>::iterator it = optionalFilesOfHaseProblem.begin();
//    ifstream fileOfProblem;
//    for(; it != optionalFilesOfHaseProblem.end(); it++){
//        fileOfProblem.open(*it, ios::binary);
//        if (!fileOfProblem){throw cache_manager::FileCacheManager::notSeeccsedOpenTheFile();}
//        char *bufferSize = new char[1];
//        fileOfProblem.read(bufferSize, 1);
//        char* bufferProblem = new char[atoi(bufferSize)];
//        fileOfProblem.read(bufferProblem, atoi(bufferSize));
//        if (strcmp(problem.c_str(),bufferProblem) == 0){
//            delete(bufferProblem, bufferSize);break; }
//        delete(bufferProblem, bufferSize);
//        fileOfProblem.close();
//    }
//    string anser;
//    fileOfProblem >> anser;
//    return anser;
//}
//todo need to do with namespace
//namespace boot{
int main()
{
//    server_side::MySerialServer at = server_side::MySerialServer();
////    Solver *a = new StringReverser;
//    server_side::ClientHandler *b = new MyTestClientHandler(a);
//    at.start(5402, b);
//    cout << "hi" << endl;
    std::vector<std::string> a = {
            "-1, 4, 543, 3232\r\n",
            "1, 4, 543, 3232\r\n",
            "1, 4, 543, 32\r\n",
            "1, 4323, 543, 3232\r\n",
            "1, 4, 543, 3232\r\n"
    };
    matrixSearchable b(a);
/**    //test for read file cachMannger
   ofstream a;
    a.open("/home/hodyah/CLionProjects/SearchingAlgoServer/testFile.txt", ios::binary);
    char *s = "1";
    a.write(s,strlen(s));

    char *o = "1anser";
    a.write(o, strlen(o));
    a.close();
    string t(s);
    string p = retrieve(t);
    cout << p << endl;
    */
}
//}