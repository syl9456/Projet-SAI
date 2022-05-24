#include"cube.h"




int cubeDansObjet(cube cBase, cube cObjet){
	//On regarde si le cubeObjet englobe en entier le cubeBase
    
	//SI pas dans le cube, les problemes commencent...
	//else{
    if(   (cBase.s1.x >= cObjet.s1.x &&
           cBase.s2.x <= cObjet.s2.x)&&
          (cBase.s1.y >= cObjet.s1.y &&
           cBase.s2.y <= cObjet.s2.y)&&
          (cBase.s1.z >= cObjet.s1.z &&
           cBase.s2.z <= cObjet.s2.z)){
        
        return TRUE;
    }
	
	return FALSE;
}


int objetPasDansCube(cube cBase, cube cObjet){
	// On test si les 8 sommets du cube sont en dehors du cube
    //On a de la chance ici d'avoir chercher tout les sommets les plus loins et plus pres de l'origine dans les collisions.
    //Cela fait que les calculs ici sont simples
    if( !((cBase.s1.x <= cObjet.s1.x &&
           cBase.s2.x >= cObjet.s2.x)&&
          (cBase.s1.y <= cObjet.s1.y &&
           cBase.s2.y >= cObjet.s2.y)&&
          (cBase.s1.z <= cObjet.s1.z &&
           cBase.s2.z >= cObjet.s2.z))){
        return TRUE;
    }
	return FALSE;
}


karbre copie(karbre A){

    if(estVide(A)){
        return kArbreVide(A->c);
    }
    if(estPlein(A)){
        return kArbrePlein(A->c);
    }

    return kConsArbre(COMPLEXE, copie(A->fils[0]), 
                                copie(A->fils[1]),
                                copie(A->fils[2]),
                                copie(A->fils[3]),
                                copie(A->fils[4]),
                                copie(A->fils[5]),
                                copie(A->fils[6]),
                                copie(A->fils[7])
                                );
}



karbre intersection(karbre A1, karbre A2){

    if(estVide(A1) || estVide(A2)){
        return kArbreVide(A1->c);
    }

    if(estPlein(A1)){
        return copie(A1);
    }
    if(estPlein(A2)){
        return copie(A2);
    }

    return kConsArbre(COMPLEXE, intersection(A1->fils[0], A2->fils[0]),
                                intersection(A1->fils[1], A2->fils[1]),
                                intersection(A1->fils[2], A2->fils[2]),
                                intersection(A1->fils[3], A2->fils[3]),
                                intersection(A1->fils[4], A2->fils[4]),
                                intersection(A1->fils[5], A2->fils[5]),
                                intersection(A1->fils[6], A2->fils[6]),
                                intersection(A1->fils[7], A2->fils[7])
                                );
}




