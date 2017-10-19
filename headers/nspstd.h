#include "/Neural_Package/headers/neurone.h"
// PreProc variable

// Data Structure

// Function
struct Network * creationManual(struct Network * ns);
void noCast(char * answer, int n);
void autoCompletionNetwork(struct Network * ns);
void manualCompletionNetwork(struct Network * ns);
void printNetwork (struct Network * ns);
void printNetworkAddress (struct Network * ns);
void freeNeuron(struct Neurone * n);
void freeNetwork(struct Network * ns);
void learningRetroPropagation(struct Network * ns,const char * data_file);
void propagation(struct Network * ns);
void retropropagation(struct Network * ns,double alpha);
double sigmoide(struct Network * ns, int i, int j);

// END
