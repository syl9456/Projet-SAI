#include "collision.h"



// Verifie une collsion avec une maison
int colMaison(point posJoueur, maison m){

	// Heureusement que la maison est un cube
	int taille = m.centre.d[0] - m.plans[0].point[0].d[0];

	// Verfie interiorité du cube
	if(posJoueur.d[0] >= m.centre.d[0] - taille &&
		posJoueur.d[0] <= m.centre.d[0] + taille &&
		posJoueur.d[1] >= m.centre.d[1] - taille &&
		posJoueur.d[1] <= m.centre.d[1] + taille &&
		posJoueur.d[2] >= m.centre.d[2] - taille &&
		posJoueur.d[2] <= m.centre.d[2] + taille){

		// Le joueur est en collision
		return 1;
	
	}

	// Verfie interiorité du cube
	if(posJoueur.d[0] <= m.centre.d[0] - taille &&
		posJoueur.d[0] >= m.centre.d[0] + taille &&
		posJoueur.d[1] <= m.centre.d[1] - taille &&
		posJoueur.d[1] >= m.centre.d[1] + taille &&
		posJoueur.d[2] <= m.centre.d[2] - taille &&
		posJoueur.d[2] >= m.centre.d[2] + taille){

		// Le joueur est en collision
		return 1;
	
	}
	// pas de collision
	return 0;
}