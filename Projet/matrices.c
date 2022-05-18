#include "matrices.h"

//  ⚠⚠⚠⚠  PAS ENCORE TESTé, JUSTE IMPLEMENTé  ⚠⚠⚠⚠
// Les return ne marchent peut etre pas car l'initialisation de matrice n'aloue pas encore la mémoire



//Initialise la matrice avec que des zeros et un 1 en bas
matrice initialiserMatriceAvec1(){
  int i,j;
  matrice m;
  for(i = 0; i<TAILLE_MATRICE; i++){
    for(j = 0; j<TAILLE_MATRICE; j++){
      m[i][j] = 0;
    }
  }
  m[3][3] = 1.0;
  return m;
}


//Initialise une matrice avec que des 0
matrice initialiserMatrice(){
  matrice m;
  int i,j;
  for(i = 0; i<TAILLE_MATRICE; i++){
    for(j = 0; j<TAILLE_MATRICE; j++){
      m[i][j] = 0;
    }
  }
  return m;
}


//Transforme uin sommet s en une matrice point et retourne ce point
point initialiserMatriceDeSommetAvec1(sommet s){
  point p;
  p[0] = sommet.x;
  p[1] = sommet.y;
  p[2] = sommet.z;
  p[3] = 1.0;
  return p;
}


//Application d'une multiplication de matrices renvoie une matrice resultat
matrice multiplicationMatrice(matrice m1, matrice m2){
  int i,j,k;
  matrice m3;
  for(i = 0; i < TAILLE_MATRICE ; i++){
    for(j = 0; j <  TAILLE_MATRICE; j++){
      for(k = 0; k < TAILLE_MATRICE ; k++) {
        m3[i][j] += m1[i][k] * m2[k][j];
      }
    }
  }
  return m3;
}


//Application d'une matrice de déplacement R,T,S sur un point p 
point multiplicationMatricePoint(matrice m1, point p2){
  int i,k;
  point p3; 
  for(i = 0; i <TAILLE_MATRICE ; i++){
    for(k = 0; k <TAILLE_MATRICE ; k++) {
      p3[i] += m1[i][k] * p2[k];
    }
  }
  return p3;
}


//Genere la matrice de translation en fonction des x,y,z donnés
matrice genereT(float x,float y, float z){
  matrice m;
  m = initialiserMatriceAvec1();
  m[0][0] = 1;
  m[1][1] = 1;
  m[2][2] = 1;
  m[0][3] = x;
  m[1][3] = y;
  m[2][3] = z;
  return m;
}

//Genere la matrice de mise a l'echelle en fonction de x,y,z 
matrice genereS(float x, float y, float z){
  matrice m;
  m = initialiserMatriceAvec1();
  m[0][0] = x;
  m[1][1] = y;
  m[2][2] = z;
  return m;
}


//Genere la matrice de rotation autour de l'axe y, On considere ici que l'objet tourne autour de l'origine
matrice genereRAutourY(){
	matrice mR;
	matrice m;

	initialiserMatrice(m);
	initialiserMatriceAvec1(mR);

	mR[0][0] = cos(a);
	mR[0][2] = -sin(a);
	mR[2][0] = sin(a);
	mR[2][2] = cos(a);

	return m;
}



//Fonctions d'affichage sur terminal
void afficheMatrice(matrice m){
  int i,j;
  for(i = 0; i <TAILLE_MATRICE ; i++){
    printf("[%f",m[i][0]);
    for(j = 1; j < TAILLE_MATRICE; j++){
      printf(",%f",m[i][j]);
    }
   printf("]\n");
  }
}



void affichePoint(point p){
  int i;
  for(i = 0; i <TAILLE_MATRICE; i++){
    printf("[%f]\n",p[i]);
  }
}