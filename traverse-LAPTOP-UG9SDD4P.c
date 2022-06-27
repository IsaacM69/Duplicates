#include  "duplicates.h"

// Recursively searches through a given directory to find files and add them to files array
void traverse_directory(char *basePath)
{
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);

    // Unable to open directory stream
    if (!dir){
        return;
	}

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {	
			struct stat  stat_buffer;
			//Ignore hidden files and directories unless -a is selected
			if(dp->d_name[0] == '.' && hidden == false) {
			}
			else{
			// Create a path to the current file
			char *new = malloc( strlen(basePath)+ strlen(dp->d_name) + 200 );
			strcpy(new, basePath);
			strcat(new,"/");
			char *new2 = malloc(strlen(dp->d_name) + 1 );
			strcpy(new2, dp->d_name);
			strcat(new,new2);
			
			//Check that file is not a directory to add it to files array
			if(stat(new, &stat_buffer) != 0) {
            continue;
			}

			if(!S_ISDIR( stat_buffer.st_mode )) {
				//Ignore hidden files unless -a is selected
				if(dp->d_name[0] != '.' || hidden) {
				files[number_of_files].filePath = new;
				files[number_of_files].unique = true;
				number_of_files++;
				}
			}

            // Construct new path from our base path
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);
			
            traverse_directory(path);
			}
        }
    }
    closedir(dir);
}
