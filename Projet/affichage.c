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



//Trace la plateforme sur la fenetre
void trace_Plateforme(plateforme plat){
	int i;
	couleur c;
	c.r = 1;
	c.g = 1;
	c.b = 1;

	for(i = 0; i<(int)(sizeof(plat.plans)/sizeof(plat.plans[0])); i++){
		//On change la couleur a chaques itérations
		c.r -= 0.1;
		c.g -= 0.1;
		c.b -= 0.1;
		trace_Plan(plat.plans[i], c);
	}
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
		c.r -= 0.1;
		c.g -= 0.1;
		c.b -= 0.1;
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



//Trace trois lignes pour visualiser l'origine 0,0,0 de la fenetre Et voir si nos formes se mettent bien au milieu tahu
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
