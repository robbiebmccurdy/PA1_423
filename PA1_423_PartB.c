#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	//Part A
	FILE* file; //establishes a pointer to the input file
	FILE* outfile; //establishes a pointer to the output file
	char ch;
	
	printf("Opening %s...\n", argv[1]);

	file = fopen(argv[1], "a+"); //opens the file

	//the next few ifs check the call of the program was correct

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
	
	printf("\n");
	outfile = fopen(argv[2], "w");
	//opening the output file to write to it
	//if no file, will return we can't open the file
	if (NULL == file) {
		printf("cannot open output file \n");
		exit(0);
	} else {
		printf("Opening %s...\n", argv[2]);
	}
	printf("\n");
	printf("Printing to %s...\n", argv[2]);
	int c;
	int* arr;
	arr = (int*)malloc(sizeof(int));
	int index = 0;
	//memory allocation and reallocation
	if (arr == NULL) {
        	printf("memory cannot be allocated");
    	}
		
	while(fscanf(file,"%d", &arr[index]) == 1){
		index++;
		arr = (int*)realloc(arr, (index + 1) * sizeof(int));
	}		
	
	int x;
	int y;
	int min;
	//sort the array using selection sort
	for (x = 0; x < (sizeof(arr)) - 1; ++x){
		min = x;
		for(y = x + 1; y < (sizeof(arr)); ++y)
			if(arr[y] < arr[min])
				min = y;
		
			 if(min != x)
				swap(&arr[min], &arr[x]);
	}	
	//print sorted array
	printf("The integers in file %s after sorting:\n", argv[1]);
	int pr;
	for(pr = 0; pr < sizeof(arr); ++pr){
		if(pr + 1 == sizeof(arr)){
			printf("%d", arr[pr]);
		} else {
		printf("%d,", arr[pr]);
		}
	}

	int j;
	for(j = 0; j < sizeof(arr); ++j){
		if(j + 1 == sizeof(arr)){
			fprintf(outfile,"%d", arr[j]);
		} else {
		fprintf(outfile,"%d,", arr[j]);
		}
	}

	printf("\n");
	
	free(arr);
	fclose(printfile);
	fclose(file);
	fclose(outfile);
	return 0;
}

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}