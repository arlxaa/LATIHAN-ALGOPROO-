#include <stdio.h>
int counter;

int S(int n){
	if (n==0){
		return 0;
	} 
	
	if (n%2 == 0){
		counter++;
	}
	return S(n-1)+n;
}

int main(){
	int t, n;
	scanf("%d", &t);
	for (int tc = 1; tc <= t ; tc++){
		counter = 0;
		scanf("%d", &n);
		int wle = S(n);
		printf("Case #%d: %d %d\n",tc , wle, counter);
	}
}


