#ifndef _Affichage_h
#define _Affichage_h
#include "setup.h"
#include "init.h"


void trace_Plan(plan p, couleur c);
void trace_Triangle(triangle t, couleur c);
void trace_Plateforme(plateforme plat);
void trace_Joueur(joueur jou);
void trace_Maison(maison maison);
void trace_Origine();
void trace_Collision(point p1, point p2);


void trace_praa(point p1, point p2, couleur c);
void trace_escalier(escalier e, int hMarche);


#endif
