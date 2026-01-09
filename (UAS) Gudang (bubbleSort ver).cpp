#include <stdio.h>
#include <string.h>

struct gudank{
	char item[101];
	int stock;
};
int main(){
	int t, a, b;
	scanf("%d", &t);
	struct gudank wle[t];
	
	for (int i = 0 ; i < t; i++){
		scanf("%s %d %d", wle[i].item, &a, &b); getchar();
		wle[i].stock = a-b;
	}
	
	for (int i = 0 ; i < t-1 ; i++){
		struct gudank temp;
		for (int j = 0 ; j < t-1-i ; j++){
			if (strcmp(wle[j].item, wle[j+1].item)>0){
				temp = wle[j];
				wle[j] = wle[j+1];
				wle[j+1] = temp;
			}
		}
	}
	
	
	for (int i = 0 ; i < t; i++){
		printf("%s %d\n", wle[i].item, wle[i].stock);
	}
}



