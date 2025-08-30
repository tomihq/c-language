#include <stdio.h>
#include <stdint.h>

typedef struct {
	char nombre[50];
	uint32_t edad;
} persona_t;

typedef struct {
	char nombre[50];
	uint32_t vida;
	double ataque;
	double defensa;

} monstruo_t;

static void fn1();
static void fn2();
static void print_msg(persona_t* p);
static void print_monstruo(monstruo_t* m);


int main(){
  fn1();
  fn2();
  return 0;
}

void fn1(){
  const persona_t p1 = {"Tomas", 20}; //way 1
  printf("-----P1------ \n");
  print_msg(&p1); 

  const persona_t p2 = {.nombre = "Jill"}; //way 2
  printf("-----P2------ \n");
  print_msg(&p2);
  
  persona_t p3 = p2;
  p3.edad = 40; //way 3
  printf("-----P3------ \n");
  print_msg(&p3);
  
  printf("----P2------ \n"); //should be Jill and age 0.
  print_msg(&p2);
	return;
}

void fn2(){
	const monstruo_t monsters[3] = {
		[0] = {"M", 100, 30, 40},
		[1] = {"V", 80, 40, 10},
		[2] = {"R", 80, 40, 20}
	};

	const uint32_t cant_monstruos = sizeof(monsters) / sizeof(monsters[0]);

	for(int i=0; i<cant_monstruos; i++){
		printf("----Monstruo: %d---- \n", i+1);
		print_monstruo(&monsters[i]);
	}

	return;
}

void print_msg(persona_t* p){
	printf("nombre: %s, edad: %d \n", p->nombre, p->edad);
	return;
}

void print_monstruo(monstruo_t* m){
	printf("nombre: %s, vida: %d, ataque: %f, defensa: %f \n", m->nombre, m->vida, m->ataque, m->defensa);
	return;
}


