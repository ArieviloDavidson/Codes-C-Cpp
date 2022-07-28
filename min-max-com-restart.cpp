/*************************************************************************************
		
b)Funcao f(x) = 10 + x^2 -10*cos(2*pi*x) para x entre [-6,6]

Agora implementando o Gradiente descendente com Restart e achando m�nimo global da fun��o b.

*************************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define PI 3.141592

using namespace std;

int aleatorio(){
	return (rand()%13)-6; // Pega o raio de -6 a 6 para escolher um numero aleatorio
}

float valor_da_funcao(float x){
	float func = 10 + pow(x,2) -10 * cos(2*PI*x); 
	return func;
}

int zero_da_funcao(float x){
	
	float func = 2*x + 20*PI*sin(2*PI*x); // Derivada da fun��o pedida no enunciado;
	
	if((func == 0)|| (func < 1 && func > -1) )
		return 0;
	else if(func > 0)
		return 1;
	else 
		return -1;
}

int main(){
	srand(time(NULL));
	
	int i=0, retorno=0;
	float x,x_aux, alfa, vetor[50];
	clock_t tInicio, tFim, tDecorrido, tInicio2, tFim2, tDecorrido2;
	
	cout << "Digite um valor para o alfa: ";
	cin >> alfa;

	for(i=0;i<50;i++){
	
		x = aleatorio();
		tInicio = clock();
		retorno = zero_da_funcao(x);
		
//		printf("\n\n\n %d VEZ\n\n\n\n", i+1); // GARANTIR QUE O C�DIGO RODA 50 VEZES;
// Com 15 vezes n�o era garantido que ele cairia em TODAS as possibilidades de random para come�ar o loop;
		
		do{	
			retorno = zero_da_funcao(x);
	
			if(retorno == 1){
				x = roundf((x - alfa) * 100) / 100; // Diminuiu alfa e garante que o n�mero ter� 2 casas decimais (estava ocorrendo um erro que ao somar ou diminuir 0.01 havia um erro de 0.0002;
			}
			else if( retorno == -1 ){
				x = roundf((x + alfa) * 100) / 100; // Acrescenta alfa e garante que o n�mero ter� 2 casas decimais (estava ocorrendo um erro que ao somar ou diminuir 0.01 havia um erro de 0.0002;
			}
			
			tFim = clock();
			tDecorrido = tFim - tInicio;
//			cout << "para x = " << x << " a funcao eh = " << zero_da_funcao(x) << "\n\n"; USAMOS ESSE COUT PARA CONTROLE DA QUANTIDADE DE VEZES QUE O WHILE FOI RODADO E PARA GARANTIR QUE O C�DIGO N EST� VICIADO;
				
			x_aux = x;
			
		}while(retorno != 0 && tDecorrido < 1000); // Como essa fun��o � mais complicada n�o estava dando exatamente zero NUNCA ent�o colocamos um limite de tempo para o loop, visto que em um certo momento ele fica repetindo os mesmo valores com 0.01 de diferen�a;
//		cout << "\nA funcao da 0 em x = " << x << endl;
// Se quiser conferir para cada restart qual valor ele acha;
		vetor[i] = x_aux; // ARRUMAMOS TODOS OS 50 RESULTADOS EM UM VETOR;
	}
	
	x = valor_da_funcao(vetor[0]); // Usaremos o valor da fun��o para o primeiro m�nimo encontrado como compara��o para os demais;
	
	for(i=1;i<50;i++){ 
		if(x > valor_da_funcao(vetor[i])){
			x = valor_da_funcao(vetor[i]); // Guarda o valor da fun��o;
			x_aux = vetor[i]; // Guarda para qual x onde a derivada � zero o valor da fun��o original � menor dentre todos os achados;
		}
	}
	
	cout << "\nA derivada da "<< x << " em x = " << x_aux << " sendo esse o valor minimo encontrado para a funcao nos pontos onde a derivada da 0 !!!" << endl;
	
	// O C�DIGO DEMORA DE 30 A 40 SEGUNDOS PRA RODAR;
	
	return 0;
}
