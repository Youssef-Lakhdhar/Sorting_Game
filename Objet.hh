#pragma once
#include <SFML/Graphics.hpp>
#include "Humain.hh"
#include <iostream>

class Objet{
protected:
	std::string nom;
	int x;
	int y;
	int x_min,x_max,y_min,y_max;
	int id;
	int genre;
	int longueur;
	int hauteur;
	int poids;
	int points;
	sf::Sprite *m_sprite;
	sf::Texture *m_texture;
	bool collected;
	bool trashed;
	Humain *m_porteur;
public:
	static int compteur;
	static std::vector <Objet> objList;
	Objet(double x, double y);
	void affichage();
	bool is_collected();
	sf::Sprite* getSprite();
	void setPosition(Humain *porteur);
	void tomber(Humain *porteur);
	void isZoned();
	void rmObjet();
	void rmTexture();
	void rmSprite();
	double getX();
	double getY();
	int getGenre();
	void rmFromList();
	bool isTrashed();
};

void remplirListe();
void afficherObjets(sf::RenderWindow *window, Humain *roger);
