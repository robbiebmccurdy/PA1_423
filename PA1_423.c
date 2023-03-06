#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	FILE* file;
	FILE* wrFile;
	FILE* newFile;
	char str[50];
	char newstr[50];
	file = fopen(argv[1], "a+");

	if (NULL == file) {
		printf("file can't be opened \n");
	}

	printf("Contents of the input file: \n");

	while (fgets(str, 50, file) != NULL) {
		printf("%s", str);
	}

	printf("\n");

	wrFile = fopen(argv[2], "w");

	if (NULL == wrFile) {
		printf("cannot open output file \n");
	} else {
		printf("Opening %s...\n", argv[2]);
	}

	if (strlen(str) > 0){
		fputs(str, wrFile);	
	}

	newFile = fopen(argv[2], "a+");

	if (NULL == newFile) {
		printf("output file can't be opened \n");
	}
	
	printf("This is the contents of the str %s\n", str);

	printf("Printing contents of the output file: \n");

	while (fgets(newstr, 50, newFile) != NULL) {
		printf("%s", newstr);
	}

	fclose(newFile);
	fclose(wrFile);
	fclose(file);
	return 0;
}