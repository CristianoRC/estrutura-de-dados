#include <stdio.h>

//Define estrutura tipo 'Jogador'
typedef struct {
	
	int num_Camisa,
		qt_Gols;
		
} Jogador;

//Declara o protótipo das funções
Jogador leJogador (void);
void escreveJogador (Jogador jog);
int ehGoleador (Jogador jog);

//Função principal
int main (void) {
	
	//Declara variáveis
	Jogador dados;
	int resp;
	
	//Lê os dados do Jogador através da função 'leJogador'
	printf ("Informe os dados do Jogador: ");
	dados = leJogador();
	//Chama a função 'ehGoleador' para verificar a quantidade de gols, que é passada como argumento através da variável 'dados'
	resp = ehGoleador(dados);
	//Imprime mansagem abaixo caso função anterior retorne 1 para a variável 'resp'
	if (resp == 1)
		printf ("E' Matador\n");
	//Se o retorno for 0 imprime mensagem abaixo
	else
		printf ("Perna de Pau\n");	
	//Escreve os dados do jogador através da função escreveJogador
	escreveJogador(dados);
	
	return 0;
}
//Função leJogador
Jogador leJogador (void) {
	
	//Variável local
	Jogador jog;
	
	//Leitura de dados
	scanf ("%d", &jog.num_Camisa);
	scanf ("%d", &jog.qt_Gols);
	
	//Retorno
	return jog;
}
//Função ehGoleador
int ehGoleador (Jogador jog) {
	
	//Validações
	if (jog.qt_Gols > 5)
		return 1;
	else
		return 0;	
}
//Função escreveJogador
void escreveJogador (Jogador dados) {
	
	//Impressões
	printf ("Numero da camisa: %d\n", dados.num_Camisa);
	printf ("Quantidade de Gols: %d\n", dados.qt_Gols);
}
