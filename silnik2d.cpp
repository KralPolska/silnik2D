#include <iostream>
#include "engine.h"
#include "primitive.h"
#include "Animation.h"
#include <windows.h>

int main()
{   
    srand(time(0));
    std::string title = "Silnik 2D :DDDDDDDDDDDDDD";

    engine engine(900, 1600, 1, title);
    engine.setFramerate(60);

    float dt;
    sf::Clock dtClock;

    sf::Texture texture;
    sf::Texture playerSS;
    sf::Texture floor;

    sf::Color color(255,0,0);

    if (!texture.loadFromFile("brickedWhite.png"))
        perror("bricked");
    if (!playerSS.loadFromFile("player1_spritesheet_copy.png"))
        perror("player_spriteSheet");
    if (!floor.loadFromFile("floor8bit.png"))
        perror("floor");

    sf::Sprite floorSprite(floor);
    floorSprite.setColor({60,60,60});
    primitive_rectangle R(*engine.window);
    R.setSize(48, 48);
    R.setPosition(100,100);
    R.setTexture(&playerSS);
    R.updateEdge();
    R.setColor(sf::Color::Blue);

    primitive_square S(*engine.window);
    S.setSize(100);
    S.setPosition(200, 200);
    S.setTexture(&texture);
    S.updateEdge();
    S.setColor({120,0,0});
    S.setTextureRect({ 0,0,(int)S.getSize(),(int)S.getSize() });

    primitive_circle C(*engine.window);
    C.setPosition({ 400,400 });
    C.setSize(100);
    C.setColor(sf::Color::Cyan);
    C.setTexture(&texture);
    C.setTextureRect({0,0,(int)C.getSize(),(int)C.getSize()});

    primitive_triangle T(*engine.window);
    T.setPosition({ 1000,500 });
    T.setSize(50);
    T.setTexture(&floor);
    T.setColor(sf::Color::Magenta);

    //primitive_line L(*engine.window);
    //L.setPosition({ 300,300 }, { 350,350 });

    //std::vector<sf::Vector2f> points = {};
    //points.push_back({ 150,150 });
    //points.push_back({ 100,200 });
    //points.push_back({ 200,200 });
    //points.push_back({ 250,150 });
    //points.push_back({ 200,100 });


    //primitive_convex Con(*engine.window);
    //Con.setPointCount(5);
    //Con.setPointPosition(points);
    //Con.setPosition(300, 300);

    Animation a(&playerSS, { 4,4 }, 0.2f);

    float x = 100.0f;
    float y = 100.0f;

    int state = 3;

    float colorTimer = 0.05f;
    float totalTimer = 0;

    sf::Color r = { 255,0,0,100 };
    sf::Color g = { 0,255,0,100 };
    sf::Color b = { 0,0,255,100 };
    sf::Color colors[6] = { r,r + g,g,g + b,b,r + b};
    int zmiana = 0;

    sf::Vector2i mousePos;

    while (engine.gameRunning())
    {
        dt = dtClock.restart().asSeconds();
        engine.clearToColor({200,200,200,1});
        engine.window->draw(floorSprite);

        while (engine.window->pollEvent(engine.event))
        {
            if (engine.event.type == sf::Event::Closed)
                engine.window->close();
            //Klawiatura
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                engine.window->close();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                R.isPressed(sf::Mouse::getPosition(*engine.window));
                S.isPressed(sf::Mouse::getPosition(*engine.window));
            }
        }
        //Basic movement check
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
        {
            x +=50;
            y +=50;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            if (R.selected)
            {
                state = 0;
                R.translate(0, -y, dt);
            }
            if (S.selected)
            {
                S.translate(0, -y, dt);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            if (R.selected)
            {
                state = 1;
                R.translate(0, y, dt);
            }
            if (S.selected)
            {
                S.translate(0, y, dt);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            if (R.selected)
            {
                state = 2;
                R.translate(-x, 0, dt);
            }
            if (S.selected)
            {
                S.translate(-x, 0, dt);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            if (R.selected)
            {
                state = 3;
                R.translate(x, 0, dt);
            }
            if (S.selected)
            {
                S.translate(x, 0, dt);
            }
        }

        a.update(dt, state);
        if (R.moving)
            R.setTextureRect({ a.uvRect });
        else
            R.setTextureRect({ state * a.uvRect.width,0,a.uvRect.width,a.uvRect.height });

        if (zmiana == 6)
            zmiana = 0;
        else zmiana++;
            
        totalTimer += dt;
        if (totalTimer >= colorTimer)
        {
            totalTimer -= colorTimer;
            C.setColor(colors[zmiana]);
        }

        C.draw();
        T.draw();
        T.rotate(100,dt);
        S.draw();
        R.draw();
        
        //engine.window->draw(circle);
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
        