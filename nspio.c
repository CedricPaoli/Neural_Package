#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "nspio.h"


void loadNeurone(struct Network * ns, FILE * file, int i, int j){

  int k;

  if(i!=0){
    fscanf(file,"%lf %lf %lf ",&ns->tab[i][j]->biais,&ns->tab[i][j]->value,&ns->tab[i][j]->sensibility);
    for (k = 0; k < ns->number_by_layer[i-1]; k++) {
      fscanf(file,"%lf ",&ns->tab[i][j]->weight[k]);
      fprintf(stderr, "%lf\n", ns->tab[i][j]->weight[k]);
    }
    fprintf(stderr, "\n");

    for (k = 0; k < ns->number_by_layer[i-1]; k++) {
      fprintf(stderr, "%lf\n", ns->tab[i][j]->weight[k]);
    }
    fprintf(stderr, "\n");
  } else {
    // Cas de la première couche.
    fscanf(file,"%lf %lf %lf ",&ns->tab[i][j]->biais,&ns->tab[i][j]->value,&ns->tab[i][j]->sensibility);
  }



}

void saveNeuron(struct Neurone * n){

}

struct Network * creationAuto(struct Network * ns, const char * ai_file){

  system("clear");

  fprintf(stderr, "********************************************************************************\n");
  fprintf(stderr, "                             Auto Neural Network Creation                       \n");
  fprintf(stderr, "                                    load from File                              \n");
  fprintf(stderr, "********************************************************************************\n\n");

  int layer;
  int * temp_struct;
  int i, j;

  FILE * file = NULL;
  file=fopen(ai_file,"r+");

  if (file==NULL) {
    fprintf(stderr, "[ERROR]Openning of %s\n",ai_file );
    return ns;
  }

  fprintf(stderr,"[OK] Openning of %s\n\n",ai_file);
  // Reading th number of layer in the network
  fscanf(file, "%d ", &layer);
  fprintf(stderr,"[OK] Reading in the file %s \n\n",ai_file);
  fprintf(stderr,"     Number of layers : %d \n\n",layer);
  ns->number_of_layer = layer;
  temp_struct = malloc(sizeof(int)*layer);

  for (i = 0; i < layer; i++) {
    // Reading of the number of neurons on layer i
    fscanf(file, "%d ", &temp_struct[i]);
  }

  ns->number_by_layer = temp_struct;

  // Initialisation by default of the network.
  autoCompletionNetwork(ns);

  // Lecture dans le fichier pour charger les param des neurones

  for (i = 0; i < layer; i++) {
    for (j = 0; j < ns->number_by_layer[i]; j++) {
      loadNeurone(ns,file,i,j);
    }
  }

  printNetwork(ns);

  return ns;
}

void saveNetwork (struct Network * ns){

  system("clear");

  fprintf(stderr, "********************************************************************************\n");
  fprintf(stderr, "                                  Save Neural Network                           \n");
  fprintf(stderr, "********************************************************************************\n\n");

  char file_name[MAX_LENGTH_FILE_NAME];
  fprintf(stderr, "Please enter the file's name without extentions : ");
  scanf("%s",file_name);
  fprintf(stderr, "%s\n",file_name);


}
