#include <stdio.h>

//Define estrutura tipo 'Jogador'
typedef struct {
	
	int num_Camisa,
		qt_Gols;
		
} Jogador;

//Declara o prot�tipo das fun��es
Jogador leJogador (void);
void escreveJogador (Jogador jog);
int ehGoleador (Jogador jog);

//Fun��o principal
int main (void) {
	
	//Declara vari�veis
	Jogador dados;
	int resp;
	
	//L� os dados do Jogador atrav�s da fun��o 'leJogador'
	printf ("Informe os dados do Jogador: ");
	dados = leJogador();
	//Chama a fun��o 'ehGoleador' para verificar a quantidade de gols, que � passada como argumento atrav�s da vari�vel 'dados'
	resp = ehGoleador(dados);
	//Imprime mansagem abaixo caso fun��o anterior retorne 1 para a vari�vel 'resp'
	if (resp == 1)
		printf ("E' Matador\n");
	//Se o retorno for 0 imprime mensagem abaixo
	else
		printf ("Perna de Pau\n");	
	//Escreve os dados do jogador atrav�s da fun��o escreveJogador
	escreveJogador(dados);
	
	return 0;
}
//Fun��o leJogador
Jogador leJogador (void) {
	
	//Vari�vel local
	Jogador jog;
	
	//Leitura de dados
	scanf ("%d", &jog.num_Camisa);
	scanf ("%d", &jog.qt_Gols);
	
	//Retorno
	return jog;
}
//Fun��o ehGoleador
int ehGoleador (Jogador jog) {
	
	//Valida��es
	if (jog.qt_Gols > 5)
		return 1;
	else
		return 0;	
}
//Fun��o escreveJogador
void escreveJogador (Jogador dados) {
	
	//Impress�es
	printf ("Numero da camisa: %d\n", dados.num_Camisa);
	printf ("Quantidade de Gols: %d\n", dados.qt_Gols);
}
