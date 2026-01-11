#include <stdio.h>

long long counter = 0;

long long fraktal_b(long long x){
	long long i;
	if (x<= 0){
		return counter;
	} else{
		fraktal_b(x-1);
		counter += x;
		
		fraktal_b(x-2);
	}
}

int main(){
	long long x;
	scanf("%lld", &x);
	long long ans = fraktal_b(x);
	printf("%lld\n", ans);
}

