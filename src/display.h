#ifndef PROJ2_DISPLAY_H
#define PROJ2_DISPLAY_H
#include <iostream>
#include <stack>
#include <vector>
#include <SFML/Graphics.hpp>
#include "randomGeneratedData.h"
#include "result.h"


class displayWindow {

    std::vector<std::string> userValues = {};

public:
    void screen();
    void uniScreen();
    void departmentScreen();
    void topicScreen();
    void levelScreen();
    void setText(sf::Text &text, float x, float y);
    std::vector<std::string> getUserValues();

};



#endif //PROJ2_DISPLAY_H