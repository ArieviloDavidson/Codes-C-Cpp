#include <iostream>

using namespace std;

// CLASSE PARA O NÓ

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

// CLASSE DA FILA

class Queue{
	private:
		Node *head, *tail;
	public:
		Queue(){
			head = tail = 0;
		}
		void clearQ();
		bool isEmpty(){
			return (head == NULL);
		}
		void enqueue(int el);
		void dequeue();
		int firstEl();
		void printQueue();
};

void Queue::clearQ(){
	Node *tmp = head;
	while(tmp != NULL){
		tmp = tmp->next;
		delete head;
		head = tmp;
	}
}

void Queue::enqueue(int el){
	if(tail != 0){ // SE A LISTA NÃO ESTIVER VAZIA
		tail->next = new Node(el, 0);
		tail = tail->next;
	}else{
		head = tail = new Node(el, 0);
	}
}

void Queue::dequeue(){
	if(!isEmpty()){
		cout << "\nElemento removido: " << firstEl();
		Node *tmp = head;
		if(head == tail){ // SE HÁ APENAS UM NÓ NA LISTA
			head = tail = 0;
		}else{
			head = head->next;
		}
		delete tmp;
	}else{
		cout << "\nLista vazia, nenhum elemento retirado!";
	}
}

int Queue::firstEl(){
	if(head == NULL){
		cout << "\nFila vazia!";
		return -1;
	}else{
		return head->info;
	}
}

void Queue::printQueue(){
	Node *tmp = head;
	while(tmp != NULL){
		cout << "\n" << tmp->info;
		tmp = tmp->next;
	}
}

int main(){
	
	Queue fila;
	cout << "conteudo atual da fila: ";
	fila.enqueue(10);
	fila.printQueue();
	
	fila.enqueue(20);
	fila.enqueue(30);
	fila.enqueue(40);
	cout << endl << "conteudo atual da fila: ";
	fila.printQueue();
	
	fila.dequeue();
	fila.dequeue();
	cout << endl << "conteudo atual da fila:";
	fila.printQueue();
	
	return 0;
}
