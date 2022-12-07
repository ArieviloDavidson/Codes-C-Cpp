#include <stdio.h>
#include <string.h>
#include <math.h>
#include <locale.h>

#define MAX 10

// FUNÇÃO SEM RETORNO PARA A OPERAÇÃO SOMA

void SOMA(float vet[]){
	int n, i;
	float soma;
	
	soma = 0;
	
	do{
		printf("Quantidade de n�meros a serem somados: ");
		scanf("%d", &n);
		if(n < 0 || n > 10){
			printf("Valor inv�lido!\n");
		}	
	}while(n > 10 || n < 0);
	
	for(i = 0; i < n; i++){
		printf("Informe o %d valor: ", i+1);
		scanf("%f", &vet[i]);
	}
	
	for(i = 0; i < n; i++){
		soma = soma + vet[i];
	}
	
	printf("Soma = %f \n", soma);
}

// FUNÇÃO SEM RETORNO PARA A OPERAÇÃO SUBTRAÇÃO

void SUBTRACAO(float vet[]){
	int n, i;
	float sub;
	
	do{
		printf("Quantidade de n�meros a serem subtra�dos: ");
		scanf("%d", &n);
		if(n < 0 || n > 10){
			printf("Valor inv�lido!\n");
		}	
	}while(n > 10 || n < 0);
	
	for(i = 0; i < n; i++){
		printf("Informe o %d valor: ", i+1);
		scanf("%f", &vet[i]);
	}
	
	sub = vet[0];
	
	for(i = 1; i < n; i++){
		sub = sub - vet[i];
	}
	
	printf("Subtra��o = %f \n", sub);
}

// FUNÇÃO SEM RETORNO PARA A OPERAÇÃO MULTIPLICAÇÃO

void MULTIPLICACAO(float vet[]){
	int n, i;
	float mult;
	
	mult = 1;
	
	do{
		printf("Quantidade de n�meros a serem multiplicados: ");
		scanf("%d", &n);
		if(n < 0 || n > 10){
			printf("Valor inv�lido!\n");
		}	
	}while(n > 10 || n < 0);
	
	for(i = 0; i < n; i++){
		printf("Informe o %d valor: ", i+1);
		scanf("%f", &vet[i]);
	}
	
	for(i = 0; i < n; i++){
		mult = mult * vet[i];
	}
	
	printf("Multiplica��o = %f \n", mult);
}

// FUNÇÃO SEM RETORNO PARA A OPERAÇÃO DIVISÃO

void DIVISAO(float vet[]){
	int n, i;
	float div;
	
	do{
		printf("Quantidade de n�meros a serem divididos: ");
		scanf("%d", &n);
		if(n < 0 || n > 10){
			printf("Valor inv�lido!\n");
		}	
	}while(n > 10 || n < 0);
	
	for(i = 0; i < n; i++){
		printf("Informe o %d valor: ", i+1);
		scanf("%f", &vet[i]);
	}
	
	div = vet[0];
	
	for(i = 1; i < n; i++){
		div = div / vet[i];
	}
	
	printf("Divis�o = %f \n", div);
}

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	int opcao;
	float vet[MAX];
	
	printf("----------- C A L C U L A D O R A -----------\n");
	
	do{
		printf("\n[1] SOMA\n");
		printf("[2] SUBTRA��O\n");
		printf("[3] MULTIPLICA��O\n");
		printf("[4] DIVIS�O\n");
		printf("[5] FIM\n");
		printf("\nOPERA��O: ");
		scanf("%d", &opcao);
		
		if(opcao < 1 || opcao > 5){
			printf("OP��O INV�LIDA!\n");
		} // PARA AVERIGUAR SE A OPÇÃO DIGITADA É VALIDA NO SISTEMA
		
		switch(opcao){
			case 1:
				SOMA(vet);
				break;
			case 2:
				SUBTRACAO(vet);
				break;
			case 3:
				MULTIPLICACAO(vet);
				break;
			case 4:
				DIVISAO(vet);
				break;
		} // USO DA ESTRUTURA SWITCH CASE APÓS O USUÁRIO DIGITAR A OPERAÇÃO A SER FEITA
		
	}while(opcao != 5); // PARA CONTROLAR A FINALIZAÇÃO DO USO
	
	printf("\n          FIM DA EXECU��O!           ");
	
	return 0;
}
