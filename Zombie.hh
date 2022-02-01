#pragma once
#include <iostream>
#include "Personnage.hh"
#include <vector>

class Zombie: public Personnage{
protected:
 	double x_dep;
	double y_dep;
	bool direction_x = true;
	bool direction_y = true;
  int direction;
public:
	Zombie();
	Zombie(double x, double y,int direction);
  void deplacement();
	void deplacement_x();
	void deplacement_y();
  void attaquer(Personnage *humain);
  static std::vector <Zombie> zombList;
};

void remplirListe();
void afficherZombies(sf::RenderWindow *window);
