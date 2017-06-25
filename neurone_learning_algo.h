// Fichier créé le 22/03/2017
// Dernière modification 22/03/2017
//
// Auteur : Cédric Paoli
//
// Licence : CC BY NC ND
//

#include "neurone_init.h"

// Fonction induisant une rétropropagation dans le réseau pour le calcul des sensibilité
void retroPropage(Reseau * r, double * espected);

// Fonction permettant la mise à jour des poids après propagation et retropropagation
void miseAJourPoids (Reseau * r, double alpha);

// Fonction appliquant le système d'apprentissage sur une donnée
void apprendre (Reseau * r, double alpha, double * parametre, double * espected);
