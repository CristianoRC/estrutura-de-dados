#include <stdio.h>
#include <math.h>

//Define uma estrutura do tipo 'Circulo'
typedef struct {
	
	int x, y;
	float raio;
	
} Circulo;

//Declara o prot�tipo das fun��es
void criaCirculo (int x, int y, float raio, Circulo *c);
float perimetroCirculo (Circulo c);
float areaCirculo (Circulo c);

//Fun��o principal
int main (void) {
	
	//Declara��o das vari�veis
	Circulo c1, c2;
	float raio1, raio2;
	float area1, area2;
	float per1, per2;
	
	//Leitura dos dados
	printf ("Informe o valor do raio 1: ");
	scanf ("%f", &raio1);
	printf ("Informe o valor do raio 2: ");
	scanf ("%f", &raio2);
	
	//Chama a fun��o duas vezes para criar os c�rculos com os dados passados como par�metro
	criaCirculo(0, 0, raio1, &c1);
	criaCirculo(10, 30, raio2, &c2);
	printf ("\n");
	
	//Mensagem
	printf ("---------- Area dos Circulos ----------\n\n");
	//Atribui o resultado retornado pela fun��o � vari�vel 'area1'
	area1 = areaCirculo(c1);
	//Printa area1
	printf ("Area do Circulo 1: %.2f\n", area1);
	
	//Atribui o resultado retornado pela fun��o � vari�vel 'area2'
	area2 = areaCirculo(c2);
	//Printa area2
	printf ("Area do Circulo 2: %.2f\n", area2);
	
	//Atribui o resultado retornado pela fun��o � vari�vel 'per1'
	per1 = perimetroCirculo(c1);
	//Atribui o resultado retornado pela fun��o � vari�vel 'per2'
	per2 = perimetroCirculo(c2);
	
	//Valida a maior �rea para imprimir o per�metro correspondente
	if (area1 > area2)
		printf ("Perimetro do Circulo de maior Area = %.2f\n", per1);
	else
		printf ("Perimetro do Circulo de maior Area = %.2f\n", per2);	
	
	return 0;
}

//Fun��o criaCirculo
void criaCirculo (int x, int y, float raio, Circulo *c) {
	
	//Atribui��o dos valores � estrutura
	c->x = x;
	c->y = y;
	c->raio = raio;
}

//Fun��o areaCirculo
float areaCirculo (Circulo c) {
	
	//Vari�vel local
	float ar;
	
	//Calcula �rea
	ar = pow((2 * M_PI * c.raio), 2);
	
	//Retorna o valor resultante
	return ar;
}

//Fun��o perimetroCirculo
float perimetroCirculo (Circulo c) {
	
	//Vari�vel local
	float per;
	
	//Calcula o per�metro
	per = 2 * M_PI * c.raio;
	
	//Retorna o valor resultante
	return per;
}
