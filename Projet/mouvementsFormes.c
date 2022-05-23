#include "mouvementsFormes.h"




//A faire avec les matrices gnagna
plateforme translation_plateforme(plateforme plat, point po){
	int i,j;
	matrice m = genereT(po.d[0],po.d[1],po.d[2]);

	for(i = 0; i<(int)(sizeof(plat.plans)/sizeof(plat.plans[0])); i++){
		for(j=0; j<4; j++){
			plat.plans[i].point[j] = multiplicationMatricePoint(m,plat.plans[i].point[j]);
		}
	}
	plat.centre = multiplicationMatricePoint(m,plat.centre);
	return plat;
} 

plateforme mise_echelle_plateforme(plateforme plat, float x,float y, float z){
	int i,j;
	matrice m = genereS(x,y,z);

	for(i = 0; i<(int)(sizeof(plat.plans)/sizeof(plat.plans[0])); i++){
		for(j=0; j<4; j++){
			plat.plans[i].point[j] = multiplicationMatricePoint(m,plat.plans[i].point[j]);
		}
	}
	plat.centre = multiplicationMatricePoint(m,plat.centre);
	return plat;

}


plateforme rotation_plateforme(plateforme plat,char axe, float angle){
	int i,j;
	matrice m;

	switch(axe){
		case 'x':
		m = genereRAutourX(angle);
		break;
		case 'y':
		m = genereRAutourY(angle);
		break;
		case 'z':
		m = genereRAutourZ(angle);
		break;
		default : 
		printf("Pas bon caractere pour rotation");
		exit(-1);
	}
	

	for(i = 0; i<(int)(sizeof(plat.plans)/sizeof(plat.plans[0])); i++){
		for(j=0; j<4; j++){
			plat.plans[i].point[j] = multiplicationMatricePoint(m,plat.plans[i].point[j]);
		}
	}
	plat.centre = multiplicationMatricePoint(m,plat.centre);
	return plat;
} 



maison translation_maison(maison mais,point po){
	int i,j;
	matrice m = genereT(po.d[0],po.d[1],po.d[2]);
	for(i = 0; i<(int)(sizeof(mais.plans)/sizeof(mais.plans[0])); i++){
		for(j=0; j<4; j++){
			mais.plans[i].point[j] = multiplicationMatricePoint(m,mais.plans[i].point[j]);
		}
	}

	for(i = 0; i<(int)(sizeof(mais.triangles)/sizeof(mais.triangles[0])); i++){
		for(j=0;j<3;j++){
			mais.triangles[i].point[j] = multiplicationMatricePoint(m,mais.triangles[i].point[j]);
		}
	}
	mais.centre = multiplicationMatricePoint(m,mais.centre);
	return mais;
} 


maison mise_echelle_maison(maison mais, float x,float y, float z){
	int i,j;
	matrice m = genereS(x,y,z);

	for(i = 0; i<(int)(sizeof(mais.plans)/sizeof(mais.plans[0])); i++){
		for(j=0; j<4; j++){
			mais.plans[i].point[j] = multiplicationMatricePoint(m,mais.plans[i].point[j]);
		}
	}

	for(i = 0; i<(int)(sizeof(mais.triangles)/sizeof(mais.triangles[0])); i++){
		for(j=0;j<3;j++){
			mais.plans[i].point[j] = multiplicationMatricePoint(m,mais.plans[i].point[j]);
		}
	}
	mais.centre = multiplicationMatricePoint(m,mais.centre);
	return mais;

}

maison rotation_maison(maison mais,char axe,float angle){
	int i,j;
	matrice m;

	switch(axe){
		case 'x':
		m = genereRAutourX(angle);
		break;
		case 'y':
		m = genereRAutourY(angle);
		break;
		case 'z':
		m = genereRAutourZ(angle);
		break;
		default : 
		printf("Pas bon caractere pour rotation");
		exit(-1);
	}

	for(i = 0; i<(int)(sizeof(mais.plans)/sizeof(mais.plans[0])); i++){
		for(j=0; j<4; j++){
			mais.plans[i].point[j] = multiplicationMatricePoint(m,mais.plans[i].point[j]);
		}
	}

	for(i = 0; i<(int)(sizeof(mais.triangles)/sizeof(mais.triangles[0])); i++){
		for(j=0;j<3;j++){
			mais.triangles[i].point[j] = multiplicationMatricePoint(m,mais.triangles[i].point[j]);
		}
	}
	mais.centre = multiplicationMatricePoint(m,mais.centre);
	return mais;

}



joueur translation_joueur(joueur jou, point po){
	int i,j;
	matrice m = genereT(po.d[0],po.d[1],po.d[2]);

	for(i = 0; i<(int)(sizeof(jou.plans)/sizeof(jou.plans[0])); i++){
		for(j=0; j<4; j++){
			jou.plans[i].point[j] = multiplicationMatricePoint(m,jou.plans[i].point[j]);
		}
	}
	jou.centre = multiplicationMatricePoint(m,jou.centre);
	return jou;
}


