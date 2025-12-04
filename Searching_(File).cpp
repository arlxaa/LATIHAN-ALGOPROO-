#include <stdio.h>
#include <string.h>

struct kata{
	char a[105];
	char b[105];
};

int main(){
	int a, b, length;
	char kalimat[105];
	char *potong;
	
	FILE *wle;
	wle = fopen("testdata.in", "r");
	
	fscanf(wle, "%d", &a); fgetc(wle);
	
	struct kata cek[a];
	
	for (int i = 0 ; i < a; i++){
		fscanf(wle, "%[^#]#%[^\n]", cek[i].a, cek[i].b);
		fgetc(wle);
	}
	fscanf(wle, "%d", &b); 
	fgetc(wle);
	
	for (int i = 0 ; i < b; i++){
		fscanf(wle, "%[^\n]", kalimat);
		fgetc(wle);
		potong = strtok(kalimat, " ");
		int first = 1;
		int found = 0;
		printf("Case #%d:\n", i+1);
		while (potong != NULL){
			if (first == 1){
				first = 0;
			} else if (first == 0){
				printf(" ");
			}
			for (int j = 0 ; j < a; j++){
				if (strcmp(potong, cek[j].a)==0){
					found = 1;
					printf("%s", cek[j].b);
					break;
				} else if (j ==a-1){
					found =0;
				}
			}
			if (found == 0){
				printf("%s", potong);
			}
			potong = strtok(NULL, " ");
		}
		printf("\n");	
	}	
}

