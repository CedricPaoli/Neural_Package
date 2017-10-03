#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "nspstd.h"

struct Network * creationManual(){

  system("clear");

  fprintf(stderr, "********************************************************************************\n");
  fprintf(stderr, "                           Manual Neural Network Creation                       \n");
  fprintf(stderr, "                                 General Parameters                             \n");
  fprintf(stderr, "********************************************************************************\n\n");

  struct Network * ns;
  ns = malloc(sizeof(struct Network));

  int i;
  int layer = 0;
  int secure = 0;
  int temp_num = 0;
  int * temp_struct;
  char answer[4];

  // [BEGIN] Initialisation of general info of network

  while (!secure) {
    fprintf(stderr, "Please enter the number of layer(s) of your network : ");
    scanf("%d",&layer);
    fprintf(stderr, "\n\n");
    if (layer>1) {
      secure = 1;
    } else {
      fprintf(stderr, "This value ( %d ) is impossible\n\n", layer );
    }
  }

  temp_struct = malloc(sizeof(int)*layer);

  secure = 0;

  for (i = 0; i < layer; i++) {
    while (!secure) {
      fprintf(stderr, "Please enter the number of neurone(s) on layer %d : ", i);
      scanf("%d",&temp_num);
      if (temp_num>0) {
        secure = 1;
      } else {
        fprintf(stderr, "This value ( %d ) is impossible\n\n", temp_num );
      }
    }
    temp_struct[i] = temp_num;
    secure = 0;
  }

  // Usage of the variables

  ns->number_of_layer = layer;
  ns->number_by_layer = temp_struct;

  // [END]  Initialisation of general info of network

  // [BEGIN] Spécifique Initialisation
  while (!secure) {
    fprintf(stderr, "\n\nWould you like to parameter manualy each neurones ? ");
    scanf("%s", answer);
    noCast(answer,3);
    if (!strcmp("NO",answer)) {
      autoCompletionNetwork(ns);
      secure = 1;
    } else if (!strcmp("YES",answer)) {
      manualCompletionNetwork(ns);
      secure = 1;
    } else {
      fprintf(stderr, "This answer ( %s ) is not available\n\n", answer );
    }
  }
  // [END] Spécifique Initialisation

  printNetwork(ns);

  return ns;
}

void noCast(char * answer,int n){

  int i;
  char delta;

  delta = 'a'-'A';

  for (i = 0; i < n; i++) {
    if (answer[i]>'a') {
      answer[i]-=delta;
    }
  }

}

void autoCompletionNetwork(struct Network * ns){

  fprintf(stderr, "\n\nAutocompletion start\n\n");

  struct Neurone ** tableau;
  int i ;
  int j ;
  int k ;
  tableau = malloc(sizeof(struct Neurone *)*ns->number_of_layer);
  fprintf(stderr, "Malloc 1 OK\n");
  tableau[0] = malloc(sizeof(struct Neurone)*ns->number_by_layer[0]);
  fprintf(stderr, "Malloc 2 OK\n");
  for (i = 1; i < ns->number_of_layer; i++) {
    struct Neurone * neur ;
    neur = (struct Neurone *) malloc(sizeof(struct Neurone)+sizeof(double *)*(ns->number_by_layer[i-1]-1));
    fprintf(stderr, "Malloc %d OK\n",i);
    tableau[i] = malloc(sizeof(&neur)*ns->number_by_layer[i]);
  }

  fprintf(stderr, "\n");

  // First layer Ininialisation

  for (j = 0; j < ns->number_by_layer[0]; j++) {

    tableau[0][j].biais = (double)0.0;
    tableau[0][j].value = (double)0.0;
    tableau[0][j].sensibility = (double)0.0;

    fprintf(stderr, "Couche 0 Neurone %d OK\n",j);
  }

  // layer Ininialisation

  for (i = 1; i < ns->number_of_layer; i++) {
    for (j = 0; j < ns->number_by_layer[i]; j++) {

      tableau[i][j].biais = (double)0.0;
      tableau[i][j].value = (double)0.0;
      tableau[i][j].sensibility = (double)0.0;

      tableau[i][j].weight = (double *) malloc(sizeof(double)*ns->number_by_layer[i-1]);

      for (k = 0; k < ns->number_by_layer[i-1]; k++) {
        tableau[i][j].weight[k] = (double)1.0;
      }

      fprintf(stderr, "Couche %d Neurone %d OK\n",i,j );
    }
  }

  fprintf(stderr, "\n\n");

  ns->tab = &tableau;

  printNetwork(ns);

}

void manualCompletionNetwork(struct Network * ns){
}

void printNetwork (struct Network * ns){
  fprintf(stderr, "********************************************************************************\n");
  fprintf(stderr, "                                  Printing Network                              \n");
  fprintf(stderr, "********************************************************************************\n\n");

  int i, j, k;

  fprintf(stderr, "General Informations :\n");
  fprintf(stderr, "         - Number of Layer : %d\n", ns->number_of_layer);
  fprintf(stderr, "         - Number by Layer : [ ");
  for (i = 0; i < ns->number_of_layer - 1; i++) {
    fprintf(stderr, "%d, ", ns->number_by_layer[i]);
  }
  fprintf(stderr, "%d ]\n\n", ns->number_by_layer[ns->number_of_layer-1]);

  fprintf(stderr, "Informations by layer :\n\n");

  fprintf(stderr, "         ---------------- Layer 0 ----------------\n");
  for (i = 0; i < ns->number_by_layer[0]; i++) {
    fprintf(stderr, "                       <> Neurone %d  : \n", i);
    fprintf(stderr, "                             - Biais  : %lf\n", ns->tab[0][i]->biais);
    fprintf(stderr, "                             - Value  : %lf\n", ns->tab[0][i]->value);
    fprintf(stderr, "                             - Sensi  : %lf\n", ns->tab[0][i]->sensibility);
    fprintf(stderr, "                             - weigth : NONE \n");
  }
  fprintf(stderr, "         -----------------------------------------\n\n");

  for (i = 1; i < ns->number_of_layer; i++) {
    fprintf(stderr, "         ---------------- Layer %d ----------------\n",i);
    for (j = 0; j < ns->number_by_layer[i]; j++) {
      fprintf(stderr, "                       <> Neurone %d  : \n", i);
      fprintf(stderr, "                             - Biais  : %lf\n", ns->tab[i][j]->biais);
      fprintf(stderr, "                             - Value  : %lf\n", ns->tab[i][j]->value);
      fprintf(stderr, "                             - Sensi  : %lf\n", ns->tab[i][j]->sensibility);
      fprintf(stderr, "                             - weigth : [ ");
      for (k = 0; k < ns->number_by_layer[i-1]-1; k++) {
        fprintf(stderr, "%lf, ", ns->tab[i][j]->weight[k]);
      }
      fprintf(stderr, "%lf ]\n", ns->tab[i][j]->weight[ns->number_by_layer[i-1]]);
    }
    fprintf(stderr, "         -----------------------------------------\n\n");
  }

}
