#include <stdio.h>

int main (void) {
	//Declaração das variáveis e vetores
	int q, v[10], valorMax, vMaior[10], cc, i;
	//Entrada da quantidade de elementos que terá o vetor 'v'
	printf ("Informe um valor de elementos para o vetor: ");
	scanf ("%d", &q);
	//Carrega o vetor 'v' com 'q' elementos
	for (i = 0; i < q; i++) {
		printf ("Informe o elemento %d do vetor: ", i + 1);
		scanf ("%d", &v[i]);
	}
	//Entra com um valor para máximo
	printf ("Informe um valor maximo: ");
	scanf ("%d", &valorMax);
	printf ("\n");
	//Zera contador que controlará o tamanho do vetor 'vMaior'
	cc = 0;
	//Varre o vetor 'v' comparando os valores indexados com o valorMax
	for (i = 0; i < q; i++) {
		if (v[i] > valorMax) {
			//Copia para o 'vMaior' o novo valor
			vMaior[cc] = v[i];
			//Incrementa contador
			cc++;
		}
	}
	//Imprime os valores que ficaram no vetor 'vMaior'
	printf ("Vetor com os valores maiores que o valor maximo: \n");
	for (i = 0; i < cc; i++) 
		printf ("%d ", vMaior[i]);
	
	printf ("\n");
	
	return 0;	
}
