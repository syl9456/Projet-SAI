#include "setup.h"
#include "init.h"
#include "affichage.h"
#include "matrices.h"


//Variables de vitesse de camera
float vitesseCamera = 0.3;

float sensitivite = 0.005;


//(point ici est un vecteur4)
//Position de l'observateur (endroit) (-50,10,0)
point posEye;
//Direction vers laquelle l'observateur regarde (vecteur) (1,0,0)  pour pouvoir marcher droit ou reculer
vecteur dirEye;
//Direction Orthogonale a celle vers laquelle l'observateur regarde (vecteur) (0,0,1)  pour pouvoir marcher sur les cotes
vecteur orthoDirEye;
//Direction vers le haut pour la tete (vecteur) (0,1,0)
vecteur upEye;


float avant = 0;
float cotes = 0;

// Une variable pour stocker la position X et Y où la souris est cliquée.
float dernierX = FENX / 2;
float dernierY = FENY / 2;

//Garde en mémoire la position du curseur sur l'écran
float xSouris=0,ySouris=0;
//Angles d'euler : compliqué : 
//nous avons deux angles car l'angle de tantage ne nous interesse pas ici
//angle de roulis est un mouvement de rotation autour de l'axe de roulis ici autour de z
//angle de lacet est un mouvement de rotation autour de l'axe de lacet ici autour de y
//ref : https://learnopengl.com/Getting-started/Camera    dans LookAround
float angleRoulis=0,angleLacet=0;



//Sommet de centre de fenetre (0,0,0)
point centre;
//Une maison
maison mais;
// Une plateforme
plateforme plate;


//plateforme plateformes[]
//maison maisons[]








/************************************************************************/

//                      AFFICHAGE

/************************************************************************/

//Calcule ici dirEyeOrtho en fonction de UpEye et de DirEye
//Pour cela il faut que Up soit definit et ensuite on fait un produit scalaire et on normalise
void calculeOrtho(){
  orthoDirEye = normalise(produitScalaire(upEye,dirEye));
}




//Fonction pour raffraichir la fenetre (encore rien fait de plus que le tp)
void animer(){
  calculeOrtho();

  if(avant){
    posEye.d[0] += avant * vitesseCamera * dirEye.d[0];
    posEye.d[1] += avant * vitesseCamera * dirEye.d[1];
    posEye.d[2] += avant * vitesseCamera * dirEye.d[2];
  }
  if(cotes){
    posEye.d[0] += cotes * vitesseCamera *  orthoDirEye.d[0];
    posEye.d[1] += cotes * vitesseCamera *  orthoDirEye.d[1];
    posEye.d[2] += cotes * vitesseCamera *  orthoDirEye.d[2];
  }


  glutPostRedisplay();
}



//Fonction pour initialiser toutes les structures (maisons,plateformes...) dans la fenetre 
//(NB faire des listes de ces structures)
void intialiser_Structures(){
  centre = initialiserPointDeFloat(0,0,0);

  mais = init_Maison(centre, TAILLE_STRUC);
  centre.d[1] = 0 - HAUTEUR_PLATEFORME; //On baisse le y pour que la plateforme soit plus bas
  plate = init_Plateforme(centre, 70);
}


//Fonction principale d'affichage, Ici on apelle que des focntions de tracage je pense
void affichage(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();


  glFrustum(-1,1,-1,1,1,50000);

  gluLookAt(posEye.d[0],
            posEye.d[1],
            posEye.d[2],
            posEye.d[0] + dirEye.d[0],
            posEye.d[1] + dirEye.d[1],
            posEye.d[2] + dirEye.d[2],
            upEye.d[0],
            upEye.d[1],
            upEye.d[2]);

  trace_Origine();
  trace_Maison(mais);
  trace_Plateforme(plate);


  glutSwapBuffers();
}








/************************************************************************/

//                      CLAVIER

/************************************************************************/


//Fonction pour gérer les touches du clavier, si la touche est appuyée les multiplicateurs de la direction (avan/cotes) sont mis a 0.5
void gererClavier(unsigned char touche, int x, int y){
  switch(touche){
    case 27: //Touche echap
      exit(0);
      break;
    case 'z':
      avant = 1;
      break;
    case 's':
      avant = -1;
      break;
    case 'd':
      cotes = -1;
      break;
    case 'q':
      cotes = 1;
      break;
  }
}

//Si une des touches du clavier est relevée on met le multiplicateur de la direction (avant/cotes) a 0
void gererUpClavier(unsigned char touche, int x, int y){
  switch(touche){
    case 'z': 
    case 's' : 
      avant = 0;
      break;
    case 'd':
    case 'q':
      cotes = 0;
      break;
  }
}







/************************************************************************/

//                      SOURIS

/************************************************************************/
void mouvementSouris(int xPos, int yPos) {

  if(xPos >= FENX-5){
    glutWarpPointer(10,yPos);
  }
  else if(xPos <= 5){
    glutWarpPointer(FENX-10,yPos);
  }

  if(yPos >= FENY-5){
    glutWarpPointer(xPos,10);
  }
  else if(yPos <= 5){
    glutWarpPointer(xPos,FENY-10);
  }

  xSouris = (float)xPos - dernierX;
  ySouris = dernierY - (float)yPos;

  dernierX = (float)xPos;
  dernierY = (float)yPos;

  xSouris *= sensitivite;
  ySouris *= sensitivite;

  angleRoulis += xSouris;
  angleLacet += ySouris;


  if(angleLacet > 89.0)
    angleLacet = 89.0;
  if(angleLacet < -89.0)
    angleLacet = -89.0;


  vecteur direction;

  direction.d[0] = cos(angleRoulis) * cos(angleLacet);
  direction.d[1] = sin(angleLacet);
  direction.d[2] = sin(angleRoulis) * cos(angleLacet);

  dirEye = normalise(direction);
}

// void bouttonSouris(int button, int state, int x, int y) {

// }







/************************************************************************/

/************************************************************************/

int main(int argc, char *argv[]){
  /********** Init de Glut ********/


  posEye = initialiserPointDeFloat(-50,HAUTEUR_JOUEUR,0);
  dirEye = initialiserVecteurDeFloat(1,0,0);
  orthoDirEye = initialiserVecteurDeFloat(0,0,0);
  upEye = initialiserVecteurDeFloat(0,1,0);


  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(FENX,FENY);
  glutInitWindowPosition(50,50);
  glutCreateWindow("Jeu du futur");
  glEnable(GL_DEPTH_TEST);
  intialiser_Structures();

  //Geestion affichage et réaffichage
  glutDisplayFunc(affichage);
  glutIdleFunc(animer);

  //Gestion du clavier
  glutKeyboardFunc(gererClavier);
  glutKeyboardUpFunc(gererUpClavier);

  // Gestion de la souris
  //glutMouseFunc(bouttonSouris);
  glutPassiveMotionFunc(mouvementSouris);

  glutMainLoop();

  exit(0);
}