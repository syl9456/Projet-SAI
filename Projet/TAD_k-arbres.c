#include"TAD_k-arbres.h"


karbre kArbreNull(){
  return NULL;
}

karbre kArbreVide(cube c){
  karbre A = kConsArbre(VIDE,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
  A->c = c;
  return A;
}

karbre kArbrePlein(cube c){
  karbre A = kConsArbre(PLEIN,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
  A->c = c;
  return A;
}


cube kCube(karbre A){
  return A->c;
}


int estVide(karbre A){
  if(A->etat == VIDE){
    return TRUE;
  }
  else return FALSE;
}


int estPlein(karbre A){
  if(A->etat == PLEIN){
    return TRUE;
  }
  return FALSE;
}




karbre kConsArbre(element e, ...){
  karbre A = kArbreNull();
  A = (karbre)malloc(1*sizeof(noeud));
  
  va_list params; //pointeur de la liste de parametres
  va_start(params,e); //initialise le pointeur avec le dernier parametre fixe
  
  A->etat = e;
  
  for(int i = 0; i<K; i++){
    A->fils[i] = va_arg(params,karbre);
  }
  va_end(params);

  return A;
}




karbre kFils(int ieme, karbre A){
  if(ieme > K || ieme < 0){
    printf("ieme trop grand ou trop petit");
    return NULL;

  }
  return A->fils[ieme];
}




element kRacine(karbre A){
  return A->etat;
}




void afficheKArbre_bis(karbre A,int prof){
  int i;

  if (A == NULL) return;
  for (i=0; i<=prof; i++) {
    printf("|");
  }

  switch(A->etat){
    case PLEIN:
    printf("PLEIN");
    break;

    case VIDE:
    printf("VIDE");
    break;

    case COMPLEXE:
    printf("COMPLEXE");
    break;

    default:
    printf("OULALALA");
    break;
  }
  
  printf("\n");
  for(int i=0; i<K; i++){
    afficheKArbre_bis(A->fils[i],prof+1);
  }
}


void afficheKArbre(karbre A){
  afficheKArbre_bis(A,0);
  printf("\n\n\n\n");
}
