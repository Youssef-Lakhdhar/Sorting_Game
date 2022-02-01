#include <iostream>
#include "Personnage.hh"

Personnage::Personnage()
{

}

Personnage::Personnage(std::string Nom)
{
	nom = Nom;
}

void Personnage::setPosition(float posX, float posY)
{
	x = posX;
	y = posY;
}

float Personnage::getX()
{
	return x;
}

float Personnage::getY()
{
	return y;
}

float Personnage::distance(Personnage *ennemi) // RETOURNE LA DISTANCE ENTRE 2 PERSONNAGES
{
	return sqrt((x-ennemi->getX())*(x-ennemi->getX())+(y-ennemi->getY())*(y-ennemi->getY()));
}

void Personnage::recevoir_degats(int nbDegats)
{
	PV -= nbDegats;
	if (PV < 0)
	{
		PV = 0;
	}
}

bool Personnage::is_dead(){
	if (PV == 0){
		return true;
	}
	return false;
}

sf::Sprite* Personnage::getSprite()
{
  return m_sprite;
}

sf::Texture* Personnage::getTexture()
{
	return m_texture;
}

void Personnage::rmSprite()
{
	delete m_sprite;
}

void Personnage::rmTexture()
{
	delete m_texture;
	m_texture = NULL;
}

void Personnage::rmPersonnage()
{
	this->rmSprite();
	this->rmTexture();
	delete this;
}
