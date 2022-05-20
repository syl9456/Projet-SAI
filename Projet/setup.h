#ifndef _Setup_h
#define _Setup_h

// FICHIER DE SETUP POUR LA BASE
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "GL/gl.h"
#include "GL/glut.h"
#include "time.h"

#include <math.h>


#define FENX 1200
#define FENY 1000

#define HAUTEUR_PLATEFORME 10
#define HAUTEUR_MAISON 20
#define TAILLE_STRUC 20

#define PI 3.141592 


typedef struct couleur{
	float r,g,b;
}couleur;

typedef struct sommet{
	float x,y,z;
}sommet;

typedef struct plan{
	sommet s1,s2,s3,s4;
}plan;

typedef struct triangle{
	sommet s1,s2,s3;
}triangle;

typedef struct maison{
	sommet centre;
	plan plans[7];
	triangle triangles[2];
}maison;

typedef struct plateforme{
	sommet centre;
	plan plans[6];
}plateforme;


#endif