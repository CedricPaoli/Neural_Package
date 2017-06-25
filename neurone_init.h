// Fichier créé le 10/03/2017
// Dernière modification 15/05/2017
//
// Auteur : Cédric Paoli
//
// Licence : CC BY NC ND
//

#include <time.h>
#include "neurone.h"


// ************************************************************************
// ************* Début de definition des variable pre proc. ***************
// ************************************************************************

// Initialisation du neurone par default.

#define DEFAULT_NEURONE {{0.0},0.0,0.0,0.0}

// Initialisation du réseau de neurones par défault

#define DEFAULT_NEURAL_NETWORK NULL

// ************************************************************************
// ************** Fin de definition des variable pre proc. ****************
// ************************************************************************

// ************************************************************************
// **************** Début de description des fonctions ********************
// ************************************************************************

// Cette fonction attribue des valeurs aléatoires aux paramètres d'un neurone d'un
// réseau. Ces paramètres sont compris dans [0,1].
void initNeurone(Neurone * neur,int n_couche, int nm1_couche);

// Cette fonction applique init_neurone sur une couche du réseau de neurones.
void initCouche(Neurone ** tab, int n_couche, int nm1_couche);

// Cette fonction renvoie un réseau de neurone de taille par défault, dont les
// paramètres des neurones sont des valeurs dans [0,1].
Reseau * initReseau(Reseau * r);

// Cette fonction crée un réseau de neuronne par défault
Reseau * defaultNeuralCreation ();

// Sauvegarde une couche du réseau dans le fichier "fichier"
void saveNeuroneCouche(Neurone ** couche, int couche_actuelle, int couche_precedente, FILE * fichier);

// Sauvegarde un réseau entier dans un fichier "neural.ia"
void saveReseau(Reseau * r, FILE * ficher);

// Affiche en consol un réseau
void afficheReseau(Reseau * r);

// Cette fonction charge dans * r le réseau contenu dans fichier
// (si fichier est NULL c'est dans le fichier par défault neural.ai)
void loadReseau(FILE * fichier, Reseau * r);

// Cette fonction libère 1 neurone
void freeNeurone (Neurone * n);

// Cette fonction libère le réseau
void freeReseau(Reseau * r);

// ************************************************************************
// ***************** Fin de description des fonctions *********************
// ************************************************************************
