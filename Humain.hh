#pragma once
#include "Personnage.hh"
#include "Zombie.hh"

class Humain: public virtual Personnage
{
protected:
	int points;
	int dep = 5;
	bool carrying = 0;
public:
	Humain();
	Humain(std::string Nom);
	void deplacement();
	bool is_equipped();
	void dep_clavier();
	void ramasse();
	void attaquer();
	void rmHumain();
	void setPoints(int pts);
	int getPoints();
	bool isCarrying();
	void setCarrying(bool booleen);
};
