#include "setup.h"
#include "init.h"
#include "affichage.h"
#include "matrices.h"

//Variables pour l'animations et le Frustrum()/gluLookAt()
float angleXZ = 0;
float angleY = 0;

//Position de l'observateur
point posEye;

//Direction vers laquelle l'observateur regarde
point dirEye;

//Direction Orthogonale a celle vers laquelle l'observateur regarde
point orthoDirEye;

// Les états des touches. Initialisé a zéro quand aucune touche n'est pressée
float deltaAngleXZ = 0;
float deltaAngleY = 0;
float avant = 0;
float cotes = 0;

// Une variable pour stocker la position X et Y où la souris est cliquée.
int xSouris = -1;
int ySouris = -1;



//Sommet de centre de fenetre (0,0,0)
sommet centre;
//Une maison
maison mais;
// Une plateforme
plateforme plate;


//plateforme plateformes[]
//maison maisons[]








/************************************************************************/

//                      AFFICHAGE

/************************************************************************/

//Calcule ici le k tel que un vecteur orthogonal a la direction sera (k,nk,mk) ou l'on enregistre n et m
void calculeOrtho(){
}




//Fonction pour raffraichir la fenetre (encore rien fait de plus que le tp)
void animer(){
  calculeOrtho();
  posEye.d[0] += avant * dirEye.d[0] * 0.3; //On change le x de la position du personnage 
  posEye.d[2] += avant * dirEye.d[2] * 0.3; //On change le y de la position du personnage


  glutPostRedisplay();
}

//Fonction pour initialiser toutes les structures (maisons,plateformes...) dans la fenetre 
//(NB faire des listes de ces structures)
void intialiser_Structures(){
  centre.x = 150;
  centre.y = 100;
  centre.z = 0;

  mais = init_Maison(centre, TAILLE_STRUC);
  centre.y = 0 - HAUTEUR_PLATEFORME;
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
    0,
    1,
    0);

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
      avant = 0.5;
      break;
    case 's':
      avant = -0.5;
      break;
    case 'd':
      cotes = 0.5;
      break;
    case 'q':
      cotes = -0.5;
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
void mouvementSouris(int x, int y) {

  // Si le bouton gauche est enfoncé.
  if (xSouris >= 0) {

    // Update deltaAngle
    deltaAngleXZ = (x - xSouris) * 0.00001;
    deltaAngleY = (y - ySouris) * 0.00001;

    // Update la Direction de la Caméra Gauche Droite
    dirEye = multiplicationMatricePoint(genereRAutourY(-deltaAngleXZ), dirEye);
    dirEye = multiplicationMatricePoint(genereRAutourZ(deltaAngleY), dirEye);
    dirEye = multiplicationMatricePoint(genereRAutourX(deltaAngleY), dirEye);
  }
}

void bouttonSouris(int button, int state, int x, int y) {

  // démarrer UN mouvement uniquement si le bouton gauche de la souris est pressé
  if (button == GLUT_LEFT_BUTTON) {

    // Lorsque le bouton est relâché
    if (state == GLUT_UP) {
      angleXZ += deltaAngleXZ;
      angleY += deltaAngleY;
      xSouris = -1;
      ySouris = -1;
    }
    else  {// Etat  = GLUT_DOWN
      xSouris = x;
      ySouris = y;
    }
  }
}







/************************************************************************/

/************************************************************************/

int main(int argc, char *argv[]){
  /********** Init de Glut ********/


  posEye = initialiserMatriceDeFloatAvec1(0,0,0);
  dirEye = initialiserMatriceDeFloatAvec1(1,0,0);
  orthoDirEye = initialiserMatriceDeFloatAvec1(0,0,1);

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
  glutMouseFunc(bouttonSouris);
  glutMotionFunc(mouvementSouris);


  glutMainLoop();

  exit(0);

}