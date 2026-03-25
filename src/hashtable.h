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

    bool push_back(const std::string& key, const Lab& lab) {
        auto thing = table[lab.hash()%table.capacity()];
        bool found = false;
        for (auto i : thing) {
            if (key==i[0].get_search_string()) {
                for (auto j : i) {
                    if (lab.get_name() == j.get_name()) {
                        return false;
                    }
                }
                i.push_back(lab);
                found = true;
                break;
            }
        }
        if (!found) {
            thing.push_back({lab});
        }
        return true;
    }

    //bool delete


};


#endif //PROJ2_HASHTABLE_H