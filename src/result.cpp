#include "result.h"
#include "display.h"
void result::setText(sf::Text &text, float x, float y)
{
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
    text.setPosition(sf::Vector2f(x, y));
}

void result::resultScreen() {
    sf::RenderWindow resultWindow(sf::VideoMode(1600, 1200), "Research Lab Finder");
    sf::Vector2u size = resultWindow.getSize();
    float centerX = size.x / 2.0f;

    sf::Font font;
    if (!font.loadFromFile("../src/font.ttf")) {
        std::cerr << "Can't find font file.";
    }

    sf::Text title("Research Lab Finder", font, 55);
    title.setFillColor(sf::Color::White);
    title.setStyle(sf::Text::Bold);
    setText(title, centerX, 100.0f);

    sf::Text tinyText("Here are the available research opportunities: ", font, 22);
    tinyText.setFillColor(sf::Color::White);
    setText(tinyText, centerX, 180.0f);

    while(resultWindow.isOpen()) {

        sf::Event event;
        while (resultWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                resultWindow.close();
            }
        }
        resultWindow.clear(sf::Color(76,124,138));

        resultWindow.draw(title);
        resultWindow.draw(tinyText);
        resultWindow.display();
    }
}