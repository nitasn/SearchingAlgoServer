//
// Created by hodyah on 20.1.2020.
//

#ifndef SEARCHINGALGOSERVER_ALGORITHMBFS_H
#define SEARCHINGALGOSERVER_ALGORITHMBFS_H

#include <Searcher.h>
#include "SearcherAbstarct.h"

template <typename State>
class algorithmBFS: public SearcherAbstarct<Searchable<State>, State>{

public:
    State findTheAnswer() override;
};




#endif //SEARCHINGALGOSERVER_ALGORITHMBFS_H
