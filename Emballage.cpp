#include "Emballage.hh"

Emballage::Emballage(double x, double y):Objet(x,y)
{
  x_min = 590;
  x_max = 630;
  y_min = 515;
  y_max = 540;
  m_texture = new sf::Texture;
  m_sprite = new sf::Sprite;
  m_texture->loadFromFile("dechet_papier.png");
  m_sprite->setTexture(*m_texture);
  m_sprite->setPosition(sf::Vector2f(x,y));
}
