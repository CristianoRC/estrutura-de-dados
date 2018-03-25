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

//Declara o prot�tipo das fun��es
void criaCirculo (int x, int y, float raio, Circulo *c);
int estaDentrodoCirculo (int x, int y, Circulo c);

//Fun��o principal
int main (void) {
	
	//Declara��o das vari�veis
	Circulo c;
	int i, resp;
	Ponto pt[5];
	
	//Cria um circulo atrav�s da chamada da fun��o, usando os dados passados como argumento
	criaCirculo(10, 5, 5, &c);
	for (i = 0; i < 5; i++) {
		//Leitura de dados
		printf ("Informe as coordenadas do ponto %d: ", i+1);
		scanf ("%d %d", &pt[i].x, &pt[i].y);
		//Verifica se o ponto [i] de cooordenadas x e y est�o dentro do circulo
		resp = estaDentrodoCirculo(pt[i].x, pt[i].y, c);
		//Imprime resposta de acordo com o valor retornado pela fun��o
		if (resp == 0)
			printf ("Ponto FORA do circulo!\n");
		if (resp == 1)
			printf ("Ponto DENTRO do circulo!\n");	
		printf ("\n");	
	}
	
	return 0;
}

//Fun��o criaCirculo
void criaCirculo (int x, int y, float raio, Circulo *c) {
	
	//Atribui��o dos valores � estrutura
	c->x = x;
	c->y = y;
	c->raio = raio;
}

//Fun��o estaDentrodoCirculo
int estaDentrodoCirculo (int x, int y, Circulo c) {
	
	//Verifica��o
	if (pow((c.x - x), 2) + pow((c.y - y), 2) == pow((c.raio), 2))
		return 1;
	else
		return 0;	
}
