#include "Objet.hh"


Objet::Objet(double x, double y)
{
  compteur++;
  id = compteur - 1;
  this->x = x;
  this->y = y;
  points = 1;
  collected = false;
  m_porteur = new Humain();
}

bool Objet::is_collected()
{
  return collected;
}

sf::Sprite* Objet::getSprite()
{
  return m_sprite;
}


void Objet::setPosition(Humain *porteur)
{
  if (!this->collected)
  {
    if ((x == porteur->getX() && y == porteur->getY()) && !porteur->isCarrying())
    {
      this->collected = true;
      m_porteur = porteur;
      porteur->setCarrying(true);
    }
  }
  else
  {
    m_sprite->setPosition(sf::Vector2f(porteur->getX(),porteur->getY()+16));
    x = porteur->getX();
    y = porteur->getY();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
    {
      this->tomber(porteur);
    }
  }
}

void Objet::tomber(Humain *porteur)
{
  x = porteur->getX();
  y = porteur->getY();
  this->isZoned();
  m_porteur = NULL;
  this->collected = false;
  porteur->setCarrying(false);
}

void Objet::isZoned()
{
  if ((x_min < x && x_max > x) && (y_min < y && y_max >y))
  {
    x = 900;
    y = 900;
    m_porteur->setPoints(m_porteur->getPoints() + points);
    this->rmObjet();
  }
}

double Objet::getX()
{
  return x;
}

void Objet::rmObjet()
{
  compteur--;
	this->rmSprite();
	this->rmTexture();
  m_porteur = NULL;
  objList.erase(objList.begin() + id);
}

void Objet::rmTexture()
{
  delete m_texture;
  m_texture = NULL;
}

void Objet::rmSprite()
{
  delete m_sprite;
  m_sprite = NULL;
}

double Objet::getY()
{
  return y;
}

int Objet::getGenre()
{
  return genre;
}

void afficherObjets(sf::RenderWindow *window, Humain *roger)
{
  for (int i = 0; i < Objet::objList.size(); i++)
  {
    if (Objet::objList[i].getSprite())
    {
      Objet::objList[i].setPosition(roger);
      if(Objet::objList[i].getSprite())
        window->draw(*(Objet::objList[i].getSprite()));
    }
  }
}