karbre objet2arbre_bis(cube cObjet, cube cBase, int prof){
    cube c1,c2,c3,c4,c5,c6,c7,c8;



    if(cubeDansObjet(cBase, cObjet)){
        return kArbrePlein(cBase);
    }
    if(objetPasDansCube(cBase, cObjet)){
        return kArbreVide(cBase);
    }
    if(prof == PROFONDEUR_MAX){
    	return kArbreVide(cBase);
    }


    /* CUBE 1 */
    c1.s1.x = cBase.s1.x;
    c1.s1.y = (cBase.s1.y + cBase.s2.y) / 2;
    c1.s1.z = cBase.s1.z;

    c1.s2.x = (cBase.s1.x + cBase.s2.x) / 2;
    c1.s2.y = cBase.s2.y;
    c1.s2.z = (cBase.s1.z + cBase.s2.z) / 2;

    /* CUBE 2 */
    c2.s1.x = (cBase.s1.x + cBase.s2.x) / 2;
    c2.s1.y = (cBase.s1.y + cBase.s2.y) / 2;
    c2.s1.z = cBase.s1.z;

    c2.s2.x = cBase.s2.x;
    c2.s2.y = cBase.s2.y;
    c2.s2.z = (cBase.s1.z + cBase.s2.z) / 2;

    /* CUBE 3 */
    c3.s1.x = (cBase.s1.x + cBase.s2.x) / 2;
    c3.s1.y = cBase.s1.y;
    c3.s1.z = cBase.s1.z;

    c3.s2.x = cBase.s2.x;
    c3.s2.y = (cBase.s1.y + cBase.s2.y) / 2;
    c3.s2.z = (cBase.s1.z + cBase.s2.z) / 2;

    /* CUBE 4 */
    c4.s1.x = cBase.s1.x;
    c4.s1.y = cBase.s1.y;
    c4.s1.z = cBase.s1.z;

    c4.s2.x = (cBase.s1.x + cBase.s2.x) / 2;
    c4.s2.y = (cBase.s1.y + cBase.s2.y) / 2;
    c4.s2.z = (cBase.s1.z + cBase.s2.z) / 2;

    /* CUBE 5 */
    c5.s1.x = cBase.s1.x;
    c5.s1.y = (cBase.s1.y + cBase.s2.y) / 2;
    c5.s1.z = (cBase.s1.z + cBase.s2.z) / 2;

    c5.s2.x = (cBase.s1.x + cBase.s2.x) / 2;
    c5.s2.y = cBase.s2.y;
    c5.s2.z = cBase.s2.z;

    /* CUBE 6 */
    c6.s1.x = (cBase.s1.x + cBase.s2.x) / 2;
    c6.s1.y = (cBase.s1.y + cBase.s2.y) / 2;
    c6.s1.z = (cBase.s1.z + cBase.s2.z) / 2;

    c6.s2.x = cBase.s2.x;
    c6.s2.y = cBase.s2.y;
    c6.s2.z = cBase.s2.z;

    /* CUBE 7 */
    c7.s1.x = (cBase.s1.x + cBase.s2.x) / 2;
    c7.s1.y = cBase.s1.y;
    c7.s1.z = (cBase.s1.z + cBase.s2.z) / 2;

    c7.s2.x = cBase.s2.x;
    c7.s2.y = (cBase.s1.y + cBase.s2.y) / 2;
    c7.s2.z = cBase.s2.z;

    /* CUBE 8 */
    c8.s1.x = cBase.s1.x;
    c8.s1.y = cBase.s1.y;
    c8.s1.z = (cBase.s1.z + cBase.s2.z) / 2;

    c8.s2.x = (cBase.s1.x + cBase.s2.x) / 2;
    c8.s2.y = (cBase.s1.y + cBase.s2.y) / 2;
    c8.s2.z = cBase.s2.z;


    return kConsArbre(COMPLEXE,
                                objet2arbre_bis(cObjet, c1, prof+1),
                      		    objet2arbre_bis(cObjet, c2, prof+1),
                      	        objet2arbre_bis(cObjet, c3, prof+1),
                      		    objet2arbre_bis(cObjet, c4, prof+1),
                      	       	objet2arbre_bis(cObjet, c5, prof+1),
                                objet2arbre_bis(cObjet, c6, prof+1),
                                objet2arbre_bis(cObjet, c7, prof+1),
                                objet2arbre_bis(cObjet, c8, prof+1));
}



