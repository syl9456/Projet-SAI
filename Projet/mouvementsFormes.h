#ifndef _MouvementsFormes_h
#define _MouvementsFormes_h
#include "setup.h"
#include "matrices.h"



plateforme translation_plateforme(plateforme plat, point po);
plateforme rotation_plateforme(plateforme plat,char axe, float angle);
plateforme mise_echelle_plateforme(plateforme plat, float x,float y, float z);

maison translation_maison(maison mais, point po);
maison rotation_maison(maison mais,char axe,float angle);
maison mise_echelle_maison(maison mais, float x,float y, float z);

joueur translation_joueur(joueur jou, point po);
joueur mise_echelle_joueur(joueur jou, float x,float y, float z);

bonus translation_bonus(bonus bon, point po);
bonus mise_echelle_bonus(bonus bon, float x,float y, float z);
bonus rotation_bonus(bonus bon,char axe, float angle);

arbre translation_arbre(arbre ab, point po);
arbre mise_echelle_arbre(arbre ab, float x,float y, float z);
arbre rotation_arbre(arbre ab,char axe, float angle);

#endif