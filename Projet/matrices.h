#ifndef _Matrices_h
#define _Matrices_h

#include "setup.h"

//Taille de la matrice
#define TAILLE_MATRICE 4

//Def de la matrice avec sa taille
typedef float matrice[TAILLE_MATRICE][TAILLE_MATRICE];

//Pour appliquer une matrice sur un sommet (x,y,z) 
//on doit transformer ce sommet en une matrice point
typedef float point[TAILLE_MATRICE];



void initialiserMatrice();
void initialiserMatriceAvec1();
void initialiseMatriceDeSommetAvec1(sommet s);
void genereS(float x, float y, float z);
void genereT(float x,float y, float z);
/* ??? mon frero ?? 
matrice genereRAutourY();
*/
void multiplicationMatrice(matrice m1, matrice m2);
//point multiplicationMatricePoint(matrice m1, point p2);
void afficheMatrice(matrice m);
void affichePoint(point p);

#endif