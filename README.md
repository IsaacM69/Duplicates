# Duplicates
A C11 program for linux that finds duplicates of files in a directory structure


Usage: 'make' to build program

./duplicates "name of directory" for standard usage

./duplicates -f "name of file" "name of directory" prints file paths in directory that are the same as the given file

./duplicates -l "name of directory" prints duplicate files

./duplicates -h "hash" "name of directory" prints files with the same sha256 hash as the given hash

./duplicates -q "name of directory" executes with no output to command line exits with failure if non unique file is found

./duplicates -a "name of directory" program will execute and not ignore hidden files



'make clean' to delete object files
