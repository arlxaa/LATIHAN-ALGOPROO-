#include <stdio.h>

int main(){
	int t, x, prime;
	scanf("%d", &t);
	
	for (int tc = 1; tc <= t ; tc++){
		scanf("%d", &x);
		prime = 1;
		for (int i = 2 ; i*i <= x; i++){
			if (x%i == 0){
				prime = -1;
				break;
			} 
		}
		printf("Case #%d: ", tc);
		if (prime == 1){
			printf("prime\n");
		} else{
			printf("not prime\n");
		}
	}
	
}



