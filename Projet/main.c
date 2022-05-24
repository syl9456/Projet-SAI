#include "setup.h"
#include "init.h"
#include "affichage.h"
#include "collision.h"
#include "matrices.h"
#include "mouvementsFormes.h"


// Listing des elements et de leur nombre sur la scene
#define nbPlateformes 2
#define nbMaisons 4
#define nbArbres 30
#define nbBonus 10
#define nbEtoiles 100
#define nbEscaliers 1
#define nbTabCollisions 250 //+1 pour la base


#define JTAILLE 10

/*
  Tableaux des elements de la scene
*/
plateforme plateformes[nbPlateformes];
maison maisons[nbMaisons];
arbre arbres[nbArbres];
bonus bonuses[nbBonus];
escalier escaliers[nbEscaliers];
bonus etoiles[nbEtoiles];

/* Comtpeur de bonus */

int score = nbBonus;

point tabCollisions[nbTabCollisions][2];
int compteurPourTab = 0;

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
// Un joueur
joueur jou;



int montrerCollision = 0;
float angleBonus = 0;




/************************************************************************/

//                      INITIALISATIONS

/************************************************************************/

void afficheScore(int s){
  printf("\n\n\n+----------------------------------------------+\n");
  if(s > 0){
    printf("| Vous n'avez pas reuni tous les bonus %2d/%2d   |\n",nbBonus-s,nbBonus);
  }
  else{
    printf("| Bravo, vous avez reuni tous les %2d bonus !  |\n",nbBonus);
  }
  printf("+----------------------------------------------+\n");
}

void initialiser_Joueur(){
  jou = init_joueur(centre,2);
}

void  initialiser_Escaliers(){

  /*float tailleP1 = fabs(p1.centre.d[0] - p1.plans[0].point[0].d[0]); 
  float tailleP2 = fabs(p2.centre.d[0] - p2.plans[0].point[0].d[0]); 

  float dist = fabs(p1.centre.d[0] - p2.centre.d[0])-tailleP1-tailleP2;
*/

  escalier e;

  e.basG.d[0] = 0;
  e.basG.d[1] = 0;
  e.basG.d[2] = 300;

  e.hautD.d[0] = 300;
  e.hautD.d[1] = 0.1+100;
  e.hautD.d[2] = 450;

  e.hMarche = 1 + rand()%5;

  escaliers[0] =  e;
}

void  initialiser_Plateformes(){
  point p = centre;
  point plusProche,plusLoin;
  p.d[0] = 150;
  p.d[1] = -HAUTEUR_PLATEFORME+0.1;
  p.d[2] = 150;

  plateformes[0] = init_plateforme(centre, 150);
  plateformes[0] = translation_plateforme(plateformes[0],p);

  plusProche = cherchePlusProchePlateforme(plateformes[0],centre);
  plusLoin = cherchePlusLoinPlateforme(plateformes[0],centre);
  tabCollisions[compteurPourTab][0] = plusProche;
  tabCollisions[compteurPourTab][1] = plusLoin;
  compteurPourTab += 1;


  p.d[0] = 150;
  p.d[1] = -HAUTEUR_PLATEFORME+100+0.1;
  p.d[2] = 600;
  plateformes[1] = init_plateforme(centre, 150);
  plateformes[1] = translation_plateforme(plateformes[1],p);

  plusProche = cherchePlusProchePlateforme(plateformes[1],centre);
  plusLoin = cherchePlusLoinPlateforme(plateformes[1],centre);
  tabCollisions[compteurPourTab][0] = plusProche;
  tabCollisions[compteurPourTab][1] = plusLoin;
  compteurPourTab += 1;
}


void  initialiser_Maisons(){
  float angle = 0;
  point plusProche,plusLoin;
  point p = centre;
  p.d[0] += 100;

  for(int i = 0; i<nbMaisons; i++){
    if(i%2 == 0){
      p.d[2] += 100;
      p.d[0] = centre.d[0]+100;
    }
    maisons[i] = init_maison(centre, 20);
    //Ne marche pas vraiment avec la rotation pour le moment
    //maisons[i] = rotation_maison(maisons[i],'y',angle);
    maisons[i] = translation_maison(maisons[i],p);

    plusProche = cherchePlusProcheMaison(maisons[i],centre);
    plusLoin = cherchePlusLoinMaison(maisons[i],centre);
    tabCollisions[compteurPourTab][0] = plusProche;
    tabCollisions[compteurPourTab][1] = plusLoin;
    compteurPourTab += 1;

    //Pour faire une rotation apres avoir mis la hitBox il faut REfaire une translation a l'origine, rotation et translation a l'endroit ou elle etait (mais on ne va pas faire ca)
    //maisons[i] = translation_maison(maisons[i],centre);
    //maisons[i] = rotation_maison(maisons[i],'y',angle);
    //maisons[i] = translation_maison(maisons[i],p);

    p.d[0] += 100;
    angle += 15;
  }
}

