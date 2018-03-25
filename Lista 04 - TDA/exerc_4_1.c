#include <stdio.h>
#include <math.h>

//Define uma estrutura do tipo 'Circulo'
typedef struct {
	
	int x, y;
	float raio;
	
} Circulo;

//Declara o protótipo das funções
void criaCirculo (int x, int y, float raio, Circulo *c);
float perimetroCirculo (Circulo c);
float areaCirculo (Circulo c);

//Função principal
int main (void) {
	
	//Declaração das variáveis
	Circulo c1, c2;
	float raio1, raio2;
	float area1, area2;
	float per1, per2;
	
	//Leitura dos dados
	printf ("Informe o valor do raio 1: ");
	scanf ("%f", &raio1);
	printf ("Informe o valor do raio 2: ");
	scanf ("%f", &raio2);
	
	//Chama a função duas vezes para criar os círculos com os dados passados como parâmetro
	criaCirculo(0, 0, raio1, &c1);
	criaCirculo(10, 30, raio2, &c2);
	printf ("\n");
	
	//Mensagem
	printf ("---------- Area dos Circulos ----------\n\n");
	//Atribui o resultado retornado pela função à variável 'area1'
	area1 = areaCirculo(c1);
	//Printa area1
	printf ("Area do Circulo 1: %.2f\n", area1);
	
	//Atribui o resultado retornado pela função à variável 'area2'
	area2 = areaCirculo(c2);
	//Printa area2
	printf ("Area do Circulo 2: %.2f\n", area2);
	
	//Atribui o resultado retornado pela função à variável 'per1'
	per1 = perimetroCirculo(c1);
	//Atribui o resultado retornado pela função à variável 'per2'
	per2 = perimetroCirculo(c2);
	
	//Valida a maior área para imprimir o perímetro correspondente
	if (area1 > area2)
		printf ("Perimetro do Circulo de maior Area = %.2f\n", per1);
	else
		printf ("Perimetro do Circulo de maior Area = %.2f\n", per2);	
	
	return 0;
}

//Função criaCirculo
void criaCirculo (int x, int y, float raio, Circulo *c) {
	
	//Atribuição dos valores à estrutura
	c->x = x;
	c->y = y;
	c->raio = raio;
}

//Função areaCirculo
float areaCirculo (Circulo c) {
	
	//Variável local
	float ar;
	
	//Calcula área
	ar = pow((2 * M_PI * c.raio), 2);
	
	//Retorna o valor resultante
	return ar;
}

//Função perimetroCirculo
float perimetroCirculo (Circulo c) {
	
	//Variável local
	float per;
	
	//Calcula o perímetro
	per = 2 * M_PI * c.raio;
	
	//Retorna o valor resultante
	return per;
}
