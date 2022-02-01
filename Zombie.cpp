#include "Zombie.hh"

Zombie::Zombie(double x, double y, int direction):Personnage()
{
  PV = 50;
  x_dep = x;
  y_dep = y;
  this->x = x;
  this->y = y;
  m_texture = new sf::Texture;
  m_texture->loadFromFile("sprites_zombie.png", sf::IntRect(0, 0, 32, 64));
  m_sprite = new sf::Sprite;
  m_sprite->setTexture(*m_texture);
  m_sprite->setPosition(sf::Vector2f(x,y-5));
  this->direction = direction;
}

void Zombie::deplacement()
{
  if (direction == 0)
    deplacement_x();
  else
    deplacement_y();
}

void Zombie::deplacement_x()
{
  if((x_dep - x == -250)||(x_dep - x == 0)){
    direction_x = !(direction_x);
  }
  if((x_dep - x > -250)&&(direction_x == 1)){
    m_texture->loadFromFile("sprites_zombie.png", sf::IntRect(0, 128, 32, 64));
    x = x + 5;
  }
  if((x_dep - x < 0)&&(direction_x == 0)){
    m_texture->loadFromFile("sprites_zombie.png", sf::IntRect(0, 64, 32, 64));
    x = x - 5;
  }
  m_sprite->setPosition(sf::Vector2f(x,y));
}

void Zombie::deplacement_y()
{
  if((y_dep - y == -250)||(y_dep - y == 0)){
    direction_y = !(direction_y);
  }
  if((y_dep - y > -250)&&(direction_y == 1)){
    m_texture->loadFromFile("sprites_zombie.png", sf::IntRect(0, 0, 32, 64));
    y = y + 5;
  }
  if((y_dep - y < 0)&&(direction_y == 0)){
    m_texture->loadFromFile("sprites_zombie.png", sf::IntRect(0, 192, 32, 64));
    y = y - 5;
  }
  m_sprite->setPosition(sf::Vector2f(x,y));
}

void Zombie::attaquer(Personnage *humain)
{

}

void remplirListe()
{
  Zombie::zombList.push_back(Zombie(200,200,0));
  Zombie::zombList.push_back(Zombie(500,300,0));
  Zombie::zombList.push_back(Zombie(200,100,1));
  Zombie::zombList.push_back(Zombie(150,400,0));
  Zombie::zombList.push_back(Zombie(535,100,1));
}

void afficherZombies(sf::RenderWindow *window)
{
  for (int i = 0; i < Zombie::zombList.size(); i++)
  {
    Zombie::zombList[i].deplacement();
    if (Zombie::zombList[i].getSprite())
    {
      if(Zombie::zombList[i].getSprite())
        window->draw(*(Zombie::zombList[i].getSprite()));
    }
  }
}
