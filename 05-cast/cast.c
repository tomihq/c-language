#include <stdio.h>

int main(){
	const float a = 0.1F;
	const double b = 0.2;
	const int c = (int) a;
	const int d = (int) b;

	printf("a: %f \n", a);
	printf("b: %f \n", b);
	printf("c: %d \n", c);
	printf("d: %d \n", d);

	return 0;
}
