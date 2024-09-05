#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char *argv[]){

	if(argc<2){
		printf("wunzip: file1 [file2 ...]\n");
		return 1;
	}
	FILE *file;
	int count;
	char character;
	for(int i=1;i<argc;i++){
		file=fopen(argv[i],"r");
		if(file==NULL){
			printf("wunzip: cannot open file\n");
			return 1;
		}
		
		while(fread(&count,sizeof(int),1,file) && fread(&character,sizeof(char),1,file)){
			for(int j=0;j<count;j++){
				printf("%c",character);
			}

		}
		fclose(file);
	}
	return 0;
}