void  initialiser_Arbres(plateforme sol){
  float angle = 0;
  point plusProche,plusLoin;
  int x,y;

  //Chanceux : elle sont forcement carree
  float tailleSol = fabs(sol.centre.d[0] - sol.plans[0].point[0].d[0]);

  int min,max;

  point p = centre;

  for(int i = 0; i<nbArbres; i++){
    min = (sol.centre.d[0] - tailleSol);
    max = (sol.centre.d[0] + tailleSol);
    x = min + rand()%(max-min);
    min = (sol.centre.d[2] - tailleSol);
    max = (sol.centre.d[2] + tailleSol);

    y = min + rand()%(max-min);

    p.d[0] = (float)x;
    p.d[1] = sol.centre.d[1]+5;
    p.d[2] = (float)y;

    arbres[i] = init_arbre(centre, 5);
    arbres[i] = rotation_arbre(arbres[i],'y',angle);
    arbres[i] = translation_arbre(arbres[i],p);

    plusProche = cherchePlusProcheArbre(arbres[i],centre);
    plusLoin = cherchePlusLoinArbre(arbres[i],centre);
    tabCollisions[compteurPourTab][0] = plusProche;
    tabCollisions[compteurPourTab][1] = plusLoin;
    compteurPourTab += 1;

    angle += 15;
  }
}


void initialiser_Bonuses(plateforme sol){

  //Chanceux : elle sont forcement carree
  float tailleSol = fabs(sol.centre.d[0] - sol.plans[0].point[0].d[0]);
  int min,max;

  point p = centre;
  point plusProche,plusLoin;
  int x,y;



  for(int i = 0; i<nbBonus; i++){
    min = (sol.centre.d[0] - tailleSol);
    max = (sol.centre.d[0] + tailleSol);
    x = min + rand()%(max-min);
    min = (sol.centre.d[2] - tailleSol);
    max = (sol.centre.d[2] + tailleSol);

    y = min + rand()%(max-min);

    p.d[0] = (float)x;
    p.d[1] = sol.centre.d[1]+5;
    p.d[2] = (float)y;

    bonuses[i] = init_bonus(centre, 2);
    bonuses[i] = translation_bonus(bonuses[i],p);

    plusProche = cherchePlusProcheBonus(bonuses[i],centre);
    plusLoin = cherchePlusLoinBonus(bonuses[i],centre);
    tabCollisions[compteurPourTab][0] = plusProche;
    tabCollisions[compteurPourTab][1] = plusLoin;
    compteurPourTab += 1;
  }
}


void initialiser_Etoiles(){

  int min,max;

  point p = centre;
  int x,y,z;

  for(int i = 0; i<(nbEtoiles/2); i++){
    min = -1000;
    max = 1000;
    x = min + rand()%(max-min);
    min = -1000;
    max = 1000;
    y = min + rand()%(max-min);
    min = 500;
    max = 1000;
    z = min + rand()%(max-min);

    p.d[0] = (float)x;
    p.d[1] = (float)z;
    p.d[2] = (float)y;

    etoiles[i] = init_bonus(centre, 2);
    etoiles[i] = translation_bonus(etoiles[i],p);
  }
  for(int i = nbEtoiles/2; i<nbEtoiles; i++){
    min = -1000;
    max = 1000;
    x = min + rand()%(max-min);
    min = -1000;
    max = 1000;
    y = min + rand()%(max-min);
    min = -400;
    max = -900;
    z = min + rand()%(max-min);

    p.d[0] = (float)x;
    p.d[1] = (float)z;
    p.d[2] = (float)y;

    etoiles[i] = init_bonus(centre, 2);
    etoiles[i] = translation_bonus(etoiles[i],p);
  }
}


// void initialiser_Spirale(){
//   point p;
//   point plusProche,plusLoin;
//   float angle = 0;
//   float ajoutAngle = 5;
//   float distance = 0;
//   float ajoutDistance = 5;

