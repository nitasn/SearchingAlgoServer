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
#include "Searchable.h"
#include "algorithmDFS.h"

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
//int main()
//{
////    server_side::MySerialServer at = server_side::MySerialServer();
//////    Solver *a = new StringReverser;
////    server_side::ClientHandler *b = new MyTestClientHandler(a);
////    at.start(5402, b);
////    cout << "hi" << endl;
//    std::vector<std::string> a = {
//            "-1, 4, 543, 3232\r\n",
//            "1, 4, 543, 3232\r\n",
//            "1, 4, 543, 32\r\n",
//            "1, 4323, 543, 3232\r\n",
//            "1, 4, 543, 3232\r\n"
//    };
//    matrixSearchable b(a);
///**    //test for read file cachMannger
//   ofstream a;
//    a.open("/home/hodyah/CLionProjects/SearchingAlgoServer/testFile.txt", ios::binary);
//    char *s = "1";
//    a.write(s,strlen(s));
//
//    char *o = "1anser";
//    a.write(o, strlen(o));
//    a.close();
//    string t(s);
//    string p = retrieve(t);
//    cout << p << endl;
//    */
//}
////}

struct Node
{
    char name;
    list<Node> neighbors;

    explicit Node(char name) : name(name) {}

    bool operator< (Node& b)
    {
        return name < b.name;
    }

    friend bool operator< (Node& a, Node& b);

    friend bool operator==(const Node& lhs, const Node& rhs);
};

bool operator<(Node &a, Node &b)
{
    return a.name < b.name;
}

bool operator==(const Node &lhs, const Node &rhs)
{
    return lhs.name == rhs.name && lhs.neighbors == rhs.neighbors;
}

bool operator < (Node const& lhs, Node const& rhs)
{
    return lhs.name < rhs.name;
}

std::ostream& operator<<(std::ostream &os, const Node &node) {
    return os << "[" << node.name << "]";
}

class Graph : public Searchable<Node>
{
    Node A = Node('A'), B = Node('B'), C = Node('C'), D = Node('D'), E = Node('E'), F = Node('F');

public:
    Graph()
    {
        A.neighbors.push_back(E);
        A.neighbors.push_back(B);
        A.neighbors.push_back(C);

        B.neighbors.push_back(C);
        B.neighbors.push_back(E);

        C.neighbors.push_back(D);
        C.neighbors.push_back(F);

        E.neighbors.push_back(D);

        F.neighbors.push_back(E);
    }

    Node getStart() override
    {
        return A;
    }

    Node getGoal() override
    {
        return F;
    }

    std::list<Node> getNeighbors(Node node) override
    {
        return node.neighbors;
    }
};



int main()
{
    auto *graph = new Graph;

    algorithmDFS<Node> dfs(graph);

    std::list<Node> path = *dfs.findTheAnswer();

    for (Node &node : path)
        cout << node << " ";

    cout << endl;
}