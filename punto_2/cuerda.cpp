#include <iostream>
#include <math.h>

using namespace std;

// Declaracion de variables

//densidad de la cuerda
float p = 10.0;
//tension de la cuerda 
float T = 40.0;
//longitud de la cuerda 
float L = 100.0;
//velocidad de propagacion
float c = pow(T/p,(1/2));
//tiempo maximo hasta donde se debe hacer mover el gif
int t_max = 200;
//deltas de tiempo y distancia en x 
float dt = 0.1;
float dx = 0.1;

//Condicion de estabilidad 
float r = c*(dt/dx);
float alph = pow(r,2);

//numero de pasos en t y x 
int t_step = t_max/dt;
int x_step = L/dx;

//Array donde se guarda la condicion inicial
double* U_in = new double[x_step];

//Arrays donde se guardan los pasos 
double* U_act = new double[x_step]; 
double* U_fut = new double[x_step];


//main
int main(){
//For que hace mi condicion inicial 
	for(int i =0; i<x_step; i++){
		double x = i*dx;
		if(x <= 0.8*L){
			U_in[i] = (1.25*x)/L;
		}
		if(x > 0.8*L){
			U_in[i]	= (5.0 - 5.0*x)/L;	
		}
	}

//For que calcula el avance de la cuerda al solucional la PDE segun la ecuacion de onda
	U_in = U_act;
	for(int i=1;i<x_step;i++){
        	U_fut[i] = U_act[i] + (1.0/2.0)*alph*(U_act[i+1] - 2.0 * U_act[i] + U_act[i-1] );
	
	}

	return 0;
} 
