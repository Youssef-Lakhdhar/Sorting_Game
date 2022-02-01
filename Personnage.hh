#pragma once
#define SIZE_X 800
#define SIZE_Y 600
#define H_SPRITE 32
#define W_SPRITE 24
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>



class Personnage{
protected:
	std::string nom;
	int PV;
	int ATK;
	int VITESSE;
	int size;
	float x;
	float y;
	int orientation;
	sf::Sprite *m_sprite;
	sf::Texture *m_texture;

public:
	Personnage();
	Personnage(std::string Nom);
	float distance(Personnage *ennemi);
	void affichage();
	void setPosition(float posX, float posY);
	void deplacement();
	float getX();
	float getY();
	void recevoir_degats(int nbDegats);
	void attaquer(Personnage *ennemi);
	bool is_dead();
	sf::Sprite* getSprite();
	sf::Texture* getTexture();
	void rmSprite();
	void rmTexture();
	void rmPersonnage();
};
