#include "Humain.hh"
#include "Obstacle.hh"

Humain::Humain():Personnage()
{

}

Humain::Humain(std::string Nom): Personnage(Nom)
{
  x = 400;
  y = 400;
  ATK = 30;
  points = 0;
  m_texture = new sf::Texture;
  m_texture->loadFromFile("sprites_link.png", sf::IntRect(24, 64, 24, 32)); //SELECTION DU SPRITE
  m_sprite = new sf::Sprite;
  m_sprite->setTexture(*m_texture);
  m_sprite->setPosition(sf::Vector2f(x,y)); //DEPLACEMENT DU SPRITE
}


void Humain::deplacement()
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && y > 0) //VERS LE HAUT
  {
    m_texture->loadFromFile("sprites_link.png",sf::IntRect(0,0,32,32));
    if (Obstacle::tabObs[int(x)/5][int(y/5)-1] == 0) //CASE DU HAUT LIBRE?
    {
      setPosition(x,y - dep); //UPDATE COORDONNEES JOUEUR
      m_sprite->setPosition(sf::Vector2f(x, y - dep)); //UPDATE COORDONNEES SPRITE
    }
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && y < SIZE_Y - H_SPRITE)
  {
    m_texture->loadFromFile("sprites_link.png",sf::IntRect(24,64,24,32));
    if (Obstacle::tabObs[int(x)/5][int(y/5)+1] == 0) //CASE DU BAS LIBRE?
    {
      setPosition(x,y + dep);
      m_sprite->setPosition(sf::Vector2f(x, y + dep));
    }
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && x < SIZE_X - W_SPRITE)
  {
    m_texture->loadFromFile("sprites_link.png",sf::IntRect(0,32,32,32));
    if (Obstacle::tabObs[int(x/5)+1][int(y/5)] == 0) //CASE DE DROITE LIBRE?
    {
      setPosition(x + dep,y);
      m_sprite->setPosition(sf::Vector2f(x + dep, y));
    }
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && x > 0)
  {
    m_texture->loadFromFile("sprites_link.png",sf::IntRect(0,96,32,32));
    if (Obstacle::tabObs[int(x/5)-1][int(y/5)] == 0) //CASE DE GAUCHE LIBRE?
    {
      setPosition(x - dep,y);
      m_sprite->setPosition(sf::Vector2f(x - dep, y));
    }
  }
}

void Humain::attaquer()
{
    for (int i = 0; i < Zombie::zombList.size(); i++)
    {
      if (this->distance(&Zombie::zombList[i]) < 25) //CHECK SI ZOMBIE TROP PROCHE
        setPosition(50,50); //ENVOI DU JOUEUR LOIN DE LA ZONE
    }
}

void Humain::setPoints(int pts)
{
  points = pts;
}

int Humain::getPoints()
{
  return points;
}

bool Humain::isCarrying() //VERIFICATION SI LE JOUEUR PORTE UN OBJET
{
  return carrying;
}

void Humain::setCarrying(bool booleen) //UPDATE DU BOOLEEN CARRYING
{
  carrying = booleen;
}
