#include <stdio.h>

int main(){
	int a = 5;
	int b = 3;
	int c = 2;
	int d = 1;
	printf("a+b*c/d: %d \n", a+b*c/d);
	printf("a%%b: %d \n", a%b); //como el % es un simbolo, para solamente escribirlo lo escapamos con otro %
	printf("a==b: %x, a!=b: %x \n", a==b, a!=b);
	printf("~a: %x \n", ~a); //bitwise not
	printf("a&b: %d, a|b: %d \n", a&b, a|b); //bitwise and, bitwise or
	printf("a&&b: %x, a || b: %x \n", a&&b, a||b); //bitwise not
	printf("a<<1: %d \n", a<<1); //bitwise left shift
	printf("a>>1: %d \n", a>>1); //bitwise right shift
	
	int e = 1;
	printf("++e: %d \n", ++e);
	e = 1;
	printf("e++: %d \n", e++);

	return 0;
}
