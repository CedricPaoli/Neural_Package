#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "/Neural_Package/headers/nspio.h"

int main(int argc, char const *argv[]) {

  system("clear");

  // Initialisation of the Network variable
  struct Network * ns;
  ns = malloc(sizeof(struct Network));

  int secure = 0;
  char answer[4];

  // Diff options of execution
  switch (argc) {

    case 2:
      if (!strcmp(argv[1],"-c")) {
        ns = creationManual(ns);
      } else{
        fprintf(stderr, "ARGV[0] : %s, ARGV[1] : %s, ARGV[2] : %s, ARGV[3] : %s,\n", argv[0],argv[1],argv[2],argv[3]);
        fprintf(stderr, "error : unknown switch %s\n",argv[1]);
        usage();
      }
      break;

    case 3:
      if (!strcmp(argv[1],"-c")) {
        ns = creationAuto(ns,argv[2]);
      } else if (!strcmp(argv[1],"-cl")) {
        fprintf(stderr, "ARGV[0] : %s, ARGV[1] : %s, ARGV[2] : %s, ARGV[3] : %s,\n", argv[0],argv[1],argv[2],argv[3]);
        ns = creationManual(ns);
        learning(ns,argv[2]);
      } else{
        fprintf(stderr, "error : unknown switch %s\n",argv[1]);
        usage();
      }
      break;

    case 4:
      if (!strcmp(argv[1],"-l")) {
        ns = loadNetwork(argv[2]);
        learning(ns,argv[3]);
      } else if (strcmp(argv[1],"-cl")) {
        ns = creationAuto(ns,argv[2]);
        learning(ns,argv[3]);
      } else if(strcmp(argv[1],"-w")){
        ns = loadNetwork(argv[2]);
        working(ns, argv[3]);
      } else {
        fprintf(stderr, "error : unknown switch %s\n",argv[1]);
        usage();
      }
      break;

    default:
      fprintf(stderr, "error : wrong number of arguments\n");
      usage();
      break;
  }

  // Prnting Propositions
  while (!secure) {
    fprintf(stderr, "\n\nDo you want to see the network ? ");
    scanf("%s", answer);
    noCast(answer,3);
    if (!strcmp("NO",answer)) {
      secure = 1;
    } else if (!strcmp("YES",answer)) {
      printNetwork(ns);
      secure = 1;
    } else {
      fprintf(stderr, "This answer ( %s ) is not available\n\n", answer );
    }
  }
  secure = 0;

  // Save Propositions
  while (!secure) {
    fprintf(stderr, "\n\nDo you want to save the changes ? ");
    scanf("%s", answer);
    noCast(answer,3);
    if (!strcmp("NO",answer)) {
      secure = 1;
    } else if (!strcmp("YES",answer)) {
      saveNetwork(ns);
      secure = 1;
    } else {
      fprintf(stderr, "This answer ( %s ) is not available\n\n", answer );
    }
  }

  //freeing Network
  freeNetwork(ns);

  system("clear");

  return 0;
}

void usage(){
  fprintf(stderr, "usage : nsp <option> [<file.ai>] [<file.data>]\n");
  fprintf(stderr, "     -c                            creation of a network\n");
  fprintf(stderr, "     -c <file.ai>                  creation of a default network from data in file.ai\n");
  fprintf(stderr, "     -l <file.ai> <file.data>      learning from file.data \n");
  fprintf(stderr, "     -cl <file.data>               creation of a network and learning from file.data\n");
  fprintf(stderr, "     -cl <file.ai> <file.data>     creation of a default network from data in file.ai and learning from file.data\n");
  fprintf(stderr, "     -w <file.ai> <file.data>      apply the network on the datas\n\n\n");
}

void learning(struct Network * ns,const char * data_file){
  fprintf(stderr, "learning\n");

}

void working(struct Network * ns,const char * data_file){
  fprintf(stderr, "working\n");

}

struct Network * loadNetwork(const char * ai_file){
  struct Network * ns = NULL;
  return ns;
}
