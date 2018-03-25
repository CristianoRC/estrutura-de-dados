#include <stdio.h>

//Criando um novo tipo de dado (estrutura)
typedef struct {
	
	int hora, minuto, segundo;
	
} Horario;

//Função principal
int main (void) {

	//Define variáveis da estrutura
	Horario hr1, hr2;
	
	//Entrada de dados
	printf ("Informe um Horario: ");
	scanf ("%d:%d:%d", &hr1.hora, &hr1.minuto, &hr1.segundo);
	
	//Entrada de dados
	printf ("Informe outro Horario: ");
	scanf ("%d:%d:%d", &hr2.hora, &hr2.minuto, &hr2.segundo);
	
	//Valida se horas são iguais e imprime a mensagem
	if (hr1.hora == hr2.hora)
		if (hr1.minuto == hr2.minuto)
			if (hr1.segundo == hr2.segundo)
				printf ("Horas Iguais\n");
			else
				//Valida o menor horário a partir dos segundos
				if (hr1.segundo > hr2.segundo)
					printf ("%d:%.2d:%.2d\n", hr2.hora, hr2.minuto, hr2.segundo);
				else
					printf ("%d:%.2d:%.2d\n", hr1.hora, hr1.minuto, hr1.segundo);
		else
			//Valida o menor horário a partir dos minutos
			if (hr1.minuto > hr2.minuto)
				printf ("%d:%.2d:%.2d\n", hr2.hora, hr2.minuto, hr2.segundo);
			else
				printf ("%d:%.2d:%.2d\n", hr1.hora, hr1.minuto, hr1.segundo);
	else
		//Valida o menor horário a partir das horas
		if (hr1.hora > hr2.hora)
			printf ("%d:%.2d:%.2d\n", hr2.hora, hr2.minuto, hr2.segundo);
		else
			printf ("%d:%.2d:%.2d\n", hr1.hora, hr1.minuto, hr1.segundo);
	  
	return 0;			
}
