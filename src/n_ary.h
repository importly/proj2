#ifndef PROJ2_N_ARY_H
#define PROJ2_N_ARY_H

#include <iostream>
#include <vector>
#include "Lab.h"

class n_ary {
    class Node {
    public:
        std::vector<std::string> researchInfo = {};
        std::string value;
        std::vector<Node*> children;
    };

    Node* head;

public:
    n_ary();
    ~n_ary();

    void deleteHelper(Node* node);
    Node* searchLevel(Node* currentNode, std::string key);
    void insert(std::string collegeName, std::string departmentName, std::string topicName, std::string levelName, std::string nameName, std::string contactInfoName, std::string synopsisName);
    std::vector<std::vector<std::string>> functionality(std::vector<std::string>& userInput);

};



#endif //PROJ2_N_ARY_H