joueur mise_echelle_joueur(joueur jou, float x,float y, float z){
	int i,j;
	matrice m = genereS(x,y,z);

	for(i = 0; i<(int)(sizeof(jou.plans)/sizeof(jou.plans[0])); i++){
		for(j=0; j<4; j++){
			jou.plans[i].point[j] = multiplicationMatricePoint(m,jou.plans[i].point[j]);
		}
	}
	jou.centre = multiplicationMatricePoint(m,jou.centre);
	return jou;
}



bonus translation_bonus(bonus bon, point po){
	int i,j;
	matrice m = genereT(po.d[0],po.d[1],po.d[2]);

	for(i = 0; i<(int)(sizeof(bon.plans)/sizeof(bon.plans[0])); i++){
		for(j=0; j<4; j++){
			bon.plans[i].point[j] = multiplicationMatricePoint(m,bon.plans[i].point[j]);
		}
	}
	bon.centre = multiplicationMatricePoint(m,bon.centre);
	return bon;
}


bonus mise_echelle_bonus(bonus bon, float x,float y, float z){
	int i,j;
	matrice m = genereS(x,y,z);

	for(i = 0; i<(int)(sizeof(bon.plans)/sizeof(bon.plans[0])); i++){
		for(j=0; j<4; j++){
			bon.plans[i].point[j] = multiplicationMatricePoint(m,bon.plans[i].point[j]);
		}
	}
	bon.centre = multiplicationMatricePoint(m,bon.centre);
	return bon;
}


bonus rotation_bonus(bonus bon,char axe, float angle){
	int i,j;
	matrice m;
	switch(axe){
		case 'x':
		m = genereRAutourX(angle);
		break;
		case 'y':
		m = genereRAutourY(angle);
		break;
		case 'z':
		m = genereRAutourZ(angle);
		break;
		default : 
		printf("Pas bon caractere pour rotation");
		exit(-1);
	}

	for(i = 0; i<(int)(sizeof(bon.plans)/sizeof(bon.plans[0])); i++){
		for(j=0; j<4; j++){
			bon.plans[i].point[j] = multiplicationMatricePoint(m,bon.plans[i].point[j]);
		}
	}
	bon.centre = multiplicationMatricePoint(m,bon.centre);
	return bon;
}

//Genere une rotation autour du vecteur passé en param
bonus rotation_bonus_vec(bonus bon, float angle, vecteur vec){
	int i,j;
	matrice m;

	m = genereRAutourVec(angle,vec);

	for(i = 0; i<(int)(sizeof(bon.plans)/sizeof(bon.plans[0])); i++){
		for(j=0; j<4; j++){
			bon.plans[i].point[j] = multiplicationMatricePoint(m,bon.plans[i].point[j]);
		}
	}
	return bon;
}





arbre translation_arbre(arbre ab, point po){
	int i,j;
	matrice m = genereT(po.d[0],po.d[1],po.d[2]);

	for(i = 0; i<(int)(sizeof(ab.plans)/sizeof(ab.plans[0])); i++){
		for(j=0; j<4; j++){
			ab.plans[i].point[j] = multiplicationMatricePoint(m,ab.plans[i].point[j]);
		}
	}
	ab.centre = multiplicationMatricePoint(m,ab.centre);
	ab.feuilles.centre = multiplicationMatricePoint(m,ab.feuilles.centre);
	return ab;
}

arbre mise_echelle_arbre(arbre ab, float x,float y, float z){
	int i,j;
	matrice m = genereS(x,y,z);

	for(i = 0; i<(int)(sizeof(ab.plans)/sizeof(ab.plans[0])); i++){
		for(j=0; j<4; j++){
			ab.plans[i].point[j] = multiplicationMatricePoint(m,ab.plans[i].point[j]);
		}
	}
	ab.centre = multiplicationMatricePoint(m,ab.centre);
	return ab;
}


arbre rotation_arbre(arbre ab,char axe, float angle){
	int i,j;
	matrice m;

	switch(axe){
		case 'x':
		m = genereRAutourX(angle);
		break;
		case 'y':
		m = genereRAutourY(angle);
		break;
		case 'z':
		m = genereRAutourZ(angle);
		break;
		default : 
		printf("Pas bon caractere pour rotation");
		exit(-1);
	}

	for(i = 0; i<(int)(sizeof(ab.plans)/sizeof(ab.plans[0])); i++){
		for(j=0; j<4; j++){
			ab.plans[i].point[j] = multiplicationMatricePoint(m,ab.plans[i].point[j]);
		}
	}

	ab.centre = multiplicationMatricePoint(m,ab.centre);
	ab.feuilles.centre = multiplicationMatricePoint(m,ab.feuilles.centre);
	return ab;
}