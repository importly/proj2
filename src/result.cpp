#include "result.h"
#include "display.h"
#include <chrono>
#include <fstream>
#include <sstream>
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
//looping over the 100000 data points to create the n-ary tree
    std::ifstream inputFile("../src/researchData.csv");
    std::string line;
    n_ary tree;

    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);

        //storing all the names of the items in the tree
        std::string temp;
        std::string collegeName;
        std::string departmentName;
        std::string topicName;
        std::string levelName;
        std::string nameName;
        std::string contactInfoName;
        std::string synopsisName;

        std::getline(ss, temp, ',');
        std::getline(ss, collegeName, ',');
        std::getline(ss, departmentName, ',');
        std::getline(ss, topicName, ',');
        std::getline(ss, levelName, ',');
        std::getline(ss, nameName, ',');
        std::getline(ss, contactInfoName, ',');
        std::getline(ss, synopsisName, ',');
        tree.insert(collegeName, departmentName, topicName, levelName, nameName, contactInfoName, synopsisName);
    }

    naryResults = tree.functionality(userInput);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    naryTime = std::to_string(elapsed_seconds.count() * 1000) + " ms";


    auto start1 = std::chrono::high_resolution_clock::now();
    std::ifstream iFile("../src/researchData.csv");
    std::string line1;
    hashtable h1;
    while (std::getline(iFile, line1)) {
        std::stringstream ss(line1);

        //storing all the names of the items in the tree
        std::string temp;
        std::string collegeName;
        std::string departmentName;
        std::string topicName;
        std::string levelName;
        std::string nameName;
        std::string contactInfoName;
        std::string synopsisName;

        std::getline(ss, temp, ',');
        std::getline(ss, collegeName, ',');
        std::getline(ss, departmentName, ',');
        std::getline(ss, topicName, ',');
        std::getline(ss, levelName, ',');
        std::getline(ss, nameName, ',');
        std::getline(ss, contactInfoName, ',');
        std::getline(ss, synopsisName, ',');

        Lab l1(collegeName, departmentName, topicName, levelName, nameName, contactInfoName, synopsisName);
        std::string key = l1.get_search_string();

        h1.push_back(key, l1);
    }

    std::string searchKey = "";
    for(int i = 0; i < userInput.size(); i++)
    {
        searchKey += userInput[i];
        if(i < userInput.size() - 1)
        {
            searchKey += "_";
        }
    }
    std::vector<Lab> hashResults = h1.search(searchKey);
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds1 = end1 - start1;
    std::string hashTime = std::to_string(elapsed_seconds1.count() * 1000) + " ms";


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


    float yStart1 = 260.0f;
    std::vector<sf::Text> hashOutput;
    for (int i = 0; i < hashResults.size(); i++) {

        Lab& l2 = hashResults[i];
        std::string tempArr[3] = {l2.get_name(), l2.get_contact_info(), l2.get_synopsis()};
        for(int j = 0; j < 3; j++)
        {

            sf::Text test("", font, 22);
            std::string temp = wrapText(test, tempArr[j], centerX - 40.0f);

            sf::Text researchInfo(temp, font, 22);
            researchInfo.setFillColor(sf::Color::White);

            if (j % 3 == 0) {
                researchInfo.setStyle(sf::Text::Bold);
            }

            researchInfo.setPosition(centerX + 20.0f, yStart1);

            hashOutput.emplace_back(researchInfo);

            yStart1 += 30;
        }

        yStart1 += 50;
    }

    sf::RectangleShape verticalLine(sf::Vector2f(2.0f, ((naryOutput[naryOutput.size()-1].getPosition().y + naryOutput[naryOutput.size()-1].getGlobalBounds().height + 10.0f)-250.0f)));
    verticalLine.setFillColor(sf::Color::White);
    verticalLine.setOrigin(1.0f, 0.0f);
    verticalLine.setPosition(centerX, 250.0f);

    sf::RectangleShape horizonLine(sf::Vector2f(size.x, 2.0f));
    horizonLine.setFillColor(sf::Color::White);
    horizonLine.setOrigin(0, 1.0f);
    horizonLine.setPosition(0, 250.0f);

    //got this to figure out mouse scrolling https://www.google.com/search?q=how+to+allow+your+window+to+scroll+in+sfml&sca_esv=9b7071d2b58e06a1&biw=1440&bih=778&sxsrf=ANbL-n73WtbOmzni1gRsa5Me95nXP66WdQ%3A1774652516594&ei=ZAzHaYeCJI2bptQP0M6q6Qo&ved=0ahUKEwiHxOfml8GTAxWNjYkEHVCnKq0Q4dUDCBE&uact=5&oq=how+to+allow+your+window+to+scroll+in+sfml&gs_lp=Egxnd3Mtd2l6LXNlcnAiKmhvdyB0byBhbGxvdyB5b3VyIHdpbmRvdyB0byBzY3JvbGwgaW4gc2ZtbDIFECEYoAEyBRAhGKABMgUQIRigATIFECEYnwVI92FQ6wVYwmBwDHgAkAEAmAG7AaAB6SqqAQUyMi4zMLgBA8gBAPgBAZgCPKACzCzCAgQQIxgnwgILEAAYgAQYkQIYigXCAgoQABiABBhDGIoFwgIFEAAYgATCAggQABiABBixA8ICBxAAGIAEGA3CAgYQABgWGB7CAggQABgWGAoYHsICCxAAGIAEGIYDGIoFwgIIEAAYgAQYogTCAggQABiiBBiJBcICBRAhGKsCwgIHECEYoAEYCsICBxAhGAoYqwKYAwDiAwUSATEgQIgGAZIHBTI3LjMzoAeGugOyBwUxOC4zM7gHoyzCBwcwLjIyLjM4yAfLAYAIAA&sclient=gws-wiz-serp
    sf::View scrollView = resultWindow.getDefaultView();
    resultWindow.setView(resultWindow.getDefaultView());



    while(resultWindow.isOpen()) {

        sf::Event event;

        while (resultWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                resultWindow.close();
            }
            if (event.type == sf::Event::MouseWheelScrolled) {
                scrollView.move(0, -event.mouseWheelScroll.delta * 30.0f);

                if ((scrollView.getCenter().y - (scrollView.getSize().y/2.0f)) < 0) {
                    scrollView.setCenter(scrollView.getCenter().x, scrollView.getSize().y/2.0f);
                }
                else if ((scrollView.getCenter().y + (scrollView.getSize().y/2.0f)) > (naryOutput[naryOutput.size()-1].getPosition().y + naryOutput[naryOutput.size()-1].getGlobalBounds().height + 10.0f)) {
                    scrollView.setCenter(scrollView.getCenter().x, ((naryOutput[naryOutput.size()-1].getPosition().y + naryOutput[naryOutput.size()-1].getGlobalBounds().height + 10.0f) - scrollView.getSize().y/2.0f));
                }
            }
        }

        resultWindow.clear(sf::Color(76,124,138));
        resultWindow.setView(scrollView);

        for (int i = 0; i < naryOutput.size(); i++) {
            resultWindow.draw(naryOutput[i]);
        }

        for (int i = 0; i < hashOutput.size(); i++) {
            resultWindow.draw(hashOutput[i]);
        }

        resultWindow.draw(title);
        resultWindow.draw(tinyText);
        resultWindow.draw(verticalLine);
        resultWindow.draw(horizonLine);
        resultWindow.draw(nary);
        resultWindow.draw(hash);
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