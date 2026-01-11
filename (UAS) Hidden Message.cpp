#include <stdio.h>

int main(){
	int n, a, b;
	char kata[100];
	
	FILE *wle;
	wle = fopen("testdata.in", "r");
	
	fscanf (wle, "%d", &n);
	fgetc(wle);
	
	for (int tc = 1; tc<= n; tc++){
		fscanf(wle, "%s %d %d", kata, &a, &b); 
		fgetc(wle);
		
		for (int i = 0 ; i <b ; i++){
			printf("%c", kata[a+i]);
		}
		printf("\n");
	}

}



