#pragma once
#include "Camera.h"
#include "Scene.h"
#include "InputStateManager.h"
#include <SFML/Graphics.hpp>



class TheGreatWar {
public:
	static void SpawnRect(sf::Vector2f dimensions, sf::Vector2f position, sf::Color color, sf::Color outlineColor, int outlineThickness = 0);
	static sf::RectangleShape SpawnRectangleReturn(sf::Vector2f dimensions, sf::Vector2f position, sf::Color color, sf::Color outlineColor, int outlineThickness = 0);
	static sf::RenderWindow window;
	static void InitializeNavMesh();

	static const int m_MeshSize = 2000;
	static const int m_CellSize = 50;
	static sf::RectangleShape GridSquares[60][60];

private:


protected:

};


sf::RenderWindow TheGreatWar::window(sf::VideoMode::getDesktopMode(), "AI Test Window", sf::Style::Fullscreen);