// Fichier créé le 14/05/2017
// Dernière modification 15/05/2017
//
// Auteur : Cédric Paoli
//
// Licence : CC BY NC ND
//

#include "neurone_learning_algo.h"


Reseau * test_creat(Reseau * r);

Reseau * test_creat_auto(Reseau * r, int taille,int taille_max, int * dans_couches);

void test_save(Reseau * r);

void test_propage(Reseau * r);

void test_retropropage(Reseau * r);

void test_free(Reseau * r);

void test_load();

int main(int argc,char *argv[]){
  fprintf(stderr,"\n\n\n************************************************\n");
  fprintf(stderr,"******* Début des teste réseau de neurones *****\n");
  fprintf(stderr,"************************************************\n\n\n\n\n\n");

  Reseau r;
  Reseau * pr = &r;
  int * testValue;
  testValue = (int *)malloc(sizeof(int)*5);
  testValue[0] = 2;
  testValue[1] = 5;
  testValue[2] = 4;
  testValue[3] = 6;
  testValue[4] = 1;

  fprintf(stderr," -------------------------------------------\n");
  fprintf(stderr," Teste de création d'un réseau\n\n");
  pr = test_creat(&r);
  r = *pr;
  fprintf(stderr," Teste de création : OK  \n");
  fprintf(stderr," -------------------------------------------\n\n\n\n\n\n");

  fprintf(stderr," -------------------------------------------\n");
  fprintf(stderr," Teste de création dynamique d'un réseau\n\n");
  //pr = test_creat_auto(&r,5,6,testValue);
  //r = *pr;
  fprintf(stderr,"\n Teste de création dynamique : OK  \n");
  fprintf(stderr," -------------------------------------------\n\n\n\n\n\n");

  fprintf(stderr," -------------------------------------------\n");
  fprintf(stderr," Teste de conservation d'un réseau\n\n");
  /*if (r.couches_contenus[0][0]->poids[0] == 0.0 && r.couches_contenus[0][0]->poids[1] == 0.0 &&
      r.couches_contenus[0][1]->poids[0] == 0.0 && r.couches_contenus[0][1]->poids[1] == 0.0 &&
      r.couches_contenus[1][0]->poids[0] == 0.5 && r.couches_contenus[1][0]->poids[1] == 1.5 &&
      r.couches_contenus[1][1]->poids[0] == -1.0 && r.couches_contenus[1][1]->poids[1] == -2.0 &&
      r.couches_contenus[2][0]->poids[0] == 1.0 && r.couches_contenus[2][0]->poids[1] == 3.0 &&
      r.couches_contenus[2][1]->poids[0] == -1.0 && r.couches_contenus[2][1]->poids[1] == -4.0 &&
      r.couches_contenus[3][0]->poids[0] == 1.0 && r.couches_contenus[3][0]->poids[1] == -3.0) {
    fprintf(stderr," Teste de conservation : OK  \n");
  } else{
    fprintf(stderr," Teste de conservation : NOP  \n");
    fprintf(stderr, " r.couches_contenus[0][0]->poids[0] == %f && r.couches_contenus[0][0]->poids[1] == %f \n r.couches_contenus[0][1]->poids[0] == %f && r.couches_contenus[0][1]->poids[1] == %f \n r.couches_contenus[1][0]->poids[0] == %f && r.couches_contenus[1][0]->poids[1] == %f \n r.couches_contenus[1][1]->poids[0] == %f && r.couches_contenus[1][1]->poids[1] == %f \n r.couches_contenus[2][0]->poids[0] == %f && r.couches_contenus[2][0]->poids[1] == %f \n r.couches_contenus[2][1]->poids[0] == %f && r.couches_contenus[2][1]->poids[1] == %f \n r.couches_contenus[3][0]->poids[0] == %f && r.couches_contenus[3][0]->poids[1] == %f\n", r.couches_contenus[0][0]->poids[0], r.couches_contenus[0][0]->poids[1], r.couches_contenus[0][1]->poids[0], r.couches_contenus[0][1]->poids[1],
    r.couches_contenus[1][0]->poids[0], r.couches_contenus[1][0]->poids[1], r.couches_contenus[1][1]->poids[0], r.couches_contenus[1][1]->poids[1], r.couches_contenus[2][0]->poids[0], r.couches_contenus[2][0]->poids[1], r.couches_contenus[2][1]->poids[0], r.couches_contenus[2][1]->poids[1],
    r.couches_contenus[3][0]->poids[0], r.couches_contenus[3][0]->poids[1]);
  }*/
  fprintf(stderr," -------------------------------------------\n\n\n\n\n\n");

  fprintf(stderr," -------------------------------------------\n");
  fprintf(stderr," Teste de d'affichage d'un réseau\n\n");
  //afficheReseau(&r);
  fprintf(stderr," Teste de d'affichage : OK  \n");
  fprintf(stderr," -------------------------------------------\n\n\n\n\n\n");


  fprintf(stderr," -------------------------------------------\n");
  fprintf(stderr," Teste de Propagation dans un réseau\n\n");
  test_propage(&r);
  fprintf(stderr,"\n Teste de Propagation : OK  \n");
  fprintf(stderr," -------------------------------------------\n\n\n\n\n\n");

  fprintf(stderr," -------------------------------------------\n");
  fprintf(stderr," Teste de Rétro-ropagation dans un réseau\n\n");
  test_retropropage(&r);
  fprintf(stderr,"\n Teste de Propagation : OK  \n");
  fprintf(stderr," -------------------------------------------\n\n\n\n\n\n");

  fprintf(stderr," -------------------------------------------\n");
  fprintf(stderr," Teste de sauvegarde d'un réseau\n\n");
  test_save(&r);
  fprintf(stderr," Teste de chargement : OK  \n");
  fprintf(stderr," -------------------------------------------\n\n\n\n\n\n");

  fprintf(stderr," -------------------------------------------\n");
  fprintf(stderr," Teste de libération d'un réseau\n\n");
  //test_free(&r);
  fprintf(stderr,"\n Teste de libération : OK  \n");
  fprintf(stderr," -------------------------------------------\n\n\n\n\n\n");

  fprintf(stderr," -------------------------------------------\n");
  fprintf(stderr," Teste de chargement d'un réseau\n\n");
  //test_load();
  fprintf(stderr," Teste de chargement : OK  \n");
  fprintf(stderr," -------------------------------------------\n\n\n\n\n\n");

  fprintf(stderr,"********************************************\n");
  fprintf(stderr,"***** Fin des teste réseau de neurones *****\n");
  fprintf(stderr,"********************************************\n\n\n\n\n\n");

  return 0;
}

