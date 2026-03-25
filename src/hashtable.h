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
        if (table.size()/table.capacity() > 0.8) table.resize(table.capacity()*2);
        auto possible_labs_vec = table[lab.hash()%table.capacity()];
        bool found = false;
        for (auto i : possible_labs_vec) {
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
            possible_labs_vec.push_back({lab});
        }
        return true;
    }

    std::vector<Lab> search(std::string key) {
        auto possible_labs_vec = table[Lab::string_hash(key)%table.capacity()];
        for (auto i:possible_labs_vec) {
            if (i[0].get_search_string() == key) {
                return i;
            }
        }
        return {};
    }
};


#endif //PROJ2_HASHTABLE_H