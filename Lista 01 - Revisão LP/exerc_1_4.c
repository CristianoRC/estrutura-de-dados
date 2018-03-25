#include <stdio.h>

//Declara o prot�tipo da fun��o
int maiorNumero (int n1, int n2);
//Fun��o principal
int main (void) {
	//Declara as vari�veis da fun��o main, sendo 'n1' e 'n2' vari�veis globais, pois 'conectam' as fun��es 
	int q, maior, i, n1, n2;
	//L� 'q' que determina a quantidade de duplas a serem lidas
	printf ("Informe um numero: ");
	scanf ("%d", &q);
	//Loop para ler as duplas e chamar a fun��o maiorNumero para cada dupla
	for (i = 0; i < q; i++) {
		printf ("Informe dois numeros: ");
		scanf ("%d %d", &n1, &n2);
		//Joga o resultado retornado pela fun��o na vari�vel 'maior'
		maior = maiorNumero(n1, n2);
		//Se o valor retornado n�o for negativo, imprime o maior
		if (maior > 0)
			printf ("Maior numero = %d\n", maior);
		//Se resultado negativo, imprime mensagem
		else
			printf ("Eles sao iguais\n");	
	}
	
	return 0;
}
//Cria��o da fun��o maiorNumero
int maiorNumero (int n1, int n2) {
	//Valida��es
	if (n1 == n2)
		return -1;
	else
		if (n1 > n2)
			return n1;
		else
			return n2;			
} 
