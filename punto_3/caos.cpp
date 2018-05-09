#include <iostream>
#include <math.h>

using namespace std;
//Declaracion variables p1, p2, e, a (condicion inicial), tiempo y delta de tiempo 
float p1;
float p2;
float e = pow(10,(-3));
float a = 1/2*pow(2,(1/2));
int t_max = 3000;
float delta_t = 0.006;

//Declaracion de la funcion que retorna la derivada q1
float derivada1_q1(float p1);

//Declaracion de la funcion que retorna la derivada q2
float derivada1_q2(float p2);
	
//Declaracion de la funcion que calcula la derivada de p1
float derivada_p1(float e, float q1);
	
//Declaracion de la funcion que calcula la derivada de p2
float derivada_p2(float e, float q1, float q2);
	
//Declaracion que la funcion que calcula las derivadas usando runge
void der(float x, float v, float t, float h);

//Defino derivada de q1
float derivada_q1(float p1){
	return p1;
}
//Defino derivada de q2
float derivada_q2(float p2){
	return p2;
}
//Defino derivada de p1
float derivada1_p1(float e, float q1){
	float a = 2.0*q1;
	float b = (4*q1*q1)+(e*e);
	float c = pow(b,(3/2)); 
	return a/c;
}

//Defino derivada de p2
float derivada1_p2(float e, float q1, float q2){
	float d = q1-q2;				
	float f = (d*d)+((e*e)/4);
	float g = d/(pow(f,(3/2)));
	float h = q1+q2;
	float i = h*h+((e*e)/4);
 	float k = h/(pow(h,(3/2)));
	return g-k;
}
//Defino la funcion que soluciona las ecuaciones diferenciales 
void der(float q1, float q2, float p1, float p2){
	//Declaracion las condiciones iniciales dadas 
	float q1_O = a;
	float q2_O = -a;
	float p1_O = 0;
	float p2_O = 0;
	
	//Halla las constantes para q1
	float cte1_q1 = derivada_q1(p1_O);
	float cte2_q1 = derivada_q1(p1_O + (0.5*cte1_q1));
	float cte3_q1 = derivada_q1(p1_O + (0.5*cte2_q1));
	float cte4_q1 = derivada_q1(p1_O + (0.5*cte3_q1));
	
  	
}
//MAIN
int main() {
return 0;
}