//   for(int i = 0; i< nbPlateformes; i++){
//     plateformes[i] = init_plateforme(centre, 10);
//     bonuses[i] = init_bonus(centre,2);
//     p.d[0] = cos(angle)* distance;
//     p.d[1] += 10;
//     p.d[2] = sin(angle)*distance;

//     plateformes[i] = rotation_plateforme(plateformes[i],'y',angle);
//     plateformes[i] = translation_plateforme(plateformes[i],p);

//     distance += ajoutDistance;
//     angle += ajoutAngle;
//   }

//   p = initialiserPointDeFloat(800,0,800);

//   for(int i = 0; i< nbPlateformes; i++){

//     plateformes[i] = translation_plateforme(plateformes[i],p);
//     bonuses[i] = translation_bonus(bonuses[i],p);

//     plusProche = cherchePlusProchePlateforme(plateformes[i],centre);
//     plusLoin = cherchePlusLoinPlateforme(plateformes[i],centre);
//     tabCollisions[compteurPourTab][0] = plusProche;
//     tabCollisions[compteurPourTab][1] = plusLoin;
//     compteurPourTab += 1;

//     plusProche = cherchePlusProcheBonus(bonuses[i],centre);
//     plusLoin = cherchePlusLoinBonus(bonuses[i],centre);
//     tabCollisions[compteurPourTab][0] = plusProche;
//     tabCollisions[compteurPourTab][1] = plusLoin;
//     compteurPourTab += 1;
//   }
// }










//Fonction pour initialiser toutes les structures (maisons,plateformes...) dans la fenetre 
//(NB faire des listes de ces structures)
void intialiser_Structures(){
  centre = initialiserPointDeFloat(0,0,0);

  //initialiser_Base(1000);
  //initialiser_Spirale();
  initialiser_Plateformes();
  initialiser_Escaliers();
  initialiser_Arbres(plateformes[1]);
  initialiser_Maisons();
  initialiser_Joueur();
  initialiser_Bonuses(plateformes[1]);
  initialiser_Etoiles(plateformes[1]);
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
    couleur cbonus;
    cbonus.r = 1;
    cbonus.g = 0.42;
    cbonus.b = 0.61;
    trace_Bonus(bonuses[i],cbonus);
  }
} 
void trace_Etoiles(){
  for(int i = 0; i<nbEtoiles; i++){
    couleur cEtoiles;
    cEtoiles.r = 1;
    cEtoiles.g = 1;
    cEtoiles.b = 1;
    trace_Bonus(etoiles[i],cEtoiles);
  }
} 
void trace_Arbres(){
  for(int i = 0; i<(int)(sizeof(arbres)/sizeof(arbre)); i++){
    trace_Arbre(arbres[i]);
  }
}
void trace_Escaliers(){
  //int nbMarche = 5 + rand()%50;
  for(int i = 0; i<nbEscaliers; i++){
    trace_Escalier(escaliers[i]);
  }
}

/************************************************************************/

//                      COLLISIONS TABLEAU OBSTACLE

/************************************************************************/

int colTabCollisions(point posJoueur){
  for(int i = 0; i<nbTabCollisions; i++){
    if(collisions(posJoueur, tabCollisions[i][0], tabCollisions[i][1])){
      return 1;
    }
  }
  return 0;
}


// Collision avec le sol
int colSol(point posJoueur){

  //Iterateur
  int i;

  // Placement aux pieds du joueurs
  // Juste sous la voute plantaire
  for(i=0; i<nbPlateformes; i++){
    if(colPlateforme(plateformes[i],posJoueur)){
      return 1;
    }
  }
  for(i=0; i<nbEscaliers; i++){
    if(colEscalier(escaliers[i],posJoueur)){
      return 1;
    }
  }

  return 0;
}

// Collision avec un des bonus
void colTabBonus(point posJoueur){

  //Iterateur
  int i;

  // Placement aux pieds du joueurs
  // Juste sous la voute plantaire
  for(i=0; i<nbBonus;i++){
    if(colBonus(bonuses[i],posJoueur)){
      bonuses[i] = bonusVide();
      score--;
      if(score <= 0){
        afficheScore(score);
        exit(0);
      }
    }
  }
}


/************************************************************************/

//                    ANIMATIONS OU CALCULS DE CAMERA

