//  CITS2002 Project 2 2021
//  Name(s):             Isaac Muia
//  Student number(s):   22701047

#include  "duplicates.h"

int main(int argc, char *argv[]) {
	
	// Check command line arguments
	if(argc == 1) {
		printf("Program requires at least 1 command-line arguments, %i given\n",argc - 1);
        exit(EXIT_FAILURE);       
	}
	
	traverse_directory(argv[argc - 1]);   //Get files in directory
	checkFiles(); 	//Get size and duplicate information about files
	
	int option;
	int argument = 2;

   while((option = getopt(argc, argv, ":f:l:a:A:q:h")) != -1){
      if(option == 'f') {
			print_same(argv[argument]);
		}
		
		else if(option == 'l') {
			print_duplicates();
			argument++;
			
		}
		else if(option == 'A'){
			exit(EXIT_FAILURE);
		}
		else if(option == 'h') {
			print_same_hash(argv[argument]);
		}
		else if(option == 'q') {
			find_unique();
		}
		else if(option == 'a') {
			//Reset number of files and traverse the directory again not ignoring hidden files
			hidden = true;
			number_of_files = 0;
			traverse_directory(argv[argc - 1]); 
			checkFiles();
			argument++;
		}
   }
	printf("%d\n", number_of_files);
	size_unique();	
	exit(EXIT_SUCCESS);
	return(0);

	}
