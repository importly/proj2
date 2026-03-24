//
// Created by aryan on 3/12/2026.
//

#include "Lab.h"


Lab::Lab(const std::string &college, const std::string &department, const std::string &topic, const std::string &level, const std::string &name,
    const std::string &contact_info, const std::string &synopsis): college(college),
                                                                   department(department),
                                                                   topic(topic),
                                                                   level(level),
                                                                   name(name),
                                                                   contact_info(contact_info),
synopsis(synopsis){
    search_string = college + "_" + department + "_" + topic + "_" + level;
}

std::string Lab::get_search_string() const {
    return search_string;
}

std::string Lab::get_college() const {
    return college;
}

std::string Lab::get_department() const{
    return department;
}

std::string Lab::get_topic() const{
    return topic;
}

std::string Lab::get_level() const{
    return level;
}

std::string Lab::get_contact_info() const{
    return contact_info;
}

std::string Lab::get_synopsis() const{
    return synopsis;
}

std::string Lab::get_name() const {
    return name;
}

uint64_t Lab::hash() const {
    return fnv1a(get_search_string());
}

uint64_t Lab::fnv1a(const std::string &key) {
    uint64_t hash = FNV_OFFSET_BASIS;
    for (char c : key) {
        hash ^= c;
        hash *= FNV_PRIME;
    }
    return hash;
}
