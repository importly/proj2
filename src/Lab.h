//
// Created by aryan on 3/12/2026.
//

#ifndef PROJ2_LAB_H
#define PROJ2_LAB_H
#include <string>


class Lab {
    std::string college;
    std::string department;
    std::string topic;
    std::string level;

    std::string contact_info;
    std::string synopsis;

public:

    Lab(const std::string &college, const std::string &department, const std::string &topic, const std::string &level,
    const std::string &contact_info, const std::string &synopsis);

    std::string get_search_string() const;

    std::string get_college();

    std::string get_department();

    std::string get_topic();

    std::string get_level();

    std::string get_contact_info();

    std::string get_synopsis();
};


#endif //PROJ2_LAB_H