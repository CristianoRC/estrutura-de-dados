#include <stdio.h>

//Declara o protótipo da função
void duplaClassificada (int cod, int *valor1, int *valor2);

//Função principal
int main (void) {
	//Declaração das variáveis
	int valor1, valor2, cod, soma;
	//Loop para digitação dos valores
	do {
		printf ("Informe dois valores inteiros: ");
		scanf ("%d %d", &valor1, &valor2); 
		//Validação
		if (valor1 != valor2) {
			//Soma o valor das variáveis 'valor1' e 'valor2'
			soma = valor1 + valor2;
			//Se 'soma' for par, cod = 0
			if (soma % 2 == 0)
				cod = 0;
			//Soma ímpar, cod = 1
			else
				cod = 1;
			//Chama a função
			duplaClassificada(cod, &valor1, &valor2);
			//Exibição dos resultados
			printf ("%d %d\n", valor1, valor2);		
		}
	//Repete enquanto os valores digitados forem válidos	
	}while (valor1 != valor2);
	
	return 0;
}
//Função duplaClassificada
void duplaClassificada (int cod, int *valor1, int *valor2) {
	//Variável local
	int aux;
	//Validações
	if (cod == 0) {
		if (*valor1 > *valor2) {
			aux = *valor1;
			*valor1 = *valor2;
			*valor2 = aux;
		}
	}if (cod == 1) {
		if (*valor1 < *valor2) {
			aux = *valor1;
			*valor1 = *valor2;
			*valor2 = aux;
		}
	}
}
