#ifndef _Setup_h
#define _Setup_h

// FICHIER DE SETUP POUR LA BASE
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "GL/gl.h"
#include "GL/glut.h"
#include <time.h>
#include <math.h>


#define FENX 1200
#define FENY 1000

#define HAUTEUR_PLATEFORME 10
#define HAUTEUR_MAISON 20
#define HAUTEUR_ARBRE 30

#define TAILLE_STRUC 20


#define PI 3.141592 





typedef struct couleur{
	float r,g,b;
}couleur;


//Un point est construit avec 3 float x y z
typedef struct point{
	float d[4];
}point;

//Un plna est construit avec 4 points
typedef struct plan{
	point point[4];
}plan;

typedef struct boule{
	point centre;
	float rayon;
}boule;

typedef struct bonus{
	point centre;
	plan plans[6];
}bonus;

//Un triangle est construit avec 3 points
typedef struct triangle{
	point point[3];
}triangle;

//Une maison est constituée de 7 plans et 2 triangles
typedef struct maison{
	point centre;
	plan plans[7];
	triangle triangles[2];
}maison;

typedef struct arbre{
	point centre;
	plan plans[6];
	boule feuilles;
}arbre;

//Une plateforme est en fait un paralepipede rectangle donc il a 6 plans
typedef struct plateforme{
	point centre;
	plan plans[6];
}plateforme;

//Un joueur est pareil qu'une plateforme
typedef struct joueur{
	point centre;
	plan plans[6];
}joueur;

typedef struct escalier{
	point basG, hautD;
}escalier;


#endif