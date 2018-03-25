#include <stdio.h>

//Declara o protótipo da função e os ponteiros
void duplaCrescente (int valor1, int valor2, int *p1, int *p2);

//Função principal
int main (void) {
	//Declaração das variáveis
	int valor1, valor2, p1, p2;
	//Laço para leitura dos valores
	do {
		printf ("Informe dois valores inteiros: ");
		scanf ("%d %d", &valor1, &valor2);
		//Validação
		if (valor1 != valor2) {
			//Chama a função passando os parâmetros e as posições de memória de cada ponteiro
			duplaCrescente(valor1, valor2, &p1, &p2);
			//Imprime os valores alocados em cada ponteiro
			printf ("%d %d\n", p1, p2);
		}	
	//Repete enquando valores digitados forem válidos	
	}while (valor1 != valor2);
	
	return 0;
}
//Função duplaCrescente
void duplaCrescente (int valor1, int valor2, int *p1, int *p2) {
	//Validações
	if (valor1 > valor2) {
		*p1 = valor2;
		*p2 = valor1;
	}else {
		*p1 = valor1;
		*p2 = valor2;
	}
}
