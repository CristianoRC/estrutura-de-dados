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
	
	//Declara��o de vari�veis
	Aluno aluno;
	Data dt_Atual;
	//Contador de Alunos
	int c = 1;
	
	//Entrada de dados (Data atual)
	printf ("Informe a data Atual: ");
	scanf ("%d %d %d", &dt_Atual.dia, &dt_Atual.mes, &dt_Atual.ano);
	
	//La�o para leitura dos dados dos alunos
	do {
		//L� matr�cula
		printf ("Informe a Matricula: ");
		scanf ("%d", &aluno.matricula);
		//Valida matricula
		if (aluno.matricula > 0) {
			//L� data de nascimento
			printf ("Informe a data de Nascimento do Aluno %d: ", c);
			scanf ("%d %d %d", &aluno.dt_Nasc.dia, &aluno.dt_Nasc.mes, &aluno.dt_Nasc.ano);
			//Valida��es de idade
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
		//Incrementa contador para pr�ximo aluno	
		c++;
	//Repete enquanto a matr�cula for v�lida	
	}while (aluno.matricula > 0);
	
	return 0;
}
