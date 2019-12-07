#include <iostream>
#include <string>
#include <vector>
using namespace std;

double  matriz[4][2];



void preenchematriz(int n){
  cout<<"Digite o x e y (um par de numeros por linha)" << "\n";
  
    for (int i=0;i<n+1;i++) {
         cout << "linha" << i << "\n";
        for(int j=0;j<2;j++){
           
            cin >>  matriz[i][j];
          
           
        }
    }
}


void interpolacaolagrange(float x0, int n){
    double produtoria =1;
    double resultado=0;
    for(int i=0;i<n+1;i++){
        produtoria = 1;
        for(int j=0;j<n+1;j++){
           
            if(i !=j){
                produtoria *= ((x0 - matriz[j][0])/(matriz[i][0] - matriz[j][0]));
            }
                                     
        }
       
        resultado += produtoria * matriz[i][1];
    }
   
    cout << "Resultado final:" << resultado;
}



int main()
{
    int n;
    double x0;
    
    cout <<"Digite o grau do polinômio." <<"\n";
    cin >> n;
         preenchematriz(n);
       
    cout << "Digite o valor inicial. " << "\n";
    cin >> x0;
   
        interpolacaolagrange(x0,n);
   
    return 0;
   
}
