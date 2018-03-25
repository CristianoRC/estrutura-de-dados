#include <stdio.h>

//Declara o prot�tipo da fun��o e os ponteiros
void duplaCrescente (int valor1, int valor2, int *p1, int *p2);

//Fun��o principal
int main (void) {
	//Declara��o das vari�veis
	int valor1, valor2, p1, p2;
	//La�o para leitura dos valores
	do {
		printf ("Informe dois valores inteiros: ");
		scanf ("%d %d", &valor1, &valor2);
		//Valida��o
		if (valor1 != valor2) {
			//Chama a fun��o passando os par�metros e as posi��es de mem�ria de cada ponteiro
			duplaCrescente(valor1, valor2, &p1, &p2);
			//Imprime os valores alocados em cada ponteiro
			printf ("%d %d\n", p1, p2);
		}	
	//Repete enquando valores digitados forem v�lidos	
	}while (valor1 != valor2);
	
	return 0;
}
//Fun��o duplaCrescente
void duplaCrescente (int valor1, int valor2, int *p1, int *p2) {
	//Valida��es
	if (valor1 > valor2) {
		*p1 = valor2;
		*p2 = valor1;
	}else {
		*p1 = valor1;
		*p2 = valor2;
	}
}
