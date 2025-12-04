//Searching
#include <stdio.h>
#include <string.h>


struct data{
	char nim[25];
	char name[25];
};

int main(){
	int a, b;
	char cari[25];
	FILE *wle;
	wle = fopen("testdata.in", "r");
	
	fscanf(wle, "%d", &a); fgetc(wle);
	struct data masuk[a];
	
	for (int i = 0 ; i < a; i++){
		fscanf(wle, "%s %[^\n]\n", masuk[i].nim, masuk[i].name);
	}
	fscanf(wle, "%d", &b); fgetc(wle);
	
	for (int i = 0; i < b; i++){
		fscanf(wle, "%s\n", cari);
		for (int j = 0 ; j < a; j++){
			if (strcmp(masuk[j].nim, cari) ==0){
				printf("Case #%d: %s\n", i+1, masuk[j].name);
				break;
			}else if (j == a-1){
				printf("Case #%d: N/A\n", i+1);
			}
		}
	}
	
	
}
