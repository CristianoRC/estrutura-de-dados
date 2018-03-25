#include <stdio.h>

//Declara o prot�tipo da fun��o
void duplaClassificada (int cod, int *valor1, int *valor2);

//Fun��o principal
int main (void) {
	//Declara��o das vari�veis
	int valor1, valor2, cod, soma;
	//Loop para digita��o dos valores
	do {
		printf ("Informe dois valores inteiros: ");
		scanf ("%d %d", &valor1, &valor2); 
		//Valida��o
		if (valor1 != valor2) {
			//Soma o valor das vari�veis 'valor1' e 'valor2'
			soma = valor1 + valor2;
			//Se 'soma' for par, cod = 0
			if (soma % 2 == 0)
				cod = 0;
			//Soma �mpar, cod = 1
			else
				cod = 1;
			//Chama a fun��o
			duplaClassificada(cod, &valor1, &valor2);
			//Exibi��o dos resultados
			printf ("%d %d\n", valor1, valor2);		
		}
	//Repete enquanto os valores digitados forem v�lidos	
	}while (valor1 != valor2);
	
	return 0;
}
//Fun��o duplaClassificada
void duplaClassificada (int cod, int *valor1, int *valor2) {
	//Vari�vel local
	int aux;
	//Valida��es
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
