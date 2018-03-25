#include <stdio.h>

//Declara o protótipo da função
int calcDivisao (int valor1, int valor2, float *res);

//Função principal
int main (void) {
	//Declara as variáveis
	int q, i, valor1, valor2;
	float res;
	//Lê a quantidade de termos do programa
	printf ("Informe um valor: ");
	scanf ("%d", &q);
	//Laço com 'q' termos
	for (i = 0; i < q; i++) {
		//Lê os termos
		printf ("Informe dois valores: ");
		scanf ("%d %d", &valor1, &valor2);
		//Chama a função, validando se o valor de retorno será '0' ou '1'
		if (calcDivisao(valor1, valor2, &res) == 1)
			//Se for 1, imprime mensagem de erro (Divisão por zero)
			printf ("Divisao por Zero\n");
		else {
			//Se for 0, divisão executada com sucesso e imprime o resultado
			printf ("%.1f\n", res);
		}	
	}
	
	return 0;
}
//Função calcDivisao
int calcDivisao (int valor1, int valor2, float *res) {
	//Validação
	if (valor2 != 0) {
		*res = (float) valor1 / valor2;
		return 0;
	}else
		return 1;
}
