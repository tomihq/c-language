#include <stdio.h>
#include <stdint.h>

int main(){
	//Guarantee the number of bits exactly (no padding) 
	//Useful for binary protocols, file formats, and hardware
	int8_t a = -100; // -128 to 127 2's complement
	int16_t b = 20000; //-32,768 to 32,767
	int32_t c = -1500000000; //-2,147,483,648 to 2,147,483,647
				 
	//Fastest signed integer with witdth of at least 8, 16, 32 and 64 bits respectively.
	//Compiler may choose a larger type for faster operations on CPU 
	int_fast8_t f8 = -50;
	int_fast16_t f16 = 40000;
	int_fast32_t f32 = 3500000000U;
	int_fast64_t  f64 = 9000000000000LL;
	
	return 0;
}
