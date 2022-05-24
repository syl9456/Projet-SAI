#ifndef _cube_h
#define _cube_h

#include "TAD_k-arbres.h"
#include "affichage.h"
#include "setup.h"

#define CBASES1X 0
#define CBASES1Y 0
#define CBASES1Z 0
#define CBASES2X 1000
#define CBASES2Y 1000
#define CBASES2Z 1000

int objetPasDansCube(cube cBase, cube cObjet);
int cubeDansObjet(cube cBase, cube cObjet);
karbre intersection(karbre A1, karbre A2);
karbre copie(karbre A);
karbre objet2arbre(point p1,point p2);

#endif
