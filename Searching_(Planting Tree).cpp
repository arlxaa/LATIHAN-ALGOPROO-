#include<stdio.h>
#include<string.h>

struct data{
	char name[45];
	char plant[45];
};

int main(){
	int a, b;
	char cari[45];
	
	FILE *wle;
	wle = fopen("testdata.in", "r");
	fscanf(wle, "%d", &a); fgetc(wle);
	
	struct data masuk[a];
	for (int i = 0 ; i < a; i++){
		fscanf(wle, "%[^#]#%[^\n]", masuk[i].name, masuk[i].plant);
		fgetc(wle);
	}
	fscanf(wle, "%d", &b);
	
	for (int i = 0; i < b; i++){
		fscanf(wle, "%s\n", cari);
		for (int j = 0 ; j < a; j++){
			if (strcmp(cari, masuk[j].name) ==0){
				printf("Case #%d: %s\n", i+1, masuk[j].plant);
				break;
			} else if(j == a-1){
				printf("Case #%d: N/A\n", i+1);
			}
		}
	}
	
	
	
}
