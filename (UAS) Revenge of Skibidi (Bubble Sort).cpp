#include <stdio.h>
#include <string.h>

struct kamus{
	char kata[1010];
	int vowels;
};

int main(){
	int x, length;
	
	scanf("%d %d", &x, &length);
	
	struct kamus wle[x];
	
	for (int i = 0 ; i < x ; i++){
		scanf("%s", wle[i].kata); getchar();
		wle[i].vowels = 0;
		for (int j = 0 ; j < length ; j++){
			if (wle[i].kata[j] == 'a' || wle[i].kata[j] == 'o' || wle[i].kata[j] == 'e' || wle[i].kata[j] == 'i' || wle[i].kata[j] == 'u'){
				wle[i].vowels++;
			}
		}
	}
	
	//urutin bubble sort
	struct kamus temp;
	for (int i = 0 ; i < x-1 ; i++){
		for (int j = 0 ; j < x-1-i ; j++){
			if (wle[j].vowels < wle[j+1].vowels){
				temp = wle[j];
				wle[j] = wle[j+1];
				wle[j+1] = temp;
			} else if (wle[j].vowels == wle[j+1].vowels){
				if (strcmp(wle[j].kata, wle[j+1].kata)<0){
					temp = wle[j];
					wle[j] = wle[j+1];
					wle[j+1] = temp;
				}
			}
		}
	}
	
	for (int i = 0 ; i < x ; i++){
		printf("%s\n", wle[i].kata);
	}

}




