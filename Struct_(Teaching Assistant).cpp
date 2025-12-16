#include <stdio.h>
struct group {
	int kel;
	char nama[11];
};

int main(){
	int a, b;
	scanf("%d", &a); getchar();
	
	
	for (int t = 1 ; t <= a; t++){
		scanf("%d", &b); getchar();
		struct group wle[b];
		int index[25]={0};
		for (int i = 0 ; i < b; i++){
			scanf("%s %d", wle[i].nama, &wle[i].kel); getchar();
			index[wle[i].kel]++;
		}
		printf("Case #%d:\n", t);
		for (int i = 1 ; i < 26 ; i++){
			
			if (index[i]>0){
				printf("Group %d(%d):\n", i, index[i]);
				for (int j = 0 ; j < b ; j++){
					if (wle[j].kel == i){
						printf("%s\n", wle[j].nama);
					}
				}
			}
			
		}
	}
}