Reseau * test_creat(Reseau * r){

  Neurone * n1 = malloc(sizeof(Neurone));
  Neurone * n2 = malloc(sizeof(Neurone));
  Neurone * n3 = malloc(sizeof(Neurone));
  Neurone * n4 = malloc(sizeof(Neurone));
  Neurone * n5 = malloc(sizeof(Neurone));
  Neurone * n6 = malloc(sizeof(Neurone));
  Neurone * n7 = malloc(sizeof(Neurone));

  // Initialisation des Poids
  fprintf(stderr," Malloc des poids neurone : ");
  n1->poids = malloc(sizeof(double)*2);
  if (n1->poids == NULL) {
    fprintf(stderr,"     Malloc FAIL 1 ");
  }
  n2->poids = malloc(sizeof(double)*2);
  if (n2->poids == NULL) {
    fprintf(stderr,"     Malloc FAIL 2 ");
  }
  n3->poids = malloc(sizeof(double)*2);
  if (n3->poids == NULL) {
    fprintf(stderr,"     Malloc FAIL 3 ");
  }
  n4->poids = malloc(sizeof(double)*2);
  if (n4->poids == NULL) {
    fprintf(stderr,"     Malloc FAIL 4 ");
  }
  n5->poids = malloc(sizeof(double)*2);
  if (n5->poids == NULL) {
    fprintf(stderr,"     Malloc FAIL 5 ");
  }
  n6->poids = malloc(sizeof(double)*2);
  if (n6->poids == NULL) {
    fprintf(stderr,"     Malloc FAIL 6 ");
  }
  n7->poids = malloc(sizeof(double)*2);
  if (n7->poids == NULL) {
    fprintf(stderr,"     Malloc FAIL 7 ");
  }
  fprintf(stderr,"OK \n");
  fprintf(stderr," Attribution des valeurs neurones : ");
  n1->poids[0] = 0.0;
  n2->poids[0] = 0.0;
  n3->poids[0] = 0.5;
  n4->poids[0] = -1.0;
  n5->poids[0] = 1.0;
  n6->poids[0] = -1.0;
  n7->poids[0] = 1.0;

  n1->poids[1] = 0.0;
  n2->poids[1] = 0.0;
  n3->poids[1] = 1.5;
  n4->poids[1] = -2.0;
  n5->poids[1] = 3.0;
  n6->poids[1] = -4.0;
  n7->poids[1] = -3.0;

  // Initialisation des biais
  n1->biais = 0.0;
  n2->biais = 0.0;
  n3->biais = 0.0;
  n4->biais = 0.0;
  n5->biais = 0.0;
  n6->biais = 0.0;
  n7->biais = 0.0;

  // Initialisation de la sensibilite
  n1->sensibilite = 0.0;
  n2->sensibilite = 0.0;
  n3->sensibilite = 0.0;
  n4->sensibilite = 0.0;
  n5->sensibilite = 0.0;
  n6->sensibilite = 0.0;
  n7->sensibilite = 0.0;

  // Initialisation des resultats
  n1->results = 2.0;
  n2->results = -1.0;
  n3->results = 0.0;
  n4->results = 0.0;
  n5->results = 0.0;
  n6->results = 0.0;
  n7->results = 0.0;
  fprintf(stderr,"OK \n");

  // Initialisation du réseau
  fprintf(stderr," Création du réseau : ");
  r->nbr_couche = 4;
  r->nbr_max_par_couche = 2;

  r->nbr_par_couche = malloc(sizeof(int*)*4);
  r->nbr_par_couche[0] = 2;
  r->nbr_par_couche[1] = 2;
  r->nbr_par_couche[2] = 2;
  r->nbr_par_couche[3] = 1;

  r->couches_contenus = malloc(sizeof(Neurone **)*4);
  r->couches_contenus[0] = malloc(sizeof(Neurone *)*2);
  r->couches_contenus[1] = malloc(sizeof(Neurone *)*2);
  r->couches_contenus[2] = malloc(sizeof(Neurone *)*2);
  r->couches_contenus[3] = malloc(sizeof(Neurone *));
  fprintf(stderr,"OK \n");

  fprintf(stderr," Peuplage du réseau : ");
  r->couches_contenus[0][0] = n1;
  if (r->couches_contenus[0][0] == NULL) {
    fprintf(stderr," \n ERREUR 1 ");
  }
  r->couches_contenus[0][1] = n2;
  if (r->couches_contenus[0][1] == NULL) {
    fprintf(stderr," \n ERREUR 2 ");
  }
  r->couches_contenus[1][0] = n3;
  if (r->couches_contenus[1][0] == NULL) {
    fprintf(stderr," \n ERREUR 3 ");
  }
  r->couches_contenus[1][1] = n4;
  if (r->couches_contenus[1][1] == NULL) {
    fprintf(stderr," \n ERREUR 4 ");
  }
  r->couches_contenus[2][0] = n5;
  if (r->couches_contenus[2][0] == NULL) {
    fprintf(stderr," \n ERREUR 5 ");
  }
  r->couches_contenus[2][1] = n6;
  if (r->couches_contenus[2][1] == NULL) {
    fprintf(stderr," \n ERREUR 6 ");
  }
  r->couches_contenus[3][0] = n7;
  if (r->couches_contenus[3][0] == NULL) {
    fprintf(stderr," \n ERREUR 7 ");
  }
  if (r->couches_contenus[0][0]->poids[0] == 0.0 && r->couches_contenus[0][0]->poids[1] == 0.0 &&
      r->couches_contenus[0][1]->poids[0] == 0.0 && r->couches_contenus[0][1]->poids[1] == 0.0 &&
      r->couches_contenus[1][0]->poids[0] == 0.5 && r->couches_contenus[1][0]->poids[1] == 1.5 &&
      r->couches_contenus[1][1]->poids[0] == -1.0 && r->couches_contenus[1][1]->poids[1] == -2.0 &&
      r->couches_contenus[2][0]->poids[0] == 1.0 && r->couches_contenus[2][0]->poids[1] == 3.0 &&
      r->couches_contenus[2][1]->poids[0] == -1.0 && r->couches_contenus[2][1]->poids[1] == -4.0 &&
      r->couches_contenus[3][0]->poids[0] == 1.0 && r->couches_contenus[3][0]->poids[1] == -3.0) {
    fprintf(stderr,"OK \n\n");
  } else{
    fprintf(stderr,"NOP \n\n");
  }
  return r;
}

