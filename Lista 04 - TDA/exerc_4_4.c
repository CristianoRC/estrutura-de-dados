#include <stdio.h>
#include <locale.h>

//Define uma estrutura do tipo 'Conta'
typedef struct {
	
	int numConta;
	float saldo;
	
} Conta;

//Declara os prot�tipos da fun��o
void criaConta (int numConta, Conta *c);
void depositaNaConta (float dep, Conta *c);
void retiraDaConta (float saque, Conta *c);
float obtemSaldo (Conta c);

//Fun��o principal
int main (void) {
	
	setlocale(LC_ALL,"");
	//Declara��o das vari�veis
	Conta cc, cp;
	float saldoCC, saldoCP, valor, dif = 0, saldo;
	int numContac, numContap, cOp;
	
	//Leitura de dados
	printf ("Informe os dados das Contas: ");
	printf ("\n\n");
	printf ("N�mero da Conta Corrente | Saldo\n");
	scanf ("%d %f", &numContac, &saldo);
	printf ("\n");
	//Cria a conta com a chamada da fun��o
	criaConta(numContac, &cc);
    printf ("N�mero da Conta Poupan�a | Saldo\n");
	scanf ("%d %f", &numContap, &saldo);
	printf ("\n");
	criaConta(numContap, &cp);
	printf ("\n");
	
	//Loop para verificar as opera��es desejadas pelo usu�rio
	do {
		//L� a opera��o
		printf ("Informe o c�digo da opera��o: \n");
		printf ("1.Deposito em CC\n");
		printf ("2.Deposito em CP\n");
		printf ("3.Retirada em CC\n");
		printf ("4.Retirada em CP\n");
		printf ("5.Fim\n");
		scanf ("%d", &cOp);
		//Limpa a tela
		system ("cls");
		//Valida se opera��o � valida
		if (cOp != 5) {
			//Auto explicativo
			printf ("Informe o Valor movimentado: \n");
			scanf ("%f", &valor);
			//Cases de opera��es
			switch(cOp) {
				//Deposita o valor na conta corrente atrav�s da fun��o
				case 1: depositaNaConta(valor, &cc);
						break;
				//Deposita o valor na conta poupan�a atrav�s da fun��o		
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
						
				default: printf ("Opera��o Invalida\n"); 				
			}
			//Obtem e imprime os saldos
			saldoCC = obtemSaldo(cc);
			saldoCP = obtemSaldo(cp);
			printf ("Saldo atual em CC - %d: R$%.2f\n", numContac, saldoCC);
			printf ("Saldo atual em CP - %d: R$%.2f\n", numContap, saldoCP);
		}
	//Repete enquanto o c�digo da opera��o for v�lido	
	}while (cOp != 5);
	
	return 0;
}

//Fun��o criaConta
void criaConta (int numConta, Conta *c) {
	
	c->numConta = numConta;
	c->saldo = 0;
}

//Fun��o depositaNaConta
void depositaNaConta (float dep, Conta *c) {
	
	c->saldo = c->saldo + dep;
}

//Fun��o obtemSaldo
float obtemSaldo (Conta c) {
	
	return c.saldo;
}

//Fun��o retiraDaConta
void retiraDaConta (float saque, Conta *c) {
	
	c->saldo = c->saldo - saque;
}
