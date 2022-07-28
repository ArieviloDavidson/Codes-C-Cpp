#include <stdio.h>

int bissexto(int x){ // FUN��O QUE "CALCULA" SE O ANO � BISSEXTO OU N�O A PARTIR DE UMA F�RMULA;
	int result;
	if(x%4 == 0 && (x%100 != 0 || x%400 == 0)){
		result = 1;
	}else{
		result = 0;
	}
	return result; // RESULT = 1 (BISSEXTO), RESULT = 0 (N�O BISSEXTO);
}

int main(){
	int x;
	
	printf("Digite um ano: ");
	scanf("%d", &x);
	
	bissexto(x); // CHAMADA DA FUN��O, TENDO COMO PARAMETRO O ANO DIGITADO PELO USU�RIO;
	
	printf("Conferindo o resultado da funcao: %d\n", bissexto(x));
	if(bissexto(x) == 1){
		printf("O ano %d e bissexto.", x);
	}
	if(bissexto(x) == 0){
		printf("O ano %d nao e bissexto.", x);	
	}
	return 0;
}
