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

//Declara os prot�tipos das fun��es
void criaRetangulo (int x1, int y1, int x2, int y2, Retangulo *r);
float areaRetangulo (Retangulo r);

//Fun��o principal
int main (void) {
	
	//Declara��o das vari�veis
	Retangulo ret;
	float areaRet;
	int x1, y1, x2, y2;
	
	//Leitura das coordenadas
	printf ("Informe as coordenadas do canto superior esquerdo: ");
	scanf ("%d %d", &x1, &y1);
	printf ("Informe as coordenadas do canto inferior direito: ");
	scanf ("%d %d", &x2, &y2);
	
	//Cria o ret�ngulo com os dados passados como par�metro
	criaRetangulo(x1, y1, x2, y2, &ret);
	//Calcula a �rea
	areaRet = areaRetangulo(ret);
	printf ("\n");
	//Imprime a �rea
	printf ("Area do Retangulo = %.2f\n", areaRet);
	
	return 0;
}

//Fun��o criaRetangulo
void criaRetangulo (int x1, int y1, int x2, int y2, Retangulo *r) {
	
	//Atribui os valores
	r->se.x = x1;
	r->se.y = y1;
	r->id.x = x2;
	r->id.y = y2;
}

//Fun��o areaRetangulo
float areaRetangulo (Retangulo r) {
	
	//Calcula a �rea do ret�ngulo
	float h, l;
	h = sqrt(pow(r.se.x - r.se.x, 2) + pow(r.id.y - r.se.y, 2));
	l = sqrt(pow(r.id.x - r.se.x, 2) + pow(r.id.y - r.id.y, 2));
	return (h*l); 
}
