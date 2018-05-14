#include <iostream>
#include <math.h>
using namespace std;

//Declaro las constantes

float L = 5.0, l = 2.0, d = 1.0, h = 5.0/512.0, V_o = 100.0, N = 2.0*(L/h)*(L/h);

//Tamanio matrices

int w = int(L/h);

//Matrices donde se guarda el estado inicial, actual y futuro
double** T_in = new double*[w];
double** T_act = new double*[w];
double** T_fut = new double*[w];


int main() {

//Posicion de las placas para condicion inicial 
int pl1_y = L/2.0 + d/2.0; //placa abajo en y
int pl2_y = L/2.0 - d/2.0; //placa arriba en y
int ex1_x = L/2.0 + l/2.0; //extremo en x hacia lo positivos
int ex2_x = L/2.0 - l/2.0; //extremo en y hacia los negativos

//For que hace mi condicion inicial 
for(int i = 0; i<w; i++){ // recorre filas
	for(int j = 0; j<w; i++){ //recorre columnas
		if ( j == pl2_y && (ex2_x <= i <= ex1_x)){
			T_in[i][j] = V_o/2.0;
		}

		if ( j == pl1_y && (ex2_x <= i <= ex1_x)){
			T_in[i][j] = -V_o/2.0;
		}
		
		else{
			T_in[i][j] = 0.0;
		}
		
	}
}	


return 0;
}
