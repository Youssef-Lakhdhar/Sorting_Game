#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Obstacle{
protected:
	double x, y;
	int longueur, hauteur;
	sf::Texture *m_texture;
	sf::Sprite *m_sprite;
public:
	static int tabObs[200][200];
	Obstacle();
	void affichage();
};

void fill_rectangle(int x1, int y1, int x2, int y2);
