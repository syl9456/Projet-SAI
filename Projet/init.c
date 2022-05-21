#include "init.h"

//Initalisation d'une maison par rapport a son centre c et sa taille
maison init_Maison(point c, float taille){

	float hauteur_murs = HAUTEUR_MAISON;
	float hauteur_toit = HAUTEUR_MAISON;
	maison mais;
	mais.centre = c;


	//Sol
	//1
	mais.plans[0].point[0] = initialiserPointDeFloat(c.d[0] - taille, c.d[1], c.d[2] + taille);

	mais.plans[0].point[1] = initialiserPointDeFloat(c.d[0] + taille, c.d[1], c.d[2] + taille);

	mais.plans[0].point[2] = initialiserPointDeFloat(c.d[0] + taille, c.d[1], c.d[2] - taille);

	mais.plans[0].point[3] = initialiserPointDeFloat(c.d[0] - taille, c.d[1], c.d[2] - taille);


	//Cotes
	//2
	mais.plans[1].point[0] = initialiserPointDeFloat(c.d[0] - taille, c.d[1], c.d[2] + taille);

	mais.plans[1].point[1] = initialiserPointDeFloat(c.d[0] + taille, c.d[1], c.d[2] + taille);

	mais.plans[1].point[2] = initialiserPointDeFloat(c.d[0] + taille, c.d[1] + hauteur_murs , c.d[2] + taille);
		
	mais.plans[1].point[3] = initialiserPointDeFloat(c.d[0] - taille, c.d[1] + hauteur_murs , c.d[2] + taille);



	//3
	mais.plans[2].point[0] = initialiserPointDeFloat(c.d[0] + taille, c.d[1], c.d[2] + taille);

	mais.plans[2].point[1] = initialiserPointDeFloat(c.d[0] + taille, c.d[1], c.d[2] - taille);

	mais.plans[2].point[2] = initialiserPointDeFloat(c.d[0] + taille, c.d[1] + hauteur_murs , c.d[2] - taille);
		
	mais.plans[2].point[3] = initialiserPointDeFloat(c.d[0] + taille, c.d[1] + hauteur_murs , c.d[2] + taille);




	//4
	mais.plans[3].point[0] = initialiserPointDeFloat(c.d[0] + taille, c.d[1], c.d[2] - taille);

	mais.plans[3].point[1] = initialiserPointDeFloat(c.d[0] - taille, c.d[1], c.d[2] - taille);

	mais.plans[3].point[2] = initialiserPointDeFloat(c.d[0] - taille, c.d[1] + hauteur_murs , c.d[2] - taille);
		
	mais.plans[3].point[3] = initialiserPointDeFloat(c.d[0] + taille, c.d[1] + hauteur_murs , c.d[2] - taille);




	//5
	mais.plans[4].point[0] = initialiserPointDeFloat(c.d[0] - taille, c.d[1], c.d[2] - taille);

	mais.plans[4].point[1] = initialiserPointDeFloat(c.d[0] - taille, c.d[1], c.d[2] + taille);

	mais.plans[4].point[2] = initialiserPointDeFloat(c.d[0] - taille, c.d[1] + hauteur_murs , c.d[2] + taille);
		
	mais.plans[4].point[3] = initialiserPointDeFloat(c.d[0] - taille, c.d[1] + hauteur_murs , c.d[2] - taille);



	//Toit
	//Carrés
	//6
	mais.plans[5].point[0] = initialiserPointDeFloat(c.d[0] + taille + (taille*(10./100.)) , c.d[1] + hauteur_murs + hauteur_toit , c.d[2]);

	mais.plans[5].point[1] = initialiserPointDeFloat(c.d[0] - taille - (taille*(10./100.)) , c.d[1] + hauteur_murs + hauteur_toit , c.d[2]);

	mais.plans[5].point[2] = initialiserPointDeFloat(c.d[0] - taille - (taille*(10./100.)) , c.d[1] + hauteur_murs - (taille*(10./100.)) , c.d[2] - taille - (taille*(10./100.)));
		
	mais.plans[5].point[3] = initialiserPointDeFloat(c.d[0] + taille + (taille*(10./100.)) , c.d[1] + hauteur_murs - (taille*(10./100.)) , c.d[2] - taille - (taille*(10./100.)));



	//7
	mais.plans[6].point[0] = initialiserPointDeFloat(c.d[0] - taille - (taille*(10./100.)) , c.d[1] + hauteur_murs + hauteur_toit , c.d[2]);

	mais.plans[6].point[1] = initialiserPointDeFloat(c.d[0] + taille + (taille*(10./100.)) , c.d[1] + hauteur_murs + hauteur_toit , c.d[2]);

	mais.plans[6].point[2] = initialiserPointDeFloat(c.d[0] + taille + (taille*(10./100.)) , c.d[1] + hauteur_murs - (taille*(10./100.)) , c.d[2] + taille + (taille*(10./100.)));
		
	mais.plans[6].point[3] = initialiserPointDeFloat(c.d[0] - taille - (taille*(10./100.)) , c.d[1] + hauteur_murs - (taille*(10./100.)) , c.d[2] + taille + (taille*(10./100.)));




	//Triangles
	//1
	mais.triangles[0].point[0] = initialiserPointDeFloat(c.d[0] + taille, c.d[1] + hauteur_murs + hauteur_toit , c.d[2]);

	mais.triangles[0].point[1] = initialiserPointDeFloat(c.d[0] + taille, c.d[1] + hauteur_murs , c.d[2] - taille);

	mais.triangles[0].point[2] = initialiserPointDeFloat(c.d[0] + taille, c.d[1] + hauteur_murs , c.d[2] + taille);


	//2
	mais.triangles[1].point[0] = initialiserPointDeFloat(c.d[0] - taille, c.d[1] + hauteur_murs + hauteur_toit , c.d[2]);

	mais.triangles[1].point[1] = initialiserPointDeFloat(c.d[0] - taille, c.d[1] + hauteur_murs , c.d[2] + taille);

	mais.triangles[1].point[2] = initialiserPointDeFloat(c.d[0] - taille, c.d[1] + hauteur_murs , c.d[2] - taille);

	return mais;

}


