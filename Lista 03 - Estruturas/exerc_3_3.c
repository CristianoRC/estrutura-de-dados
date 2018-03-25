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
	
	//Declaração de variáveis
	Aluno aluno;
	Data dt_Atual;
	//Contador de Alunos
	int c = 1;
	
	//Entrada de dados (Data atual)
	printf ("Informe a data Atual: ");
	scanf ("%d %d %d", &dt_Atual.dia, &dt_Atual.mes, &dt_Atual.ano);
	
	//Laço para leitura dos dados dos alunos
	do {
		//Lê matrícula
		printf ("Informe a Matricula: ");
		scanf ("%d", &aluno.matricula);
		//Valida matricula
		if (aluno.matricula > 0) {
			//Lê data de nascimento
			printf ("Informe a data de Nascimento do Aluno %d: ", c);
			scanf ("%d %d %d", &aluno.dt_Nasc.dia, &aluno.dt_Nasc.mes, &aluno.dt_Nasc.ano);
			//Validações de idade
			if (dt_Atual.ano - aluno.dt_Nasc.ano > 18)
				printf ("18 Anos completos\n");
			else
				if (dt_Atual.ano - aluno.dt_Nasc.ano == 18)
					if (dt_Atual.mes <= aluno.dt_Nasc.mes && dt_Atual.dia <= aluno.dt_Nasc.dia)	
						printf ("18 anos completos\n");
							
					else
						printf ("Aluno menor de 18\n");	
				else
					printf ("Aluno menor de 18\n");				
		}
		//Incrementa contador para próximo aluno	
		c++;
	//Repete enquanto a matrícula for válida	
	}while (aluno.matricula > 0);
	
	return 0;
}
