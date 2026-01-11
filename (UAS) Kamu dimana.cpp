#include <stdio.h>
#include <string.h>

struct data{
	char kata[101];
	int vowels = {0};
};

int main (){
	int a, length;;
	
	scanf("%d %d", &a, &length);
	struct data wle[a];
	struct data temp;
	
	getchar();
	
	for (int i = 0 ; i < a; i++){
//		wle[i].vowels = 0;
		scanf("%s", wle[i].kata);
		getchar();
		for (int j = 0 ; j < length ; j++){
			if (wle[i].kata[j] == 'a' || wle[i].kata[j] == 'o' || wle[i].kata[j] == 'e' || wle[i].kata[j] == 'i' || wle[i].kata[j] == 'u'){
				wle[i].vowels++;
			}
		}
	}
	
	//bubblesort
	
	
	for (int i = 0 ; i < a-1; i++){
		for (int j = 0 ; j < a - i- 1 ; j++){
			if (wle[j].vowels > wle[j+1].vowels){
				temp = wle[j];
				wle[j] = wle[j+1];
				wle[j+1] = temp;
			} else if (wle[j].vowels == wle[j+1].vowels){
				if (strcmp(wle[j].kata, wle[j+1].kata)>0){
					temp = wle[j];
					wle[j] = wle[j+1];
					wle[j+1] = temp;
				}
			} 
		}
	}
	
	for (int i = 0 ; i < a ; i++){
		printf("%s\n", wle[i].kata);
	}
}
	



