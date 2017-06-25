// Fichier créé le 08/03/2017
// Dernière modification 15/05/2017
//
// Auteur : Cédric Paoli
//
// Licence : CC BY NC ND
//

#include "neurone.h"

// ************************************************************************
// ********* Definition la fonction d'activation des Neurones *************
// ************************************************************************

double activation(double x){
	return 1/(1+exp(-x));
}

// *********************************************************************************
// ** Definition de la fonction de propagation de l'information couche par couche **
// *********************************************************************************

void propage(Reseau * r, int couche ){
	int i = 0;
	int j = 0;
	double s = 0.0;
	for(i=0;i<r->nbr_par_couche[couche];i++){
		fprintf(stderr, "     Propagation %d\n", i);
		s = 0.0;
		// calcul de la somme pondérée.
		for(j=0;j<r->nbr_par_couche[couche-1];j++){
			fprintf(stderr, "         Neurone %d : ", j);
			s += r->couches_contenus[couche][i]->poids[j]*r->couches_contenus[couche-1][j]->results;
			fprintf(stderr, "OK\n");
		}
		// calcul du résultat.
		r->couches_contenus[couche][i]->results = activation(s);
	}
}

// ************************************************************************
// ** Definition de la fonction calculant l'erreur quadratique de sortie **
// ************************************************************************

double erreurQuadra (Reseau * r, double attendu[TAILLE_SORTIE]){
	int i = 0;
	double temp = 0.0;
	double err = 0.0;
	for(i=0;i<r->nbr_par_couche[r->nbr_par_couche[r->nbr_couche]-1];i++){
		temp = r->couches_contenus[r->nbr_couche-1][i]->results-attendu[i];
		err += temp*temp;
	}
	return sqrt(err);
}

// ****************************************************************************************************
// ** Definition de la fonction retournant le coup à jouer en fonction du résultat de la propagation **
// ****************************************************************************************************

int comparaison(Reseau * r){

	fprintf(stderr, "     Début de l'interprétation du résultat \n");
	// Initialisation des valeurs attendues.
	fprintf(stderr, "         Initialisation des constantes : ");
	INIT_CONST();
	fprintf(stderr, "OK\n");
	// Fin de l'Initialisation

	// Comparaison entre valeurs attendues et obtenues
	fprintf(stderr, "     Début des comparaison :\n");
	if (erreurQuadra(r,tab0)<TOLERANCE) {
		fprintf(stderr, "         Résultat 1\n");
		fprintf(stderr, "     Fin des comparaison \n");
		return 0;
	}
	else if (erreurQuadra(r,tab1)<TOLERANCE) {
		fprintf(stderr, "         Résultat 2\n");
		fprintf(stderr, "     Fin des comparaison \n");
		return 1;
	}
	else if (erreurQuadra(r,tab2)<TOLERANCE) {
		fprintf(stderr, "         Résultat 3\n");
		fprintf(stderr, "     Fin des comparaison \n");
		return 2;
	}
	else if (erreurQuadra(r,tab3)<TOLERANCE) {
		fprintf(stderr, "         Résultat 4\n");
		fprintf(stderr, "     Fin des comparaison \n");
		return 3;
	}
	else if (erreurQuadra(r,tab4)<TOLERANCE) {
		fprintf(stderr, "         Résultat 5\n");
		fprintf(stderr, "     Fin des comparaison \n");
		return 4;
	}
	else if (erreurQuadra(r,tab5)<TOLERANCE) {
		fprintf(stderr, "         Résultat 6\n");
		fprintf(stderr, "     Fin des comparaison \n");
		return 5;
	}
	fprintf(stderr, "         Résultat ABANDON\n");
	fprintf(stderr, "     Fin des comparaison \n");
	return -1;
}

// **********************************************************************************************
// ** Definition de la fonction éxécutant la propagation en fonction de l'historique des coups **
// **********************************************************************************************

int resultat(int * hist, Reseau * r ){

	int i = 0;

	// On envoie les coups précédents sur la couche 1
	fprintf(stderr, "     Attribution des valeurs d'entré : \n");
	for(i=0;i<r->nbr_par_couche[0];i++){
		fprintf(stderr, "         - Valeur %d : ", i);
		r->couches_contenus[0][i]->results = hist[i];
		fprintf(stderr, "OK\n");
	}

	int j = i - 1;

	fprintf(stderr, "\n     Début de la propagation dans le réseau \n");
	for(i=1;i<r->nbr_couche;i++){
		j = i - 1;
		fprintf(stderr, "         - propagation des couches %d à %d : ", i, j);
		propage(r,i);
		fprintf(stderr, "OK\n");
	}
	fprintf(stderr, "     Fin de la propagation dans le réseau \n");

	return comparaison(r);
}

//int wrapperDeResultat(Awale awale){


//	return resultat();
//}
