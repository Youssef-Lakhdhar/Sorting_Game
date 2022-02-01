#include "Verre.hh"

Verre::Verre(double x, double y): Objet(x,y)
{
  x_min = 670;
  x_max = 700;
  y_min = 465;
  y_max = 505;
  m_texture = new sf::Texture;
  m_sprite = new sf::Sprite;
  m_texture->loadFromFile("dechet_bouteille_verre.png");
  m_sprite->setTexture(*m_texture);
  m_sprite->setPosition(sf::Vector2f(x,y));
}
