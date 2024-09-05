#include <stdio.h>

int main(int argc, char *argv[]){
	FILE *file;
	for(int i =1;i<argc;i++){
		file=fopen(argv[i],"r");
		if(file == NULL){
			printf("wcat: cannot open file\n");
			return 1;
		}
		char str[256];
		while(fgets(str,sizeof(str),file)!=NULL){
			printf("%s",str);
		}
		fclose(file);
	}
	return 0;
}
