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
    std::vector<std::vector<std::string>> allInfo;

public:
    n_ary();
    ~n_ary();

    void deleteHelper(Node* node);
    Node* searchLevel(Node* currentNode, std::string key);
    void insert(std::vector<Lab *> dataVector);
    std::vector<std::vector<std::string>> functionality(std::vector<std::string>& userInput);

};



#endif //PROJ2_N_ARY_H