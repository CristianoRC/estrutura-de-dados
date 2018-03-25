#include <stdio.h>

//Define a estrutura para o tipo 'Data'
typedef struct {
	
	int dia, mes, ano;
	
} Data;

//Define a estrutura para o tipo 'Aluno'
typedef struct {
	
	int matricula;
	Data dt_Nasc;
	
} Aluno;

//Fun��o principal
int main (void) {
	
	//Declara��o das vari�veis
	Aluno alu[5];
	Data dt, vetor_Dt[5];
	int i, c = 0;
	
	//Loop para ler os dados dos alunos
	for (i = 0; i < 5; i++) {
		printf ("Informe a matricula do aluno %d: ", i+1);
		scanf ("%d", &alu[i].matricula);
		printf ("Informe a data de nascimento do aluno %d: ", i+1);
		scanf ("%d %d %d", &alu[i].dt_Nasc.dia, &alu[i].dt_Nasc.mes, &alu[i].dt_Nasc.ano);
		printf ("\n");
	}
	
	//L� a data de refer�ncia
	printf ("Informe uma data: ");
	scanf ("%d %d %d", &dt.dia, &dt.mes, &dt.ano);
	printf ("\n");
	
	/*Verifica se o M�s de nascimento do aluno[i] � igual ao m�s da data de refer�ncia, caso seja
	copia para o vetor de datas e incrementa o contador*/
	for (i = 0; i < 5; i++) {
		if (alu[i].dt_Nasc.mes == dt.mes) {
			vetor_Dt[c] = alu[i].dt_Nasc;
			c++;
		}
	}
	//Imprime a(s) data(s) em que o m�s da data refer�ncia esteja presente
	for (i = 0; i < c; i++) 
		printf ("%d %d %d\n", vetor_Dt[i].dia, vetor_Dt[i].mes, vetor_Dt[i].ano);
	
	printf ("\n");
	
	return 0;
}
