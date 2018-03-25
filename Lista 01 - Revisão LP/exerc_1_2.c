#include <stdio.h>
#include <stdlib.h>

//Declara os prot�tipos das fun��es
void exibeOnzeTracos (void);
void retanguloTracos (void);

int main (void) {
	
	//Chama a fun��o 'retanguloTracos' dentro da 'main'
	retanguloTracos();
	printf ("\n");
	retanguloTracos();
	
	return 0;
}
//Fun��o para exibir o ret�ngulo de tra�os
void retanguloTracos (void) {
	
	//Vari�vel local
	int i;
	//Loop para chamar 4x a fun��o exibeOnzeTracos
	for (i = 0; i < 4; i++) {
		exibeOnzeTracos();
		printf ("\n");
	}		
}
//Fun��o exibeOnzeTracos
void exibeOnzeTracos (void) {
	
	//Vari�vel local
	int i;
	//Loop para imprimir 11 tra�os na tela
	for (i = 0; i < 11; i++)
		printf ("-");	
}


