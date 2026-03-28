#include <iostream>
#include <stack>
#include <vector>
#include <SFML/Graphics.hpp>
#include "randomGeneratedData.h"
#include "display.h"

int main() {
    // first generate data for each run, function in randomGeneratedData.h
    generate();
    // then display window object and start with .screen
    displayWindow window;
    window.screen();

    return 0;
};
