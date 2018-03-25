#include <stdio.h>

//Define uma estrutura do tipo 'Circulo'
typedef struct {
	
	int x, y;
	float raio;
	
} Circulo;

//Declara o protótipo das funções
void exibeCirculo (Circulo c);
void moveCirculo (int x, int y, Circulo *c);
void criaCirculo (int x, int y, float raio, Circulo *c);
int comparaCirculo (Circulo c1, Circulo c2);
int estaDentrodoCirculo (int x, int y, Circulo c);

//Função principal
int main (void) {
	
	//Declarção das variáveis
	Circulo c1, c2;
	float raio1, raio2;
	int x, y, resp;
	
	//Entrada de dados
	printf ("Informe o valor do primeiro raio: ");
	scanf ("%f", &raio1);
	printf ("\n");
	printf ("Informe as coordenadas do centro: ");
	scanf ("%d %d", &x, &y);
	printf ("\n");
	//Cria o primeiro circulo através da chamada da função, passando como argumento os valores digitados
	criaCirculo(x, y, raio1, &c1);
	
	//Entrada de dados
	printf ("Informe o valor do segundo raio: ");
	scanf ("%f", &raio2);
	printf ("\n");
	printf ("Informe as coordenadas do centro: ");
	scanf ("%d %d", &x, &y);
	printf ("\n");
	//Cria o segundo circulo através da chamada da função, passando como argumento os valores digitados
	criaCirculo(x, y, raio2, &c2);
	
	//Define o maior dos circulos através da chamada da função
	resp = comparaCirculo(c1, c2);
	//Compara os valores retornados pela função
	if (resp == 0)
		printf ("Circulos Iguais\n");
	if (resp == 1)
		printf ("Circulo 1 e' o MAIOR\n");
	if (resp == -1)
		printf ("Circulo 2 e' o MAIOR\n");
	
	//Exibe os dados dos circulos criados
	printf ("------ Dados do Circulo 1 ------\n");
	exibeCirculo(c1);
	printf ("\n");
	printf ("------ Dados do Circulo 2 ------\n");
	exibeCirculo(c2);
	printf ("\n");		
	
	//Entrada de valores para o deslocamento do c2 em 'x' e em 'y'
	printf ("Informe um novo valor para o deslocamento em X: ");
	scanf ("%d", &x);
	printf ("Informe um novo valor para o deslocamento em Y: ");
	scanf ("%d", &y);
	
	//Atualiza os valores das coordenadas através da chamada da função
	moveCirculo(x, y, &c2);
	printf ("\n");
	//Exibe os valores atualizados
	printf ("------ Novos Dados para o Circulo 2 ------\n");
	exibeCirculo(c2);
	printf ("\n");
	
	return 0;
}

//Função criaCirculo
void criaCirculo (int x, int y, float raio, Circulo *c) {
	
	//Atribuição dos valores à estrutura
	c->x = x;
	c->y = y;
	c->raio = raio;
}

//Função comparaCirculo
int comparaCirculo (Circulo c1, Circulo c2) {
	
	//Comparações
	if (c1.raio == c2.raio)
		return 0;
	else
		if (c1.raio > c2.raio)
			return 1;
		else
			return -1;		
}

//Função exibeCirculo
void exibeCirculo (Circulo c) {
	
	//Exibição dos dados 
	printf ("Coordenada X -> %d\n", c.x);
	printf ("Coordenada Y -> %d\n", c.y);
	printf ("Raio -> %.2f\n", c.raio);
}

//Função moveCirculo
void moveCirculo (int x, int y, Circulo *c) {
	
	//Atualiza as coordenadas com os valores de entrada passados como argumento
	c->x = c->x + x;
	c->y = c->y + y;
}
