// Fichier créé le 10/03/2017
// Dernière modification 15/05/2017
//
// Auteur : Cédric Paoli
//
// Licence : CC BY NC ND
//

#include "neurone_init.h"

// ****************************************************************************************
// ** Definition de la fonction initialisant des paramètres aléatoires pour les neurones **
// ****************************************************************************************

void initNeurone(Neurone * neur,int n_couche, int nm1_couche){
  int i = 0;

  // On initialise l'aléatoire
  srand(time(NULL));

  if(n_couche==0){
    neur->results = rand()/(double)RAND_MAX;
  } else {
    for(i=0;i<nm1_couche;i++){
      neur->poids[i] = rand()/(double)RAND_MAX;
    }
    neur->biais = rand()/(double)RAND_MAX;
    neur->sensibilite = rand()/(double)RAND_MAX;
    neur->results = rand()/(double)RAND_MAX;
  }
}

// ***************************************************************************************************
// ** Definition de la fonction initialisant des paramètres aléatoires pour les couches de neurones **
// ***************************************************************************************************

void initCouche(Neurone ** tab, int n_couche, int nm1_couche){
  int i = 0;
  for(i=0;i<n_couche;i++){
    initNeurone(tab[i],n_couche,nm1_couche);
  }
}

// *************************************************************************************************
// ** Definition de la fonction initialisant des paramètres aléatoires pour le réseau de neurones **
// *************************************************************************************************

Reseau * initReseau(Reseau * r){
  int i = 0;
  initCouche(r->couches_contenus[i],r->nbr_par_couche[0],r->nbr_par_couche[0]);
  for(i=1;i<r->nbr_couche;i++){
    initCouche(r->couches_contenus[i],r->nbr_par_couche[i],r->nbr_par_couche[i-1]);
  }
  return r;
}

// ****************************************************************************
// ** Definition de la fonction decréation du réseau de neurones par default **
// ****************************************************************************

Reseau * defaultNeuralCreation (){
  Reseau * r;

  int i = 0;
  int j = 0;
  int k = 0;

  r->nbr_couche = NBR_DE_COUCHE;
  r->nbr_max_par_couche = NBR_MAX_PAR_COUCHE;
  r->nbr_par_couche = malloc(sizeof(int)*r->nbr_couche);
  r->couches_contenus = malloc(sizeof(Neurone)*r->nbr_couche);

  // On initialise l'aléatoire
  srand(time(NULL));

  for (i = 0; i < r->nbr_couche; i++) {
    r->nbr_par_couche[i] = NBR_MAX_PAR_COUCHE;
    r->couches_contenus[i] = malloc(sizeof(Neurone)*r->nbr_par_couche[i]);
    for (j = 0; j < r->nbr_par_couche[i]; j++) {
      Neurone neur;
      neur.poids = malloc(sizeof(double)*r->nbr_par_couche[i]);
      for (k = 0; k < r->nbr_par_couche[i]; k++) {
        neur.poids[i] = rand()/(double)RAND_MAX;
      }
      neur.biais = rand()/(double)RAND_MAX;
      neur.results = rand()/(double)RAND_MAX;
      neur.sensibilite = rand()/(double)RAND_MAX;
      r->couches_contenus[i][j] = &neur;
    }
  }
  return r;
}

// ********************************************************************************
// ** Definition de la fonction sauvegardant une couche du le réseau de neurones **
// **       Une couche est sauvegardée sur une ligne neurones par neurones       **
// ********************************************************************************


void saveNeuroneCouche(Neurone ** couche, int couche_actuelle, int couche_precedente, FILE * fichier){

  int i = 0;
  int j = 0;

  for(i=0;i<couche_actuelle;i++){
    fprintf(stderr,"\n     - neurone %d : \n",i);
    fprintf(stderr,"       - poids : \n");
    for(j=0;j<couche_precedente;j++){
      fprintf(stderr,"           - %d : ",j);
      fprintf(fichier, "%f ",couche[i]->poids[j] );
      fprintf(stderr,"OK \n");
    }
    fprintf(stderr,"       - biais : ");
    fprintf(fichier, "%f ",couche[i]->biais );
    fprintf(stderr,"OK \n");
    fprintf(stderr,"       - sensibilité : ");
    fprintf(fichier, "%f ",couche[i]->sensibilite );
    fprintf(stderr,"OK \n");
    fprintf(stderr,"       - resultat : ");
    fprintf(fichier, "%f ",couche[i]->results );
    fprintf(stderr,"OK \n");
    fprintf(stderr,"       - retour ligne : ");
    fprintf(fichier, "\n");
  }
  fprintf(stderr,"OK \n");

}

