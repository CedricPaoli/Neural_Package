// Fichier créé le 24/06/2017
// Dernière modification 24/06/2017
//
// Auteur : Cédric Paoli
//
// Licence : CC BY NC ND
//

#include <time.h>

struct Neurone{};

struct Reseau{};


struct Reseau * test_creat(struct Reseau * r);

struct Reseau * test_creat_auto(struct Reseau * r, int taille,int taille_max, int * dans_couches);

void test_save(struct Reseau * r);

void test_propage(struct Reseau * r);

void test_retropropage(struct Reseau * r);

void test_free(struct Reseau * r);

void test_load();

void saveReseau(struct Reseau * r, FILE * fichier);

void propage(struct Reseau * r, int couche);

void retroPropage(struct Reseau * r, double * espected);

void freeReseau(struct Reseau * r);

void loadReseau(FILE * fichier,struct Reseau * r);

void afficheReseau(struct Reseau * r);
