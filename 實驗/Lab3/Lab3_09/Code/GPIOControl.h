using namespace std;

int ioExport(unsigned int gpio);

int ioUnexport(unsigned int gpio);

int ioSetDir(unsigned int gpio, string dirStatus);  // dirStatus="in", "out"

int ioSetValue(unsigned int gpio, int value);