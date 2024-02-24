#include "TheGreatWar.h"


sf::RectangleShape TheGreatWar::GridSquares[60][60];


int main() {
    
    while (TheGreatWar::window.isOpen()) {
        sf::Event event;
        while (TheGreatWar::window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                TheGreatWar::window.close();
            }
        }

        TheGreatWar::window.clear(sf::Color::Black);

        TheGreatWar::SpawnRect(sf::Vector2f(100, 100), sf::Vector2f(TheGreatWar::window.getSize().x, TheGreatWar::window.getSize().y / 2), sf::Color::Red, sf::Color::Red);
        
        TheGreatWar::SpawnRect(sf::Vector2f(50, 50), sf::Vector2f(0, 0), sf::Color::Magenta, sf::Color::Magenta, 0);

        int numYellowSquares = 5;
        sf::RectangleShape yellowSquare(sf::Vector2f(20, 20));
        yellowSquare.setPosition(0, TheGreatWar::window.getSize().y / 2 - yellowSquare.getSize().y);
        yellowSquare.setFillColor(sf::Color::Yellow);
        for (int i = 0; i < numYellowSquares; i++) {
            TheGreatWar::window.draw(yellowSquare);
            yellowSquare.move(0, yellowSquare.getSize().y + 10);
        }

        // Building navmesh
        TheGreatWar::InitializeNavMesh();


        

        TheGreatWar::window.display();
    }

    return 0;
}

void TheGreatWar::SpawnRect(sf::Vector2f dimensions, sf::Vector2f position, sf::Color color, sf::Color outlineColor, int outlineThickness)
{
    sf::RectangleShape tempSquare(sf::Vector2f(dimensions.x, dimensions.y));
    tempSquare.setPosition(position.x - tempSquare.getSize().x / 2, position.y - tempSquare.getSize().y / 2);
    tempSquare.setFillColor(color);
    tempSquare.setOutlineThickness(outlineThickness);
    tempSquare.setOutlineColor(outlineColor);
    TheGreatWar::window.draw(tempSquare);
}

sf::RectangleShape TheGreatWar::SpawnRectangleReturn(sf::Vector2f dimensions, sf::Vector2f position, sf::Color color, sf::Color outlineColor, int outlineThickness)
{
    sf::RectangleShape tempSquare(sf::Vector2f(dimensions.x, dimensions.y));
    tempSquare.setPosition(position.x - tempSquare.getSize().x / 2, position.y - tempSquare.getSize().y / 2);
    tempSquare.setFillColor(color);
    tempSquare.setOutlineThickness(outlineThickness);
    tempSquare.setOutlineColor(outlineColor);
    TheGreatWar::window.draw(tempSquare); 
    return tempSquare;
}

void TheGreatWar::InitializeNavMesh()
{
    sf::RectangleShape BlueRectangle = TheGreatWar::SpawnRectangleReturn(sf::Vector2f(50, 100), sf::Vector2f(TheGreatWar::window.getSize().x / 2, TheGreatWar::window.getSize().y / 2), sf::Color::Transparent, sf::Color::Blue, 1);
    // 2D array to initialize grid
    for (int x = 0; x < 60; x++)
    {
        for (int y = 0; y < 60; y++)
        {
            TheGreatWar::GridSquares[x][y] = TheGreatWar::SpawnRectangleReturn(sf::Vector2f(m_CellSize, m_CellSize), sf::Vector2f(x * m_CellSize, y * m_CellSize), sf::Color::Transparent, sf::Color::White, 1);
            if (TheGreatWar::GridSquares[x][y].getGlobalBounds().intersects(BlueRectangle.getGlobalBounds()))
            {
                TheGreatWar::GridSquares[x][y].setFillColor(sf::Color::Red);
                TheGreatWar::window.draw(TheGreatWar::GridSquares[x][y]);
            }
        }
    }

}


