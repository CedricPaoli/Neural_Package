// Fichier créé le 22/03/2017
// Dernière modification 22/03/2017
//
// Auteur : Cédric Paoli
//
// Licence : CC BY NC ND
//

#include "neurone_learning_algo.h"

// **********************************************************************************
// ** Definition de la fonction éxécutant la rétro-propagation du résultat attendu **
// **********************************************************************************


void retroPropage(Reseau * r, double * espected){

  int i = 0;
  int j = 0;
  int k = 0;
  double temp_r;
  double temp_s;

  // Sensibilité de de la couche de Fin
  fprintf(stderr, "     Initialisation couche de fin\n");
  for (i = 0; i < r->nbr_par_couche[r->nbr_couche-1]; i++) {
    r->couches_contenus[r->nbr_couche-1][i]->sensibilite = espected[i] - r->couches_contenus[r->nbr_couche-1][i]->results;
  }
  fprintf(stderr, "     Initialisation couche de fin : OK \n");
  i = 1;

  // Calcul des sensibilités lors de la rétropropagation
  for (i = 1; i < r->nbr_couche-1; i++) {
    for (j = 0; j < r->nbr_par_couche[r->nbr_couche-i-1]; j++) {
      fprintf(stderr, "     Initialisation couche %i\n", i-j);
      temp_r = r->couches_contenus[r->nbr_couche-i-1][j]->results*(1-r->couches_contenus[r->nbr_couche-i-1][j]->results);
      for (k = 0; k < r->nbr_par_couche[r->nbr_couche-i-2]; k++) {
        temp_s = temp_s + (r->couches_contenus[r->nbr_couche-i-2][k]->sensibilite*r->couches_contenus[r->nbr_couche-i-2][k]->poids[j]);
      }
      r->couches_contenus[i][j]->sensibilite = temp_r*temp_s;
      temp_s = 0.0;
      temp_r = 0.0;
    }
  }

}

// ***************************************************************************************************
// ** Definition de la fonction éxécutant la MAJ des poids en fonction des sensibilite et résultats **
// ***************************************************************************************************


void miseAJourPoids (Reseau * r, double alpha){

  int i = 1;
  int j = 0;
  int k = 0;

  for (i = 1; i < r->nbr_couche-1; i++) {
    for (j = 0; j < r->nbr_par_couche[i]; j++) {
      for (k = 0; k < r->nbr_par_couche[i-1]; k++) {
        r->couches_contenus[i][j]->poids[k] = r->couches_contenus[i][j]->poids[k] + (alpha*r->couches_contenus[i-1][j]->results*r->couches_contenus[i][j]->sensibilite);
      }
    }
  }

}

// **********************************************************************************************
// ** Definition de la fonction éxécutant un apprentissage assisté sur une donnée en parametre **
// **********************************************************************************************


void apprendre(Reseau * r, double alpha, double * parametre, double * espected) {

  int i = 0;

  // Début de la propagation dans le réseau

  // On envoie les coups précédents sur la couche 1
	for(i=0;i<r->nbr_par_couche[0];i++){
		r->couches_contenus[0][i]->results = parametre[i];
	}

	int j = i - 1;

	for(i=1;i<r->nbr_couche;i++){
		j = i - 1;
		propage(r,i);
	}

  // Fin de la propagation
  // Début de l'apprentissage

  retroPropage(r,espected);
  miseAJourPoids(r,alpha);

  // Fin de l'apprentissage

}
