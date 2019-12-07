#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#define pi 3.1415; 
using namespace std;


// Retorna o valor da fun��o para cada ponto (Xo at� Xn).
double fx (double x)
{
    double resultado;
    resultado = sin(x); // Fun��o utilizada.
    return resultado;
}
//C�lculo da integra��o de richardson pelo m�todo da regra dos trap�zios.
double calculaintegracao(int n,double a,double b){
	
    double h = (b-a) /n;
    double arg = a;
    double integracao =0;
    double x0[n]; // Vetor para armazenar os valores de X subdivididos por n.
    
    for (int i=0; i<n+1;i++) {
        x0[i] = arg;
        arg +=h;
    }
    
    for(int j=0;j<n;j++){
     integracao += (h/2)*(fx(x0[j]) + fx(x0[j+1]));
    }
    cout << "Integral para n = " << n << ":" << integracao << endl;
     return integracao;
}



//C�lculo da aproxima��o para os dois subintervalos.
double calculaextrapolacao(double integracao1,double integracao2,int n1,int n2){
	
    double resultado = integracao2 + (pow(n1,2)/(pow(n2,2) - pow(n1,2))*(integracao2 - integracao1)); // F�rmula da extrapola��o de Richardson.
    
    	cout << "Extrapolacao: " << resultado << endl;
    	
    	return resultado;
}

int main()
{
    
    double a=0; // Valor inicial da integra��o.
    double b = pi; // Valor final da intergra��o.
    
    int n1=2; // Valor da 1� aproxima��o usando 2 subintervalos.
    int n2 =4; // Valor da 2� aproxima��o usando 4 subintervalos.
    
    calculaextrapolacao(calculaintegracao(n1,a,b),calculaintegracao(n2,a,b),n1,n2);
    return 0;
}
