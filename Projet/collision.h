#ifndef _Collision_h
#define _Collision_h

#include "setup.h"
#include "matrices.h"
#include "affichage.h"

// Controle la collision avec une maison
point cherchePlusLoinMaison(maison m, point origine);
point cherchePlusProcheMaison(maison m, point origine);
point cherchePlusLoinPlateforme(plateforme p, point origine);
point cherchePlusProchePlateforme(plateforme p, point origine);
point cherchePlusLoinBonus(bonus b, point origine);
point cherchePlusProcheBonus(bonus b, point origine);
point cherchePlusLoinArbre(arbre a, point origine);
point cherchePlusProcheArbre(arbre a, point origine);

int colMaison(point posJoueur, point plusProche, point plusLoin);


#endif



