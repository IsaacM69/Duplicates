#include  "duplicates.h"

//Functions for executing command line options

//Prints files that are the same as the selected file
void print_same(char* file) {
	bool found = false;
	for(int i = 0; i < number_of_files; i++) {
		bool same = same_file(files[i].filePath, file);
		if(same){
			found = true;
			printf("%s\n",files[i].filePath);
		}
	}
		
	if(found) {
		exit(EXIT_SUCCESS);
	}
	else {
		exit(EXIT_FAILURE);
	}
}
//Print duplicate files
void print_duplicates() {
	for(int i = 0; i < number_of_files; i++) {
		if(files[i].unique &&  files[i].number_of_duplicates != 0) {
			for(int a = 0; a < files[i].number_of_duplicates; a++) {	
					
				printf("%s	",files[i].sameFiles[a]);
			}
			printf("%s", files[i].filePath);
			printf("\n");
		}
	}
		
}
//Print files with hashes that match given hash
void print_same_hash(char* hash) {
	bool found = false;
	for(int i = 0; i < number_of_files; i++) {
				
		bool same = true;
		char *hash2 = strSHA2(files[i].filePath);
		int a = 0;
		while(hash[a] != '\0'){
			if(hash[a] != hash2[a]) {
				same = false;
				found = true;
			}
			a++;
		}
		if(same) {
			printf("%s\n",files[i].filePath);
		}
	}
	if(found) {
		exit(EXIT_SUCCESS);
	}
	else {
		exit(EXIT_FAILURE);
	}
}

//EXIT_FAILURE if non unique file is found EXIT_SUCCESS otherwise
void find_unique() {
	for(int i = 0; i < number_of_files; i++) {
		if(!files[i].unique) {
			exit(EXIT_FAILURE);
		}
	}
	exit(EXIT_SUCCESS);
}