/*************************************************************************************
 
Achando mínimo/máximo de uma função quadrática.
			
Fun��o:  f(x) = ( x+5)^2 para x entre [-10,5] alfa= 0.01

*************************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;

int aleatorio(){
	return (rand()%16)-10; // Pega o raio de -10 a 5 para escolher um numero aleatorio;
}

int zero_da_funcao(float x){
	
	float func = 2*x + 10; // Derivada da fun��o pedida no enunciado;
	
	if(func == 0)
		return 0;
	else if(func > 0)
		return 1;
	else 
		return -1;
	
}

int main(){
	srand(time(NULL));
	
	int i=0, retorno;
	float x, alfa;
	
	x = aleatorio();
	
	cout << "Digite um valor para o alfa: ";
	cin >> alfa;
	
	do{
		retorno = zero_da_funcao(x);

		if(retorno == 1){
			x = roundf((x - alfa) * 100) / 100;	// Diminuiu alfa e garante que o n�mero ter� 2 casas decimais (estava ocorrendo um erro que ao somar ou diminuir 0.01 havia um erro de 0.0002;	
		}
		else if( retorno == -1 ){
			x = roundf((x + alfa) * 100) / 100; // Acrescenta alfa e garante que o n�mero ter� 2 casas decimais (estava ocorrendo um erro que ao somar ou diminuir 0.01 havia um erro de 0.0002;
		}
		
		cout << "para x = " << x << " a funcao eh = " << zero_da_funcao(x) << "\n\n"; // Esse cout � apenas para controle, para sabermos que o c�digo est� rodando esse while x vezes acrescentando ou diminuindo alfa e que n�o est� viciado em um resultado espec�fico; 
	}while(retorno != 0);
	
	cout << "\nA funcao da 0 em x = " << x << endl;
	
	return 0;
}
