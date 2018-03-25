#include <stdio.h>
#include <stdlib.h>

//Declara os protótipos das funções
void exibeOnzeTracos (void);
void retanguloTracos (void);

int main (void) {
	
	//Chama a função 'retanguloTracos' dentro da 'main'
	retanguloTracos();
	printf ("\n");
	retanguloTracos();
	
	return 0;
}
//Função para exibir o retângulo de traços
void retanguloTracos (void) {
	
	//Variável local
	int i;
	//Loop para chamar 4x a função exibeOnzeTracos
	for (i = 0; i < 4; i++) {
		exibeOnzeTracos();
		printf ("\n");
	}		
}
//Função exibeOnzeTracos
void exibeOnzeTracos (void) {
	
	//Variável local
	int i;
	//Loop para imprimir 11 traços na tela
	for (i = 0; i < 11; i++)
		printf ("-");	
}


