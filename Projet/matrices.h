#ifndef _Matrices_h
#define _Matrices_h

#include "setup.h"

//Taille de la matrice
#define TAILLE_MATRICE 4

//Def de la matrice avec sa taille
typedef struct matrice{
	float d[TAILLE_MATRICE][TAILLE_MATRICE];
}matrice;

//Pour appliquer une matrice sur un sommet (x,y,z) 
//on doit transformer ce sommet en une matrice point
typedef struct point{
	float d[TAILLE_MATRICE];
}point;



matrice initialiserMatrice();
matrice initialiserMatriceDeFloat(float a,float b, float c,float d,float e, float f,float g,float , float i);
point initialiserPointDeSommet(sommet s);
point initialiserPointDeFloat(float x, float y, float z);
matrice genereS(float x, float y, float z);
matrice genereT(float x,float y, float z);
matrice genereRAutourX(float angle);
matrice genereRAutourY(float angle);
matrice genereRAutourZ(float angle);
matrice multiplicationMatrice(matrice m1, matrice m2);
point multiplicationMatricePoint(matrice m1, point p2);
void afficheMatrice(matrice m);
void affichePoint(point p);

#endif
