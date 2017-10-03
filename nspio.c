#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "neurone.h"

void afficheNeurone(struct Neurone * neur,int n){

  int i;

  if (neur == NULL) {
    fprintf(stderr, "\n             [Neurone NULL]\n");
  } else {
    fprintf(stderr, "             [Description] - Biais        : %lf\n",neur->biais);
    fprintf(stderr, "                           - Sensibility  : %lf\n",neur->sensibility);
    fprintf(stderr, "                           - Value        : %lf\n",neur->value);
    fprintf(stderr, "                           - Weight       : [\n");
    for (i = 0; i < n-1; i++) {
      fprintf(stderr, "%lf, ", neur->weight[i]);
    }
    fprintf(stderr, "%lf]\n\n", neur->weight[n-1]);
  }
}

void loadNeurone(struct Network * ns, FILE * file, int i, int j){
  int k;

  if(i!=0){
    ns->tab[i][j] = (struct Neurone *) malloc(sizeof(double)*(ns->number_by_layer[i-1]+3));
    if (sizeof(ns->tab[i][j])== sizeof(double)*(ns->number_by_layer[i-1]+3)) {
      fprintf(stderr, "             [OK] Malloc Neurone (%d,%d)\n",i,j);
    } else {
      fprintf(stderr, "             [ERROR] Malloc Neurone (%d,%d)\n",i,j);
    }

    fscanf(file,"%lf %lf %lf ",&ns->tab[i][j]->biais,&ns->tab[i][j]->sensibility,&ns->tab[i][j]->value);

    for (k = 0; k < ns->number_by_layer[i-1]; k++) {
      fscanf(file,"%lf ",&ns->tab[i][j]->weight[k]);
    }
  } else {

    // Cas de la première couche.

    ns->tab[i][j] = (struct Neurone *) malloc(sizeof(struct Neurone));
    if (sizeof(ns->tab[i][j])==sizeof(struct Neurone)) {
      fprintf(stderr, "             [OK] Malloc Neurone (%d,%d)\n",i,j);
    } else {
      fprintf(stderr, "             [ERROR] Malloc Neurone (%d,%d)\n",i,j);
    }

    fscanf(file,"%lf %lf %lf ",&ns->tab[i][j]->biais,&ns->tab[i][j]->sensibility,&ns->tab[i][j]->value);

  }


}

struct Network * creationAuto(struct Network * ns, const char * ai_file){

  fprintf(stderr, "****************************************\n");
  fprintf(stderr, "**    Creation from file beginning    **\n");
  fprintf(stderr, "****************************************\n\n");

  int layer;
  int i, j;

  FILE * file = NULL;
  file=fopen(ai_file,"r+");

  if (file==NULL) {
    fprintf(stderr, "[ERROR]Openning of %s\n",ai_file );
    return ns;
  }

  fprintf(stderr,"[OK] Openning of %s\n\n",ai_file);
  // Lecture du nombre max de couches du réseau chargé
  fscanf(file, "%d ", &layer);
  fprintf(stderr,"[OK] Reading in the file %s \n\n",ai_file);
  fprintf(stderr,"     Number of layers : %d \n\n",layer);

  // Initialisation des valeurs constante et taille des tableau
  ns->number_of_layer = layer;
  fprintf(stderr, "pb 1\n");
  ns->number_by_layer = malloc(sizeof(int)*layer);
  fprintf(stderr, "pb 2\n");
  ns->tab = (struct Neurone ***) malloc(sizeof(struct Neurone **)*layer);
  fprintf(stderr, "pb 2\n");
  if (sizeof(ns->number_by_layer)==(sizeof(int)*layer) && sizeof(ns->tab)==(sizeof(struct Neurone **)*layer)) {
    fprintf(stderr,"[OK] Première vague d'Initialisation et de malloc \n\n");
  } else {
    fprintf(stderr,"[ERROR] Première vague d'Initialisation et de malloc \n\n");
  }


  for (i = 0; i < layer; i++) {
    // lecture du nombre de neurone de la couche i
    fscanf(file, "%d ", &ns->number_by_layer[i]);
    // Ininialisation de la seconde dimension du tableau
    ns->tab[i] = (struct Neurone **) malloc(sizeof(struct Neurone *)*ns->number_by_layer[i]);
    if (sizeof(ns->tab[i])==sizeof(struct Neurone *)*ns->number_by_layer[i]) {
      fprintf(stderr, "         [OK] Malloc layer %d\n",i);
    } else {
      fprintf(stderr, "         [ERROR] Malloc layer %d\n",i);
    }
  }

  // Lecture dans le fichier pour charger les param des neurones

  for (i = 0; i < layer; i++) {
    for (j = 0; j < ns->number_by_layer[i]; j++) {
      loadNeurone(ns,file,i,j);
      if (i>0) {
        afficheNeurone(ns->tab[i][j],ns->number_by_layer[i]-1);
      } else {
        afficheNeurone(ns->tab[i][j],0);
      }

    }
  }

  return ns;
}
