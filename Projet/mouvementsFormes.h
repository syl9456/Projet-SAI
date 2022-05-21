#ifndef _MouvementsFormes_h
#define _MouvementsFormes_h
#include "setup.h"
#include "matrices.h"



void translation_plateforme(plateforme plat, point po);
void rotation_plateforme(plateforme plat, float angle);
void mise_echelle_plateforme(plateforme plat, float x,float y, float z);
void translation_maison(maison mais, point po);
void rotation_maison(maison mais,float angle);
void mise_echelle_maison(maison mais, float x,float y, float z);
#endif