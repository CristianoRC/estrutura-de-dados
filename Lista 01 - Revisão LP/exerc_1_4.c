#include <stdio.h>

//Declara o protótipo da função
int maiorNumero (int n1, int n2);
//Função principal
int main (void) {
	//Declara as variáveis da função main, sendo 'n1' e 'n2' variáveis globais, pois 'conectam' as funções 
	int q, maior, i, n1, n2;
	//Lê 'q' que determina a quantidade de duplas a serem lidas
	printf ("Informe um numero: ");
	scanf ("%d", &q);
	//Loop para ler as duplas e chamar a função maiorNumero para cada dupla
	for (i = 0; i < q; i++) {
		printf ("Informe dois numeros: ");
		scanf ("%d %d", &n1, &n2);
		//Joga o resultado retornado pela função na variável 'maior'
		maior = maiorNumero(n1, n2);
		//Se o valor retornado não for negativo, imprime o maior
		if (maior > 0)
			printf ("Maior numero = %d\n", maior);
		//Se resultado negativo, imprime mensagem
		else
			printf ("Eles sao iguais\n");	
	}
	
	return 0;
}
//Criação da função maiorNumero
int maiorNumero (int n1, int n2) {
	//Validações
	if (n1 == n2)
		return -1;
	else
		if (n1 > n2)
			return n1;
		else
			return n2;			
} 
