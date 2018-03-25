#include <stdio.h>
#include <locale.h>

//Define uma estrutura do tipo 'Conta'
typedef struct {
	
	int numConta;
	float saldo;
	
} Conta;

//Declara os protótipos da função
void criaConta (int numConta, Conta *c);
void depositaNaConta (float dep, Conta *c);
void retiraDaConta (float saque, Conta *c);
float obtemSaldo (Conta c);

//Função principal
int main (void) {
	
	setlocale(LC_ALL,"");
	//Declaração das variáveis
	Conta cc, cp;
	float saldoCC, saldoCP, valor, dif = 0, saldo;
	int numContac, numContap, cOp;
	
	//Leitura de dados
	printf ("Informe os dados das Contas: ");
	printf ("\n\n");
	printf ("Número da Conta Corrente | Saldo\n");
	scanf ("%d %f", &numContac, &saldo);
	printf ("\n");
	//Cria a conta com a chamada da função
	criaConta(numContac, &cc);
    printf ("Número da Conta Poupança | Saldo\n");
	scanf ("%d %f", &numContap, &saldo);
	printf ("\n");
	criaConta(numContap, &cp);
	printf ("\n");
	
	//Loop para verificar as operações desejadas pelo usuário
	do {
		//Lê a operação
		printf ("Informe o código da operação: \n");
		printf ("1.Deposito em CC\n");
		printf ("2.Deposito em CP\n");
		printf ("3.Retirada em CC\n");
		printf ("4.Retirada em CP\n");
		printf ("5.Fim\n");
		scanf ("%d", &cOp);
		//Limpa a tela
		system ("cls");
		//Valida se operação é valida
		if (cOp != 5) {
			//Auto explicativo
			printf ("Informe o Valor movimentado: \n");
			scanf ("%f", &valor);
			//Cases de operações
			switch(cOp) {
				//Deposita o valor na conta corrente através da função
				case 1: depositaNaConta(valor, &cc);
						break;
				//Deposita o valor na conta poupança através da função		
				case 2: depositaNaConta(valor, &cp);
						break;
				//Auto explicativo
				case 3: saldoCC = obtemSaldo(cc);
						saldoCP = obtemSaldo(cp);
						if (saldoCC < valor) {
							dif = valor - saldoCC;
							if (saldoCP >= dif) {
								retiraDaConta(dif, &cp);
								depositaNaConta(dif, &cc);
								retiraDaConta(valor, &cc);
							}else 
								printf ("Saldo Insuficiente\n");
						}else
							retiraDaConta(valor, &cc);
						break;	
				
				case 4: saldoCP = obtemSaldo(cp);
						if (saldoCP >= valor)
							retiraDaConta(valor, &cp);
						else
							printf ("Saldo Insuficiente\n");
						break;	
						
				default: printf ("Operação Invalida\n"); 				
			}
			//Obtem e imprime os saldos
			saldoCC = obtemSaldo(cc);
			saldoCP = obtemSaldo(cp);
			printf ("Saldo atual em CC - %d: R$%.2f\n", numContac, saldoCC);
			printf ("Saldo atual em CP - %d: R$%.2f\n", numContap, saldoCP);
		}
	//Repete enquanto o código da operação for válido	
	}while (cOp != 5);
	
	return 0;
}

//Função criaConta
void criaConta (int numConta, Conta *c) {
	
	c->numConta = numConta;
	c->saldo = 0;
}

//Função depositaNaConta
void depositaNaConta (float dep, Conta *c) {
	
	c->saldo = c->saldo + dep;
}

//Função obtemSaldo
float obtemSaldo (Conta c) {
	
	return c.saldo;
}

//Função retiraDaConta
void retiraDaConta (float saque, Conta *c) {
	
	c->saldo = c->saldo - saque;
}
