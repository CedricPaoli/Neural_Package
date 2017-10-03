#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "nspstd.h"

int main(int argc, char const *argv[]) {

  struct Network * ns;
  ns = malloc(sizeof(struct Network));

  switch (argc) {

    case 2:
      if (!strcmp(argv[1],"-c")) {
        ns = creationManual();
      } else{
        fprintf(stderr, "ARGV[0] : %s, ARGV[1] : %s, ARGV[2] : %s, ARGV[3] : %s,\n", argv[0],argv[1],argv[2],argv[3]);
        fprintf(stderr, "error : unknown switch %s\n",argv[1]);
        usage();
      }
      break;

    case 3:
      if (!strcmp(argv[1],"-c")) {
        ns = creationAuto(ns,argv[2]);
        fprintf(stderr, "ARGV[0] : %s, ARGV[1] : %s, ARGV[2] : %s, ARGV[3] : %s,\n", argv[0],argv[1],argv[2],argv[3]);
      } else if (!strcmp(argv[1],"-cl")) {
        fprintf(stderr, "ARGV[0] : %s, ARGV[1] : %s, ARGV[2] : %s, ARGV[3] : %s,\n", argv[0],argv[1],argv[2],argv[3]);
        ns = creationManual();
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

  return 0;
}

void usage(){
  fprintf(stderr, "usage : nsp <option> [<file.ia>] [<file.data>]\n");
  fprintf(stderr, "     -c                            creation of a network\n");
  fprintf(stderr, "     -c <file.ia>                  creation of a default network from data in file.ia\n");
  fprintf(stderr, "     -l <file.ia> <file.data>      learning from file.data \n");
  fprintf(stderr, "     -cl <file.data>               creation of a network and learning from file.data\n");
  fprintf(stderr, "     -cl <file.ia> <file.data>     creation of a default network from data in file.ia and learning from file.data\n");
  fprintf(stderr, "     -w <file.ia> <file.data>      apply the network on the datas\n\n\n");
}

void learning(struct Network * ns,const char * data_file){
  fprintf(stderr, "learning\n");

}

void working(struct Network * ns,const char * data_file){
  fprintf(stderr, "working\n");

}

struct Network * loadNetwork(const char * ai_file){
  fprintf(stderr, "LoadNet\n");
  struct Network * net;
  net = NULL;
  return net;
}
