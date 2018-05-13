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
float derivada_p1(float e, float q1){
	float a = 2.0*q1;
	float b = (4*q1*q1)+(e*e);
	float c = pow(b,(3/2)); 
	return a/c;
}

//Defino derivada de p2
float derivada_p2(float e, float q1, float q2){
	float d = q1-q2;				
	float f = (d*d)+((e*e)/4);
	float g = d/(pow(f,(3/2)));
	float h = q1+q2;
	float i = h*h+((e*e)/4);
 	float k = h/(pow(h,(3/2)));
	return g-k;
}

//Declaracion las condiciones iniciales dadas 
	float q1_O = a;
	float q2_O = -a;
	float p1_O = 0;
	float p2_O = 0;

//Defino la funcion que soluciona las ecuaciones diferenciales 
void der(float q1, float q2, float p1, float p2){
	
	//Condiciones iniciales 
	float q1_O = q1; 
	float q2_O = q2;
	float p1_O = p1;
	float p2_O = p2;
	
	//Halla las constantes para q1
	float cte_q1_1 = derivada_q1(p1_O);
	float cte_q1_2 = derivada_q1(p1_O + ((delta_t*0.5)*cte_q1_1));
	float cte_q1_3 = derivada_q1(p1_O + ((delta_t*0.5)*cte_q1_2));
	float cte_q1_4 = derivada_q1(p1_O + (delta_t*cte_q1_3));
	
  	//Halla las constantes para q2
	float cte_q2_1 = derivada_q2(p2_O);
	float cte_q2_2 = derivada_q2(p2_O + (delta_t*0.5*cte_q2_1) );
	float cte_q2_3 = derivada_q2(p2_O + (delta_t*0.5*cte_q2_2) );
	float cte_q2_4 = derivada_q2(p2_O + (delta_t*cte_q2_3) );

	//Halla las constantes para p1
	float cte_p1_1 = derivada_p1(e, q1_O);
	float cte_p1_2 = derivada_p1(e, q1_O + (delta_t*0.5*cte_p1_1) );
	float cte_p1_3 = derivada_p1(e, q1_O + (delta_t*0.5*cte_p1_2) );
	float cte_p1_4 = derivada_p1(e, q1_O + (delta_t*cte_p1_3) );

	//Halla las constantes para p2
	float cte_p2_1 = derivada_p2(e, q1_O, q2_O);
	float cte_p2_2 = derivada_p2(e, q1_O + (delta_t*0.5*cte_p2_1), q2_O + (delta_t*0.5*cte_p2_1));
	float cte_p2_3 = derivada_p2(e, q1_O + (delta_t*0.5*cte_p2_2), q2_O + (delta_t*0.5*cte_p2_2));
	float cte_p2_4 = derivada_p2(e, q1_O + (delta_t*cte_p2_3), p2_O + (delta_t*cte_p2_3));

	//Calcula el siguiente paso 
	float q1_n = q1_O + (delta_t/6.0)*(cte_q1_1 + 2.0*cte_q1_2 + 2.0*cte_q1_3 + cte_q1_4);
	float q2_n = q2_O + (delta_t/6.0)*(cte_q2_1 + 2.0*cte_q2_2 + 2.0*cte_q2_3 + cte_q2_4);
	float p1_n = p1_O + (delta_t/6.0)*(cte_p1_1 + 2.0*cte_p1_2 + 2.0*cte_p1_3 + cte_p1_4);
	float p2_n = p1_O + (delta_t/6.0)*(cte_p2_1 + 2.0*cte_p2_2 + 2.0*cte_p2_3 + cte_p2_4);

	//Pregunta si q1 cambia de signo
	if(q1_O*q1_n < 0.0){
	cout << q2_n <<endl;	
	}

	//Actualiza el los valores inciales para hacer el ciclo
	q1_O = q1_n; 
	q2_O = q2_n;
	p1_O = p1_n;
	p2_O = p2_n;
}
//MAIN
int main() {

for(int i = 0; i < 3000/delta_t; i++){
	der(a,-a,0.0,0.0);
	
}
return 0;
}
