#include "/Neural_Package/headers/nspstd.h"
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
#define SAVING_FILE_NAME "/Neural_Package/ai/ns.ai"
#endif

// Data Structure

// Function
void loadNeurone(struct Network * ns, FILE * file, int i, int j);
struct Network * creationAuto(struct Network * ns, const char * ai_file);
void saveNetwork (struct Network * ns);
