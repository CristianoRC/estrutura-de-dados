#include <stdio.h>

//Declara o protótipo da função
void exibeDivisores (int n);

//Função principal
int main (void) {
	//Variável local da função main
	int i;
	//Loop para chamar a função exibeDivisores passando 'i' como parâmetro
	for (i = 1; i <= 20; i++) 
		exibeDivisores(i);
	
	return 0;
}
//Função exibeDivisores
void exibeDivisores (int n) {
	//Variável local da função exibeDivisores
	int i;
	//Imprime o 'n' vindo como parâmetro da função main
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
