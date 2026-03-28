#ifndef PROJ2_RESULT_H
#define PROJ2_RESULT_H
#include <SFML/Graphics.hpp>
#include "n_ary.h"

class result {
public:
    void setText(sf::Text &text, float x, float y);
    void resultScreen(std::vector<std::string>& userInput);
    std::string wrapText(sf::Text& researchInfo, std::string outputText, float limit);
};


#endif //PROJ2_RESULT_H
