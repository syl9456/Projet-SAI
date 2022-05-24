#include "collision.h"




point cherchePlusProcheMaison(maison m, point origine){
	float plusPetiteDistance = 1000000000;
	point pointPlusProche;
	float d;
	for(int i=0; i<5;i++){
		for(int j=0; j<4; j++){
			if((d = distance(origine,m.plans[i].point[j])) <= plusPetiteDistance){
				pointPlusProche = m.plans[i].point[j];
				plusPetiteDistance = d;
			}
		}
	}
	return pointPlusProche;
}

point cherchePlusLoinMaison(maison m, point origine){
	float plusGrandeDistance = 0;
	float d;
	point pointPlusLoin;

	for(int i=0; i<5;i++){
		for(int j=0; j<4;j++){
			if((d=distance(origine,m.plans[i].point[j])) >= plusGrandeDistance){

				pointPlusLoin = m.plans[i].point[j];
				plusGrandeDistance = d;
			}
		}
	}
	return pointPlusLoin;
}


point cherchePlusProchePlateforme(plateforme p, point origine){
	float plusPetiteDistance = 1000000000;
	point pointPlusProche;
	float d;
	for(int i=0; i<6;i++){ 
		for(int j=0; j<4; j++){
			if((d = distance(origine,p.plans[i].point[j])) <= plusPetiteDistance){
				pointPlusProche = p.plans[i].point[j];
				plusPetiteDistance = d;
			}
		}
	}
	return pointPlusProche;
}

point cherchePlusLoinPlateforme(plateforme p, point origine){
	float plusGrandeDistance = 0;
	float d;
	point pointPlusLoin;

	for(int i=0; i<6;i++){
		for(int j=0; j<4;j++){
			if((d=distance(origine,p.plans[i].point[j])) >= plusGrandeDistance){

				pointPlusLoin = p.plans[i].point[j];
				plusGrandeDistance = d;
			}
		}
	}
	return pointPlusLoin;
}

point cherchePlusProcheBonus(bonus b, point origine){
	float plusPetiteDistance = 1000000000;
	point pointPlusProche;
	float d;
	for(int i=0; i<6;i++){
		for(int j=0; j<4; j++){
			if((d = distance(origine,b.plans[i].point[j])) <= plusPetiteDistance){
				pointPlusProche = b.plans[i].point[j];
				plusPetiteDistance = d;
			}
		}
	}
	return pointPlusProche;
}


point cherchePlusLoinBonus(bonus b, point origine){
	float plusGrandeDistance = 0;
	float d;
	point pointPlusLoin;

	for(int i=0; i<6;i++){
		for(int j=0; j<4;j++){
			if((d=distance(origine,b.plans[i].point[j])) >= plusGrandeDistance){

				pointPlusLoin = b.plans[i].point[j];
				plusGrandeDistance = d;
			}
		}
	}
	return pointPlusLoin;
}


point cherchePlusProcheArbre(arbre a, point origine){
	float plusPetiteDistance = 1000000000;
	point pointPlusProche;
	float d;
	for(int i=0; i<6;i++){
		for(int j=0; j<4; j++){
			if((d = distance(origine,a.plans[i].point[j])) <= plusPetiteDistance){
				pointPlusProche = a.plans[i].point[j];
				plusPetiteDistance = d;
			}
		}
	}
	return pointPlusProche;
}

point cherchePlusLoinArbre(arbre a, point origine){
	float plusGrandeDistance = 0;
	float d;
	point pointPlusLoin;

	for(int i=0; i<6;i++){
		for(int j=0; j<4;j++){
			if((d=distance(origine,a.plans[i].point[j])) >= plusGrandeDistance){

				pointPlusLoin = a.plans[i].point[j];
				plusGrandeDistance = d;
			}
		}
	}
	return pointPlusLoin;
}






