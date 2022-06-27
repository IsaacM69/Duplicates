#include  "duplicates.h"

//Functions for analyzing and acquiring information about files

//Returns true if two files are the same
bool same_file(char *file1,char *file2) {
	bool same = true;
	char *hash1 = strSHA2(file1);
	char *hash2 = strSHA2(file2);
	
	int i = 0;
	while(hash1[i] != '\0'){
		if(hash1[i] != hash2[i]) {
			same = false;
		}
	i++;
	}
	return(same);
}
//Gets size of each file and if its unique
void checkFiles() {
	for(int index = 0; index < number_of_files; index++) {
		
	FILE* fp = fopen(files[index].filePath, "r"); // opening a file in read mode
	
	if (fp == NULL) {		// checking whether the file exists or not {
	  printf("File couldn't be opened%s\n",files[index].filePath);
      printf("File Not Found!\n");
      exit(EXIT_FAILURE);
	}
	//Check to se if current file is the same as any that haven't been checked
	int a = 0;
	for(int i = index + 1; i < number_of_files; i++) {

		if(!files[index].unique) {	
		break;
		}
		
		bool same = same_file(files[index].filePath, files[i].filePath);
		if(same){
			files[i].unique = false;
			files[index].sameFiles[a] = files[i].filePath;
			a++;
		}
		
	}
	files[index].number_of_duplicates = a;
		
		
	//Get file size
	fseek(fp, 0L, SEEK_END);
	unsigned int res = ftell(fp); //counting the size of the file
	files[index].size = res;
	fclose(fp); //closing the file

	}
}
//Prints the size of all files unique files and size of uniqe files
void size_unique() {
	unsigned int totalSize = 0;
	int unique = 0;
	unsigned int uniqueSize = 0;
	for(int index = 0; index < number_of_files; index++) {
		totalSize = totalSize + files[index].size;
		if(files[index].unique) {
			unique++;
			uniqueSize = uniqueSize + files[index].size;
		}
	}
	printf("%d\n", totalSize);
	printf("%d\n", unique);
	printf("%d\n", uniqueSize);
	
}