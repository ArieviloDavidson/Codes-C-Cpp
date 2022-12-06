#include <iostream>

using namespace std;

// CLASSE DO N�

class Node{
	public:
		int info; // NESSE CASO UM NÚMERO QUE ESTÁ ASSOCIADO A CADA NÓ DA PILHA (MAS PODERIA SER UMA INFORMAÇÃO MAIS COMPLEXA)
		Node *next; // CADA NÓ É LIGADO POR UM POITEIRO (APONTADOR) PARA O PRÓXIMO NÓ DA PILHA
		Node(){
			next = 0;
		} // PODEMOS CRIAR UM NÓ VAZIO
		Node(int el, Node *pr){
			info = el;
			next = pr;
		} // ASSIM COMO PODEMOS CRIAR UM NÓ JÁ COM INFORMAÇÃO (NÚMERO) DENTRO DELE, ALÉM DO APONTAMENTO PARA O PROXÍMO NÓ
};

// CLASSE PARA ACESSAR A PILHA

class Stack{
	private:
 		Node* head; // O NÓ HEAD (CABEÇA) SÓ PODE SER ACESSADO PELA PRÓPRIA PILHA, POIS QUASE TODAS AS OPERAÇÕES SÃO FEITAS A PARTIR DELE
	public:
 		Stack(){
			head = 0;
		} // CRIAÇÃO DA PILHA AINDA VAZIA
 		void clear () ; // FUNÇÃO QUE LIMPA A PILHA
 		bool isEmpty(){
 			return (head==NULL);
 		} // CASO A PILHA ESTEJA VAZIA (HEAD==NULL) RETORNA TRUE, CASO NÃO RETORNA FALSE
 		void push(int el); // PUSH = COLOCAR UM ELEMENTO NA PILHA (TOPO) (LEMBRANDO QUE A PILHA FUNCIONA COMO LIFO (LAST IN, FIRST OUT))
 		void pop() ; // POP = RETIRAR UM ELEMENTO DA PILHA (TOPO) (LEMBRANDO QUE A PILHA FUNCIONA COMO LIFO (LAST IN, FIRST OUT)
		int popEl(); // FUNÇÃO CRIADA PARA REMOVER UM ELEMENTO ESPECÍFICO DA PILHA (DESRESPEITANDO A REGRA DO LIFO(LAST IN, FIRST OUT))
 		void printStack(); // MOSTRA A ATUAL CONDIÇÃO DA PILHA
};

void Stack::clear(){
	Node *tmp = head;
	while(tmp != NULL){
		tmp = tmp->next;
		delete head;
		head = tmp;
	}
}

void Stack::push(int el){
	head = new Node(el, head);
	head->info = el;
}

void Stack::pop(){
	cout << "\nElemento removido " << popEl();
	//popEl();
	if(head != NULL){
		Node *tmp = head;
		head = head->next;
		delete tmp;
	}
}

int Stack::popEl(){
	if(head == NULL){
		cout << "\nPilha vazia!";
		return -1;
	}else{
		return head->info;
	}
}

void Stack::printStack(){
	Node *tmp = head;
	cout << "\nCondicao atual da pilha:";
	while(tmp != NULL){
		cout << "\n" << tmp->info;
		tmp = tmp->next;
	}
}

int main(){
	
	Stack teste; // CRIA��O DA PILHA TESTE
	
	teste.push(45);
	teste.push(3);
	
	teste.printStack();
	
	teste.pop();
	
	teste.printStack();
	
	return 0;
}
