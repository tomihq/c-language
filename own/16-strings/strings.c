#include <stdio.h>

int length(char* str);


int main(){
	char str[] = "This too shall pass";
	printf("Amount of chars in the string: %d \n", length(str));
	return 0;
}


int length(char* str){
	int len = 0;
	while(*str != '\0'){
		len++;
		str++; //move the pointer to the next char.
	}
	return len;
}

