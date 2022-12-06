#include <iostream>

using namespace std;

// SLL = LISTA SINGULARMENTE LIGADA (POIS CADA NÓ É LIGADO APENAS COM O SEU SUCESSOR)

// Classe para os n�s da lista
class IntSLLNode{
	public:
		IntSLLNode(){
			next = 0;
		}
		IntSLLNode (int el, IntSLLNode *ptr = 0){
			info = el; // info guarda a informa��o
			next = ptr; // next vincula os n�s da lista
		}
		int info;
		IntSLLNode *next;
};

// Classe para acesso � lista
class IntSLLList{
	private:
		IntSLLNode *head, *tail;
	public:
		IntSLLList(){
			head = tail = 0;
		}
		//~IntSLList();
		int isEmpty(){
			return head == 0;
		}
		void addToHead(int); // INSERE NO HEAD
		void addToTail(int); // INSERE NO TAIL
		int deleteFromHead(); // DELETA DO HEAD
		int deleteFromTail(); // DELETA DO TAIL
		void deleteNode(int); // DELETA UM NÓ ESPECIFICO A PARTIR DA INFORMAÇÃO CONTIDA NELE
		bool isInList(int) const; // RETORNA SE UM DETERMINADO VALOR (INFO) ESTÁ PRESENTE NA LISTA (TRUE OR FALSE)
		void printSLLList(); // MOSTRA A LISTA NA ATUAL SITUAÇÃO
};

// DEFINI��O DAS FUN��ES DA CLASSE INTSLLLIST

void IntSLLList :: addToHead(int el){
	head = new IntSLLNode(el, head);
	if(tail == 0){
		tail = head;
	}
}

void IntSLLList :: addToTail(int el){
	if(tail != 0){ // SE A LISTA N�O TIVER VAZIA
		tail -> next = new IntSLLNode(el);
		tail = tail->next;
	}else{
		head = tail = new IntSLLNode(el);
	}
}

int IntSLLList :: deleteFromHead(){ // N�O CONSIDERAMOS AQUI AINDA O CASO DA LISTA ESTAR VAZIA
	int el = head->info;
	IntSLLNode *tmp = head;
	if(head == tail){ // SE S� TIVER UM N� (UM ELEMENTO) NA LISTA
		head = tail = 0;
	}else{
		head = head->next;	
	}
	delete tmp;	
	return el;
}

int IntSLLList :: deleteFromTail(){ // N�O CONSIDERAMOS AQUI AINDA O CASO DA LISTA ESTAR VAZIA
	int el = tail->info;
	if(head == tail){ // SE S� TIVER UM N� (UM ELEMENTO) NA LISTA
		delete head;
		head = tail = 0;
	}else{ // SE TIVER MAIS DE UM N� 
		IntSLLNode *tmp; // PARA ACHAR O PREDECESSOR DE TAIL DA LISTA
		for(tmp = head; tmp->next != tail; tmp = tmp->next);
		delete tail;
		tail = tmp;
		tail->next = 0;
	}
	return el;
}

void IntSLLList :: deleteNode(int el){ // DELETAR UM ELEMENTO ESPEC�FICO CASO ELE EXISTA NA LISTA
	if(head != 0){ // SE LISTA N�O VAZIA
		if(head == tail && el == head->info){ // SE S� TEM UM N� NA LISTA E O ELEMENTO DESSE N� � O PROCURADO
			delete head;
			head = tail = 0;
		}else{
			if(el == head->info){ // SE H� MAIS DE UM N� E O ELEMENTO PROCURADO EST� NO PRIMEIRO N�
				IntSLLNode *tmp = head;
				head = head->next;
				delete tmp; // HEAD ANTERIOR E DELETADO
			}else{
				IntSLLNode *pred, *tmp;
				for(pred = head, tmp = head->next; tmp != 0 && !(tmp->info == el); pred = pred->next, tmp = tmp->next); // AT� TMP INFO = EL;
				if(tmp != 0){ // OU SEJA TMP ENCONTROU O EL
					pred->next = tmp->next; // A GROSSO MODO PULA UMA CASA
					if(tmp == tail){ // SE O EL EST� EM TAIL
						tail = pred;
					}
					delete tmp;
				}
			}
		}
	}
}

bool IntSLLList :: isInList(int el) const{ // DIZ SE UM EL EST� PRESENTE EM UMA LISTA
	IntSLLNode *tmp;
	for(tmp = head; tmp != 0 && !(tmp->info == el); tmp = tmp->next);
	return tmp != 0;
}

void IntSLLList :: printSLLList(){ // PRINTA A LISTA DO HEAD PARA O TAIL
	IntSLLNode *tmp = head;
	while(tmp != NULL){
		cout << "tmp->info: " << tmp->info << endl; // INFO PRESENTE NO N�
		cout << "&tmp: " << tmp << endl; // ENDERE�O DESSE N�
		cout << "tmp->next: " << tmp->next << endl << endl; // ENDERE�O DO PR�XIMO N�
		tmp = tmp->next;
	}
}

int main(){

	IntSLLList teste;
	
	teste.addToHead(34);
	teste.addToHead(21);
	teste.addToHead(2);
	
	teste.printSLLList();
	
	return 0;
}
