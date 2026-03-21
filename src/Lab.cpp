//
// Created by aryan on 3/12/2026.
//

#include "Lab.h"


Lab::Lab(const std::string &college, const std::string &department, const std::string &topic, const std::string &level,
    const std::string &contact_info, const std::string &synopsis): college(college),
                                                                   department(department),
                                                                   topic(topic),
                                                                   level(level),
                                                                   contact_info(contact_info),
                                                                   synopsis(synopsis) {
}

std::string Lab::get_search_string() const {
    return college + "_" + department + "_" + topic + "_" + level;
}

std::string Lab::get_college() {
    return college;
}

std::string Lab::get_department() {
    return department;
}

std::string Lab::get_topic() {
    return topic;
}

std::string Lab::get_level() {
    return level;
}

std::string Lab::get_contact_info() {
    return contact_info;
}

std::string Lab::get_synopsis() {
    return synopsis;
}
