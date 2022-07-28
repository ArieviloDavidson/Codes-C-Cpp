/*************************************************************************************
			
min�mo global de f(x) = Somatorio de i=1 at� d-1 de [100(x_(i+1) - x^2_(i) + (x_(i) - 1)^2] para x_(i) = [-5, 10]

algoritmo : hill climbing 

s <- uma solu�ao candidata
repeat
	R <- tweak(copia de s)
	if qualidade(R) > qualidade(s) then
		S <- R
	
at� que S seja ideal ou estourar o tempo

*************************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;

int aleatorio(){
	return (rand()%16)-5; // Pega o raio de -5 a 10 para escolher um numero aleatorio
}

float valor_da_funcao(int x1, int x2){
	float res = pow(x1-1,2) + 100*pow(x2 - pow(x1,2),2);
	return res;
}

void tweak(int vet[2]){
	int l = 2 , n, aux;
	int min = -5;
	int max = 10;
	for(int i=0; i<l; i++){
		n = aleatorio();
		while(vet[i]+n < max and vet[i]+n > min){
			aux = n;
			n = aleatorio();
		}
		vet[i] = vet[i] + aux;
	}
}

int main(){
	
	srand(time(NULL));
	
	int x1, x2, x1aux, x2aux;
	int i = 0;
	
	x1 = aleatorio();
	x2 = aleatorio();
	
	int vet[2] = {x1, x2};
	float s = valor_da_funcao(x1, x2);	

	do{
		tweak(vet);
		x1aux = vet[0];
		x2aux = vet[1];
		float r = valor_da_funcao(x1aux,x2aux);
		if(r < s){
			s = r;
			x1 = x1aux;
			x2 = x2aux;
		}
		i++;
	}while(s != 0 and i<1000000);
	
	cout << "Valores encontrados: " << endl << "X1 = " << x1 << endl << "X2 = " << x2 << endl << "com s sendo = " << s;

	return 0;
}


