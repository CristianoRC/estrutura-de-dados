#include <stdio.h>

//Declara o prot�tipo da fun��o
void exibeDivisores (int n);

//Fun��o principal
int main (void) {
	//Vari�vel local da fun��o main
	int i;
	//Loop para chamar a fun��o exibeDivisores passando 'i' como par�metro
	for (i = 1; i <= 20; i++) 
		exibeDivisores(i);
	
	return 0;
}
//Fun��o exibeDivisores
void exibeDivisores (int n) {
	//Vari�vel local da fun��o exibeDivisores
	int i;
	//Imprime o 'n' vindo como par�metro da fun��o main
	printf ("%d: ", n);
	//Loop que verifica todos os divisores do 'n' vindo do main
	for (i = 1; i <= n; i++) {
			if (n % i == 0)
				//Imprime o divisor
				printf ("%d ", i);	
	}
	//Quebra de linha
	printf ("\n");
}