//Initalisation d'une plateforme par rapport a son centre c et sa taille
plateforme init_Plateforme(point c, float taille){

	plateforme plate;
	int hauteur_murs = HAUTEUR_PLATEFORME;



	plate.plans[0].point[0] = initialiserPointDeFloat(c.d[0] - taille, c.d[1], c.d[2] + taille);

	plate.plans[0].point[1] = initialiserPointDeFloat(c.d[0] + taille, c.d[1], c.d[2] + taille);

	plate.plans[0].point[2] = initialiserPointDeFloat(c.d[0] + taille, c.d[1], c.d[2] - taille);

	plate.plans[0].point[3] = initialiserPointDeFloat(c.d[0] - taille, c.d[1], c.d[2] - taille);


	//Cotes
	//2
	plate.plans[1].point[0] = initialiserPointDeFloat(c.d[0] - taille, c.d[1], c.d[2] + taille);

	plate.plans[1].point[1] = initialiserPointDeFloat(c.d[0] + taille, c.d[1], c.d[2] + taille);

	plate.plans[1].point[2] = initialiserPointDeFloat(c.d[0] + taille, c.d[1] + hauteur_murs , c.d[2] + taille);
		
	plate.plans[1].point[3] = initialiserPointDeFloat(c.d[0] - taille, c.d[1] + hauteur_murs , c.d[2] + taille);



	//3
	plate.plans[2].point[0] = initialiserPointDeFloat(c.d[0] + taille, c.d[1], c.d[2] + taille);

	plate.plans[2].point[1] = initialiserPointDeFloat(c.d[0] + taille, c.d[1], c.d[2] - taille);

	plate.plans[2].point[2] = initialiserPointDeFloat(c.d[0] + taille, c.d[1] + hauteur_murs , c.d[2] - taille);
		
	plate.plans[2].point[3] = initialiserPointDeFloat(c.d[0] + taille, c.d[1] + hauteur_murs , c.d[2] + taille);




	//4
	plate.plans[3].point[0] = initialiserPointDeFloat(c.d[0] + taille, c.d[1], c.d[2] - taille);

	plate.plans[3].point[1] = initialiserPointDeFloat(c.d[0] - taille, c.d[1], c.d[2] - taille);

	plate.plans[3].point[2] = initialiserPointDeFloat(c.d[0] - taille, c.d[1] + hauteur_murs , c.d[2] - taille);
		
	plate.plans[3].point[3] = initialiserPointDeFloat(c.d[0] + taille, c.d[1] + hauteur_murs , c.d[2] - taille);




	//5
	plate.plans[4].point[0] = initialiserPointDeFloat(c.d[0] - taille, c.d[1], c.d[2] - taille);

	plate.plans[4].point[1] = initialiserPointDeFloat(c.d[0] - taille, c.d[1], c.d[2] + taille);

	plate.plans[4].point[2] = initialiserPointDeFloat(c.d[0] - taille, c.d[1] + hauteur_murs , c.d[2] + taille);
		
	plate.plans[4].point[3] = initialiserPointDeFloat(c.d[0] - taille, c.d[1] + hauteur_murs , c.d[2] - taille);
	

	//Dessus 
	//6
	plate.plans[4].point[0] = initialiserPointDeFloat(c.d[0] - taille, c.d[1] + hauteur_murs , c.d[2] + taille);

	plate.plans[4].point[1] = initialiserPointDeFloat(c.d[0] + taille, c.d[1] + hauteur_murs , c.d[2] + taille);

	plate.plans[4].point[2] = initialiserPointDeFloat(c.d[0] + taille, c.d[1] + hauteur_murs , c.d[2] - taille);
		
	plate.plans[4].point[3] = initialiserPointDeFloat(c.d[0] - taille, c.d[1] + hauteur_murs , c.d[2] - taille);
	

	return plate;
}


