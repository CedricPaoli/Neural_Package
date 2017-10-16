#include "nspstd.h"
// PreProc variable
#ifndef MAX_LENGTH_FILE_NAME
#define MAX_LENGTH_FILE_NAME 256
#endif

// Data Structure

// Function
void afficheNeurone(struct Neurone * neur,int n);
void saveNeuron(struct Neurone * n);
void loadNeurone(struct Network * ns, FILE * file, int i, int j);
void saveNetwork (struct Network * ns);
