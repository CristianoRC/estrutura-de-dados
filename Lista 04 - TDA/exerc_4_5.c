#include <stdio.h>
#include <math.h>

//Define uma estrutura do tipo 'Ponto'
typedef struct {
	
	int x, y;
	
} Ponto;

//Define uma estrutura do tipo 'Retangulo'
typedef struct {
	
	Ponto se, id;
	
} Retangulo;

//Declara os protótipos das funções
void criaRetangulo (int x1, int y1, int x2, int y2, Retangulo *r);
float areaRetangulo (Retangulo r);

//Função principal
int main (void) {
	
	//Declaração das variáveis
	Retangulo ret;
	float areaRet;
	int x1, y1, x2, y2;
	
	//Leitura das coordenadas
	printf ("Informe as coordenadas do canto superior esquerdo: ");
	scanf ("%d %d", &x1, &y1);
	printf ("Informe as coordenadas do canto inferior direito: ");
	scanf ("%d %d", &x2, &y2);
	
	//Cria o retângulo com os dados passados como parâmetro
	criaRetangulo(x1, y1, x2, y2, &ret);
	//Calcula a área
	areaRet = areaRetangulo(ret);
	printf ("\n");
	//Imprime a área
	printf ("Area do Retangulo = %.2f\n", areaRet);
	
	return 0;
}

//Função criaRetangulo
void criaRetangulo (int x1, int y1, int x2, int y2, Retangulo *r) {
	
	//Atribui os valores
	r->se.x = x1;
	r->se.y = y1;
	r->id.x = x2;
	r->id.y = y2;
}

//Função areaRetangulo
float areaRetangulo (Retangulo r) {
	
	//Calcula a área do retângulo
	float h, l;
	h = sqrt(pow(r.se.x - r.se.x, 2) + pow(r.id.y - r.se.y, 2));
	l = sqrt(pow(r.id.x - r.se.x, 2) + pow(r.id.y - r.id.y, 2));
	return (h*l); 
}
