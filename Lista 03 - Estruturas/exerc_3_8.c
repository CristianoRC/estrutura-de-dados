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

//Declara o protótipo das funções
void leEquipe (Equipe *dados);
void marcouGol (int num_Cam, Equipe *dados);
Jogador obtemGoleador (Equipe dados);
Jogador leJogador (void);
void escreveJogador (Jogador dados);

//Função principal
int main (void) {
	
	//Declaração das variáveis
	Equipe dados;
	Jogador goleador;
	int num_Cam;
	
	//Leitura dos dados da equipe através da chamada da função 'leEquipe'
	printf ("-------------Dados da Equipe-------------");
	printf("\n\n");
	//Chamada da função
	leEquipe(&dados);
	//Lê o número da camisa do jogador que marcou o gol
	printf ("Gol de quem? \n");
	scanf ("%d", &num_Cam);
	//Validação de camisas
	while (num_Cam < 99) {
		//Atualiza a quantidade de gols do jogador cujo o número da camisa entrou como parâmetro
		marcouGol(num_Cam, &dados);
		//Repete a leitura da camisa do jogador
		printf ("Gol de quem? \n");
		scanf ("%d", &num_Cam);
	}
	//Mensagem	
	printf ("Fim do Programa!\n\n");
	/*Obtém o jogador com maior quantidade de gols através da função 'obtemGoleador',
	atribuindo o seu retorno à variável 'goleador' que é do tipo 'Jogador*/
	goleador = obtemGoleador(dados);
	printf ("Goleador: \n\n");
	//Imprime os dados do goleador através da função 'escreveJogador'
	escreveJogador(goleador);
	
	return 0;
}
//Função leEquipe
void leEquipe (Equipe *dados) {
	
	//Variável local
	int i;
	
	//Leitura do ano de fundação e dos dados dos jogadores da equipe
	printf ("Informe o ano de fundacao: \n");
	scanf ("%d", &dados->ano_criacao);
	printf ("\n");
	for (i = 0; i < 5; i++) {
		//Joga dentro do campo 'dados' as informações do vetor 'vet_Jog[i]
		dados->vet_Jog[i] = leJogador();
		printf ("\n");
	}
}
//Função leJogador
Jogador leJogador (void) {
	
	//Variável local
	Jogador jog;
	
	//Leitura de dados
	printf ("Numero da camisa | Gols: \n");
	scanf ("%d %d", &jog.num_Camisa, &jog.qt_Gols);
	
	//Retorno
	return jog;
}
//Função marcouGol
void marcouGol (int num_Cam, Equipe *dados) {
	
	//Variável local
	int i;
	
	/*Varre o vetor e verifica se o número da camisa que entrou como parâmetro coincide com os dados do vetor 'vet_Jog[i],
	se sim, atualiza a quantidade de gols 'qt_Gols' do jogador*/
	for (i = 0; i < 5; i++)
		if (dados->vet_Jog[i].num_Camisa == num_Cam)
			dados->vet_Jog[i].qt_Gols++;
}
//Função obtemGoleador
Jogador obtemGoleador (Equipe dados) {
	
	//Variáveis locais
	int i, maior = 0;
	Jogador jogador;
	
	/*Compara se a quantidade de gols do jogador 'vet_Jog[i]' é maior que o valor da variável 'maior',
	se sim, joga os dados daquele jogador na variável 'Jogador' e atualiza a variável 'maior'*/
	for (i = 0; i < 5; i++) {
		if (dados.vet_Jog[i].qt_Gols >= maior) {
			jogador = dados.vet_Jog[i];
			maior = dados.vet_Jog[i].qt_Gols;
		}		
	}
	//Retorna o jogador com maior número de gols
	return jogador;
}
//Função escreveJogador
void escreveJogador (Jogador dados) {
	
	//Impressões
	printf ("Numero da camisa: %d\n", dados.num_Camisa);
	printf ("Quantidade de Gols: %d\n", dados.qt_Gols);
}
