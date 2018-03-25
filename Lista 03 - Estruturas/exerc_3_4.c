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

//Função principal
int main (void) {
	
	//Declaração das variáveis
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
	
	//Lê a data de referência
	printf ("Informe uma data: ");
	scanf ("%d %d %d", &dt.dia, &dt.mes, &dt.ano);
	printf ("\n");
	
	/*Verifica se o Mês de nascimento do aluno[i] é igual ao mês da data de referência, caso seja
	copia para o vetor de datas e incrementa o contador*/
	for (i = 0; i < 5; i++) {
		if (alu[i].dt_Nasc.mes == dt.mes) {
			vetor_Dt[c] = alu[i].dt_Nasc;
			c++;
		}
	}
	//Imprime a(s) data(s) em que o mês da data referência esteja presente
	for (i = 0; i < c; i++) 
		printf ("%d %d %d\n", vetor_Dt[i].dia, vetor_Dt[i].mes, vetor_Dt[i].ano);
	
	printf ("\n");
	
	return 0;
}
