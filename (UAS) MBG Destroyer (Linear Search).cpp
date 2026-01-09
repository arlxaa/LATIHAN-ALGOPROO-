#include <stdio.h>

int main(){
	int x, y;
	scanf("%d %d", &x, &y);
	int mbg[x];
	int cari;
	
	for (int i = 0 ; i < x; i++){
		scanf("%d", &mbg[i]);
	}
	for (int i = 0 ; i < y ; i++){
		scanf("%d", &cari);
		//looping cari linear search
		
		for (int j = 0; j < x ; j++){
			if (mbg[j] == cari){
				printf("MBG %d was located in %d meters!\n", cari, j+1);
				break;
			} else if (j == x-1){
				printf("MBG %d was not located!\n", cari);
			}
		}
	}
	
	
}
