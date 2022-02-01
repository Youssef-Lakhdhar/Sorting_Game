#include "Obstacle.hh"

Obstacle::Obstacle()
{
  for(int i = 0; i < 200; i++)
  {
    for(int j = 0; j < 200; j++)
    {
      tabObs[j][i] = 0;
    }
  }
    fill_rectangle(330,265,395,320); //base d'arbre
    fill_rectangle(445,400,595,455); //mur gauche haut
    fill_rectangle(435,400,485,600);//mur gauche
    fill_rectangle(630,400,800,455);//mur droit haut
    fill_rectangle(740,400,800,600);//mur droit
    fill_rectangle(380,85,415,135); //citrouille 1
    fill_rectangle(430,95,465,145); //citrouille 2
    fill_rectangle(465,115,510,155); //citrouille 3
    fill_rectangle(475,155,520,200); //citrouille 4
    fill_rectangle(0,195,75,240); //petit tronc d'arbre
    fill_rectangle(380,175,480,220); //gros tronc d'arbre
    fill_rectangle(270,185,325,240); //ronce seule gauche
    fill_rectangle(40,195,240,305); //voiture
    fill_rectangle(30,270,65,320); //buisson voiture
    fill_rectangle(640,15,690,55); //bosquet ronces 1
    fill_rectangle(680,35,740,95); //bosquet ronces 2
    fill_rectangle(690,95,745,140); //bosquet ronces 3
    fill_rectangle(635,105,695,165); //bosquet ronces 4
    fill_rectangle(580,100,650,150); //bosquet ronces 5
    fill_rectangle(550,55,600,120); //bosquet ronces 6
    fill_rectangle(690,330,740,385); //ronces seules haut mur droit
    fill_rectangle(650,365,710,410); //buisson seul haut mur droit
    fill_rectangle(235,455,275,495); //petite base
    fill_rectangle(170,430,195,470); //buisson seul a gauche petite base
    fill_rectangle(0,550,50,600); //base arbre 1
    fill_rectangle(40,530,70,555); //base arbre 2
    fill_rectangle(105,530,145,555); //base arbre 3
    fill_rectangle(140,550,190,600); //base arbre 4
    fill_rectangle(345,500,390,530); //petit buisson bas gauche
    fill_rectangle(385,505,440,545); //petit tronc d'arbre bordel
    fill_rectangle(380,560,450,600); //arbre colle mur gauche
}

void fill_rectangle(int x1, int y1, int x2, int y2)
{
  for(int i = x1; i < x2; i++){
    for(int j = y1; j < y2; j++){
      Obstacle::tabObs[i/5][j/5] = 1;
    }
  }
}
