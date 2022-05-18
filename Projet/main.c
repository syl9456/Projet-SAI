#include "setup.h"
#include "init.h"
#include "affichage.h"
#include "mouvementsFormes.h"

/*
//Variables pour l'animations et le Frustrum()/gluLookAt()
float angle = 0;
float rayon = 50;
float eyex,eyey=10,eyez;
*/


// Position de la vue du joueur
double vueX;
double vueY;
double vueZ; 

// Position du jour
double posX = 0;
double posY = 0;
double posZ = 0;


//Sommet de centre de fenetre (0,0,0)
sommet centre;
//Une maison
maison mais;
// Une plateforme
plateforme plate;


//plateforme plateformes[]
//maison maisons[]



//Fonction pour raffraichir la fenetre (encore rien fait de plus que le tp)
void animer(){
  /*if (droite) angle += 0.005;
  else angle -= 0.005;
  
  if(angle > 360) angle = 0;
  if(angle < 0) angle = 360;
  */
  vueX = 10;//rayon * cos(angle);
  vueZ = 10;//rayon * sin(angle);

  glutPostRedisplay();
}

//Fonction pour gérer les touches du clavier (encore rien fait de plus que le tp)
void gererClavier(unsigned char touche, int x, int y){
  if(touche == 'z'){
    vueY += 1;
  }
  if(touche == 'q'){
    posZ += 1;
  }
  if(touche == 's'){
    posX -= 1;
  }
  if(touche == 'd'){
    posZ += 1;
  }

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
  gluLookAt(vueX,vueY,vueZ,posX,posY,posZ,0,1,0);

  trace_Origine();
  trace_Maison(mais);
  trace_Plateforme(plate);


  glutSwapBuffers();
}



int main(int argc, char *argv[]){
  /********** Init de Glut *********/

  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

  glutInitWindowSize(FENX,FENY);
  glutInitWindowPosition(50,50);

  glutCreateWindow("Jeu du futur");
  glEnable(GL_DEPTH_TEST);


  intialiser_Structures();


  glutDisplayFunc(affichage);
  glutKeyboardFunc(gererClavier);
  glutIdleFunc(animer);

  glutMainLoop();

  exit(0);

}