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
int colMaison(point posJoueur, point plusProche, point plusLoin){
	// Heureusement que la maison est un cube

	printf("Plus Proche:");
	affichePoint(plusProche);
	printf("Plus Loin:");
	affichePoint(plusLoin);

	// Verfie interiorité du cube
	if(posJoueur.d[0] >= plusProche.d[0]  &&
		posJoueur.d[0] <= plusLoin.d[0]   &&
		posJoueur.d[1] >= plusProche.d[1] &&
		posJoueur.d[1] <= plusLoin.d[1]   &&
		posJoueur.d[2] >= plusProche.d[2] &&
		posJoueur.d[2] <= plusLoin.d[2]   ){

		// Le joueur est en collision
		return 1;
	
	}

	// Verfie interiorité du cube
	if(posJoueur.d[0] <= plusProche.d[0]  &&
		posJoueur.d[0] >= plusLoin.d[0]   &&
		posJoueur.d[1] <= plusProche.d[1] &&
		posJoueur.d[1] >= plusLoin.d[1]   &&
		posJoueur.d[2] <= plusProche.d[2] &&
		posJoueur.d[2] >= plusLoin.d[2]   ){

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