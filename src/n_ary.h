#ifndef PROJ2_N_ARY_H
#define PROJ2_N_ARY_H

#include <iostream>
#include <vector>


class n_ary {
    class Node {
    public:
        std::string value;
        std::vector<Node*> children;
    };

    Node* head;

public:
    n_ary();
    Node* searchLevel(Node* currentNode, std::string key);
    void insert();

};

#endif //PROJ2_N_ARY_H