#include <SFML/Graphics.hpp>
#include "Personnage.hh"
#include "Humain.hh"
#include "Obstacle.hh"
#include "Objet.hh"
#include "Zombie.hh"
#include "Emballage.hh"
#include "Verre.hh"
#include "Organique.hh"
#include <vector>
#include <iostream>
#include "unistd.h"
#define TEMPS_IMPARTI 70

int Obstacle::tabObs[200][200];
int Objet::compteur = 0;
std::vector <Objet> Objet::objList; //LISTE DES OBJETS
std::vector <Zombie> Zombie::zombList; //LISTE DES ZOMBIES

int main()
{
  sf::RenderWindow window(sf::VideoMode(800,600), "Jeu CPP");
  window.setFramerateLimit(30);

  //CHOIX DIFFICULTE
  sf::Texture startText;
  startText.loadFromFile("choix_diff1.png"); //AFFICHAGE ECRAN D'ACCUEIL
  sf::Sprite startSprite;
  startSprite.setTexture(startText);
  bool start = false; //CONDITION BLOQUANTE POUR MENU DES CHOIX
  int choix; //ENTIER POUR CHOISIR L DIFFICULTE
  while(!start)
  {
    window.draw(startSprite);
    window.display();
    //ON ATTEND QUE LE JOUR APPUIE SUR A B OU C
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
      choix = 0;
      start = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
    {
      choix = 1;
      start = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
    {
      choix = 2;
      start = true;
    }
  }
  
  //CREATION DU FOND
  sf::Texture backText;
  backText.loadFromFile("background.png", sf::IntRect(0,0,800,600));
  sf::Sprite backSprite;
  backSprite.setTexture(backText);

  //CREATION DU PERSONNAGE
  Humain *roger = new Humain("Roger");

  // CREATION DES ZOMBIES
  remplirListe(); //creation des zombies

  // CREATION DES OBSTACLES DANS LE CONSTRUCTEUR DE obs1
  Obstacle obs1;

  int to_reach; //score a atteindre

  //CREATION DES OBJETS EN FONCTION DE LA DIFFICULTE ET ON SET LE SCORE
  if (choix >= 0)
  {
    Objet::objList.push_back(Verre(130,570));
    Objet::objList.push_back(Organique(60,570));
    Objet::objList.push_back(Emballage(25,260));
    Objet::objList.push_back(Organique(340,350));
    Objet::objList.push_back(Emballage(215,90));
    Objet::objList.push_back(Verre(125,315));
    to_reach = 3;
  }
  if (choix >= 1)
  {
    Objet::objList.push_back(Verre(350,340));
    Objet::objList.push_back(Organique(720,395));
    Objet::objList.push_back(Emballage(215,475));
    Objet::objList.push_back(Verre(225,415));
    Objet::objList.push_back(Emballage(650,350));
    to_reach = 5;
  }
  if (choix >= 2)
  {
    Objet::objList.push_back(Organique(430,550));
    Objet::objList.push_back(Emballage(460,170));
    Objet::objList.push_back(Verre(655,100));
    Objet::objList.push_back(Organique(115,85));
    Objet::objList.push_back(Verre(125,315));
    Objet::objList.push_back(Emballage(185,315));
    Objet::objList.push_back(Verre(145,325));
    Objet::objList.push_back(Emballage(525,45));
    to_reach = 8;
  }

  int timer = 0; //Initialisation du compteur de temps

// BOUCLE DE JEU
  sf::Clock clock; // démarre le chrono
  while (window.isOpen())
  {
    if (clock.getElapsedTime().asSeconds() > 1) //Increment du compteur de temps
    {
      timer++;
      clock.restart(); //ON RECOMMENCE A COMPTER A CHAQUE SECONDES
      if (roger->getPoints() >= to_reach) //Le score a ete atteint
      {
        while (clock.getElapsedTime().asSeconds() < 5)
        {
          window.clear();

          //AFFICHAGE DE L'IMAGE DE VICTOIRE
          sf::Texture texture_win;
          texture_win.loadFromFile("ballons.png");
          sf::Sprite sprite_win;
          sprite_win.setTexture(texture_win);
          sprite_win.setPosition(sf::Vector2f(144,48));
          window.draw(sprite_win);
          window.display();
        }
        return 0;
      }
      if (timer >= TEMPS_IMPARTI) //Perdu
      {
        while (clock.getElapsedTime().asSeconds() < 5)
        {
          window.clear();

          //AFFICHAGE DE L'IMAGE DE DEFAITE
          sf::Texture texture_lose;
          texture_lose.loadFromFile("pleurs.png");
          sf::Sprite sprite_lose;
          sprite_lose.setTexture(texture_lose);
          sprite_lose.setPosition(sf::Vector2f(100,0)); //Decalage pour nettete
          window.draw(sprite_lose);
          window.display();
        }
        return 0;
      }
    }
    window.clear();
    window.draw(backSprite); //AFFICHAGE DE LA CARTE DE JEU
    sf::Event event;
    while(window.pollEvent(event)) //SCRUTATION DU CLIC SUR CROIX POUR FERMER LE JEU
    {
      if (event.type == sf::Event::Closed)
      {
        window.close();
      }
    }
    if (roger) //VERIFICATION QUE LE PERSO N'A PAS DISPARU
    {
      roger->deplacement(); //DEPLACEMENT DU PERSONNAGE
      window.draw(*(roger->getSprite())); //DESSIN DU PERSONNAGE
      roger->attaquer(); //ATTAQUE DES ZOMBIES SUR LE PERSONNAGE
    }
    afficherObjets(&window,roger); //AFFICHAGE OBJETS
    afficherZombies(&window); //AFFICHAGE ZOMBIES
    window.display(); //AFFICHAGE DE TOUS LES ELEMENTS VISUELS CHARGES PRECEDEMMENT
  }
  return 0;
}
