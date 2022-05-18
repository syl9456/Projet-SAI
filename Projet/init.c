#include "init.h"

//Initalisation d'une maison par rapport a son centre c et sa taille
maison init_Maison(sommet c, int taille){

	int hauteur_murs = HAUTEUR_MAISON;
	int hauteur_toit = HAUTEUR_MAISON;


	maison mais;

	mais.centre = c;

	//Sol
	//1
	mais.plans[0].s1.x = c.x - taille;
	mais.plans[0].s1.y = c.y;
	mais.plans[0].s1.z = c.z + taille;

	mais.plans[0].s2.x = c.x + taille;
	mais.plans[0].s2.y = c.y;
	mais.plans[0].s2.z = c.z + taille;

	mais.plans[0].s3.x = c.x + taille;
	mais.plans[0].s3.y = c.y;
	mais.plans[0].s3.z = c.z - taille;

	mais.plans[0].s4.x = c.x - taille;
	mais.plans[0].s4.y = c.y;
	mais.plans[0].s4.z = c.z - taille;


	//Cotes
	//2
	mais.plans[1].s1.x = c.x - taille;
	mais.plans[1].s1.y = c.y;
	mais.plans[1].s1.z = c.z + taille;

	mais.plans[1].s2.x = c.x + taille;
	mais.plans[1].s2.y = c.y;
	mais.plans[1].s2.z = c.z + taille;

	mais.plans[1].s3.x = c.x + taille;
	mais.plans[1].s3.y = c.y + hauteur_murs;
	mais.plans[1].s3.z = c.z + taille;

	mais.plans[1].s4.x = c.x - taille;
	mais.plans[1].s4.y = c.y + hauteur_murs;
	mais.plans[1].s4.z = c.z + taille;



	//3
	mais.plans[2].s1.x = c.x + taille;
	mais.plans[2].s1.y = c.y;
	mais.plans[2].s1.z = c.z + taille;

	mais.plans[2].s2.x = c.x + taille;
	mais.plans[2].s2.y = c.y;
	mais.plans[2].s2.z = c.z - taille;

	mais.plans[2].s3.x = c.x + taille;
	mais.plans[2].s3.y = c.y + hauteur_murs;
	mais.plans[2].s3.z = c.z - taille;

	mais.plans[2].s4.x = c.x + taille;
	mais.plans[2].s4.y = c.y + hauteur_murs;
	mais.plans[2].s4.z = c.z + taille;



	//4
	mais.plans[3].s1.x = c.x + taille;
	mais.plans[3].s1.y = c.y;
	mais.plans[3].s1.z = c.z - taille;

	mais.plans[3].s2.x = c.x - taille;
	mais.plans[3].s2.y = c.y;
	mais.plans[3].s2.z = c.z - taille;

	mais.plans[3].s3.x = c.x - taille;
	mais.plans[3].s3.y = c.y + hauteur_murs;
	mais.plans[3].s3.z = c.z - taille;

	mais.plans[3].s4.x = c.x + taille;
	mais.plans[3].s4.y = c.y + hauteur_murs;
	mais.plans[3].s4.z = c.z - taille;



	//5
	mais.plans[4].s1.x = c.x - taille;
	mais.plans[4].s1.y = c.y;
	mais.plans[4].s1.z = c.z - taille;

	mais.plans[4].s2.x = c.x - taille;
	mais.plans[4].s2.y = c.y;
	mais.plans[4].s2.z = c.z + taille;

	mais.plans[4].s3.x = c.x - taille;
	mais.plans[4].s3.y = c.y + hauteur_murs;
	mais.plans[4].s3.z = c.z + taille;

	mais.plans[4].s4.x = c.x - taille;
	mais.plans[4].s4.y = c.y + hauteur_murs;
	mais.plans[4].s4.z = c.z - taille;



	//Toit
	//Carrés
	//6
	mais.plans[5].s1.x = c.x + taille;
	mais.plans[5].s1.y = c.y + hauteur_murs + hauteur_toit;
	mais.plans[5].s1.z = c.z;

	mais.plans[5].s2.x = c.x - taille;
	mais.plans[5].s2.y = c.y + hauteur_murs + hauteur_toit;
	mais.plans[5].s2.z = c.z;

	mais.plans[5].s3.x = c.x - taille;
	mais.plans[5].s3.y = c.y + hauteur_murs;
	mais.plans[5].s3.z = c.z - taille;

	mais.plans[5].s4.x = c.x + taille;
	mais.plans[5].s4.y = c.y + hauteur_murs;
	mais.plans[5].s4.z = c.z - taille;



	//7
	mais.plans[6].s1.x = c.x - taille;
	mais.plans[6].s1.y = c.y + hauteur_murs + hauteur_toit;
	mais.plans[6].s1.z = c.z;

	mais.plans[6].s2.x = c.x + taille;
	mais.plans[6].s2.y = c.y + hauteur_murs + hauteur_toit;
	mais.plans[6].s2.z = c.z;

	mais.plans[6].s3.x = c.x + taille;
	mais.plans[6].s3.y = c.y + hauteur_murs;
	mais.plans[6].s3.z = c.z + taille;

	mais.plans[6].s4.x = c.x - taille;
	mais.plans[6].s4.y = c.y + hauteur_murs;
	mais.plans[6].s4.z = c.z + taille;



	//Triangles
	mais.triangles[0].s1.x = c.x + taille;
	mais.triangles[0].s1.y = c.y + hauteur_murs + hauteur_toit;
	mais.triangles[0].s1.z = c.z;

	mais.triangles[0].s2.x = c.x + taille;
	mais.triangles[0].s2.y = c.y + hauteur_murs;
	mais.triangles[0].s2.z = c.z - taille;

	mais.triangles[0].s3.x = c.x + taille;
	mais.triangles[0].s3.y = c.y + hauteur_murs; 
	mais.triangles[0].s3.z = c.z + taille;



	mais.triangles[1].s1.x = c.x - taille;
	mais.triangles[1].s1.y = c.y + hauteur_murs + hauteur_toit;
	mais.triangles[1].s1.z = c.z;

	mais.triangles[1].s2.x = c.x - taille;
	mais.triangles[1].s2.y = c.y + hauteur_murs;
	mais.triangles[1].s2.z = c.z + taille;

	mais.triangles[1].s3.x = c.x - taille;
	mais.triangles[1].s3.y = c.y + hauteur_murs;
	mais.triangles[1].s3.z = c.z - taille;

	return mais;

}


