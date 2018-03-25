#include <stdio.h>

//Declara o prot�tipo da fun��o
void classificaCrescente (int *valor1, int *valor2);

//Fun��o principal
int main (void) {
	//Declara��o das vari�veis
	int valor1, valor2;
	//La�o de leitura dos valores
	do {
		printf ("Informe dois valores inteiros: ");
		scanf ("%d %d", &valor1, &valor2);
		//Valida��o
		if (valor1 != valor2) {
			classificaCrescente(&valor1, &valor2);
			printf ("%d %d\n", valor1, valor2);
		}
	//Repete enquando os valores digitados forem v�lidos	
	}while (valor1 != valor2);
	
	return 0;
}
//Fun��o classificaCrescente
void classificaCrescente (int *valor1, int *valor2) {
	//Declara vari�vel auxiliar que � exclusiva da fun��o
	int aux;
	//Valida��es e trocas de conte�dos das posi��es de mem�ria das vari�veis 'valor1' e 'valor2'
	if (*valor1 > *valor2) {
		aux = *valor1;
		*valor1 = *valor2;
		*valor2 = aux;
	}else {
		*valor1 = *valor1;
		*valor2 = *valor2;
	}
}
