//
// Created by aryan on 3/12/2026.
//

#ifndef PROJ2_HASHTABLE_H
#define PROJ2_HASHTABLE_H
#include <list>
#include <string>
#include <vector>

#include "Lab.h"


class hashtable {
public:
    std::vector<std::vector<std::vector<Lab>>> table;
    //  ^ hashed ^ handle collisions ^ vec of labs
    size_t num_labs = 0;
    hashtable() { // had issues with / by 0 check, need initializations.
        table.resize(7);
    }

    bool push_back(const std::string& key, const Lab& lab);

    std::vector<Lab> search(std::string key);
};


#endif //PROJ2_HASHTABLE_H