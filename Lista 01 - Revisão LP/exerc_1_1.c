#include <stdio.h>
#include <stdlib.h>

int main (void) {
	
	//Declaração de variáveis
	int q, cod, i, ca = 0;
	float altura, media = 0, s = 0, maior = 0;
	//Informa quantidade de alunos
	printf ("Informe a quantidade de Alunos da turma: ");
	scanf ("%d", &q);
	//Lê altura e código dos "q" alunos
	for (i = 0; i < q; i++) {
		printf ("Informe a altura do Aluno(a): ");
		scanf ("%f", &altura);
		printf ("Informe o codigo do Aluno: ");
		scanf ("%d", &cod);
		printf ("\n");
		//Switch de códigos
		switch (cod) {
			//Se código = 1 compara a altura do menino com o conteúdo da variável 'maior' (no primeiro loop é 0)
			case 1: if (altura > maior)
						maior = altura;
						break;
			//Se código = 2 incrementa o contador 'ca' e soma a altura no somador 's'			
			case 2: ca++;
					s = s + altura;
					break;			
		}
	}
	//Se o ca != 0 calcula e imprime a media
	if (ca != 0) {
		media = s / ca;	
		printf ("Media Alunas: %.2fm\n", media);
	//Se ca == 0 imprime a média zerada	
	}else
		printf ("Media Alunas: %.2fm\n", media);
	//Imprime o valor que ficou na variável 'maior', após fazer as comparações	
	printf ("Maior Aluno: %.2fm\n", maior);

	return 0;
}
