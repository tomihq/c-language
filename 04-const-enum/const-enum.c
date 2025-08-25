#include <stdio.h>

int main(){
	const double x = 10.0; 
	const long double a = 10.0L;
	const float b = 10.0F;

	enum Day {MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY};
	printf("%f \n", x);
	printf("%Lf \n", a);
	printf("%f \n", b);
	printf("%d \n", MONDAY); //0
	printf("%d \n", TUESDAY); //1

	return 0;
}