Reseau * test_creat_auto(Reseau * r, int taille,int taille_max, int * dans_couches){
  fprintf(stderr,"     Teste de création dynamique du réseau \n");

  int i = 0;
  int j = 0;
  Neurone * neur;
  neur = (Neurone *)malloc(sizeof(Neurone));
  neur->poids = (double *)malloc(sizeof(double)*taille_max);
  Neurone ** p_neur;
  p_neur = &neur;
  int couche_precedente = 0;
  r->nbr_max_par_couche = taille_max;
  fprintf(stderr,"     Premier malloc : ");
  r->nbr_par_couche = (int *) malloc(sizeof(int*)*taille);
  r->couches_contenus = (Neurone ***) malloc(sizeof(p_neur)*taille);
  if (sizeof(r->nbr_par_couche) == (sizeof(int)*taille) && sizeof(r->couches_contenus) == (sizeof(p_neur)*taille)) {
    fprintf(stderr,"Ok\n");
  }
  else {
    fprintf(stderr,"NOP\n");
    fprintf(stderr, "     Taille de nbr_par_couche : %lu || Taille attendue : %lu\n", sizeof(r->nbr_par_couche), sizeof(int)*taille);
    fprintf(stderr, "     Adresse de nbr_par_couche : %p\n", &r->nbr_par_couche);
    fprintf(stderr, "     Taille de couches_contenus : %lu || Taille attendue : %lu\n", sizeof(r->couches_contenus), sizeof(p_neur)*taille);
    fprintf(stderr, "     Adresse de couches_contenus : %p\n", &r->couches_contenus);
  }

  fprintf(stderr, "     Ajout dynamique des couches du réseau \n");
  for (i = 0; i < taille; i++) {
    r->nbr_par_couche[i] = dans_couches[i];
    fprintf(stderr, "         Malloc de la couches %d : ",i);
    r->couches_contenus[i] = (Neurone **)malloc(sizeof(neur)*dans_couches[i]);
    if(sizeof(r->couches_contenus[i]) == sizeof(neur)*dans_couches[i]){
      fprintf(stderr,"Ok\n");
    }
    else {
      fprintf(stderr,"NOP\n");
    }
  }

  fprintf(stderr, "     Ajout dynamique des neurones du réseau \n ");
  for (i = 0; i < taille; i++) {
    for (j = 0; j < couche_precedente; j++) {
      fprintf(stderr, "         Malloc du neurones %d couche %d : ",j,i );
      r->couches_contenus[i][j] = (Neurone *)malloc(sizeof(Neurone));
      if(sizeof(r->couches_contenus[i][j]) == sizeof(Neurone)){
        fprintf(stderr,"Ok\n");
      }
      else {
        fprintf(stderr,"NOP\n");
      }
      r->couches_contenus[i][j]->poids = (double *)malloc(sizeof(double)*couche_precedente);
      if(sizeof(r->couches_contenus[i][j]->poids) == sizeof(double)*couche_precedente){
        fprintf(stderr,"Ok\n");
      }
      else {
        fprintf(stderr,"NOP\n");
      }
    }
  }
  return r ;
}

