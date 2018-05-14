#include <iostream>
#include <math.h>

using namespace std;
//Declaracion variables p1, p2, e, a (condicion inicial), tiempo y delta de tiempo 
double p1;
double p2;
double e = pow(10,(-3));
double a = 1.0/2.0*pow(2,(1/2));
double t_max = 3000.0;
double delta_t = 0.006;

//Declaracion de la funcion que retorna la derivada q1
double derivada1_q1(double p1);

//Declaracion de la funcion que retorna la derivada q2
double derivada1_q2(double p2);
	
//Declaracion de la funcion que calcula la derivada de p1
double derivada_p1(double e, double q1);
	
//Declaracion de la funcion que calcula la derivada de p2
double derivada_p2(double e, double q1, double q2);
	
//Defino derivada de q1
double derivada_q1(double p1){
	return p1;
}
//Defino derivada de q2
double derivada_q2(double p2){
	return p2;
}
//Defino derivada de p1
double derivada_p1(double q1){
	double a = 2.0*q1;
	double b = (4.0*q1*q1)+(e*e);
	double c = pow(b,(3/2)); 
	return a/c;
}

//Defino derivada de p2
double derivada_p2(double q1, double q2){
	double d = (q1-q2);	
	double j = (d*d)+(e*e)/4.0;
	double g = (pow(j,(3.0/2.0)));
	double h = q1+q2;
	double i = h*h+(e*e)/4.0;
 	double k = (pow(i,(1.5)));
	double rta = (d/g) - (h/k);
	return rta;
}

int main() {
//Condiciones iniciales dadas 
	double q1_O = a;
	double q2_O = -1.0*a;
	double p1_O = 0.0;
	double p2_O = 0.0;
	
for(float i = 0; i < 3000/delta_t; i++){
		
	//Halla la2 constante 1
	double cte_q1_1 = derivada_q1(p1_O);
	double cte_q2_1 = derivada_q2(p2_O);
	double cte_p1_1 = derivada_p1(q1_O);
	double cte_p2_1 = derivada_p2(q1_O, q2_O);
	
	//Halla la constante 2
	double cte_q1_2 = derivada_q1(p1_O + ((delta_t*0.5)*cte_q1_1));
	double cte_q2_2 = derivada_q2(p2_O + (delta_t*0.5*cte_q2_1) );
	double cte_p1_2 = derivada_p1( q1_O + (delta_t*0.5*cte_p1_1) );
	double cte_p2_2 = derivada_p2( q1_O + (delta_t*0.5*cte_p2_1), q2_O + (delta_t*0.5*cte_p2_1));

	//Halla constante 3
	double cte_q1_3 = derivada_q1(p1_O + ((delta_t*0.5)*cte_q1_2));
	double cte_q2_3 = derivada_q2(p2_O + (delta_t*0.5*cte_q2_2) );
	double cte_p1_3 = derivada_p1( q1_O + (delta_t*0.5*cte_p1_2) );
	double cte_p2_3 = derivada_p2( q1_O + (delta_t*0.5*cte_p2_2), q2_O + (delta_t*0.5*cte_p2_2));

	//Halla constante 4
	double cte_q1_4 = derivada_q1(p1_O + (delta_t*cte_q1_3));
	double cte_q2_4 = derivada_q2(p2_O + (delta_t*cte_q2_3) );
	double cte_p1_4 = derivada_p1( q1_O + (delta_t*cte_p1_3) );
	double cte_p2_4 = derivada_p2( q1_O + (delta_t*cte_p2_3), p2_O + (delta_t*cte_p2_3));

	//Calcula el siguiente paso 

	double q1_n = q1_O + (delta_t/6.0)*(cte_q1_1 + 2.0*cte_q1_2 + 2.0*cte_q1_3 + cte_q1_4);
	double q2_n = q2_O + (delta_t/6.0)*(cte_q2_1 + 2.0*cte_q2_2 + 2.0*cte_q2_3 + cte_q2_4);
	double p1_n = p1_O + (delta_t/6.0)*(cte_p1_1 + 2.0*cte_p1_2 + 2.0*cte_p1_3 + cte_p1_4);
	double p2_n = p1_O + (delta_t/6.0)*(cte_p2_1 + 2.0*cte_p2_2 + 2.0*cte_p2_3 + cte_p2_4);

	cout << q2_n << " " << p2_n;

	//Pregunta si q1 cambia de signo
	if(q1_O*q1_n < 0.0){
		cout << q2_n << " " << p2_n;		
	}

	//Actualiza el los valores inciales para hacer el ciclo
	q1_O = q1_n; 
	q2_O = q2_n;
	p1_O = p1_n;
	p2_O = p2_n;
	
}

return 0;
}
