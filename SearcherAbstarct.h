//
// Created by hodyah on 20.1.2020.
//

#ifndef SEARCHINGALGOSERVER_SearcherAbstarct_H
#define SEARCHINGALGOSERVER_SearcherAbstarct_H

#include <Searcher.h>
#include <queue>

template <typename Problem, typename Solution>
 class  SearcherAbstarct: public Searcher<Problem, Solution>{
    //todo THATS A REGUALR QUEUE
    std::queue<Problem> priorityQueue;
    int numObjectOpen;
 public:
     SearcherAbstarct() {
        priorityQueue = new std::queue<Problem>();
        numObjectOpen = 0;
     }
     int howNumObjectIOpen() final{
         return numObjectOpen;
     }

     ~SearcherAbstarct(){
         delete priorityQueue;
     }

     void popPriorityQueue(){
         numObjectOpen++;
         priorityQueue.pop();
     }

     int getPriorityQueueSize(){
         return this->priorityQueue.size();
     }
};

#endif //SEARCHINGALGOSERVER_SearcherAbstarct_H