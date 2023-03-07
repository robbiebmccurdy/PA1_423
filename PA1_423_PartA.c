#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	//Part A
	FILE* file; //establishes a pointer to the input file
	FILE* outfile; //establishes a pointer to the output file
	char ch; //will be used to record our string
	file = fopen(argv[1], "a+"); //opens the file to view and append to it if necessary
	//the next few ifs are just checking the call of the program was correct
	if (argv[1] == NULL){
		printf("Please format the call of this program as: %s textfile1.txt textfile2.txt\n", argv[0]);
		exit(0);
	}

	if (argv[2] == NULL){
		printf("Please format the call of this program as: %s textfile1.txt textfile2.txt\n", argv[0]);
		exit(0);
	}

	if (NULL == file) {
		printf("Input file can't be opened \n");
		exit(0);
	}

	if(argv[3] != NULL){
		printf("There are too many arguments when calling %s, please call them in this format: %s %s %s\n", argv[0], argv[0], argv[1], argv[2]);
		exit(0);
	}
	//printing the contents of the input file

	FILE* printfile;
	printfile = fopen(argv[1], "a+");
		
	char nw;
	printf("\n");
	printf("Printing the contents of %s...\n", argv[1]);
	
	while((nw=fgetc(printfile))!=EOF) {
      		printf("%c",nw);
   	}

	outfile = fopen(argv[2], "w");
	//opening the output file to write to it
	//if no file, will return we can't open the file
	if (NULL == file) {
		printf("cannot open output file \n");
		exit(0);
	} else {
		printf("Opening %s...\n", argv[2]);
	}
	printf("Printing to %s...\n", argv[2]);
	int c;
	do
	{
		c = fgetc(file);
		
		if(feof(file)){
			break;
		}
		printf("%c ", c);
		fputc(c, outfile);
	} while(1);

	printf("\n");
	
	fclose(printfile);
	fclose(file);
	fclose(outfile);
	return 0;
}