karbre objet2arbre(point p1Objet, point p2Objet){
    int prof = 1;
    
    cube cBase,c1,c2,c3,c4,c5,c6,c7,c8;
    cube cObjet;

    cBase.s1.x = CBASES1X;
    cBase.s1.y = CBASES1Y;
    cBase.s1.z = CBASES1Z;
    cBase.s2.x = CBASES2X;
    cBase.s2.y = CBASES2Y;
    cBase.s2.z = CBASES2Z;

    cObjet.s1.x = p1Objet.d[0];
    cObjet.s1.y = p1Objet.d[1];
    cObjet.s1.z = p1Objet.d[2];
    cObjet.s2.x = p2Objet.d[0];
    cObjet.s2.y = p2Objet.d[1];
    cObjet.s2.z = p2Objet.d[2];


    if(cubeDansObjet(cBase, cObjet)){
        return kArbrePlein(cBase);
    }
    if(objetPasDansCube(cBase, cObjet)){
        return kArbreVide(cBase);
    }


    /* CUBE 1 */
    c1.s1.x = cBase.s1.x; 
    c1.s1.y = (cBase.s1.y + cBase.s2.y) / 2;
    c1.s1.z = cBase.s1.z;

    c1.s2.x = (cBase.s1.x + cBase.s2.x) / 2;
    c1.s2.y = cBase.s2.y;
    c1.s2.z = (cBase.s1.z + cBase.s2.z) / 2;

    /* CUBE 2 */
    c2.s1.x = (cBase.s1.x + cBase.s2.x) / 2;
    c2.s1.y = (cBase.s1.y + cBase.s2.y) / 2;
    c2.s1.z = cBase.s1.z;

    c2.s2.x = cBase.s2.x;
    c2.s2.y = cBase.s2.y;
    c2.s2.z = (cBase.s1.z + cBase.s2.z) / 2;

    /* CUBE 3 */
    c3.s1.x = (cBase.s1.x + cBase.s2.x) / 2;
    c3.s1.y = cBase.s1.y;
    c3.s1.z = cBase.s1.z;

    c3.s2.x = cBase.s2.x;
    c3.s2.y = (cBase.s1.y + cBase.s2.y) / 2;
    c3.s2.z = (cBase.s1.z + cBase.s2.z) / 2;

    /* CUBE 4 */
    c4.s1.x = cBase.s1.x;
    c4.s1.y = cBase.s1.y;
    c4.s1.z = cBase.s1.z;

    c4.s2.x = (cBase.s1.x + cBase.s2.x) / 2;
    c4.s2.y = (cBase.s1.y + cBase.s2.y) / 2;
    c4.s2.z = (cBase.s1.z + cBase.s2.z) / 2;

    /* CUBE 5 */
    c5.s1.x = cBase.s1.x;
    c5.s1.y = (cBase.s1.y + cBase.s2.y) / 2;
    c5.s1.z = (cBase.s1.z + cBase.s2.z) / 2;

    c5.s2.x = (cBase.s1.x + cBase.s2.x) / 2;
    c5.s2.y = cBase.s2.y;
    c5.s2.z = cBase.s2.z;

    /* CUBE 6 */
    c6.s1.x = (cBase.s1.x + cBase.s2.x) / 2;
    c6.s1.y = (cBase.s1.y + cBase.s2.y) / 2;
    c6.s1.z = (cBase.s1.z + cBase.s2.z) / 2;

    c6.s2.x = cBase.s2.x;
    c6.s2.y = cBase.s2.y;
    c6.s2.z = cBase.s2.z;

    /* CUBE 7 */
    c7.s1.x = (cBase.s1.x + cBase.s2.x) / 2;
    c7.s1.y = cBase.s1.y;
    c7.s1.z = (cBase.s1.z + cBase.s2.z) / 2;

    c7.s2.x = cBase.s2.x;
    c7.s2.y = (cBase.s1.y + cBase.s2.y) / 2;
    c7.s2.z = cBase.s2.z;

    /* CUBE 8 */
    c8.s1.x = cBase.s1.x;
    c8.s1.y = cBase.s1.y;
    c8.s1.z = (cBase.s1.z + cBase.s2.z) / 2;

    c8.s2.x = (cBase.s1.x + cBase.s2.x) / 2;
    c8.s2.y = (cBase.s1.y + cBase.s2.y) / 2;
    c8.s2.z = cBase.s2.z;


    return kConsArbre(COMPLEXE, objet2arbre_bis(cObjet, c1, prof+1),
                      			objet2arbre_bis(cObjet, c2, prof+1),
                      			objet2arbre_bis(cObjet, c3, prof+1),
                      			objet2arbre_bis(cObjet, c4, prof+1),
                      			objet2arbre_bis(cObjet, c5, prof+1),
                     			objet2arbre_bis(cObjet, c6, prof+1),
                      			objet2arbre_bis(cObjet, c7, prof+1),
                      			objet2arbre_bis(cObjet, c8, prof+1)
                      			);
}