// ***********************************************************************
// ** Definition de la fonction sauvegardant tout le réseau de neurones **
// **        Les paramètres du réseau sont en première ligne            **
// ***********************************************************************


void saveReseau(Reseau * r, FILE * fichier){
  fprintf(stderr,"******************************************\n");
  fprintf(stderr,"****** Fonction saveReseau begining ******\n");
  fprintf(stderr,"******************************************\n\n");
  if (fichier == NULL) {
    fichier = fopen("neural.ai","w");
  }
  if(fichier != NULL){
    int i = 1;
    fprintf(stderr," Ecriture des paramètre réseau : \n");
    // Sauvegarde du nombre de couche
    fprintf(fichier, "%d ", r->nbr_couche);
    fprintf(stderr,"   - Nombre de couches : OK \n");

    // Sauvegarde du nombre max de neurones sur une couche
    fprintf(fichier, "%d ", r->nbr_max_par_couche);
    fprintf(stderr,"   - Nombre max par couches : OK \n");

    fprintf(stderr,"   - Nombre de neur/couches : ");
    // Sauvegarde du nombre de neurones sur chaque couche
    for (i = 0; i < r->nbr_couche; i++) {
      fprintf(fichier, "%d ", r->nbr_par_couche[i]);
    }
    // Retour à la ligne
    fprintf(fichier, "\n");
    fprintf(stderr,"OK \n\n");

    fprintf(stderr," Ecriture des couches :\n");
    fprintf(stderr,"\n   <> couches 0 : ");
    // La première couche est sauvegardée (les poids précédent à prendre en compte)
    saveNeuroneCouche(r->couches_contenus[0],r->nbr_par_couche[0],r->nbr_par_couche[0],fichier);

    // Sauvegarde des autres couches du réseau
    for(i=1;i<NBR_DE_COUCHE;i++){
      fprintf(stderr,"\n   <> couche %d : ",i);
      saveNeuroneCouche(r->couches_contenus[i],r->nbr_par_couche[i],r->nbr_par_couche[i-1],fichier);

    }
    fprintf(fichier, "\n");
  }
}

// *********************************
// ** Affiche en consol un réseau **
// *********************************

void afficheReseau(Reseau * r){
  int i,j,k;
  int couche_precedente = 0;
  fprintf(stderr, "     Paramètre du réseau :\n");
  fprintf(stderr, "          - Nombre de couche : %d\n", r->nbr_couche);
  fprintf(stderr, "          - Nombre max par couche : %d\n", r->nbr_max_par_couche);
  fprintf(stderr, "     Le réseau contient :\n");
  for (i = 0; i < r->nbr_couche; i++) {
    fprintf(stderr, "         Taille couche %d :\n", r->nbr_par_couche[i]);
    fprintf(stderr, "         Dans la couche %d :\n", i);
    for (j = 0; j < r->nbr_par_couche[i]; j++) {
      fprintf(stderr, "             - Le neurones %d à pour paramètres : \n", j);
      fprintf(stderr, "                 - Poids : [ ");
      double * teste = r->couches_contenus[i][j]->poids;
      for (k = 0; k < r->nbr_par_couche[couche_precedente]; k++) {
        fprintf(stderr, "%f, ", r->couches_contenus[i][j]->poids[k]);
      }
      fprintf(stderr, "]\n");
      fprintf(stderr, "                 - Biais : %f\n", r->couches_contenus[i][j]->biais);
      fprintf(stderr, "                 - Sensibilité : %f \n", r->couches_contenus[i][j]->sensibilite);
      fprintf(stderr, "                 - Résultat : %f \n",r->couches_contenus[i][j]->results);

    }
  }

}

// ********************************************************************
// ** Definition de la fonction chargeant tout le réseau de neurones **
// **           Crée de réseau qui est stocké dand le tas            **
// ********************************************************************

