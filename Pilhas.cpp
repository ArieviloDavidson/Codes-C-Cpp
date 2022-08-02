#include <iostream>

using namespace std;

// CLASSE DO NÓ

class Node{
	public:
		int info;
		Node *next;
		Node(){
			next = 0;
		}
		Node(int el, Node *pr){
			info = el;
			next = pr;
		}
};

// CLASSE PARA ACESSAR A PILHA

class Stack{
	private:
 		Node* head;
	public:
 		Stack(){
			head = 0;
		}
 		void clear () ;
 		bool isEmpty(){
 			return (head==NULL);
 		}
 		void push(int el);
 		void pop() ;
		int popEl();
 		void printStack();
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
	while(tmp != NULL){
		cout << "\n" << tmp->info;
		tmp = tmp->next;
	}
}

int main(){
	
	Stack teste;
	
	teste.push(45);
	teste.push(3);
	
	teste.printStack();
	
	teste.pop();
	
	teste.printStack();
	
	return 0;
}
