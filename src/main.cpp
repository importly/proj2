#include <iostream>
#include <stack>
#include <vector>
#include <SFML/Graphics.hpp>
#include "randomGeneratedData.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "UF Lab Finder - SFML Edition");

    std::cout << "SFML Window is opening..." << std::endl;

    // The "Infinite Loop" for the GUI
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(0, 33, 165)); // UF Blue
        // You can draw your 100k data points here later!
        window.display();
    }
};
