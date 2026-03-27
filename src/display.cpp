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

    setText(title, centerX, centerY - 50.0f);

    sf::RectangleShape button(sf::Vector2f(200, 70));
    button.setFillColor(sf::Color(127, 156, 150));

    button.setOrigin(100.0f, 35.0f);
    button.setPosition(centerX, centerY + 30.0f);

    sf::Text buttonText("Start Here!!", font, 20);
    buttonText.setFillColor(sf::Color::White);
    setText(buttonText, centerX, centerY + 30.0f);

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

            //if screen is clicked
            if(event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    uniWindow.close();
                    departmentScreen();
                }
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

void displayWindow::departmentScreen() {
    //make window and get sizes
    sf::RenderWindow departmentWindow(sf::VideoMode(1600, 1200), "Research Lab Finder");
    sf::Vector2u size = departmentWindow.getSize();
    float centerX = size.x / 2.0f;
    float centerY = size.y / 2.0f;

    sf::Font font;
    if (!font.loadFromFile("../src/font.ttf")) {
        std::cerr << "Can't find font file.";
    }

    sf::Text title("Research Lab Finder", font, 50);
    title.setFillColor(sf::Color::White);
    title.setStyle(sf::Text::Bold);
    setText(title, centerX, 26);

    sf::Text tinyText("Please select a department to find available research oppurtunities: ", font, 25);
    tinyText.setFillColor(sf::Color::White);
    setText(tinyText, centerX, 75);

    sf::RectangleShape cs(sf::Vector2f(600, 140));
    cs.setFillColor(sf::Color(127, 156, 150));
    cs.setOrigin(300.0f, 70.0f);
    cs.setPosition(centerX - 325.0f, centerY);
    sf::Text csText("Computer Science", font, 40);
    csText.setFillColor(sf::Color::White);
    setText(csText, centerX - 325.0f, centerY);

    sf::RectangleShape cpe(sf::Vector2f(600, 140));
    cpe.setFillColor(sf::Color(127, 156, 150));
    cpe.setOrigin(300.0f, 70.0f);
    cpe.setPosition(centerX + 325.0f, centerY);
    sf::Text cpeText("Computer Engineering", font, 40);
    cpeText.setFillColor(sf::Color::White);
    setText(cpeText, centerX + 325.0f, centerY);

    sf::RectangleShape me(sf::Vector2f(600, 140));
    me.setFillColor(sf::Color(127, 156, 150));
    me.setOrigin(300.0f, 70.0f);
    me.setPosition(centerX - 325.0f, centerY + 150);
    sf::Text meText("Mechanical Engineering", font, 40);
    meText.setFillColor(sf::Color::White);
    setText(meText, centerX - 325.0f, centerY + 150);

    sf::RectangleShape ae(sf::Vector2f(600, 140));
    ae.setFillColor(sf::Color(127, 156, 150));
    ae.setOrigin(300.0f, 70.0f);
    ae.setPosition(centerX + 325.0f, centerY + 150);
    sf::Text aeText("Aerospace Engineering", font, 40);
    aeText.setFillColor(sf::Color::White);
    setText(aeText, centerX + 325.0f, centerY + 150);

    sf::RectangleShape ee(sf::Vector2f(600, 140));
    ee.setFillColor(sf::Color(127, 156, 150));
    ee.setOrigin(300.0f, 70.0f);
    ee.setPosition(centerX - 325.0f, centerY + 300.0f);
    sf::Text eeText("Electrical Engineering", font, 40);
    eeText.setFillColor(sf::Color::White);
    setText(eeText, centerX - 325.0f, centerY + 300.0f);

    sf::RectangleShape be(sf::Vector2f(600, 140));
    be.setFillColor(sf::Color(127, 156, 150));
    be.setOrigin(300.0f, 70.0f);
    be.setPosition(centerX + 325.0f, centerY + 300.0f);
    sf::Text beText("Biomedical Engineering", font, 40);
    beText.setFillColor(sf::Color::White);
    setText(beText, centerX + 325.0f, centerY + 300.0f);

    sf::RectangleShape ce(sf::Vector2f(600, 140));
    ce.setFillColor(sf::Color(127, 156, 150));
    ce.setOrigin(300.0f, 70.0f);
    ce.setPosition(centerX - 325.0f, centerY - 150.0f);
    sf::Text ceText("Civil Engineering", font, 40);
    ceText.setFillColor(sf::Color::White);
    setText(ceText, centerX - 325.0f, centerY - 150.0f);

    sf::RectangleShape che(sf::Vector2f(600, 140));
    che.setFillColor(sf::Color(127, 156, 150));
    che.setOrigin(300.0f, 70.0f);
    che.setPosition(centerX + 325.0f, centerY - 150.0f);
    sf::Text cheText("Chemical Engineering", font, 40);
    cheText.setFillColor(sf::Color::White);
    setText(cheText, centerX + 325.0f, centerY - 150.0f);

    sf::RectangleShape ne(sf::Vector2f(600, 140));
    ne.setFillColor(sf::Color(127, 156, 150));
    ne.setOrigin(300.0f, 70.0f);
    ne.setPosition(centerX - 325.0f, centerY - 300.0f);
    sf::Text neText("Nuclear Engineering", font, 40);
    neText.setFillColor(sf::Color::White);
    setText(neText, centerX - 325.0f, centerY - 300.0f);

    sf::RectangleShape phy(sf::Vector2f(600, 140));
    phy.setFillColor(sf::Color(127, 156, 150));
    phy.setOrigin(300.0f, 70.0f);
    phy.setPosition(centerX + 325.0f, centerY - 300.0f);
    sf::Text phyText("Physics", font, 40);
    phyText.setFillColor(sf::Color::White);
    setText(phyText, centerX + 325.0f, centerY - 300.0f);


    while(departmentWindow.isOpen())
    {
        sf::Event event;
        while (departmentWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                departmentWindow.close();
            }
        }

        departmentWindow.clear(sf::Color(76,124,138));
        departmentWindow.draw(title);

        departmentWindow.draw(cs);
        departmentWindow.draw(csText);

        departmentWindow.draw(cpe);
        departmentWindow.draw(cpeText);

        departmentWindow.draw(me);
        departmentWindow.draw(meText);

        departmentWindow.draw(ae);
        departmentWindow.draw(aeText);

        departmentWindow.draw(ee);
        departmentWindow.draw(eeText);

        departmentWindow.draw(be);
        departmentWindow.draw(beText);

        departmentWindow.draw(ce);
        departmentWindow.draw(ceText);

        departmentWindow.draw(che);
        departmentWindow.draw(cheText);

        departmentWindow.draw(ne);
        departmentWindow.draw(neText);

        departmentWindow.draw(phy);
        departmentWindow.draw(phyText);

        departmentWindow.draw(tinyText);
        departmentWindow.display();

    }
}
