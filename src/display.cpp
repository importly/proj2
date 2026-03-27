#include "display.h"

void displayWindow::setText(sf::Text &text, float x, float y)
{
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
    text.setPosition(sf::Vector2f(x, y));
}

void displayWindow::screen() {
    sf::RenderWindow window(sf::VideoMode(1600, 1200), "Research Lab Finder");

    sf::Font font;
    if(!font.loadFromFile("../src/font.ttf"))
    {
        std::cerr << "Font file not found.";
    }

    sf::Text title("Welcome to the Research Lab Finder!", font,50);
    setText(title, 800,500);
    title.setFillColor(sf::Color::White);
    title.setStyle(sf::Text::Bold);

    sf::RectangleShape button(sf::Vector2f(200,70));
    button.setFillColor(sf::Color(127,156,150));
    button.setPosition(700,565);

    sf::Text buttonText("Start Here!!", font, 20);
    buttonText.setFillColor(sf::Color::White);
    setText(buttonText, 800,600);


    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(76,124,138));
        window.draw(title);
        window.draw(button);
        window.draw(buttonText);
        window.display();
    }
}
