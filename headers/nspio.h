#include "/Users/paolicedric/Desktop/Neural_Package/headers/nspstd.h"
// PreProc variable
#ifndef MAX_LENGTH_FILE_NAME
#define MAX_LENGTH_FILE_NAME 256
#endif
#ifndef EXTENTION
#define EXTENTION ".ai"
#endif
#ifndef LENGTH_EXTENTION
#define LENGTH_EXTENTION 4
#endif
#ifndef SAVING_FILE_NAME
#define SAVING_FILE_NAME "nsp.ai"
#endif

// Data Structure

// Function
void afficheNeurone(struct Neurone * neur,int n);
void loadNeurone(struct Network * ns, FILE * file, int i, int j);
void saveNetwork (struct Network * ns);
