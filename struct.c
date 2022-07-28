#include <stdio.h>

int main(){
	
	struct ficha_aluno
	{
		char nome[40];
		int numero;
		float nota;	
	};//definição da struct
	
	struct ficha_aluno aluno;
	
	printf("\n---------- Cadastro de Aluno ----------\n\n");
	
	printf("Nome do Aluno ......: ");
	scanf("%s", &aluno.nome); // ESTRUTURA DE LEITURA PARA CADA "TERMO" DA ESTRUTURA, o nome da ficha_aluno "." o termo;
	
	printf("Digite o numero do aluno: ");
	scanf("%d", &aluno.numero);
	
	printf("Informe a nota do aluno: ");
	scanf("%f", &aluno.nota);
	
	printf("\n---------- Lendo os dados da struct ----------\n\n");
	printf("Nome: %s \n", aluno.nome);
	printf("Numero: %d \n", aluno.numero);
	printf("Nota : %.2f \n", aluno.nota);
	
	return 0;
}
