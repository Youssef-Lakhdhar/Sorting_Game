#include "Organique.hh"

Organique::Organique(double x, double y):Objet(x,y)
{
  x_min = 520;
  x_max = 555;
  y_min = 475;
  y_max = 505;
  m_texture = new sf::Texture;
  m_sprite = new sf::Sprite;
  m_texture->loadFromFile("objet_bleu.png");
  m_sprite->setTexture(*m_texture);
  m_sprite->setPosition(sf::Vector2f(x,y));
}
