#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;


double matriz[50][50];

double aproximacaoderivada(double x, double y){
	
	return (1+x) / (1+y); // Derivada da função 1 ordem.
}

void preenchematriz(double a, double b,double h,int m){
	
	double x=a; // Valor de Xo.
	double y=b; // Valor de Yo.
	double yf; // Yj+1.
	
	matriz[0][1] = y; // Valor da função Yo.
	
	//Armazena na matriz os valores  de Xo até Xi subdivididos. 
	for(int i=0;i<m+1;i++){
		matriz[i][0] = x;
		x +=h;
	}
	
	for(int j=0;j<m;j++){
		
		// Fórmula do método de Euler utilizando método de Passo Simples de 1 ordem para calcular Yj+1.
		yf = matriz[j][1] + (h * aproximacaoderivada(matriz[j][0],matriz[j][1])); 
		matriz[j+1][1] = yf;
	}
	
	for(int i=0;i<m+1;i++){
	
			cout << "Valor de x" << i <<": " << matriz[i][0] << "  ";
			cout << "Valor de y" << i <<": " << matriz[i][1]<< endl;	
			
	}
	
	
}

int main(){
	
	int m=4; // Quantidade de subintervalos.
	double a =1; // Valor de Xo.
	double b = 2; // Valor de Yo.
	double h = 0.25; // Diferença entre Xi+1 e Xi;
	
	preenchematriz(a,b,h,m);
}
