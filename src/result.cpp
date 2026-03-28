#include "result.h"
#include "display.h"
#include <chrono>

void result::setText(sf::Text &text, float x, float y) {
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
    text.setPosition(sf::Vector2f(x, y));
}

void result::resultScreen(std::vector<std::string>& userInput) {

    //call all n-ary and hash functions
    std::string naryTime;
    std::vector<std::vector<std::string>> naryResults;

    auto start = std::chrono::high_resolution_clock::now();

    n_ary tree;
    tree.insert();
    naryResults = tree.functionality(userInput);

    for (int i = 0; i < naryResults.size(); i++) {
        for (int j = 0; j < naryResults[i].size(); j++) {
            std::cout << naryResults[i][j] << std::endl;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    naryTime = std::to_string(elapsed_seconds.count() * 1000) + " ms";

    std::string hashTime = " ";

    //display
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

    std::string naryText = "N-Ary Tree (Time Taken: " + naryTime + ")";
    sf::Text nary(naryText, font, 22);
    nary.setFillColor(sf::Color::White);
    nary.setStyle(sf::Text::Bold);
    setText(nary, centerX/2.0f, 237.0f);

    std::string hashText = "Hash Table (Time Taken: " + hashTime + ")";
    sf::Text hash(hashText, font, 22);
    hash.setFillColor(sf::Color::White);
    hash.setStyle(sf::Text::Bold);
    setText(hash, centerX/2.0f+centerX, 237.0f);

    sf::RectangleShape verticalLine(sf::Vector2f(2.0f, 800.0f));
    verticalLine.setFillColor(sf::Color::White);
    verticalLine.setOrigin(1.0f, 0.0f);
    verticalLine.setPosition(centerX, 250.0f);

    sf::RectangleShape horizonLine(sf::Vector2f(size.x, 2.0f));
    horizonLine.setFillColor(sf::Color::White);
    horizonLine.setOrigin(0, 1.0f);
    horizonLine.setPosition(0, 250.0f);

    //got this to figure out mouse scrolling https://www.google.com/search?q=how+to+allow+your+window+to+scroll+in+sfml&sca_esv=9b7071d2b58e06a1&biw=1440&bih=778&sxsrf=ANbL-n73WtbOmzni1gRsa5Me95nXP66WdQ%3A1774652516594&ei=ZAzHaYeCJI2bptQP0M6q6Qo&ved=0ahUKEwiHxOfml8GTAxWNjYkEHVCnKq0Q4dUDCBE&uact=5&oq=how+to+allow+your+window+to+scroll+in+sfml&gs_lp=Egxnd3Mtd2l6LXNlcnAiKmhvdyB0byBhbGxvdyB5b3VyIHdpbmRvdyB0byBzY3JvbGwgaW4gc2ZtbDIFECEYoAEyBRAhGKABMgUQIRigATIFECEYnwVI92FQ6wVYwmBwDHgAkAEAmAG7AaAB6SqqAQUyMi4zMLgBA8gBAPgBAZgCPKACzCzCAgQQIxgnwgILEAAYgAQYkQIYigXCAgoQABiABBhDGIoFwgIFEAAYgATCAggQABiABBixA8ICBxAAGIAEGA3CAgYQABgWGB7CAggQABgWGAoYHsICCxAAGIAEGIYDGIoFwgIIEAAYgAQYogTCAggQABiiBBiJBcICBRAhGKsCwgIHECEYoAEYCsICBxAhGAoYqwKYAwDiAwUSATEgQIgGAZIHBTI3LjMzoAeGugOyBwUxOC4zM7gHoyzCBwcwLjIyLjM4yAfLAYAIAA&sclient=gws-wiz-serp
    sf::View scrollView = resultWindow.getDefaultView();

    float yStart = 260.0f;
    std::vector<sf::Text> naryOutput;
    for (int i = 0; i < naryResults.size(); i++) {

        for (int j = 0; j < naryResults[i].size(); j++) {

            sf::Text test("", font, 22);
            std::string temp = wrapText(test, naryResults[i][j], centerX - 20.0f);

            sf::Text researchInfo(temp, font, 22);
            researchInfo.setFillColor(sf::Color::White);

            if (j % 3 == 0) {
                researchInfo.setStyle(sf::Text::Bold);
            }

            researchInfo.setPosition(20.0f, yStart);

            naryOutput.emplace_back(researchInfo);

            yStart += 30;
        }

        yStart += 50;
    }

    while(resultWindow.isOpen()) {

        sf::Event event;

        while (resultWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                resultWindow.close();
            }
            if (event.type == sf::Event::MouseWheelScrolled) {
                scrollView.move(0, -event.mouseWheelScroll.delta * 30.0f);
            }
        }

        resultWindow.clear(sf::Color(76,124,138));
        resultWindow.setView(resultWindow.getDefaultView());

        for (int i = 0; i < naryOutput.size(); i++) {
            resultWindow.draw(naryOutput[i]);
        }

        resultWindow.draw(title);
        resultWindow.draw(tinyText);
        resultWindow.draw(verticalLine);
        resultWindow.draw(horizonLine);
        resultWindow.draw(nary);
        resultWindow.draw(hash);

        resultWindow.setView(scrollView);

        resultWindow.display();
    }
}

std::string result::wrapText(sf::Text& researchInfo, std::string outputText, float limit) {
    std::string wrappedText = "";
    std::string currentLine = "";
    std::stringstream ss(outputText);
    std::string word;

    while (ss >> word) {
        std::string testLine = currentLine + word + " ";
        researchInfo.setString(testLine);

        if (researchInfo.getLocalBounds().width > limit) {
            wrappedText += currentLine + "\n";
            currentLine = word + " ";
        }
        else {
            currentLine = testLine;
        }
    }

    return wrappedText + currentLine;
}