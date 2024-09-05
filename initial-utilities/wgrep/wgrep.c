#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	if(argc<2){
		printf("wgrep: searchterm [file ...]\n");
		return 1;
	}
	FILE *file;
	char *line=argv[1];
	char str[256];

	if(argc==2){
		while(fgets(str,sizeof(str),stdin)!=NULL){
			if(strstr(str,line)!=NULL){
				printf("%s",str);
			}
		}
	}
	else{
		for(int i =2;i<argc;i++){
			file=fopen(argv[i],"r");
			if(file == NULL){
				printf("wgrep: cannot open file\n");
				return 1;
			}
			while(fgets(str,sizeof(str),file)!=NULL){
				if(strstr(str,line)!=NULL){
					printf("%s",str);
				}
			}
			fclose(file);
		}
	}

	
	return 0;
}
