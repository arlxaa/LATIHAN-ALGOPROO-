//ALPHABET CONVERTER

#include <stdio.h>
#include <string.h>

int main(){
	FILE *wle;
	wle = fopen("testdata.in", "r");
	
	int a, b;
	
	char kata[101], dari, ke;
	
	fscanf(wle, "%d", &a); fgetc(wle);
	
	for (int i = 0; i < a; i++){
		
		int index[26]={0};
		int alrChanged[26] = {0};
		
		fscanf(wle, "%s", kata); fgetc(wle);
		
		int length =  strlen(kata);
		
		fscanf(wle, "%d", &b); fgetc(wle);
		
		for (int j = 0; j < b; j++){
			fscanf(wle, "%c %c", &dari, &ke); fgetc(wle);
			
			if (alrChanged[dari-'A'] == 0){
				alrChanged[dari-'A'] = 1;
				
				for (int k = 0 ; k < length ; k++){
					if (kata[k] == dari){
					kata[k] = ke;
					}
				}	
			}
		}
		
		
		for (int j = 0; j < length ; j++){
			index[kata[j]-'A']++;
		}
		
		for (int j = 0; j < 26; j++){
			if (index[j]>0){
				printf("%c %d\n", j+'A', index[j]);
			}
		}
	}
	
	
}
