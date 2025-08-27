#include <stdio.h>
#include <stdint.h>

int fact(int n);

/*won't work if n>=32*/
int main(){
	int32_t n = 0;
	printf("Enter the value of n (must be a positive integer): ");
	scanf("%d", &n);
	signed long long r = fact(n);
	printf("Fact n: %d is: %lld \n", n, r);
	return 0;
}

/* n must be a positive number. */
int fact(int n){
	if(n == 0) return 1; 
	return n * fact(n-1);
}
