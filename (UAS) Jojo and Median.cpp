#include <stdio.h>

struct data{
	long long kode;
	char nama[100];
	long long harga;
};

int main(){
	int n, median;
	scanf("%d", &n); getchar();
	struct data wle[n];
	for (int i = 0 ; i < n ; i++){
		scanf("%lld", &wle[i].kode); getchar();
		scanf("%[^\n]", wle[i].nama); getchar();
		scanf("%lld", &wle[i].harga); getchar();
	}
	
	median = n/2;
	
	for (int i = 0 ; i < n ; i++){
		if (wle[i].harga >= wle[median].harga){
			printf("%lld %s\n", wle[i].kode, wle[i].nama);
		}
	}
	
}



