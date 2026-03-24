//
// Created by aryan on 3/12/2026.
//

#ifndef PROJ2_N_ARY_H
#define PROJ2_N_ARY_H

#include <iostream>
#include <vector>

class n_ary {
    class Node {
        std::string value;
        std::vector<Node*> children;
    public:
        Node(std::string val): value(val) {};
    };

    Node* head;

public:
    n_ary();
    Node* search(Node* currentNode);
    void insert();

};


#endif //PROJ2_N_ARY_H