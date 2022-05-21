#include "mouvementsFormes.h"




//A faire avec les matrices gnagna
void translation_plateforme(plateforme plat, point po){
	int i,j;
	matrice m = genereT(po.d[0],po.d[1],po.d[2]);

	for(i = 0; i<(int)(sizeof(plat.plans)/sizeof(plat.plans[0])); i++){
		for(j=0; j<4; j++){
			plat.plans[i].point[j] = multiplicationMatricePoint(m,plat.plans[i].point[j]);
		}
	}

} 

void mise_echelle_plateforme(plateforme plat, float x,float y, float z){
	int i,j;
	matrice m = genereS(x,y,z);

	for(i = 0; i<(int)(sizeof(plat.plans)/sizeof(plat.plans[0])); i++){
		for(j=0; j<4; j++){
			plat.plans[i].point[j] = multiplicationMatricePoint(m,plat.plans[i].point[j]);
		}
	}

}


// void rotation_plateforme(plateforme plat, float angle){

// }




void translation_maison(maison mais,point po){
	int i,j;
	matrice m = genereT(po.d[0],po.d[1],po.d[2]);
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
} 

void mise_echelle_maison(maison mais, float x,float y, float z){
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
}

// void rotation_maison(maison p,float angle){

// }


