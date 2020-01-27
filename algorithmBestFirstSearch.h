////
//// Created by hodyah on 21.1.2020.
////
//
//#ifndef SEARCHINGALGOSERVER_ALGORITHMBESTFIRSTSEARCH_H
//#define SEARCHINGALGOSERVER_ALGORITHMBESTFIRSTSEARCH_H
//#include <Searcher.h>
//#include "matrixSearchable.h"
//#include <queue>
//#include <set>
//#include <map>
//
//template <typename State>
//class algorithmBestFirstSearch: public Searcher<State> {
//
//    Searchable<State> *graph;
//
//    std::set<State> visited;
//    std::multimap<double, State> mul;
//    std::map<State, State> *mapFather;
//    std::list<State> listState;
//
//    void upDateVisitInState(State neighbors, State father){
//        this->queueState->push(neighbors);
//        (*mapFather)[neighbors] = father;
//    }
//public:
//    std::list<State> *findPath(Searchable<State> *_graph) override {
//
//        this->graph = _graph;
//
//        //todo
//        queueState->push(graph->getStart());
//        while(!queueState->empty()){
//            State state = queueState->top();
//            visited.insert(state);
//            if (state == graph->getGoal()){
//                updateTheWay();
//                return &this->listState;
//            }
//            for (auto neighbors :graph->getNeighbors(state)){
//                //todo need check if semothing in queue?
//                visited.insert(neighbors);
//                if (mapFather->find(neighbors) == mapFather->end()) {
//                    upDateVisitInState(neighbors, state);
//                }
//                if(graph->getWayNum(neighbors) > (graph->getWayNum(state)
//                                + graph->getValueOfState(neighbors))){
//                    graph->addToWayNum(neighbors, graph->getWayNum(state));
//                    upDateVisitInState(neighbors, state);
//                } else {
//                    // todo what need happend here?
//                }
//            }
//            queueState->pop();
//        }
//        return nullptr;
//    }
//    void updateTheWay(){
//        State father = (*mapFather)[graph->getGoal()];
//        while(father != this->graph->getStart()){
//            listState.push_front(father);
//            father = (*mapFather)[father];
//        }
//        listState.push_front(this->graph->getStart());
//    }
//};
//#endif //SEARCHINGALGOSERVER_ALGORITHMBESTFIRSTSEARCH_H
