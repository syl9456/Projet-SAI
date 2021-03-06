#include "affichage.h"


//Trace un plan sur la fenetre
void trace_Plan(plan pl, couleur c){
	glBegin(GL_QUADS);
	glColor3f(c.r, c.g, c.b);
	glVertex3f(pl.point[0].d[0], pl.point[0].d[1], pl.point[0].d[2]);
	glVertex3f(pl.point[1].d[0], pl.point[1].d[1], pl.point[1].d[2]);
	glVertex3f(pl.point[2].d[0], pl.point[2].d[1], pl.point[2].d[2]);
	glVertex3f(pl.point[3].d[0], pl.point[3].d[1], pl.point[3].d[2]);
	glEnd();
}



//Trace un triangle sur la fenetre
void trace_Triangle(triangle t, couleur c){
	glBegin(GL_TRIANGLES);
	glColor3f(c.r, c.g, c.b);
	glVertex3f(t.point[0].d[0], t.point[0].d[1], t.point[0].d[2]);
	glVertex3f(t.point[1].d[0], t.point[1].d[1], t.point[1].d[2]);
	glVertex3f(t.point[2].d[0], t.point[2].d[1], t.point[2].d[2]);
	glEnd();
}


void trace_Boule(boule bou, couleur c){
	glColor3f(c.r, c.g, c.b);
	glTranslatef(bou.centre.d[0],bou.centre.d[1],bou.centre.d[2]);
  glutSolidSphere(bou.rayon,20,20);
  glTranslatef(-bou.centre.d[0],-bou.centre.d[1],-bou.centre.d[2]);
}


void traceCube(int x1, int y1, int z1, int x2, int y2, int z2){
  glBegin(GL_QUADS);
  glColor3f(1,1,1);
  //face bas
  glVertex3f(x1,y1,z2);
  glVertex3f(x2,y1,z2);
  glVertex3f(x2,y2,z1);
  glVertex3f(x1,y1,z1);

  glColor3f(0.9,0.9,0.9);
  //face dessus
  glVertex3f(x1,y2,z2);
  glVertex3f(x2,y2,z2);
  glVertex3f(x2,y2,z1);
  glVertex3f(x1,y2,z1);

  //cotés
  glColor3f(0.8,0.8,0.8);
  //1
  glVertex3f(x1,y2,z2);
  glVertex3f(x2,y2,z2);
  glVertex3f(x2,y1,z2);
  glVertex3f(x1,y1,z2);

  glColor3f(0.7,0.7,0.7);
  //2
  glVertex3f(x2,y1,z2);
  glVertex3f(x2,y2,z2);
  glVertex3f(x2,y2,z1);
  glVertex3f(x2,y1,z1);

  glColor3f(0.6,0.6,0.6);
  //3
  glVertex3f(x1,y1,z1);
  glVertex3f(x2,y1,z1);
  glVertex3f(x2,y2,z1);
  glVertex3f(x1,y2,z1);
  
  glColor3f(0.5,0.5,0.5);
  //3
  glVertex3f(x1,y2,z2);
  glVertex3f(x1,y1,z2);
  glVertex3f(x1,y1,z1);
  glVertex3f(x1,y2,z1);


  glEnd();
}



//Trace la plateforme sur la fenetre
void trace_Plateforme(plateforme plat){
	int i;
	couleur c;
	c.r = 0.43;
	c.g = 0.3;
	c.b = 0.3;

	for(i = 0; i<(int)(sizeof(plat.plans)/sizeof(plat.plans[0]))-1; i++){
		//On change la couleur a chaques itérations
		c.r -= 0.03;
		c.g -= 0.03;
		c.b -= 0.03;
		trace_Plan(plat.plans[i], c);
	}

	c.r = 0.05;
	c.g = 0.45;
	c.b = 0.05;
	trace_Plan(plat.plans[i], c);
}

//Trace la plateforme sur la fenetre
void trace_Joueur(joueur jou){
	int i;
	couleur c;
	c.r = 1;
	c.g = 1;
	c.b = 1;

	for(i = 0; i<(int)(sizeof(jou.plans)/sizeof(jou.plans[0])); i++){
		//On change la couleur a chaques itérations
		c.r -= 0.08;
		c.g -= 0.08;
		c.b -= 0.08;
		trace_Plan(jou.plans[i], c);
	}
}

void trace_Bonus(bonus bon, couleur c){
	int i;
	/*couleur c;
	c.r = 1;
	c.g = 0.42;
	c.b = 0.61;
	*/

	for(i = 0; i<(int)(sizeof(bon.plans)/sizeof(bon.plans[0])); i++){
		//On change la couleur a chaques itérations
		c.r -= 0.03;
		c.g -= 0.03;
		c.b -= 0.03;
		trace_Plan(bon.plans[i], c);
	}
}


void trace_Arbre(arbre ab){
	int i;
	couleur c;
	c.r = 0.43;
	c.g = 0.3;
	c.b = 0.3;

	for(i = 0; i<(int)(sizeof(ab.plans)/sizeof(ab.plans[0])); i++){
		//On change la couleur a chaques itérations
		c.r -= 0.03;
		c.g -= 0.03;
		c.b -= 0.03;
		trace_Plan(ab.plans[i], c);
	}

	c.r = 0;
	c.g = 0.5;
	c.b = 0;
	trace_Boule(ab.feuilles, c);
}



