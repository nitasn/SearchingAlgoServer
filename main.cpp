//
// Created by Nitsan BenHanoch on 12/01/2020.
//


#include <vector>

#include "matrixSearchable.h"
#include "Searchable.h"
#include <iostream>
#include "algorithmDFS.h"
#include "algorithmBFS.h"
#include "algorithmA_star.h"

#include "log.h"

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

using namespace std;

struct Node
{
    char name;

    list<Node *> neighbors;

    explicit Node(char name) : name(name) {}

    bool operator<(const Node *other)
    {
        return this->name < other->name;;
    }

    bool operator==(const Node *other)
    {
        return this->name == other->name;;
    }
};

std::ostream& operator<<(std::ostream &os, const Node &node) {
    return os << "[" << node.name << "]";
}


Node A('A');
Node B('B');
Node C('C');
Node D('D');
Node E('E');
Node F('F');


class Graph : public Searchable<Node *>
{
public:

    Node *start = nullptr, *goal = nullptr;

    Graph()
    {
        A.neighbors.push_back(&E);
        A.neighbors.push_back(&B);
        A.neighbors.push_back(&C);

        B.neighbors.push_back(&C);
        B.neighbors.push_back(&E);

        C.neighbors.push_back(&D);
        C.neighbors.push_back(&F);

        E.neighbors.push_back(&D);

        F.neighbors.push_back(&E);
    }

    Node *getStart() override
    {
        return start;
    }

    Node *getGoal() override
    {
        return goal;
    }

    std::list<Node *> getNeighbors(Node *node) override
    {
        return node->neighbors;
    }

    double getWeight(Node *t1, Node *t2) override
    {
        return 0;
    }

    double getMinimalWeight() override
    {
        return 0;
    }
};


//int not_main()
//{
//    auto *graph = new Graph;
//
//    graph->start = &B;
//    graph->goal = &D;
//
//    algorithmA_star<Node *> dfs(graph);
//
//    list<Node *> *path = dfs.findPath();
//
//    if (path == nullptr)
//    {
//        cout << "no path found";
//    }
//    else
//    {
//        cout << "path: ";
//        for (Node *node : *path)
//            cout << *node << " ";
//    }
//
//    cout << endl;
//
//    return 0;
//}

std::vector<std::string> a = {

        "19,   2,  3,  14  \r\n",
        " -1, -1,  77,  8  \r\n",
        " 9,  10, -1,  12  \r\n",
        " 13, 14, 543, 3232\r\n",
        " 1,  1,   1,   1  \r\n",

        " 0, 1              \r\n",

        " 2, 1              \r\n"
};


Searchable<coords> *graph = new matrixSearchable(a);

std::ostream& operator<<(std::ostream &os, const coords &ij) {
    int i = ij.first, j = ij.second;
    return os << "[" << dynamic_cast<matrixSearchable*>(graph)->matrix[i][j] << "](" << i << "," << j << ")";
}

int main()
{
    algorithmA_star<coords> dfs;

    auto *path = dfs.findPath(graph);

    if (path == nullptr)
    {
        cout << "no path found";
    }
    else
    {
        for (auto ij : *path)
            cout << ij << " ";
    }

    cout << endl;

    return 0;
}