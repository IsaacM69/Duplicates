//File to initialize global variables
#include  "duplicates.h" 

struct directFile files[MAXFILES]; //Array of files of size MAXFILES
int number_of_files = 0;		   // Total number of regular files
bool hidden = false;			   //Will become true of option -a is selected to search hidden files