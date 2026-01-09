#include <stdio.h>

struct cafe{
	char nama[35];
	long long harga;
};

int main(){
	int n, mili;
	scanf("%d", &n); getchar();
	struct cafe wle[n];
	
	for (int i = 0 ; i < n; i++){
		scanf("%[^#]#%d", wle[i].nama, &mili); getchar();
		if (mili >= 0 && mili <= 354){
			wle[i].harga = 53000;
		} else if (mili > 354 && mili <= 473){
			wle[i].harga = 57000;
		} else if (mili > 473 && mili <= 591){
			wle[i].harga = 60000;
		} else{
			wle[i].harga = 70000;
		}
	}
	struct cafe temp;
	for (int i = 0 ; i < n-1 ; i++){
		for (int j = 0 ; j < n-1-i ; j++){
			if (wle[j].harga > wle[j+1].harga){
				temp = wle[j];
				wle[j] = wle[j+1];
				wle[j+1] = temp;
			}
		}
	}
	
	for (int i = 0 ; i < n ; i++){
		printf("%s - %lld\n", wle[i].nama, wle[i].harga);
	}
	
	
}