// Verifie une collsion avec une maison
int collisions(point posJoueur, point plusProche, point plusLoin){
	// Heureusement que la maison est un cube

	// Verfie interiorité du cube
	if(posJoueur.d[0]+2 >= plusProche.d[0]  &&
		posJoueur.d[0]-2 <= plusLoin.d[0]   &&
		posJoueur.d[1]+2 >= plusProche.d[1] &&
		posJoueur.d[1]-2 <= plusLoin.d[1]   &&
		posJoueur.d[2]+2 >= plusProche.d[2] &&
		posJoueur.d[2]-2 <= plusLoin.d[2]   ){

		// Le joueur est en collision
		return 1;
	
	}

	// Verfie interiorité du cube
	if(posJoueur.d[0]-2 <= plusProche.d[0]  &&
		posJoueur.d[0]+2 >= plusLoin.d[0]   &&
		posJoueur.d[1]-2 <= plusProche.d[1] &&
		posJoueur.d[1]+2 >= plusLoin.d[1]   &&
		posJoueur.d[2]-2 <= plusProche.d[2] &&
		posJoueur.d[2]+2 >= plusLoin.d[2]   ){

		// Le joueur est en collision
		return 1;
	}

	// float taille = m.centre.d[0] - m.plans[0].point[0].d[0];
	// // Verfie interiorité du cube
	// if(posJoueur.d[0] >= m.centre.d[0] - taille &&
	// 	posJoueur.d[0] <= m.centre.d[0] + taille &&
	// 	posJoueur.d[1] >= m.centre.d[1] - taille &&
	// 	posJoueur.d[1] <= m.centre.d[1] + taille&&
	// 	posJoueur.d[2] >= m.centre.d[2] - taille &&
	// 	posJoueur.d[2] <= m.centre.d[2] + taille){

	// 	// Le joueur est en collision
	// 	return 1;
	
	// }

	// // Verfie interiorité du cube
	// if(posJoueur.d[0] <= m.centre.d[0] - taille &&
	// 	posJoueur.d[0] >= m.centre.d[0] + taille &&
	// 	posJoueur.d[1] <= m.centre.d[1] - taille &&
	// 	posJoueur.d[1] >= m.centre.d[1] + taille &&
	// 	posJoueur.d[2] <= m.centre.d[2] - taille &&
	// 	posJoueur.d[2] >= m.centre.d[2] + taille){

	// 	// Le joueur est en collision
	// 	return 1;
	
	// }


	//pas de collision
	return 0;
}

// Verifie la collision avec un escalier de bas en haut
int colPlateforme(plateforme p, point posJoueur){
	float taille = p.centre.d[0] - p.plans[0].point[0].d[0];
	// Verfie interiorité du cube
	 if(posJoueur.d[0] >= p.centre.d[0] - taille &&
	 	posJoueur.d[0] <= p.centre.d[0] + taille &&
	 	posJoueur.d[1]-11 >= p.centre.d[1] - taille &&
	 	posJoueur.d[1]-11 <= p.centre.d[1] + taille&&
	 	posJoueur.d[2] >= p.centre.d[2] - taille &&
	 	posJoueur.d[2] <= p.centre.d[2] + taille){

	 	// Le joueur est en collision
	 	return 1;
	
	 }

	return 0;
}

// Verifie la collision avec un escalier de bas en haut
int colEscalier(escalier e, point posJoueur){

	// Verfie interiorité du cube
	if(posJoueur.d[0] >= e.basG.d[0]   &&
		posJoueur.d[0] <= e.hautD.d[0] &&
		posJoueur.d[1]-10 >= e.basG.d[1]  &&
		posJoueur.d[1]-10 <= e.hautD.d[1] &&
		posJoueur.d[2] >= e.basG.d[2]  &&
		posJoueur.d[2] <= e.hautD.d[2]   ){

		// Le joueur est en collision
		return 1;
	
	}

	return 0;
}

// Renvoie la hauteur du joueur dans escalier
float etatHauteur(escalier e, point posJoueur){

	int nbMarche = (e.hautD.d[1] - e.basG.d[1])/e.hMarche;
	float posInt = fabs(e.hautD.d[2] - posJoueur.d[2]);
	float profMarche = (e.hautD.d[2] - e.basG.d[2])/nbMarche;

	int numMarche = (int)(posInt/profMarche);

	//printf("\n\n\n\n\n\n%d\n\n\n\n\n\n\n",numMarche);
	//printf("\n\n\n\n\n\n%d\n\n\n\n\n\n\n",nbMarche);
	//printf("\n\n\n\n\n\n%d\n\n\n\n\n\n\n",e.hMarche*(nbMarche-numMarche));

	return  e.hMarche*(nbMarche-numMarche);


}



// Verifie la collision avec un bonus
int colBonus(bonus b, point posJoueur){
	
	float taille = b.centre.d[0] - b.plans[0].point[0].d[0];
	// Verfie interiorité du cube
	 if(posJoueur.d[0] >= b.centre.d[0] - taille &&
	 	posJoueur.d[0] <= b.centre.d[0] + taille &&
	 	posJoueur.d[1]-8 >= b.centre.d[1] - taille &&
	 	posJoueur.d[1]-8 <= b.centre.d[1] + taille&&
	 	posJoueur.d[2] >= b.centre.d[2] - taille &&
	 	posJoueur.d[2] <= b.centre.d[2] + taille){

		// Le joueur est en collision
		return 1;
	
	}

	return 0;
}
