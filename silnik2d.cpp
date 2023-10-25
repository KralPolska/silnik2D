// silnik2d.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "engine.h"
#include "primitive.h"
#include <windows.h>
int main()
{   
    engine engine;
    engine.setFramerate(60);

    primitive game(*engine.window);
    tPrimitive obj1(*engine.window);

    float x=20;

    while (engine.gameRunning())
    {
        engine.startClock();
        engine.clearToColor(sf::Color::White);
        engine.update();

        game.drawLine({ 0,0 }, {100,200}, sf::Color::Red);
        game.drawCircle({ 0,0 }, 50, sf::Color::Red,5);
        game.drawFilledCircle({ 0,0}, 30, sf::Color::Black, 5);
        game.drawRectangle({ 100,100 }, { 50,20 }, sf::Color::Green, 10);
        game.drawFilledRectangle({ 100,200 }, { 50,20 }, sf::Color::Green, 10);
        game.drawSquare({ 300,300 }, 20, sf::Color::Yellow, 10);
        game.drawFilledSquare({ 400,400 }, 20, sf::Color::Yellow, 10);
        obj1.drawCircle({ 500,500 }, 50, sf::Color::Red, 25);
        obj1.translate(300, 0);
        engine.render();
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
        