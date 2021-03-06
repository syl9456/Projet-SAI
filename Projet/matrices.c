#include "matrices.h"

//  ⚠⚠⚠⚠  PAS ENCORE TESTé, JUSTE IMPLEMENTé  ⚠⚠⚠⚠
// Les return ne marchent peut etre pas car l'initialisation de matrice n'aloue pas encore la mémoire



//Initialise la matrice avec que des zeros et un 1 en bas
matrice initialiserMatrice(){
  int i,j;
  matrice m;
  for(i = 0; i<TAILLE_MATRICE; i++){
    for(j = 0; j<TAILLE_MATRICE; j++){
      m.d[i][j] = 0;
    }
  }
  m.d[3][3] = 1.0;
  return m;
}



matrice initialiserMatriceDeFloat(float a,float b, float c,float d,float e, float f,float g,float h, float i){
  matrice m;
  m = initialiserMatrice();
  m.d[0][0] = a;
  m.d[0][1] = b;
  m.d[0][2] = c;
  m.d[1][0] = d;
  m.d[1][1] = e;
  m.d[1][2] = f;
  m.d[2][0] = g; 
  m.d[2][1] = h;
  m.d[2][2] = i;
  return m;
}


//Transforme trois coordonnées en une matrice point et retourne ce point
point initialiserPointDeFloat(float x, float y, float z){
  point p;
  p.d[0] = x;
  p.d[1] = y;
  p.d[2] = z;
  p.d[3] = 1.0;
  return p;
}


vecteur initialiserVecteurDeFloat(float x, float y, float z){
  vecteur v;
  v.d[0] = x;
  v.d[1] = y;
  v.d[2] = z;
  v.d[3] = 1.0;
  return v;
}


//Application d'une multiplication de matrices renvoie une matrice resultat
matrice multiplicationMatrice(matrice m1, matrice m2){
  int i,j,k;
  matrice m3;
  for(i = 0; i < TAILLE_MATRICE ; i++){
    for(j = 0; j <  TAILLE_MATRICE; j++){
      m3.d[i][j] = 0;
      for(k = 0; k < TAILLE_MATRICE ; k++) {
        m3.d[i][j] += m1.d[i][k] * m2.d[k][j];
      }
    }
  }
  return m3;
}


//Application d'une mutiplication de matrice de déplacement (R,T,S..) et d'un point p 
point multiplicationMatricePoint(matrice m1, point p2){
   int i,j;
   point p3;
   for(i = 0; i <TAILLE_MATRICE ; i++){
    p3.d[i] = 0;
     for(j = 0; j <TAILLE_MATRICE ; j++) {
       p3.d[i] += m1.d[i][j] * p2.d[j];
     }
  }
  return p3;
}

//Application d'une mutiplication de matrice de déplacement (R,T,S..) et d'un vecteur p 
vecteur multiplicationMatriceVecteur(matrice m1, vecteur p2){
   int i,j;
   vecteur p3;
   for(i = 0; i <TAILLE_MATRICE ; i++){
    p3.d[i] = 0;
     for(j = 0; j <TAILLE_MATRICE ; j++) {
       p3.d[i] += m1.d[i][j] * p2.d[j];
     }
  }
  return p3;
}


//Genere la matrice de translation en fonction des x,y,z donnés
matrice genereT(float x,float y, float z){
  matrice m;
  m = initialiserMatrice();
  m.d[0][0] = 1;
  m.d[1][1] = 1;
  m.d[2][2] = 1;
  m.d[0][3] = x;
  m.d[1][3] = y;
  m.d[2][3] = z;
  return m;
}

//Genere la matrice de mise a l'echelle en fonction de x,y,z 
matrice genereS(float x, float y, float z){
  matrice m;
  m = initialiserMatrice();
  m.d[0][0] = x;
  m.d[1][1] = y;
  m.d[2][2] = z;
  return m;
}


//Genere la matrice de rotation autour de l'axe y, On considere ici que l'objet tourne autour de l'origine
matrice genereRAutourX(float angle){
	matrice mR;
	mR = initialiserMatrice();

	mR.d[1][1] = cos(angle);
	mR.d[1][2] = -sin(angle);
	mR.d[2][1] = sin(angle);
	mR.d[2][2] = cos(angle);

  mR.d[0][0] = 1.0;

	return mR;
}


