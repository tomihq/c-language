#include <stdio.h>

int main(){
	char c = 100;
	unsigned char c2 = -100;
	short s = -8712;
	unsigned short s2 = -8712;
	int i = 123456;
	long l = 123456789;
	unsigned long l2 = -123456789;
	
	printf("char(%lu): %d \n", sizeof(c), c);
	printf("short(%lu): %d \n", sizeof(s), s);
	printf("int(%lu): %d \n", sizeof(i), i);
	printf("long(%lu): %ld \n", sizeof(l), l);
	printf("unsigned char(%lu): %d \n", sizeof(c2), c2);
	printf("unsigned short(%lu): %d \n", sizeof(s2), s2);
	printf("unsigned long(%lu): %ld \n", sizeof(l2), l2);

	return 0;

}
