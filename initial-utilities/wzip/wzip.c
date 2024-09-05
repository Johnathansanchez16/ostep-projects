#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char *argv[]){

	if(argc<2){
		printf("wzip: file1 [file2 ...]\n");
		return 1;
	}
	FILE *file;
	int count=1;
	char prevChar;
	char character;
	for(int i=1;i<argc;i++){
		file=fopen(argv[i],"r");
		if(file==NULL){
			printf("wzip: cannot open file\n");
			return 1;
		}
		if(i==1){
			prevChar=fgetc(file);
		}
		
		while((character=fgetc(file))!=EOF){
			if(prevChar==character){
				count++;
			}
			else{
				fwrite(&count, sizeof(int), 1, stdout);
				printf("%c",prevChar);
				prevChar=character;
				count=1;
			}	

		}
		if(i+1==argc){
			fwrite(&count, sizeof(int), 1, stdout);
			printf("%c",prevChar);
			prevChar=character;
			count=1;
		}
		fclose(file);
	}
	return 0;
}