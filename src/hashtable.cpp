//
// Created by aryan on 3/12/2026.
//

#include "hashtable.h"
#include <vector>
// hashtable insert, supports the Lab object and resizing when past load factor of 0.8
bool hashtable::push_back(const std::string &key, const Lab &lab) {
    if (static_cast<double>(num_keys)/static_cast<double>(table.size()) > 0.8) { // resizing and rehashing entire table
        // if more than 0.8 load factor.
        std::vector<std::vector<std::vector<Lab>>> new_table;
        new_table.resize(table.size() * 2);
        for (auto bucket = table.begin();bucket != table.end();++bucket) {
            for (auto lab_group = bucket->begin(); lab_group != bucket->end(); ++lab_group) {
                size_t new_index = lab_group->at(0).hash() % (table.size() * 2);
                new_table[new_index].push_back(std::move(*lab_group));
            }
        }

        table = std::move(new_table);

    }
    std::vector<std::vector<Lab>>& possible_labs_vec = table[lab.hash()%table.size()];
    bool found = false;
    for (std::vector<Lab> &group: possible_labs_vec) {
        if (key==group[0].get_search_string()) {
            group.push_back(lab);
            found = true;
            break;
        }
    }
    if (!found) {
        possible_labs_vec.push_back({lab});
        num_keys++;
    }
    return true;
}

// hashtable seraching, simply uses the hashing of a key bounded withing the table size and gets the bucket with all labs inside
std::vector<Lab> hashtable::search(const std::string &key) {
    const std::vector<std::vector<Lab>>& possible_labs_vec = table[Lab::string_hash(key)%table.size()];
    for (const std::vector<Lab>& group: possible_labs_vec) {
        if (group[0].get_search_string() == key) {
            return group;
        }
    }
    return {};
}