void loadReseau(FILE * fichier, Reseau * r){
  fprintf(stderr,"******************************************\n");
  fprintf(stderr,"****** Fonction loadReseau begining ******\n");
  fprintf(stderr,"******************************************\n\n");
  fprintf(stderr," Initialisation des variable : ");
  char cleaner[25];
  double param;
  double val1;
  int couches,max_couche,val;
  int i, j, k, couche_precedente;
  fprintf(stderr,"OK\n\n");
  fprintf(stderr," Lecture dans le fichier : ");
  // Lecture du nombre max de couches du réseau chargé
  // Lecture du nombre max de neurones présent sur une couche
  fscanf(fichier, "%d %d", &couches, &max_couche);
  fprintf(stderr,"OK \n\n");
  fprintf(stderr," Nombre de couches : %d \n\n",couches);
  fprintf(stderr," Nombre max par couche : %d\n\n", max_couche);
  fprintf(stderr," Première vague d'Initialisation et de malloc : ");
  // Initialisation des valeurs constante et taille des tableau
  r->nbr_couche = couches;
  r->nbr_max_par_couche = max_couche;
  Neurone neurone;
  neurone.poids = (double *) malloc(sizeof(double)*max_couche);
  Neurone * ptr_neurone = &neurone;
  Neurone ** ptr_ptr_neurone = &ptr_neurone;
  r->nbr_par_couche = (int *) malloc(sizeof(int)*couches);
  r->couches_contenus = (Neurone ***) malloc(sizeof(&ptr_ptr_neurone)*couches);
  fprintf(stderr,"OK \n\n");



  fprintf(stderr,"--------------------------------------------------\n");
  fprintf(stderr," Début première boucle d'Initialisation et malloc \n\n");
  // Chargement du nobre de neurones dans chaque couche
  // Initialisation des tableau de couches_contenus
  for (i = 0; i < couches; i++) {
    fprintf(stderr," Lecture %d ans le fichier : ",i);
    fscanf(fichier, "%d ", &val);
    fprintf(stderr,"OK \n");
    fprintf(stderr," Initialisation %d des variables et malloc: ",i);
    r->nbr_par_couche[i] = val;
    r->couches_contenus[i] = (Neurone **) malloc(sizeof(&ptr_neurone)*val);
    fprintf(stderr,"OK \n");
  }
  fprintf(stderr,"\n Première boucle d'Initialisation et malloc : OK \n");
  fprintf(stderr,"--------------------------------------------------\n\n");
  //fprintf(stderr," Elimination du caractère de fin de ligne : ");
  // Elimination du caractère '\n' de fin de ligne
  //fgets(cleaner, 255, (FILE*)fichier);
  //fprintf(stderr,"OK \n\n");
  // Initialisation pour la boucle de chargement des poids
  couche_precedente = r->nbr_par_couche[0];
  // Chargement du contenu des couches
  fprintf(stderr,"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
  fprintf(stderr," Début de la boucle d'Initialisation des couches \n\n");
  for (i = 0; i < couches; i++) {
    // Chargement des Neurones
    fprintf(stderr,"    --------------------------------------------------------------------\n");
    fprintf(stderr,"        Début de la boucle d'Initialisation des neurones couche %d \n\n",i);
    for (j = 0; j < r->nbr_par_couche[i]; j++) {
      // Chargement des paramètres des neurones
      // Initialisation tableau des poids en fonction du nombre de neurones
      // de la couche_precedente
      fprintf(stderr,"        Malloc des poids du neurone %d couche %d : ",j,i);
      r->couches_contenus[i][j] = (Neurone *) malloc(sizeof(&neurone));
      fprintf(stderr, " Taille de la nouvelle couche : %d \n", couche_precedente);
      r->couches_contenus[i][j]->poids = (double *) malloc(sizeof(double) * couche_precedente);

      if (r->couches_contenus[i][j]->poids == NULL ) {
        fprintf(stderr, "CA BUG LE MALLOC \n" );
      }

      fprintf(stderr, "%lf CA BUG PAS LA\n",  r->couches_contenus[i][j]->poids[3]);

      for (k = 0; k < couche_precedente; k++) {
        r->couches_contenus[i][j]->poids[k] = 0.00000;
        fprintf(stderr, "Initialisation: %lf\n", r->couches_contenus[i][j]->poids[k] );
      }
      fprintf(stderr, "OK\n");
      fprintf(stderr,"        ----------------------------------------------------------------------\n");
      fprintf(stderr,"            Début de la boucle d'Initialisation du Poids du neurones %d couche %d \n\n",j,i);
      for (k = 0; k < couche_precedente; k++) {
        double a;
        fprintf(stderr,"                Lecture et affectation  : ");
        fscanf(fichier, "%lf ", &a);
        fprintf(stderr, "a a bien ete lue \n");
        //r->couches_contenus[i][j]->poids[k] = a;
        //fprintf(stderr,"                r->couches_contenus[i][j]->poids[k] = %lf \n ",r->couches_contenus[i][j]->poids[k]);
        //fprintf(stderr,"OK \n");
        //fprintf(stderr,"               IN BOUCLE r->couches_contenus[i][j]->poids[0] = %lf \n ",r->couches_contenus[i][j]->poids[0]);

      }
      fprintf(stderr,"               OUT BOUCLE r->couches_contenus[i][j]->poids[0] = %lf \n ",r->couches_contenus[i][j]->poids[0]);
      fprintf(stderr,"\n            Boucle d'Initialisation de Poids du neurones %d : OK \n",i);
      fprintf(stderr,"        ----------------------------------------------------------------------\n\n");
      fprintf(stderr,"                Lecture et affectation  : ");
      fprintf(stderr, " TEST 1\n" );
      fprintf(stderr,"                r->couches_contenus[i][j]->poids[0] = %lf \n ",r->couches_contenus[i][j]->poids[0]);
      // Chargement du biais
      fscanf(fichier, "%lf ", &r->couches_contenus[i][j]->biais);

      fprintf(stderr, "  r->couches_contenus[i][j]->biais = %lf adresse : %p\n",r->couches_contenus[i][j]->biais,&r->couches_contenus[i][j]->biais);
      fprintf(stderr,"                r->couches_contenus[i][j]->poids[0] = %lf \n ",r->couches_contenus[i][j]->poids[0]);

      // Chargement du résultat
      fscanf(fichier, "%lf ", &r->couches_contenus[i][j]->results);

      fprintf(stderr, "  r->couches_contenus[i][j]->results = %lf adresse : %p\n",r->couches_contenus[i][j]->results, &r->couches_contenus[i][j]->results);
      fprintf(stderr,"                r->couches_contenus[i][j]->poids[0] = %lf adresse : %p\n ",r->couches_contenus[i][j]->poids[0],&r->couches_contenus[i][j]->poids[0]);

      // Chargement de la sensibilité
      fscanf(fichier, "%lf ", &r->couches_contenus[i][j]->sensibilite);

      fprintf(stderr, "  r->couches_contenus[i][j]->sensibilite = %lf, adresse : %p\n",r->couches_contenus[i][j]->sensibilite,&r->couches_contenus[i][j]->sensibilite);
      fprintf(stderr,"                r->couches_contenus[i][j]->poids[0] = %lf adresse : %p\n ",r->couches_contenus[i][j]->poids[0],&r->couches_contenus[i][j]->poids[0]);

      fprintf(stderr,"OK\n\n");

      //fprintf(stderr,"                Elimination du caractère de fin de ligne : ");
      // Elimination du caractère '\n' de fin de ligne
      //fgets(cleaner, 255, (FILE*)fichier);
      //fprintf(stderr,"OK\n\n");
    }
    fprintf(stderr,"            Boucle d'Initialisation du neurones %d couche %d : OK \n",j,i);
    fprintf(stderr,"        ----------------------------------------------------------------\n\n");
    // MAJ pour la boucle suivante
    couche_precedente = r->nbr_par_couche[i];

    fprintf(stderr,"        Fin de la boucle d'Initialisation des neurones couche %d \n\n",i);
    fprintf(stderr,"    --------------------------------------------------------------------\n\n");

  }

  fprintf(stderr," Boucle d'Initialisation des couches : OK\n");
  fprintf(stderr,"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");

  fprintf(stderr, " TEST VAL %lf\n",r->couches_contenus[1][1]->poids[1]);

  afficheReseau(r);
  fprintf(stderr,"\n\n******************************************\n");
  fprintf(stderr,"******** Fonction loadReseau END *********\n");
  fprintf(stderr,"******************************************\n\n");

}

// *******************************************************
// ** Definition de la fonction libération d'un neurone **
// *******************************************************

void freeNeurone (Neurone * n){
  free(n->poids);
  free(n);
}

// ************************************************************************
// ** Definition de la fonction libération de tout le réseau de neurones **
// ************************************************************************

void freeReseau(Reseau * r){
  int i = 0;
  int j = 0;

  for (i = 0; i < r->nbr_couche; i++) {
    // libération des poids des neurones de la couche i
    fprintf(stderr, "   Libération de la couche %d :\n", i);
    for (j = 0; j < r->nbr_par_couche[i]; j++) {
      fprintf(stderr, "     - libération du neurone %d : ", j);
      freeNeurone(r->couches_contenus[i][j]);
      fprintf(stderr, "OK \n");
    }
    // libération de la couche i
    free(r->couches_contenus[i]);
  }

  // libération du réseau
  fprintf(stderr, "   Libération finale du réseau : ");
  free(r->couches_contenus);
  fprintf(stderr, "OK\n");
}
