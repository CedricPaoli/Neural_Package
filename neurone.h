// Fichier créé le 08/03/2017
// Dernière modification 15/05/2017
//
// Auteur : Cédric Paoli
//
// Licence : CC BY NC ND
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ************************************************************************
// ************* Début de definition des variable pre proc. ***************
// ************************************************************************

#define NBR_MAX_PAR_COUCHE 50
#define NBR_DE_COUCHE 4
#define TOLERANCE 0.05

#define TAILLE_DONNEES 200
#define TAILLE_COUCHE_1 50
#define TAILLE_COUCHE_2 50
#define TAILLE_SORTIE 6


// Initialisation des valeurs attendues (pour la comparaison des résultats).

#define INIT_CONST() double tab0[NBR_MAX_PAR_COUCHE] = {0.0};\
                      tab0[0] = 1.0;\
                     double tab1[NBR_MAX_PAR_COUCHE] = {0.0};\
                      tab1[1] = 1.0;\
                     double tab2[NBR_MAX_PAR_COUCHE] = {0.0};\
                      tab2[2] = 1.0;\
                     double tab3[NBR_MAX_PAR_COUCHE] = {0.0};\
                      tab3[3] = 1.0;\
                     double tab4[NBR_MAX_PAR_COUCHE] = {0.0};\
                      tab4[4] = 1.0;\
                     double tab5[NBR_MAX_PAR_COUCHE] = {0.0};\
                      tab5[5] = 1.0;

  // Propagation manuel sur le réseau.
  #define PROPAGE_MANUEL() propage(r,1);\
	                         propage(r,2);\
	                         propage(r,3);

  // ************************************************************************
  // ************** Fin de definition des variable pre proc. ****************
  // ************************************************************************

  // ************************************************************************
  // *************** Definition des types Neurone et Reseau *****************
  // ************************************************************************


  typedef struct{

  	double biais;

  	double sensibilite;

  	double results;

    double * poids;

  } Neurone;

  typedef struct{

    int nbr_couche;

    int nbr_max_par_couche;

    int * nbr_par_couche;

  	Neurone *** couches_contenus;

  } Reseau;

  // ************************************************************************
  // ********** Fin de definition des types Neurone et Reseau ***************
  // ************************************************************************


  // ************************************************************************
  // **************** Début de description des fonctions ********************
  // ************************************************************************

  // Renvoie le coup suivant à jouer après avoir propager l'information contenue
  // dans historique dans le réseau de Neurones.
  int resultat(int * hist, Reseau * r );

  // Renvoie le coup à jouer par l'IA en fonction des valeurs attendues et obtenues.
  int comparaison(Reseau * r);

  // Renvoie l'erreur quadratique moyenne entre le resultat de sortie du réseau
  // et le résultat attendu.
  double erreurQuadra (Reseau * r, double attendu[TAILLE_SORTIE]);

  // Propage l'information de la couche 'couche - 1' à la couche 'couche' du réseau.
  void propage(Reseau * r, int couche );

  // Renvoie le résultat d'une sigmoïde de paramètre x, c'est la fonction d'activation.
  double activation(double x);

  // ************************************************************************
  // ***************** Fin de description des fonctions *********************
  // ************************************************************************
