#include <stdio.h>

//Declara o protótipo da função
void classificaCrescente (int *valor1, int *valor2);

//Função principal
int main (void) {
	//Declaração das variáveis
	int valor1, valor2;
	//Laço de leitura dos valores
	do {
		printf ("Informe dois valores inteiros: ");
		scanf ("%d %d", &valor1, &valor2);
		//Validação
		if (valor1 != valor2) {
			classificaCrescente(&valor1, &valor2);
			printf ("%d %d\n", valor1, valor2);
		}
	//Repete enquando os valores digitados forem válidos	
	}while (valor1 != valor2);
	
	return 0;
}
//Função classificaCrescente
void classificaCrescente (int *valor1, int *valor2) {
	//Declara variável auxiliar que é exclusiva da função
	int aux;
	//Validações e trocas de conteúdos das posições de memória das variáveis 'valor1' e 'valor2'
	if (*valor1 > *valor2) {
		aux = *valor1;
		*valor1 = *valor2;
		*valor2 = aux;
	}else {
		*valor1 = *valor1;
		*valor2 = *valor2;
	}
}
