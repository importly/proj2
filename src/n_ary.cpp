#include "n_ary.h"

#include <ranges>

void n_ary::insert(std::vector<Lab *> dataVector)
{
    //looping over the 100000 data points to create the n-ary tree
    for(int i = 0; i < dataVector.size(); i++)
    {
        //storing all the names of the items in the tree
        std::string collegeName = dataVector[i]->get_college();
        std::string departmentName = dataVector[i]->get_department();
        std::string topicName = dataVector[i]->get_topic();
        std::string levelName = dataVector[i]->get_level();
        std::string nameName = dataVector[i]->get_name();
        std::string contactInfoName = dataVector[i]->get_contact_info();
        std::string synopsisName = dataVector[i]->get_synopsis();

        //calling search to see if the college exists and if it doesn't then it will be nullptr
        Node* college = searchLevel(head, collegeName);
        //if college is nullptr then create a new node and insert it as the head's children
        if(college == nullptr)
        {
            college = new n_ary::Node();
            college->value = collegeName;
            head->children.push_back(college);
        }

        Node* department = searchLevel(college, departmentName);
        if(department == nullptr)
        {
            department = new n_ary::Node();
            department->value = departmentName;
            college->children.push_back(department);
        }

        Node* topic = searchLevel(department, topicName);
        if(topic == nullptr)
        {
            topic = new n_ary::Node();
            topic->value = topicName;
            department->children.push_back(topic);
        }

        Node* level = searchLevel(topic, levelName);
        if(level == nullptr)
        {
            level = new n_ary::Node();
            level->value = levelName;
            topic->children.push_back(level);
        }
        Node* info = new n_ary::Node();

        info->researchInfo.push_back(nameName);
        info->researchInfo.push_back(contactInfoName);
        info->researchInfo.push_back(synopsisName);
        level->children.push_back(info);


        /*
        Node* name = searchLevel(level, nameName);
        if(name == nullptr)
        {
            name = new n_ary::Node();
            name->value = nameName;
            level->children.push_back(name);
        }

        Node* contactInfo = searchLevel(name, contactInfoName);
        if(contactInfo == nullptr)
        {
            contactInfo = new n_ary::Node();
            contactInfo->value = contactInfoName;
            name->children.push_back(contactInfo);
        }

        Node* synopsis = searchLevel(contactInfo, synopsisName);
        if(synopsis == nullptr)
        {
            synopsis = new n_ary::Node();
            synopsis->value = synopsisName;
            name->children.push_back(synopsis);
        }
        */
    }
}

//searches through the children of the current node for the key (ex if you are looking for the department,
//will search the children of the college for the department and return it if found, else will return nullptr
n_ary::Node* n_ary::searchLevel(Node* currentNode, std::string key) {
    if (currentNode->children.empty()) {
        return nullptr;
    }

    for (int i = 0; i < currentNode->children.size(); i++) {
        if (currentNode->children[i]->value == key) {
            return currentNode->children[i];
        }
    }

    return nullptr;
}

//tries to find the research opportunities, if foudn returns a vector containing all the vectors of info.
//if not found returns an empty vector.
std::vector<std::vector<std::string>> n_ary::functionality(std::vector<std::string>& userInput) {
    Node* temp = head;
    for (int i = 0; i < userInput.size(); i++) {
        temp = searchLevel(temp, userInput[0]);
        if (temp == nullptr) {
            return {};
        }
    }

    for (int i = 0; i < temp->children.size(); i++) {
        allInfo.push_back(temp->children[i]->researchInfo);
    }

    return allInfo;
}