joueur init_Joueur(point c, float taille){
	//Ici joueur est un quadirlatere rectangle
	joueur j;

	//Ici hauteur joueur
	int hauteur_joueur = HAUTEUR_JOUEUR;


	j.plans[0].point[0] = initialiserPointDeFloat(c.d[0] - taille, c.d[1], c.d[2] + taille);

	j.plans[0].point[1] = initialiserPointDeFloat(c.d[0] + taille, c.d[1], c.d[2] + taille);

	j.plans[0].point[2] = initialiserPointDeFloat(c.d[0] + taille, c.d[1], c.d[2] - taille);

	j.plans[0].point[3] = initialiserPointDeFloat(c.d[0] - taille, c.d[1], c.d[2] - taille);


	//Cotes
	//2
	j.plans[1].point[0] = initialiserPointDeFloat(c.d[0] - taille, c.d[1], c.d[2] + taille);

	j.plans[1].point[1] = initialiserPointDeFloat(c.d[0] + taille, c.d[1], c.d[2] + taille);

	j.plans[1].point[2] = initialiserPointDeFloat(c.d[0] + taille, c.d[1] + hauteur_joueur , c.d[2] + taille);
		
	j.plans[1].point[3] = initialiserPointDeFloat(c.d[0] - taille, c.d[1] + hauteur_joueur , c.d[2] + taille);



	//3
	j.plans[2].point[0] = initialiserPointDeFloat(c.d[0] + taille, c.d[1], c.d[2] + taille);

	j.plans[2].point[1] = initialiserPointDeFloat(c.d[0] + taille, c.d[1], c.d[2] - taille);

	j.plans[2].point[2] = initialiserPointDeFloat(c.d[0] + taille, c.d[1] + hauteur_joueur , c.d[2] - taille);
		
	j.plans[2].point[3] = initialiserPointDeFloat(c.d[0] + taille, c.d[1] + hauteur_joueur , c.d[2] + taille);




	//4
	j.plans[3].point[0] = initialiserPointDeFloat(c.d[0] + taille, c.d[1], c.d[2] - taille);

	j.plans[3].point[1] = initialiserPointDeFloat(c.d[0] - taille, c.d[1], c.d[2] - taille);

	j.plans[3].point[2] = initialiserPointDeFloat(c.d[0] - taille, c.d[1] + hauteur_joueur , c.d[2] - taille);
		
	j.plans[3].point[3] = initialiserPointDeFloat(c.d[0] + taille, c.d[1] + hauteur_joueur , c.d[2] - taille);




	//5
	j.plans[4].point[0] = initialiserPointDeFloat(c.d[0] - taille, c.d[1], c.d[2] - taille);

	j.plans[4].point[1] = initialiserPointDeFloat(c.d[0] - taille, c.d[1], c.d[2] + taille);

	j.plans[4].point[2] = initialiserPointDeFloat(c.d[0] - taille, c.d[1] + hauteur_joueur , c.d[2] + taille);
		
	j.plans[4].point[3] = initialiserPointDeFloat(c.d[0] - taille, c.d[1] + hauteur_joueur , c.d[2] - taille);
	

	//Dessus 
	//6
	j.plans[4].point[0] = initialiserPointDeFloat(c.d[0] - taille, c.d[1] + hauteur_joueur , c.d[2] + taille);

	j.plans[4].point[1] = initialiserPointDeFloat(c.d[0] + taille, c.d[1] + hauteur_joueur , c.d[2] + taille);

	j.plans[4].point[2] = initialiserPointDeFloat(c.d[0] + taille, c.d[1] + hauteur_joueur , c.d[2] - taille);
		
	j.plans[4].point[3] = initialiserPointDeFloat(c.d[0] - taille, c.d[1] + hauteur_joueur , c.d[2] - taille);


	return j;
}
