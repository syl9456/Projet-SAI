#include "affichage.h"


//Trace un plan sur la fenetre
void trace_Plan(plan p, couleur c){
	glBegin(GL_QUADS);
	glColor3f(c.r, c.g, c.b);
	glVertex3f(p.s1.x, p.s1.y, p.s1.z);
	glVertex3f(p.s2.x, p.s2.y, p.s2.z);
	glVertex3f(p.s3.x, p.s3.y, p.s3.z);
	glVertex3f(p.s4.x, p.s4.y, p.s4.z);
	glEnd();
}


//Trace un triangle sur la fenetre
void trace_Triangle(triangle t, couleur c){
	glBegin(GL_TRIANGLES);
	glColor3f(c.r, c.g, c.b);
	glVertex3f(t.s1.x, t.s1.y, t.s1.z);
	glVertex3f(t.s2.x, t.s2.y, t.s2.z);
	glVertex3f(t.s3.x, t.s3.y, t.s3.z);
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

	for(i = 0; i<(int)(sizeof(mais.plans)/sizeof(mais.plans[0])); i++){
		c.r -= 0.1;
		c.g -= 0.1;
		c.b -= 0.1;
		trace_Plan(mais.plans[i], c);
	}

	c.r = 1;
	c.g = 0;
	c.b = 0;
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

