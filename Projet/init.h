#ifndef _Init_h
#define _Init_h

#include "setup.h"
#include "matrices.h"

maison init_maison(point c, float taille);
plateforme init_plateforme(point c, float taille);
joueur init_joueur(point c, float taille);
arbre init_arbre(point c, float taille);
bonus init_bonus(point c, float taille);

#endif