matrice genereRAutourY(float angle){
	matrice mR;
	mR = initialiserMatrice();

	mR.d[0][0] = cos(angle);
	mR.d[0][2] = sin(angle);
	mR.d[2][0] = -sin(angle);
	mR.d[2][2] = cos(angle);

  mR.d[1][1] = 1.0;

	return mR;
}


matrice genereRAutourZ(float angle){
	matrice mR;
	mR = initialiserMatrice();

	mR.d[0][0] = cos(angle);
	mR.d[0][1] = -sin(angle);
	mR.d[1][0] = sin(angle);
	mR.d[1][1] = cos(angle);

  mR.d[2][2] = 1.0;

	return mR;
}


matrice genereRAutourVec(float angle, vecteur vec){
  matrice mR;
  mR = initialiserMatriceDeFloat( ((vec.d[0]*vec.d[0])*(1-cos(angle))) +cos(angle) , ((vec.d[0]*vec.d[1])*(1-cos(angle))) -vec.d[2]*sin(angle) , ((vec.d[0]*vec.d[2])*(1-cos(angle))) +vec.d[1]*sin(angle),

                                  ((vec.d[0]*vec.d[1])*(1-cos(angle))) +vec.d[2]*sin(angle) , ((vec.d[1]*vec.d[1])*(1-cos(angle))) +cos(angle) , ((vec.d[1]*vec.d[2])*(1-cos(angle))) -vec.d[0]*sin(angle),

                                  ((vec.d[0]*vec.d[2])*(1-cos(angle))) -vec.d[1]*sin(angle) , ((vec.d[1]*vec.d[2])*(1-cos(angle))) +vec.d[0]*sin(angle) , ((vec.d[2]*vec.d[2])*(1-cos(angle))) +cos(angle)
                                  );
  return mR;
}




vecteur vecAvec2points(point p1, point p2){
  vecteur v = initialiserVecteurDeFloat(p1.d[0],p1.d[1]-p2.d[1],p1.d[2]);
  return v;
}


vecteur produitScalaire(vecteur p1, vecteur p2){
  vecteur p;
  p = initialiserVecteurDeFloat(0,0,0);
  p.d[0] = (p1.d[1]*p2.d[2]) - (p1.d[2]*p2.d[1]);
  p.d[1] = (p1.d[2]*p2.d[0]) - (p1.d[0]*p2.d[2]);
  p.d[2] = (p1.d[0]*p2.d[1]) - (p1.d[1]*p2.d[0]);

  return p;
}


vecteur normalise(vecteur p){
  float w = sqrt(p.d[0]* p.d[0] + p.d[1]* p.d[1] + p.d[2]* p.d[2]);

  p.d[0] /= w;
  p.d[1] /= w;
  p.d[2] /= w;

  return p;
}


vecteur addition(vecteur p1, vecteur p2){
  vecteur p; 
  p = initialiserVecteurDeFloat(0,0,0);

  p.d[0] = p1.d[0] + p2.d[0]; 
  p.d[1] = p1.d[1] + p2.d[1];
  p.d[2] = p1.d[2] + p2.d[2];

  return p;
}


vecteur soustraction(vecteur p1, vecteur p2){
  vecteur p; 
  p = initialiserVecteurDeFloat(0,0,0);

  p.d[0] = p1.d[0] - p2.d[0];
  p.d[1] = p1.d[1] - p2.d[1];
  p.d[2] = p1.d[2] - p2.d[2];

  return p;
}


float distance(point p1, point p2){
  float distance;
  distance = sqrt(((p2.d[0] - p1.d[0])*(p2.d[0] - p1.d[0])) + ((p2.d[1] - p1.d[1])*(p2.d[1] - p1.d[1])) + ((p2.d[2] - p1.d[2])*(p2.d[2] - p1.d[2])));
  return distance;
}



//Fonctions d'affichage sur terminal
void afficheMatrice(matrice m){
  int i,j;
  for(i = 0; i <TAILLE_MATRICE ; i++){
    printf("[%f",m.d[i][0]);
    for(j = 1; j < TAILLE_MATRICE; j++){
      printf(",%f",m.d[i][j]);
    }
   printf("]\n");
  }
  printf("\n");
}



void affichePoint(point p){
  int i;
  for(i = 0; i <TAILLE_MATRICE; i++){
    printf("[%f]\n",p.d[i]);
  }
  printf("\n");
}



void afficheVecteur(vecteur p){
  int i;
  for(i = 0; i <TAILLE_MATRICE; i++){
    printf("[%f]\n",p.d[i]);
  }
  printf("\n");
}
