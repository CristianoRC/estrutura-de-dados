#include <stdio.h>

//Declara o prot�tipo da fun��o
int calcDivisao (int valor1, int valor2, float *res);

//Fun��o principal
int main (void) {
	//Declara as vari�veis
	int q, i, valor1, valor2;
	float res;
	//L� a quantidade de termos do programa
	printf ("Informe um valor: ");
	scanf ("%d", &q);
	//La�o com 'q' termos
	for (i = 0; i < q; i++) {
		//L� os termos
		printf ("Informe dois valores: ");
		scanf ("%d %d", &valor1, &valor2);
		//Chama a fun��o, validando se o valor de retorno ser� '0' ou '1'
		if (calcDivisao(valor1, valor2, &res) == 1)
			//Se for 1, imprime mensagem de erro (Divis�o por zero)
			printf ("Divisao por Zero\n");
		else {
			//Se for 0, divis�o executada com sucesso e imprime o resultado
			printf ("%.1f\n", res);
		}	
	}
	
	return 0;
}
//Fun��o calcDivisao
int calcDivisao (int valor1, int valor2, float *res) {
	//Valida��o
	if (valor2 != 0) {
		*res = (float) valor1 / valor2;
		return 0;
	}else
		return 1;
}
