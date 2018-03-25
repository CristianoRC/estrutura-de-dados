#include <stdio.h>
#include <math.h>

//Define uma estrutura do tipo 'ponto'
typedef struct {
	
	int x, y;
	
} Ponto;

//Define uma estrutura do tipo 'Circulo'
typedef struct {
	
	int x, y;
	float raio;
	
} Circulo;

//Declara o protótipo das funções
void criaCirculo (int x, int y, float raio, Circulo *c);
int estaDentrodoCirculo (int x, int y, Circulo c);

//Função principal
int main (void) {
	
	//Declaração das variáveis
	Circulo c;
	int i, resp;
	Ponto pt[5];
	
	//Cria um circulo através da chamada da função, usando os dados passados como argumento
	criaCirculo(10, 5, 5, &c);
	for (i = 0; i < 5; i++) {
		//Leitura de dados
		printf ("Informe as coordenadas do ponto %d: ", i+1);
		scanf ("%d %d", &pt[i].x, &pt[i].y);
		//Verifica se o ponto [i] de cooordenadas x e y estão dentro do circulo
		resp = estaDentrodoCirculo(pt[i].x, pt[i].y, c);
		//Imprime resposta de acordo com o valor retornado pela função
		if (resp == 0)
			printf ("Ponto FORA do circulo!\n");
		if (resp == 1)
			printf ("Ponto DENTRO do circulo!\n");	
		printf ("\n");	
	}
	
	return 0;
}

//Função criaCirculo
void criaCirculo (int x, int y, float raio, Circulo *c) {
	
	//Atribuição dos valores à estrutura
	c->x = x;
	c->y = y;
	c->raio = raio;
}

//Função estaDentrodoCirculo
int estaDentrodoCirculo (int x, int y, Circulo c) {
	
	//Verificação
	if (pow((c.x - x), 2) + pow((c.y - y), 2) == pow((c.raio), 2))
		return 1;
	else
		return 0;	
}
