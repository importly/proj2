#include "display.h"
#include <vector>
#include <SFML/Graphics.hpp>
std::vector<std::string> userValues = {};
void displayWindow::setText(sf::Text &text, float x, float y)
{
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
    text.setPosition(sf::Vector2f(x, y));
}

void displayWindow::screen() {
    sf::RenderWindow window(sf::VideoMode(1600, 1200), "Research Lab Finder");

    sf::Vector2u size = window.getSize();
    float centerX = size.x / 2.0f;
    float centerY = size.y / 2.0f;

    sf::Font font;
    if (!font.loadFromFile("../src/font.ttf")) {
        std::cerr << "Can't find font file.";
    }

    sf::Text title("Welcome to the Research Lab Finder!", font, 50);
    title.setFillColor(sf::Color::White);
    title.setStyle(sf::Text::Bold);

    setText(title, centerX, centerY - 100.0f);

    sf::RectangleShape button(sf::Vector2f(200, 70));
    button.setFillColor(sf::Color(127, 156, 150));

    button.setOrigin(100.0f, 35.0f);
    button.setPosition(centerX, centerY + 50.0f);

    sf::Text buttonText("Start Here!!", font, 20);
    buttonText.setFillColor(sf::Color::White);
    setText(buttonText, centerX, centerY + 50.0f);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
 //used https://www.google.com/search?q=how+to+check+if+a+button+is+clicked+in+sfml&oq=how+to+check+if+a+button+is+clicked+in+sfml&gs_lcrp=EgZjaHJvbWUyBggAEEUYOTIHCAEQIRigATIHCAIQIRigATIHCAMQIRigATIHCAQQIRifBTIHCAUQIRiPAtIBCDkyNDNqMGo3qAIAsAIA&sourceid=chrome&ie=UTF-8
 //^^ helped figure out how to check if a button is clicked and what to do next
            if(event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i position = sf::Mouse::getPosition(window);
                    if (button.getGlobalBounds().contains(static_cast<sf::Vector2f>(position)))
                    {
                        window.close();
                        uniScreen();
                    }
                }
            }
        }

        window.clear(sf::Color(76,124,138));
        window.draw(title);
        window.draw(button);
        window.draw(buttonText);
        window.display();
    }
}

void displayWindow::uniScreen() {
    std::vector<std::string> university = {"University of Florida", "Florida State University", "University of Miami", "University of South Florida", "University of Central Florida", "Florida International University", "Florida Atlantic University", "Florida Gulf Coast University", "NOVA Southeastern University", "University of North Florida"};
    sf::RenderWindow uniWindow(sf::VideoMode(1600, 1200), "Research Lab Finder");

    sf::Vector2u size = uniWindow.getSize();
    float centerX = size.x / 2.0f;

    float btnWidth = 600.0f;
    float btnHeight = 85.0f;
    float xSpace = 40.0f;
    float ySpace = 25.0f;

    float buttonGridWidth = (2 * btnWidth) + xSpace;
    float xStart = centerX - (buttonGridWidth / 2.0f);
    float yStart = 250.0f;

    sf::Font font;
    if (!font.loadFromFile("../src/font.ttf")) {
        std::cerr << "Can't find font file.";
    }
    sf::Text title("Research Lab Finder", font, 55);
    title.setFillColor(sf::Color::White);
    //title.setStyle(sf::Text::Bold);
    setText(title, centerX, 100.0f);

    sf::Text tinyText("Please select a university to find available research opportunities: ", font, 22);
    tinyText.setFillColor(sf::Color::White);
    setText(tinyText, centerX, 180.0f);

    sf::RectangleShape button(sf::Vector2f(btnWidth, btnHeight));

    while(uniWindow.isOpen())
    {
        sf::Event event;
        while (uniWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                uniWindow.close();
            }
        }


        uniWindow.clear(sf::Color(76,124,138));
        uniWindow.draw(title);
        uniWindow.draw(tinyText);
        //drawing the buttons
        for(int i = 0; i < university.size(); i++)
        {
            //column and rows of buttons
            int row = i / 2;
            int col = i % 2;

            float x = xStart + (col * (btnWidth + xSpace));
            float y = yStart + (row * (btnHeight + ySpace));
            button.setPosition(x, y);
            button.setFillColor(sf::Color(127, 156, 150));

            sf::Text buttonText(university[i], font, 24);
            buttonText.setFillColor(sf::Color::White);
            setText(buttonText, x + (btnWidth/ 2.0), y + (btnHeight/ 2.0));

            uniWindow.draw(button);
            uniWindow.draw(buttonText);
        }
        uniWindow.display();
    }
}