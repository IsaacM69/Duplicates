# Makefile to build duplicates program
# To run type make then ./duplicates {command line options} directory
# make clean to clear object files


duplicates : traverse.o duplicates.o globals.o strSHA2.o checkFiles.o commandOptions.o
	cc -std=c11 -Wall -Werror -o duplicates \
                  traverse.o duplicates.o globals.o strSHA2.o checkFiles.o commandOptions.o -lm


duplicates.o : duplicates.c duplicates.h
	cc -std=c11 -Wall -Werror -c duplicates.c

globals.o : globals.c duplicates.h
	cc -std=c11 -Wall -Werror -c globals.c

strSHA2.o : strSHA2.c duplicates.h
	cc -std=c11 -Wall -Werror -c strSHA2.c 

traverse.o : traverse.c duplicates.h
	cc -std=c11 -Wall -Werror -c traverse.c

checkFiles.o : checkFiles.c duplicates.h
	cc -std=c11 -Wall -Werror -c checkFiles.c

commandOptions.o : commandOptions.c duplicates.h
	cc -std=c11 -Wall -Werror -c commandOptions.c

clean:
	rm -f *.o duplicates
