// PreProc variable

// Data Structure
enum typestruct { SIMPLE, GRAPH };

struct Neurone {
  double biais;
  double value;
  double sensibility;
  double * weight;
};

struct Network {
  int number_of_layer;
  int * number_by_layer;
  struct Neurone *** tab;
};

// Function
void usage();
void learning(struct Network * ns,const char * data_file);
void working(struct Network * ns,const char * data_file);
struct Network * loadNetwork(const char * ai_file);
struct Network * creationManual();
void afficheNeurone(struct Neurone * neur,int n);
void loadNeurone(struct Network * ns, FILE * file, int i, int j);
struct Network * creationAuto(struct Network * ns, const char * ai_file);
