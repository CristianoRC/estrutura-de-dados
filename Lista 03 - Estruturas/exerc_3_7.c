#include <stdio.h>

//Define a estrutura tipo 'Equipe'
typedef struct {
	
	int ano_criacao;
	Jogador vet_Jog[5];
	
} Equipe;

//Define estrutura tipo 'Jogador'
typedef struct {
	
	int num_Camisa,
		qt_Gols;
		
} Jogador;
