#include "result.h"
#include "display.h"

void result::resultScreen() {
    sf::RenderWindow resultWindow(sf::VideoMode(1600, 1200), "Research Lab Finder");


    while(resultWindow.isOpen()) {

        sf::Event event;
        while (resultWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                resultWindow.close();
            }
        }

        resultWindow.clear(sf::Color(76,124,138));
        resultWindow.display();
    }
}