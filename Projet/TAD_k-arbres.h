#ifndef _TADkarbres_h
#define _TADkarbres_h

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <math.h>
#include <time.h>

#define K 8

#define TRUE 1
#define FALSE 0
#define PROFONDEUR_MAX 8

#define VIDE 6
#define PLEIN 7
#define COMPLEXE 8

typedef struct sommet{
  int x,y,z;
}sommet;

typedef struct boule{
  sommet p;
  int r;
}boule;

typedef struct cube{
  sommet s1;
  sommet s2;
}cube;


typedef int element;

typedef struct noeud{
  element etat;
  cube c;
  struct noeud *fils[K];
}noeud;

typedef noeud *karbre;

karbre kArbreNull();
karbre kArbreVide(cube c);
karbre kArbrePlein(cube c);
cube kCube(karbre A);
int estVide(karbre A);
int estPlein(karbre A);
element kRacine(karbre A);
karbre kConsArbre(element e,...);
karbre kFils(int ieme, karbre A);
void afficheKArbre(karbre A);

#endif
