#include  <stdio.h>
#include  <stdbool.h>
#include  <stdlib.h>
#include  <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <getopt.h> 


// DECLARE GLOBAL  CONSTANTS
#define  MAXFILES  1000	//Maximum number of files program can detect

// DECLARE GLOBAL FUNCTIONS
extern char *strSHA2(char *);
extern void traverse_directory(char *);
extern void checkFiles();
extern void size_unique();
extern bool same_file(char *, char *);
extern void print_same(char*);
extern void print_duplicates();
extern void print_same_hash(char*);
extern void find_unique();

// DECLARE GLOBAL VARIABLES

//Structure for storing information about a file
struct directFile {
char *sameFiles[MAXFILES];	//Path of duplicate files
int number_of_duplicates;  //Number og files that are the same as the current file
char  *filePath;   //Path to file
bool unique; //True if file is unique
unsigned int size; //Size of file
}file;

extern struct directFile  files[];
extern int number_of_files;
extern bool hidden;