/************************************************************************/

//Calcule ici dirEyeOrtho en fonction de UpEye et de DirEye
//Pour cela il faut que Up soit definit et ensuite on fait un produit scalaire et on normalise
void calculeOrtho(){
  orthoDirEye = normalise(produitScalaire(upEye,dirEye));
}


//Ici nous essayons de faire tourner les objets sur eux meme
//On leur attribut donc un vecteur central parrallele a l'axe des y, mais d'origine le centre de l'objet, puis on effectue une rotation autour de ce vecteur
//Ne marche pas encore le vecteur est mauvais 
void animation_bonuses(){
  //point pvec;
  vecteur vec;
  for(int i = 0; i<nbBonus; i++){
    // pvec = bonuses[i].centre;
    // vec = normalise(vecAvec2points(pvec,bonuses[i].centre));
    vec.d[0] = bonuses[i].centre.d[0];
    vec.d[1] = bonuses[i].centre.d[1]+2;
    vec.d[2] = bonuses[i].centre.d[2];

    vec = normalise(vec);
    //affichePoint(bonuses[i].centre);
    // affichePoint(pvec);
    afficheVecteur(vec);
    bonuses[i] = rotation_bonus_vec(bonuses[i],angleBonus,vec);
  }
  angleBonus += 0.0001;
  if(angleBonus >= 360) angleBonus = 0;
}

void animation_Etoiles(){
    for(int i = 0; i<nbEtoiles; i++){
      if(i%3 == 0){
        etoiles[i] = rotation_bonus(etoiles[i],'x',0.0002);
      }
      if(i%3 == 1){
        etoiles[i] = rotation_bonus(etoiles[i],'z',0.0002);
      }
      if(i%3 == 2){
        etoiles[i] = rotation_bonus(etoiles[i],'x',0.0003);
        etoiles[i] = rotation_bonus(etoiles[i],'z',0.0003);
      }
  }
}

/*
void animation_Etoiles(){
  //point pvec;
  vecteur vec;
  for(int i = 0; i<nbEtoiles; i++){
    // pvec = bonuses[i].centre;
    // vec = normalise(vecAvec2points(pvec,bonuses[i].centre));
    vec.d[0] = etoiles[i].centre.d[0];
    vec.d[1] = etoiles[i].centre.d[1]+2;
    vec.d[2] = etoiles[i].centre.d[2];

    vec = normalise(vec);
    //affichePoint(bonuses[i].centre);
    // affichePoint(pvec);
    afficheVecteur(vec);
    etoiles[i] = rotation_bonus_vec(etoiles[i],angleBonus,vec);
  }
  angleEtoiles += 0.0001;
  if(angleEtoiles>= 360) angleBonus = 0;
}
*/


//Fonction pour raffraichir la fenetre (encore rien fait de plus que le tp)
void animer(){
  animation_bonuses();
  animation_Etoiles();
  calculeOrtho();

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


  if(colTabCollisions(initialiserPointDeFloat(x,y,z))==0 &&
    colSol(initialiserPointDeFloat(x,y,z)) == 1){
    posEye.d[0] = x;
    posEye.d[1] = y;
    posEye.d[2] = z;
  }

  if(colEscalier(escaliers[0],posEye) == 1){
    posEye.d[1] = etatHauteur(escaliers[0], posEye) ;//+ JTAILLE;
    posEye.d[1] += 10;
  }

  colTabBonus(posEye);


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
  
  trace_Plateformes();
  trace_Escaliers();
  trace_Origine();
  trace_Maisons();
  trace_Bonuses();
  trace_Arbres();
  trace_Joueur(jou);
  trace_Etoiles();


  if(montrerCollision){
    for(int i = 0; i<nbTabCollisions; i++){
      trace_Collision(tabCollisions[i][0], tabCollisions[i][1]);
    }
  }


  glutSwapBuffers();
}





/************************************************************************/

//                      CLAVIER

/************************************************************************/


//Fonction pour gérer les touches du clavier, si la touche est appuyée les multiplicateurs de la direction (avan/cotes) sont mis a 0.5
void gererClavier(unsigned char touche, int x, int y){
  switch(touche){
    case 27: //Touche echap
    afficheScore(score);
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
    case 'c':
      if(montrerCollision) montrerCollision = 0;
      else montrerCollision = 1;
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

  srand(getpid());

  posEye = initialiserPointDeFloat(10,10,10);
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