#include <stdio.h>
#include <stdint.h>

typedef struct {
	char name[50];
	uint32_t age;
} persona;

void print_msg(persona* p);

int main(){
  const persona p1 = {"Tomas", 20}; //way 1
  printf("-----P1------ \n");
  print_msg(&p1); 

  const persona p2 = {.name = "Jill"}; //way 2
  printf("-----P2------ \n");
  print_msg(&p2);
  
  persona p3 = p2;
  p3.age = 40; //way 3
  printf("-----P3------ \n");
  print_msg(&p3);
  
  printf("----P2------ \n"); //should be Jill and age 0.
  print_msg(&p2);
  return 0;
}

void print_msg(persona* p){
	printf("name: %s, age: %d \n", p->name, p->age);
	return;
}
