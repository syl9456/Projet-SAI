#include "setup.h"
#include "init.h"
#include "affichage.h"
#include "collision.h"
#include "matrices.h"
#include "mouvementsFormes.h"


// Listing des elements et de leur nombre sur la scene

#define nbPlateformes 30
#define nbMaisons 20 
#define nbArbres 20 
#define nbBonus 20 

/*
  Tableaux des elements de la scene
*/
plateforme plateformes[nbPlateformes];
maison maisons[nbMaisons];
arbre arbres[nbArbres];
bonus bonuses[nbBonus];

//Variables de vitesse de camera
float vitesseCamera = 1;

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
plateforme base;
// Un joueur
joueur jou;





float angleBonus = 0;




/************************************************************************/

//                      INITIALISATIONS

/************************************************************************/


void initialiser_Base(){
  point p = centre;
  p.d[1] -= HAUTEUR_PLATEFORME+1;
  base = init_plateforme(p, 200);
}


void  initialiser_plateformes(){
  point p = centre;
  p.d[2] -= 50;
  for(int i = 0; i<nbPlateformes; i++){
    plateformes[i] = init_plateforme(centre, 10);
    plateformes[i] = translation_plateforme(plateformes[i],p);
    p.d[2] -= 0;
  }
}


void  initialiser_Maisons(){
  float angle = 0;

  point p = centre;
  p.d[0] -= 100;
  for(int i = 0; i<nbMaisons; i++){
    if(i%5 == 0){
      p.d[2] -= 100;
      p.d[0] = centre.d[0]-100; 
    }
    maisons[i] = init_maison(centre, 20);
    maisons[i] = rotation_maison(maisons[i],'y',angle);
    maisons[i] = translation_maison(maisons[i],p);
    p.d[0] -= 100;
    angle += 15;
  }
}

void  initialiser_Arbres(){
  float angle = 0;
  int x,y;

  srand(getpid());
  point p = centre;
  for(int i = 0; i<nbArbres; i++){
    x = rand()%1001;
    y = rand()%1001;

    p.d[0] = (float)x;
    p.d[2] = (float)y;

    arbres[i] = init_arbre(centre, 5);
    arbres[i] = rotation_arbre(arbres[i],'y',angle);
    arbres[i] = translation_arbre(arbres[i],p);
    angle += 15;
  }


}

void  initialiser_bonuses(){
  point p = centre;
  p.d[0] -= 50;
  for(int i = 0; i<nbBonus; i++){
    bonuses[i] = init_bonus(centre, 3);
    bonuses[i] = translation_bonus(bonuses[i],p);
    p.d[0] -= 50;
  }

}



void initialiser_Spirale(){
  point p;
  float angle = 0;
  float ajoutAngle = 5;
  float distance = 0;
  float ajoutDistance = 5;

  for(int i = 0; i< nbPlateformes; i++){
    plateformes[i] = init_plateforme(centre, 10);
    bonuses[i] = init_bonus(centre,2);


    p.d[0] = cos(angle)* distance;
    p.d[1] += 10;
    p.d[2] = sin(angle)*distance;

    plateformes[i] = rotation_plateforme(plateformes[i],'y',angle);
    plateformes[i] = translation_plateforme(plateformes[i],p);
    bonuses[i] = translation_bonus(bonuses[i],p);

    distance += ajoutDistance;
    angle += ajoutAngle;
  }
}










//Fonction pour initialiser toutes les structures (maisons,plateformes...) dans la fenetre 
//(NB faire des listes de ces structures)
void intialiser_Structures(){
  centre = initialiserPointDeFloat(0,0,0);

  initialiser_Spirale();
  initialiser_Arbres();
  initialiser_Base();
  initialiser_Maisons();
}



/************************************************************************/

//                      AFFICHAGE

/************************************************************************/




void trace_Maisons(){
  for(int i = 0; i<(int)(sizeof(maisons)/sizeof(maison)); i++){
    trace_Maison(maisons[i]);
  }
}
void trace_Plateformes(){
  for(int i = 0; i<(int)(sizeof(plateformes)/sizeof(plateforme)); i++){
    trace_Plateforme(plateformes[i]);
  }
}

void trace_Bonuses(){
  for(int i = 0; i<(int)(sizeof(bonuses)/sizeof(bonus)); i++){
    trace_Bonus(bonuses[i]);
  }
} 
void trace_Arbres(){
  for(int i = 0; i<(int)(sizeof(arbres)/sizeof(arbre)); i++){
    trace_Arbre(arbres[i]);
  }
}

/************************************************************************/

//                      COLLISIONS TABLEAU OBSTACLE

/************************************************************************/

int colTabMaisons(point posJoueur){
  for(int i = 0; i<nbMaisons; i++){
    if(colMaison(posJoueur, maisons[i])){
      return 1;
    }
  }
  return 0;
}

//Calcule ici dirEyeOrtho en fonction de UpEye et de DirEye
//Pour cela il faut que Up soit definit et ensuite on fait un produit scalaire et on normalise
void calculeOrtho(){
  orthoDirEye = normalise(produitScalaire(upEye,dirEye));
}

void animation_bonuses(){
  point pvec;
  vecteur vec;
  for(int i = 0; i<nbBonus; i++){
    pvec = bonuses[i].centre;
    pvec.d[1] +=  1;
    vec = vecAvec2points(bonuses[i].centre,pvec);
    bonuses[i] = rotation_bonus_vec(bonuses[i],angleBonus,vec);
  }
  angleBonus += 0.0001;
}




//Fonction pour raffraichir la fenetre (encore rien fait de plus que le tp)
void animer(){
  animation_bonuses();
  calculeOrtho();
  //calculeCollision();

  float x,y,z;

  x = posEye.d[0];
  y = posEye.d[1];
  z = posEye.d[2];

  if(avant){
    x += avant * vitesseCamera * dirEye.d[0];
    //y += avant * vitesseCamera * dirEye.d[1];
    z += avant * vitesseCamera * dirEye.d[2];
  }
  if(cotes){
    x += cotes * vitesseCamera *  orthoDirEye.d[0];
    //y += cotes * vitesseCamera *  orthoDirEye.d[1];
    z += cotes * vitesseCamera *  orthoDirEye.d[2];
  }

  if(colTabMaisons(initialiserPointDeFloat(x,y,z))==0){
    posEye.d[0] = x;
    posEye.d[1] = y;
    posEye.d[2] = z;
  }

  if(avant || cotes){
    jou = translation_joueur(jou,posEye);
  }

  glutPostRedisplay();
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
  trace_Maisons();
  trace_Plateformes();
  trace_Bonuses();
  trace_Arbres();
  trace_Plateforme(base);
  trace_Joueur(jou);


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


  posEye = initialiserPointDeFloat(-50,10,0);
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