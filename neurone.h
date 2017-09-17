// PreProc variable

// Data Structure
struct Neurone {
  int value;
};

struct Network {
  struct Neurone ** tab;
};

// Function
void usage();
void learning(struct Network * ns,const char * data_file);
void working(struct Network * ns,const char * data_file);
struct Network * loadNetwork(const char * ai_file);
struct Network * creationManual();
struct Network * creationAuto(const char * ai_file);
