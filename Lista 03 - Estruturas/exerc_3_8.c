#include <stdio.h>

//Define a estrutura tipo 'Jogador'
typedef struct {
	
	int num_Camisa,
		qt_Gols;
		
} Jogador;

//Define a estrutura tipo 'Equipe'
typedef struct {
	
	int ano_criacao;
	Jogador vet_Jog[5];
	
} Equipe;

//Declara o prot�tipo das fun��es
void leEquipe (Equipe *dados);
void marcouGol (int num_Cam, Equipe *dados);
Jogador obtemGoleador (Equipe dados);
Jogador leJogador (void);
void escreveJogador (Jogador dados);

//Fun��o principal
int main (void) {
	
	//Declara��o das vari�veis
	Equipe dados;
	Jogador goleador;
	int num_Cam;
	
	//Leitura dos dados da equipe atrav�s da chamada da fun��o 'leEquipe'
	printf ("-------------Dados da Equipe-------------");
	printf("\n\n");
	//Chamada da fun��o
	leEquipe(&dados);
	//L� o n�mero da camisa do jogador que marcou o gol
	printf ("Gol de quem? \n");
	scanf ("%d", &num_Cam);
	//Valida��o de camisas
	while (num_Cam < 99) {
		//Atualiza a quantidade de gols do jogador cujo o n�mero da camisa entrou como par�metro
		marcouGol(num_Cam, &dados);
		//Repete a leitura da camisa do jogador
		printf ("Gol de quem? \n");
		scanf ("%d", &num_Cam);
	}
	//Mensagem	
	printf ("Fim do Programa!\n\n");
	/*Obt�m o jogador com maior quantidade de gols atrav�s da fun��o 'obtemGoleador',
	atribuindo o seu retorno � vari�vel 'goleador' que � do tipo 'Jogador*/
	goleador = obtemGoleador(dados);
	printf ("Goleador: \n\n");
	//Imprime os dados do goleador atrav�s da fun��o 'escreveJogador'
	escreveJogador(goleador);
	
	return 0;
}
//Fun��o leEquipe
void leEquipe (Equipe *dados) {
	
	//Vari�vel local
	int i;
	
	//Leitura do ano de funda��o e dos dados dos jogadores da equipe
	printf ("Informe o ano de fundacao: \n");
	scanf ("%d", &dados->ano_criacao);
	printf ("\n");
	for (i = 0; i < 5; i++) {
		//Joga dentro do campo 'dados' as informa��es do vetor 'vet_Jog[i]
		dados->vet_Jog[i] = leJogador();
		printf ("\n");
	}
}
//Fun��o leJogador
Jogador leJogador (void) {
	
	//Vari�vel local
	Jogador jog;
	
	//Leitura de dados
	printf ("Numero da camisa | Gols: \n");
	scanf ("%d %d", &jog.num_Camisa, &jog.qt_Gols);
	
	//Retorno
	return jog;
}
//Fun��o marcouGol
void marcouGol (int num_Cam, Equipe *dados) {
	
	//Vari�vel local
	int i;
	
	/*Varre o vetor e verifica se o n�mero da camisa que entrou como par�metro coincide com os dados do vetor 'vet_Jog[i],
	se sim, atualiza a quantidade de gols 'qt_Gols' do jogador*/
	for (i = 0; i < 5; i++)
		if (dados->vet_Jog[i].num_Camisa == num_Cam)
			dados->vet_Jog[i].qt_Gols++;
}
//Fun��o obtemGoleador
Jogador obtemGoleador (Equipe dados) {
	
	//Vari�veis locais
	int i, maior = 0;
	Jogador jogador;
	
	/*Compara se a quantidade de gols do jogador 'vet_Jog[i]' � maior que o valor da vari�vel 'maior',
	se sim, joga os dados daquele jogador na vari�vel 'Jogador' e atualiza a vari�vel 'maior'*/
	for (i = 0; i < 5; i++) {
		if (dados.vet_Jog[i].qt_Gols >= maior) {
			jogador = dados.vet_Jog[i];
			maior = dados.vet_Jog[i].qt_Gols;
		}		
	}
	//Retorna o jogador com maior n�mero de gols
	return jogador;
}
//Fun��o escreveJogador
void escreveJogador (Jogador dados) {
	
	//Impress�es
	printf ("Numero da camisa: %d\n", dados.num_Camisa);
	printf ("Quantidade de Gols: %d\n", dados.qt_Gols);
}