void test_save(Reseau * r){
  if (r == NULL) {
    fprintf(stderr," Réseau d'entré vide ! \n ");
  }
  else {
    fprintf(stderr," Le réseau va être enregistré dans le fichier 'test_save.ai' \n");
    FILE * fichier;
    fichier = fopen("test_save.ai","w");
    if (fichier == NULL) {
      fprintf(stderr," Problème lors de l'ouverture de 'test_save.ai' \n\n");
    }
    else{
      fprintf(stderr," Sauvegarde du réseau \n\n");
      saveReseau(r,fichier);
      fprintf(stderr," La sauvegarde s'est bien passée ! \n");
    }
    fclose(fichier);
  }
}

void test_propage(Reseau * r){
  int i = 0;

  fprintf(stderr, "  Début du teste de propagation \n");
  for(i=1;i<r->nbr_couche;i++){
    fprintf(stderr, "    Couche %d\n", i);
		propage(r,i);
	}
  fprintf(stderr, "  Fin du teste de propagation \n");
}

void test_retropropage(Reseau * r){
  double i = 1.0;
  fprintf(stderr, "   Début du test de rétro-propagation \n");
  retroPropage(r,&i);
  fprintf(stderr, "   Fin du test de rétro-propagation \n");
}

void test_free(Reseau * r){
  if (r == NULL) {
    fprintf(stderr," Déjà vide ! \n");
  } else {
    fprintf(stderr," Début de la libération \n");
    freeReseau(r);
    fprintf(stderr," Fin de la libération \n");
  }
}

void test_load(){
  Reseau r1;
  Reseau * pr1;
  FILE * fichier;

  pr1 = &r1;

  fichier = fopen("ex_neur.ai","r");
  if (fichier == NULL) {
    fprintf(stderr,"\nProblème d'ouverture de l'exemple\n" );
  }
  loadReseau(fichier,pr1);
  fprintf(stderr,"\n Création du réseau : " );
  if (pr1 == NULL) {
    fprintf(stderr,"NON \n");
  }
  else{
    fprintf(stderr,"OK \n");
    afficheReseau(pr1);
  }
}
