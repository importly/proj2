//
// Created by aryan on 3/12/2026.
//

#ifndef PROJ2_LAB_H
#define PROJ2_LAB_H
#define FNV_OFFSET_BASIS 14695981039346656037
#define FNV_PRIME 1099511628211
#include <cstdint>
#include <string>


class Lab {
    std::string college;
    std::string department;
    std::string topic;
    std::string level;
    std::string search_string;

    std::string name;
    std::string contact_info;
    std::string synopsis;

public:

    Lab(const std::string &college, const std::string &department, const std::string &topic, const std::string &level, const std::string &name,
    const std::string &contact_info, const std::string &synopsis);

    const std::string& get_search_string() const;

    const std::string& get_college() const;

    const std::string& get_department() const;

    const std::string& get_topic() const;

    const std::string& get_level() const;

    const std::string& get_contact_info() const;

    const std::string& get_synopsis() const;

    const std::string& get_name() const;

    uint64_t hash() const;

    static uint64_t string_hash(std::string key) ;

private:
    // FNV-1a hash algorithm, got from edugator reference material (https://edugator.app/courses/b471fb90-c706-4a6c-9f09-8fbdee880e2a/lesson/acf30a19-a54b-42f8-b282-3a95a5a6a554)
    static uint64_t fnv1a(const std::string& key);
};


#endif //PROJ2_LAB_H