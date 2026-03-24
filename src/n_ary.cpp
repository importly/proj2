#include "n_ary.h"

void n_ary::insert(std::vector<Lab *> dataVector)
{
    for(int i = 0; i < dataVector.size(); i++)
    {
        if(!search(head , dataVector[i]->get_college()))
        {
            Node *college = new n_ary::Node();
            head->children.push_back(college);
        }
    }
}

n_ary::Node* n_ary::search(Node* currentNode)
{
    return nullptr;
}