//Trace la maison sur la fenetre
void trace_Maison(maison mais){
	int i;
	couleur c;
	c.r = 1;
	c.g = 1;
	c.b = 1;
	//On change la couleur a chaques itérations
	for(i = 0; i<(int)(sizeof(mais.plans)/sizeof(mais.plans[0])); i++){
		c.r -= 0.08;
		c.g -= 0.08;
		c.b -= 0.08;
		trace_Plan(mais.plans[i], c);
	}

	c.r = 1;
	c.g = 0;
	c.b = 0;
	//On change la couleur a chaques itérations
	for(i = 0; i<(int)(sizeof(mais.triangles)/sizeof(mais.triangles[0])); i++){
		trace_Triangle(mais.triangles[i], c);
	}
}


void trace_Collision(point p1, point p2){
	boule b1,b2;
	couleur c;
	b1.centre = p1;
	b2.centre = p2;
	b1.rayon = 1;
	b2.rayon = 1;
	c.r = 1;
	c.g = 0;
	c.b = 0;
	trace_Boule(b1, c);
	trace_Boule(b2, c);

}



//Trace trois lignes pour visualiser l'origine 0,0,0 de la fenetre Et voir si nos formes se mettent bien au milieu
void trace_Origine(){
  glBegin(GL_LINES);
  glColor3f(0,0,1);

  glVertex3f(0,0,0);
  glVertex3f(100,0,0);

  glVertex3f(0,0,0);
  glVertex3f(0,100,0);

  glVertex3f(0,0,0);
  glVertex3f(0,0,100);

  glEnd();
}

void trace_praa(point p1, point p2, couleur c){


	glBegin(GL_QUADS);
	glColor3f(c.r, c.g, c.b);

	// Face avant
	glVertex3f(p1.d[0], p1.d[1], p1.d[2]);
	glVertex3f(p2.d[0], p1.d[1], p1.d[2]);
	glVertex3f(p2.d[0], p2.d[1], p1.d[2]);
	glVertex3f(p1.d[0], p2.d[1], p1.d[2]);


	// Face droite
	glColor3f(c.r-0.1, c.g-0.1, c.b-0.1);
	glVertex3f(p2.d[0], p1.d[1], p1.d[2]);
	glVertex3f(p2.d[0], p1.d[1], p2.d[2]);
	glVertex3f(p2.d[0], p2.d[1], p2.d[2]);
	glVertex3f(p2.d[0], p2.d[1], p1.d[2]);


	// Face arriere
	glVertex3f(p2.d[0], p1.d[1], p2.d[2]);
	glVertex3f(p1.d[0], p1.d[1], p2.d[2]);
	glVertex3f(p1.d[0], p2.d[1], p2.d[2]);
	glVertex3f(p2.d[0], p2.d[1], p2.d[2]);

	// Face gauche
	glColor3f(c.r-0.1, c.g-0.1, c.b-0.1);
	glVertex3f(p1.d[0], p1.d[1], p2.d[2]);
	glVertex3f(p1.d[0], p1.d[1], p1.d[2]);
	glVertex3f(p1.d[0], p2.d[1], p1.d[2]);
	glVertex3f(p1.d[0], p2.d[1], p2.d[2]);

	
	// Face haute
	glColor3f(c.r-0.5, c.g-0.5, c.b-0.5);
	glVertex3f(p1.d[0], p2.d[1], p1.d[2]);
	glVertex3f(p2.d[0], p2.d[1], p1.d[2]);
	glVertex3f(p2.d[0], p2.d[1], p2.d[2]);
	glVertex3f(p1.d[0], p2.d[1], p2.d[2]);

	// Face basse
	glVertex3f(p1.d[0], p1.d[1], p1.d[2]);
	glVertex3f(p2.d[0], p1.d[1], p1.d[2]);
	glVertex3f(p2.d[0], p1.d[1], p2.d[2]);
	glVertex3f(p1.d[0], p1.d[1], p2.d[2]);



	glEnd();


}

void trace_Escalier(escalier e){


	//iterateur
	int i;


	// Nombre de marche
	int nbMarche = (e.hautD.d[1] - e.basG.d[1])/e.hMarche;
	// La derniere marche peut ne pas etre de la meme taille
	float hDerMarche = (int)(e.hautD.d[1] - e.basG.d[1])%e.hMarche;
	// printf("\n\n\n%d %f\n", nbMarche, hDerMarche);
	// profondeur marche
	float profMarche = (e.hautD.d[2] - e.basG.d[2])/nbMarche;

	point marche1, marche2;
	// Couleur
	couleur c;
	c.r = 0.10;
	c.g = 0.70;
	c.b = 0.2;

	marche1 = e.basG;

	marche2.d[0] = e.hautD.d[0];
	marche2.d[1] = e.basG.d[1] + hDerMarche;
	marche2.d[2] = e.hautD.d[2];

	trace_praa(marche1,marche2,c);

	for(i=0; i<nbMarche; i++){

		marche1.d[0] = e.basG.d[0];
		marche1.d[1] = marche2.d[1];
		marche1.d[2] += profMarche;

		marche2.d[0] = e.hautD.d[0];
		marche2.d[1] = marche1.d[1] + e.hMarche;
		marche2.d[2] = e.hautD.d[2];

		/*
		if(i%2 == 0){
			c.r -= i/1000.;
			c.g -= i/10000.;
		}
		*/

		if(i%2 == 0){
			c.r += i/100.;
		}
		//c.r = i%3/10.;
		//c.g = i%3/10.;
		//c.b = i%3/10.;


		if(marche1.d[2] != marche2.d[2]){
			trace_praa(marche1,marche2,c);
		}
	}
}

