#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "/Neural_Package/headers/nspstd.h"

struct Network * creationManual(struct Network * ns){

  system("clear");

  fprintf(stderr, "********************************************************************************\n");
  fprintf(stderr, "                           Manual Neural Network Creation                       \n");
  fprintf(stderr, "                                 General Parameters                             \n");
  fprintf(stderr, "********************************************************************************\n\n");

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

  autoCompletionNetwork(ns);

  // [END]  Initialisation of general info of network

  // [BEGIN] Spécifique Initialisation
  while (!secure) {
    fprintf(stderr, "\n\nWould you like to parameter manualy each neurones ? ");
    scanf("%s", answer);
    noCast(answer,3);
    if (!strcmp("NO",answer)) {
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
  propagation(ns);
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

  //fprintf(stderr, "\n\nAutocompletion start\n\n");

  int i ;
  int j ;
  int k ;
  ns->tab = malloc(sizeof(struct Neurone **)*ns->number_of_layer);
  //fprintf(stderr, "Malloc 1 OK\n");
  for (i = 0; i < ns->number_of_layer; i++) {
    ns->tab[i] = malloc(sizeof(struct Neurone *)*ns->number_by_layer[i]);
    //fprintf(stderr, "Malloc %d OK\n",i);
  }

  fprintf(stderr, "\n");

  // First layer Ininialisation

  for (j = 0; j < ns->number_by_layer[0]; j++) {
    ns->tab[0][j]=malloc(sizeof(struct Neurone));
    ns->tab[0][j]->biais = (double)0.0;
    ns->tab[0][j]->value = (double)0.0;
    ns->tab[0][j]->sensibility = (double)0.0;

    //fprintf(stderr, "Couche 0 Neurone %d OK\n",j);
  }

  // Next layer Ininialisation

  for (i = 1; i < ns->number_of_layer; i++) {
    for (j = 0; j < ns->number_by_layer[i]; j++) {
      ns->tab[i][j]=malloc(sizeof(struct Neurone)+sizeof(double)*(ns->number_by_layer[i-1]));
      ns->tab[i][j]->biais = (double)0.0;
      ns->tab[i][j]->value = (double)0.0;
      ns->tab[i][j]->sensibility = (double)0.0;

      ns->tab[i][j]->weight = (double *) malloc(sizeof(double)*(ns->number_by_layer[i-1]));
      for (k = 0; k < ns->number_by_layer[i-1]; k++) {
        ns->tab[i][j]->weight[k] = (double)1.0;
      }

      //fprintf(stderr, "Couche %d Neurone %d OK\n",i,j );
    }
  }

  fprintf(stderr, "\n\n");

  //printNetwork(ns);
  //ns->tab[1][1]->weight[1]= 2.0;
  //ns->tab[2][0]->biais = 5.5;
  //printNetwork(ns);

  //printNetworkAddress(ns);

  //fprintf(stderr, "\n\nAutocompletion finish\n\n");

}

void manualCompletionNetwork(struct Network * ns){

  fprintf(stderr, "\nManual Completion start\n\n");

  int i ;
  int j ;
  int k ;

  // Général @ infos

  fprintf(stderr, "General Informations :\n");
  fprintf(stderr, "         - Number of Layer : %d\n", ns->number_of_layer);
  fprintf(stderr, "         - Number by Layer : [ ");
  for (i = 0; i < ns->number_of_layer - 1; i++) {
    fprintf(stderr, "%d, ", ns->number_by_layer[i]);
  }
  fprintf(stderr, "%d ]\n\n", ns->number_by_layer[ns->number_of_layer - 1]);

  // First layer @ infos
  fprintf(stderr, "         ---------------- Layer 0 ----------------\n");
  for (i = 0; i < ns->number_by_layer[0]; i++) {
    fprintf(stderr, "                       <> Neurone %d  : \n", i);
    fprintf(stderr, "                             - Biais  : ");
    scanf("%lf", &ns->tab[0][i]->biais);
    fprintf(stderr, "                             - Value  : ");
    scanf("%lf", &ns->tab[0][i]->value);
    fprintf(stderr, "                             - Sensi  : ");
    scanf("%lf", &ns->tab[0][i]->sensibility);
    fprintf(stderr, "                             - weigth : NONE \n");
  }
  fprintf(stderr, "         -----------------------------------------\n\n");


  // Next layer @ infos
  for (i = 1; i < ns->number_of_layer; i++) {
    fprintf(stderr, "         ---------------- Layer %d ----------------\n",i);
    for (j = 0; j < ns->number_by_layer[i]; j++) {
      fprintf(stderr, "                       <> Neurone %d  : \n", i);
      fprintf(stderr, "                             - Biais  : ");
      scanf("%lf", &ns->tab[i][j]->biais);
      fprintf(stderr, "                             - Value  : ");
      scanf("%lf", &ns->tab[i][j]->value);
      fprintf(stderr, "                             - Sensi  : ");
      scanf("%lf", &ns->tab[i][j]->sensibility);
      fprintf(stderr, "                             - weigth : ");
      for (k = 0; k < ns->number_by_layer[i-1]-1; k++) {
        scanf("%lf", &ns->tab[i][j]->weight[k]);
        fprintf(stderr, "                                        ");
      }
      scanf("%lf", &ns->tab[i][j]->weight[ns->number_by_layer[i-1]-1]);
    }
    fprintf(stderr, "\n         -----------------------------------------\n\n");
  }

}

void freeNeuron(struct Neurone * n){
  free(n->weight);
  free(n);
}

void freeNetwork(struct Network * ns){
  int i,j;

  for ( i = 0; i < ns->number_of_layer; i++) {
    for ( j = 0; j < ns->number_by_layer[i]; j++) {
      freeNeuron(ns->tab[i][j]);
    }
  }
  //free(ns->number_by_layer);
  //free(ns);
}

void printNetwork (struct Network * ns){
  fprintf(stderr, "********************************************************************************\n");
  fprintf(stderr, "                                  Printing Network                              \n");
  fprintf(stderr, "********************************************************************************\n\n");

  int i, j, k;

  fprintf(stderr, "General Informations :\n");
  fprintf(stderr, "         - Number of Layer : %d\n", ns->number_of_layer);
  fprintf(stderr, "         - Number by Layer : [ ");
  for (i = 0; i < ns->number_of_layer-1; i++) {
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
      fprintf(stderr, "                       <> Neurone %d  : \n", j);
      fprintf(stderr, "                             - Biais  : %lf\n", ns->tab[i][j]->biais);
      fprintf(stderr, "                             - Value  : %lf\n", ns->tab[i][j]->value);
      fprintf(stderr, "                             - Sensi  : %lf\n", ns->tab[i][j]->sensibility);
      fprintf(stderr, "                             - weigth : [ ");
      for (k = 0; k < ns->number_by_layer[i-1]-1; k++) {
        fprintf(stderr, "%lf, ", ns->tab[i][j]->weight[k]);
      }
      fprintf(stderr, "%lf ]\n", ns->tab[i][j]->weight[ns->number_by_layer[i-1]-1]);
    }
    fprintf(stderr, "         -----------------------------------------\n\n");
  }

}

void printNetworkAddress (struct Network * ns){

  fprintf(stderr, "********************************************************************************\n");
  fprintf(stderr, "                                  Printing Memory                               \n");
  fprintf(stderr, "********************************************************************************\n\n");

  int i, j, k;

  fprintf(stderr, "General Infos\n\n");
  fprintf(stderr, "         Adress Network : %p\n",ns);
  fprintf(stderr, "                     - number_of_layer   : %p\n",&ns->number_of_layer);
  fprintf(stderr, "                     - number_by_layer   : %p\n",ns->number_by_layer);
  fprintf(stderr, "                                           Details :\n");
  for (i = 0; i < ns->number_of_layer - 1; i++) {
    fprintf(stderr, "                                                       %p\n", &ns->number_by_layer[i]);
  }
  fprintf(stderr, "                                                       %p\n", &ns->number_by_layer[ns->number_of_layer - 1]);
  fprintf(stderr, "                     - tab               : %p\n",&ns->tab);


  fprintf(stderr, "\nInformations by layer :\n\n");

  fprintf(stderr, "         ---------------- Layer 0 : %p ----------------\n",&ns->tab[0]);
  for (i = 0; i < ns->number_by_layer[0]; i++) {
    fprintf(stderr, "                       <> Neurone %d  : %p\n", i, ns->tab[0][i]);
    fprintf(stderr, "                             - Biais  : %p\n", &ns->tab[0][i]->biais);
    fprintf(stderr, "                             - Value  : %p\n", &ns->tab[0][i]->value);
    fprintf(stderr, "                             - Sensi  : %p\n", &ns->tab[0][i]->sensibility);
    fprintf(stderr, "                             - weigth : %p\n",  ns->tab[0][i]->weight);
  }
  fprintf(stderr, "         -----------------------------------------\n\n");

  for (i = 1; i < ns->number_of_layer; i++) {
    fprintf(stderr, "         ---------------- Layer %d : %p ----------------\n",i,&ns->tab[i]);
    for (j = 0; j < ns->number_by_layer[i]; j++) {
      fprintf(stderr, "                       <> Neurone %d  : %p\n", j, ns->tab[i][j]);
      fprintf(stderr, "                             - Biais  : %p\n", &ns->tab[i][j]->biais);
      fprintf(stderr, "                             - Value  : %p\n", &ns->tab[i][j]->value);
      fprintf(stderr, "                             - Sensi  : %p\n", &ns->tab[i][j]->sensibility);
      fprintf(stderr, "                             - weigth : %p\n",  ns->tab[i][j]->weight);
      fprintf(stderr, "                                       [ ");
      for (k = 0; k < ns->number_by_layer[i-1]-1; k++) {
        fprintf(stderr, "%p, ", &ns->tab[i][j]->weight[k]);
      }
      fprintf(stderr, "%p ]\n", &ns->tab[i][j]->weight[ns->number_by_layer[i-1]]);
    }
    fprintf(stderr, "         -----------------------------------------\n\n");
  }

}

void learningRetroPropagation(struct Network * ns,const char * data_file) {

  system("clear");

  fprintf(stderr, "********************************************************************************\n");
  fprintf(stderr, "                             Neural Network Learning by                         \n");
  fprintf(stderr, "                                 Retropropagation :D                               \n");
  fprintf(stderr, "********************************************************************************\n\n");

  FILE * file ;

  int i,j ;
  int num_by_elem;
  int num_of_elem;

  double alpha;

  char c;
  // the size of the datas must match the size of the first layer
  int data_size = ns->number_by_layer[0];

  // Openning data file
  file=fopen(data_file,"r+");
  // Securing code
  if (file!=NULL) {

    fscanf(file,"%d \n",&num_of_elem);

    fprintf(stderr, "How many time would you like to train for each elements ? ");
    scanf("%d",&num_by_elem );
    fprintf(stderr, "\nWhat is the coeficient to apply ? ");
    scanf("%lf",&alpha);

    for (i = 0; i < num_of_elem; i++) {
      // Loading of a data set
      for (j = 0; j < data_size; j++) {
        fscanf(file,"%lf ",&ns->tab[0][i]->value);
      }
      fscanf(file,"%c",&c);

      // Learning Loop
      for (j = 0; j < num_by_elem; j++) {
        propagation(ns);
        retropropagationSig(ns,alpha,file);
      }
    }

    fclose(file);

  } else{
    fprintf(stderr, "error : failing during openning of data file %s\n", data_file);
  }

}

void propagation(struct Network * ns) {

  int i,j;

  for (i = 1; i < ns->number_of_layer; i++) {
    for (j = 0; j < ns->number_by_layer[i]; j++) {
      ns->tab[i][j]->value = sigmoide(ns,i,j);
    }
  }
}

void retropropagationSig(struct Network * ns, double alpha,FILE * data_file) {


  double * datas ;
  int i,j;
  char c;

  datas = malloc(sizeof(double)*ns->number_by_layer[ns->number_of_layer-1]);

  // BEGINNIG Loading of datas
  for (i = 0; i < ns->number_by_layer[ns->number_of_layer-1]; i++) {
    fscanf(data_file,"%lf ",&datas[i]);
  }
  fscanf(data_file,"%c",&c);
  // END

  // BEGINNING Updating the sensibilities in the Network (do not count First Layer)

  // Ini. of the sensi for the last layer
  for (i = 0; i < ns->number_of_layer-1; i++) {
    ns->tab[ns->number_of_layer-1][i]->sensibility = datas[i]-ns->tab[ns->number_of_layer-1][i]->value;
  }

  // Previous Layers
  for (i = 1; i < ns->number_of_layer-1; i++) {
    // Going back from Last Layer to the first ones
    for (j = 0; j < ns->number_by_layer[ns->number_of_layer-1-i]-1; j++) {
      ns->tab[ns->number_of_layer-1-i][j]->sensibility = updateSensibility(ns,ns->number_of_layer-1-i,j);
    }
  }

}

double sigmoide(struct Network * ns, int i, int j){

  int k;
  double sum = 0.0;
  double sig;

  // Pondered sum
  for (k = 0; k < ns->number_by_layer[i-1]; k++) {
    sum += ns->tab[i][j]->weight[k]*ns->tab[i-1][k]->value;
  }

  // Calcul of the activation
  sig = 1.0/(1+exp(-sum));

  return sig;
}

double updateSensibility(struct Network * ns, int i, int j){

  double sensi;
  int k;

  // Looking of the weight of the next layer (propagation direct.)
  for (k = 1; k < ns->number_by_layer[i+1]-1; k++) {
    sensi = ns->tab[i-1][k]->weight[j]*ns->tab[i-1][k]->sensibility;
  }

  sensi = sensi * ns->tab[i][j]->value * (1.0-ns->tab[i][j]->value);

  return sensi;

}

// END
