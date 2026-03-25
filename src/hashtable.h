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
    std::vector<std::vector<std::vector<Lab>>> table;
    //  ^ hashed ^ handle collisions ^ vec of labs

    bool push_back(const std::string& key, const Lab& lab);

    std::vector<Lab> search(std::string key);
};


#endif //PROJ2_HASHTABLE_H