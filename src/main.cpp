#include <iostream>
#include <stack>
#include <vector>
#include <SFML/Graphics.hpp>
#include "randomGeneratedData.h"
#include "display.h"

int main() {
    generate();
    displayWindow window;
    window.screen();

    return 0;
};
