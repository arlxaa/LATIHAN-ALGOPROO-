#include <stdio.h>
#include <string.h>

struct data{
	char kode[5];
	char nama[101];
	long long harga;
};

int main(){
	int n;
	scanf("%d", &n);
	getchar();
	
	struct data wle[n];
	
	for (int i = 0 ; i < n ; i++){
		
		scanf("%[^,],%[^,],%lld", wle[i].kode, wle[i].nama, &wle[i].harga);
		getchar();
	}
	char tanya[5];
	scanf("%s", tanya); getchar();
	long long counter = 0;
	int jenis = -1;
	if (strcmp(tanya, "B40") == 0){
		jenis = 1;
		for (int i = 0; i < n; i++){
			if (strcmp(tanya, wle[i].kode)==0){
				counter++;
				printf("%s %s %lld\n", wle[i].kode, wle[i].nama, wle[i].harga);
			}
		}
	} else{
		jenis = 2;
		for (int i = 0 ; i < n ; i++){
			if (strcmp(tanya, wle[i].kode)==0){
				counter++;
				printf("%s %s %lld\n", wle[i].kode, wle[i].nama, wle[i].harga);
			}
		}
	}
	printf("Total Recipients : %d\n", counter);
	printf("Total Amount : ");
	if (jenis == 1){
		printf("%lld\n", 1000*counter);
	} else{
		printf("%lld\n", 600*counter);
	}
}