//Initalisation d'une plateforme par rapport a son centre c et sa taille
plateforme init_Plateforme(sommet c, int taille){

	plateforme plate;
	int hauteur_murs = HAUTEUR_PLATEFORME;


	//Dessous
	//1
	plate.plans[0].s1.x = c.x - taille;
	plate.plans[0].s1.y = c.y;
	plate.plans[0].s1.z = c.z + taille;

	plate.plans[0].s2.x = c.x + taille;
	plate.plans[0].s2.y = c.y;
	plate.plans[0].s2.z = c.z + taille;

	plate.plans[0].s3.x = c.x + taille;
	plate.plans[0].s3.y = c.y;
	plate.plans[0].s3.z = c.z - taille;

	plate.plans[0].s4.x = c.x - taille;
	plate.plans[0].s4.y = c.y;
	plate.plans[0].s4.z = c.z - taille;


	//Cotes
	//2
	plate.plans[1].s1.x = c.x - taille;
	plate.plans[1].s1.y = c.y;
	plate.plans[1].s1.z = c.z + taille;

	plate.plans[1].s2.x = c.x + taille;
	plate.plans[1].s2.y = c.y;
	plate.plans[1].s2.z = c.z + taille;

	plate.plans[1].s3.x = c.x + taille;
	plate.plans[1].s3.y = c.y + hauteur_murs;
	plate.plans[1].s3.z = c.z + taille;

	plate.plans[1].s4.x = c.x - taille;
	plate.plans[1].s4.y = c.y + hauteur_murs;
	plate.plans[1].s4.z = c.z + taille;



	//3
	plate.plans[2].s1.x = c.x + taille;
	plate.plans[2].s1.y = c.y;
	plate.plans[2].s1.z = c.z + taille;

	plate.plans[2].s2.x = c.x + taille;
	plate.plans[2].s2.y = c.y;
	plate.plans[2].s2.z = c.z - taille;

	plate.plans[2].s3.x = c.x + taille;
	plate.plans[2].s3.y = c.y + hauteur_murs;
	plate.plans[2].s3.z = c.z - taille;

	plate.plans[2].s4.x = c.x + taille;
	plate.plans[2].s4.y = c.y + hauteur_murs;
	plate.plans[2].s4.z = c.z + taille;



	//4
	plate.plans[3].s1.x = c.x + taille;
	plate.plans[3].s1.y = c.y;
	plate.plans[3].s1.z = c.z - taille;

	plate.plans[3].s2.x = c.x - taille;
	plate.plans[3].s2.y = c.y;
	plate.plans[3].s2.z = c.z - taille;

	plate.plans[3].s3.x = c.x - taille;
	plate.plans[3].s3.y = c.y + hauteur_murs;
	plate.plans[3].s3.z = c.z - taille;

	plate.plans[3].s4.x = c.x + taille;
	plate.plans[3].s4.y = c.y + hauteur_murs;
	plate.plans[3].s4.z = c.z - taille;



	//5
	plate.plans[4].s1.x = c.x - taille;
	plate.plans[4].s1.y = c.y;
	plate.plans[4].s1.z = c.z - taille;

	plate.plans[4].s2.x = c.x - taille;
	plate.plans[4].s2.y = c.y;
	plate.plans[4].s2.z = c.z + taille;

	plate.plans[4].s3.x = c.x - taille;
	plate.plans[4].s3.y = c.y + hauteur_murs;
	plate.plans[4].s3.z = c.z + taille;

	plate.plans[4].s4.x = c.x - taille;
	plate.plans[4].s4.y = c.y + hauteur_murs;
	plate.plans[4].s4.z = c.z - taille;



	//Dessus
	//6
	plate.plans[5].s1.x = c.x - taille;
	plate.plans[5].s1.y = c.y + hauteur_murs;
	plate.plans[5].s1.z = c.z + taille;

	plate.plans[5].s2.x = c.x + taille;
	plate.plans[5].s2.y = c.y + hauteur_murs;
	plate.plans[5].s2.z = c.z + taille;

	plate.plans[5].s3.x = c.x + taille;
	plate.plans[5].s3.y = c.y + hauteur_murs;
	plate.plans[5].s3.z = c.z - taille;

	plate.plans[5].s4.x = c.x - taille;
	plate.plans[5].s4.y = c.y + hauteur_murs;
	plate.plans[5].s4.z = c.z - taille;


	return plate;
}