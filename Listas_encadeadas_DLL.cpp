#include <iostream>

using namespace std;

// DLL = LISTA DUPLAMENTE LIGADA

// Classe para os nós da lista
class DLLNode {
	public:
		DLLNode(){
			next = prev = 0;
		}
		DLLNode(int el, DLLNode *n = 0, DLLNode *p = 0){
		info = el; // info guarda a informação 
		next = n; // next vincula o proximo nó
		prev = p; // prev vincula o nó anterior
		}
		int info;
		DLLNode *next, *prev;
};

// Classe para acesso a lista
class DoublyLinkedList {
	public:
		DoublyLinkedList() {
			head = tail = 0;
		}
		void addToDLLTail(int); // INSERE NO TAIL
		int deleteFromDLLTail(); // DELETA DO TAIL
		//. . . . . . . . . . . . . INSERIR AS OUTRAS OPERAÇÕES
	protected:
		DLLNode *head, *tail;
};

// DEFINIÇÃO DAS FUNÇÕES DA CLASSE DOUBLYLINKEDLIST

void DoublyLinkedList :: addToDLLTail(int el) {
	if(tail != 0){
		tail = new DLLNode (el, 0, tail);
		tail->prev->next = tail;
	}else{
	 	head = tail = new DLLNode (el);
	}
}

int DoublyLinkedList :: deleteFromDLLTail() {
	int el = tail->info;
	if(head == tail){ // Se já apenas um nó na lista
		delete head;
		head = tail = 0;
	}else{ // se há mais de um nó na lista
		tail = tail->prev;
		delete tail->next;
		tail->next = 0;
	}
	return el;
}

int main(){
	
	DoublyLinkedList teste;
	
	teste.addToDLLTail(56);
	teste.addToDLLTail(4);
	
	cout << teste.deleteFromDLLTail();
	
	return 0;
}
