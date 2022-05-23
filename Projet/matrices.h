#ifndef _Matrices_h
#define _Matrices_h

#include "setup.h"

//Taille de la matrice
#define TAILLE_MATRICE 4

//Def de la matrice avec sa taille
typedef struct matrice{
	float d[TAILLE_MATRICE][TAILLE_MATRICE];
}matrice;

//Pour appliquer une matrice sur un vecteur (x,y,z) 
typedef struct vecteur{
	float d[TAILLE_MATRICE];
}vecteur;




matrice initialiserMatrice();
matrice initialiserMatriceDeFloat(float a,float b, float c,float d,float e, float f,float g,float h, float i);
point initialiserPointDeFloat(float x, float y, float z);
vecteur initialiserVecteurDeFloat(float x, float y, float z);

matrice genereS(float x, float y, float z);
matrice genereT(float x,float y, float z);

matrice genereRAutourX(float angle);
matrice genereRAutourY(float angle);
matrice genereRAutourZ(float angle);
matrice genereRAutourVec(float angle, vecteur vec);

matrice multiplicationMatrice(matrice m1, matrice m2);
point multiplicationMatricePoint(matrice m1, point p2);
vecteur multiplicationMatriceVecteur(matrice m1, vecteur p2);
void afficheMatrice(matrice m);
void affichePoint(point p);
void afficheVecteur(vecteur v);

vecteur vecAvec2points(point p1, point p2);
vecteur produitScalaire(vecteur p1, vecteur p2);
vecteur normalise(vecteur p);
vecteur soustraction(vecteur p1, vecteur p2);
vecteur addition(vecteur p1, vecteur p2);

float distance(point p1, point p2);

#endif
