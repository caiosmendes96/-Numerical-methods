#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

// Retorna o valor da fun��o para cada ponto (Xo at� Xn).
double fx (double x){
    double resultado;
    resultado = (pow(x,3.0) + pow(x,2.0) + x + 1);
    return resultado;
}
//C�lculo da integra��o de richardson pelo m�todo da 1 regra de Simpson.
double calculaintegracao(int n,double a,double b){
    double h = (b-a) / n;
    double arg = a;
    double integracao =0;
    double x0[n]; // Vetor para armazenar os valores de X subdivididos por n.
    
    for (int i=0; i<n+1;i++) {
  
        x0[i] = arg; // adiciona todos os pontos de Xo at� Xn.
        arg +=h;
    }
    for(int j=0;j<n;j+=2){ // 
    	
     integracao += (h/3)*(fx(x0[j]) + 4*fx(x0[j+1]) + fx(x0[j+2])); // F�rmula da Integra��o Num�rica para 1 Regra de simpson.
     
    }
   	 cout << "Integral para n = " << n << ": " << integracao << endl;
     return integracao;
}



//C�lculo da aproxima��o para os dois subintervalos.
double calculaextrapolacao(double integracao1,double integracao2,int n1,int n2){
	
    double resultado = integracao2+ (pow(n1,2)/(pow(n2,2) - pow(n1,2))*(integracao2 - integracao1)); // F�rmula da extrapola��o de Richardson.
    	cout << "Extrapolacao: " << resultado << endl;
    	
    return resultado;
}

int main()
{
    
    double a=1; // Valor inicial da integra��o.
    double b = 2;  // Valor final da intergra��o.
    int n1=4; // Valor da 1� aproxima��o usando 4 subintervalos.
    int n2 =6;// Valor da 2� aproxima��o usando 6 subintervalos.
    	calculaextrapolacao(calculaintegracao(n1,a,b),calculaintegracao(n2,a,b),n1,n2);
    return 0;
}
