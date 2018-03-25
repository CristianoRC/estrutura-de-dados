#include <stdio.h>

int main (void) {
	//Declaração das variáveis e da matriz
	int ql, qc, m[10][10], v, i, j, f;
	//Informa a quantidade de linhas da matriz
	printf ("Informe a quantidade de linhas da matriz: ");
	scanf ("%d", &ql);
	//Informa a quantidade de colunas da matriz
	printf ("Informe a quantidade de colunas da matriz: ");
	scanf ("%d", &qc);
	printf ("\n");
	//Carrega a matriz com os valores digitados
	for (i = 0; i < ql; i++) {
		for (j = 0; j < qc; j++) {
			printf ("Informe o elemento %d %d da matriz: ", i, j);
			scanf ("%d", &m[i][j]);
		}
		printf ("\n");
	}
	//Loop para leitura dos valores a serem verificados na matriz
	do {
		printf ("Informe um valor: ");
		scanf ("%d", &v);
		//Validação de segurança
		if (v > 0) {
			//Zera uma flag
			f = 0;
			//Varre a matriz e verifica se o valor digitado se encontra dentro dela
			for (i = 0; i < ql; i++) {
				for (j = 0; j < qc; j++) {
					if (v == m[i][j]) {
						//Se sim, muda estado da flag e interrompe o laço do for j
						f = 1;
						break;
					}
				}
				//Valida a flag, imprime mensagem e interrompe o for i
				if (f == 1) {
					printf ("Esta na Matriz\n");
					break;
				}	
			}
			//Se a flag não for alterada, o elemento não foi encontrado na matriz
			if (f == 0)
				printf ("Nao esta na Matriz\n");	
		}else
			printf ("Fim do Programa\n");
	//Repete enquando o valor digitado for maior que zero			
	}while (v > 0);
	
	return 0;
}
