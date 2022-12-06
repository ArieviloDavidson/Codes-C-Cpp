#include <iostream>
#include <queue>
#include <stack>

using namespace std;

template<class T>
class Stack:public stack<T> { /* implementar */ };

template<class T>
class Queue:public queue<T>{
	public:
		T dequeue(){
			T tmp = queue<T>::front(); // returns a reference to the first element of the queue
			queue<T>::pop();
		return tmp;
		}
	void enqueue(const T& el){
		queue<T>::push(el);
	}
};


// DEFINI��O DA CLASSE DO N�
template <class T>
class BSTNode{
	public:
		T el;
		BSTNode<T> *left, *right;
		BSTNode() {
			left = right = 0;
		}
		BSTNode(const T& e, BSTNode<T> *l = 0, BSTNode<T> *r = 0) {
			el = e; left = l; right = r;
		}	
};

//Defini��o da classe da �rvore
template <class T>
class BST{
	public:
		BST(){
			root = 0;
		}
		//~BST(){
		//	clear();
		//}
		//void clear(){
		//	clear(root); root = 0;
		//}
		bool isEmpty() const{
			return root == 0;
		} // DIZ SE A ÁRVORE ESTÁ VAZIA
		void preorder(){
			preorder(root);
		} // METÓDO DE ORDENAÇÃO PRÉ-ORDEM
		void inorder(){
			inorder(root);
		} // MÉTODO DE ORDENAÇÃO EM ORDEM
		void postorder(){
			postorder(root);
		} // MÉTODO DE ORDENAÇÃO PÓS-ORDEM
		T *search(const T& el) const{
			return search(root,el);
		}
		void breadthFirst();
		void insert(const T& el);
		void deleteByMerging(BSTNode<T>*& node);
		void findAndDeleteByMerging(const T &el);
	protected:
		BSTNode<T>* root;
		//void clear(BSTNode<T>*);
		T* search(BSTNode<T>*, const T&) const;
		void preorder(BSTNode<T>*);
		void inorder(BSTNode<T>*);
		void postorder(BSTNode<T>*);
		virtual void visit(BSTNode<T>* p){
			cout << p->el << ' ';
		}
		//void deleteByMerging(BSTNode<T>*& node);
		//void findAndDeleteByMerging(const T &el);
};

// BUSCA EM EXTENS�O DE CIMA PRA BAIXO DA DIREITA PRA ESQUERDA

template <class T>
void BST<T>::breadthFirst(){
	Queue <BSTNode<T>*> queue;
	BSTNode<T> *p = root;
	if(p != 0){
		queue.enqueue(p);
		while(!queue.empty()){
			p = queue.dequeue();
			visit(p);
			if(p->right != 0){
				queue.enqueue(p->right);
			}
			if(p->left != 0){
				queue.enqueue(p->left);
			}
		}
	}
}

// Pesquisar por valores em �rvores bin�rias de busca
template<class T>
T* BST<T>::search(BSTNode<T>* p, const T& el) const{
	while(p != 0){
		if(el == p->el){
			return &p->el;
		}else if(el < p->el){
			p = p->left;
		}else{
			p = p->right;
		}	
	}
	return 0;
}

//Procedimento em-ordem (inorder)

template <class T>
void BST<T>::inorder(BSTNode<T> *p){
	if(p != 0){
		inorder(p->left);
		visit(p);
		inorder (p->right);
	}
}

//Procedimento pr�-ordem

template <class T>
void BST<T>::preorder(BSTNode<T> *p){
	if(p != 0){
		visit(p);
		preorder(p->left);
		preorder(p->right);
	}
}

//Procedimento p�s-ordem

template <class T>
void BST<T>::postorder(BSTNode<T> *p){
	if(p != 0){
		postorder(p->left);
		postorder(p->right);
		visit(p);
	}
}

//Procedimento para inserir valores

template <class T>
void BST<T>::insert(const T& el){
	BSTNode<T> *p = root, *prev = 0;
	while(p != 0){ // encontrar um lugar para inserir um n�
	prev = p;
		if(el < p->el){
			p = p->left;
		}else{
			p = p->right;
		} 
	}
	if(root == 0){ // verifica se a �rvore esta vazia
		root = new BSTNode<T>(el); //insere o n� na raiz
	}else if(el < prev->el){ // compara el com o filho � esquerda
		prev->left = new BSTNode<T>(el); //insere o n� no filho � esquerda
	}else{ 
		prev->right = new BSTNode<T>(el); //insere o n� no filho � direita.
	}
}

//Procedimentos para deletar n�

template <class T>
void BST<T>::deleteByMerging(BSTNode<T>*& node){
	BSTNode<T> *tmp = node;
	if(node != 0){
		if(!node->right){//n� n�o tem filhos a direita: seu filho esquerdo (se houver) � anexado a seu pai
			node = node->left;
		}else if(node->left == 0){//n� n�o tem filhos a esquerda: seu filho direito (se houver) � anexado a seu pai
			node = node->right;
		}else{//Mesclar sub�rvores
			tmp = node->left;//Mova pra esquerda
			while(tmp->right != 0){//Ent�o na medida do possivel
				tmp = tmp->right;
			}
			tmp->right = node->right;//estabelecer a liga��o entre o n� mais � direita da sub�rvore esquerda e a sub�rvore direita
			tmp = node;
			node = node->left;
		}
		delete tmp;
	}
}

template <class T>
void BST<T>::findAndDeleteByMerging(const T &el){
	BSTNode<T> *node = root, *prev = 0;
	while(node != 0){
		if(node->el == el){
			break;
		}
		prev = node;
		if(el < node->el){
			node = node->left;
		}else{
			node = node->right;
		}
	}
	if(node != 0 and node->el == el){
		if(node == root){
			deleteByMerging(root);
		}else if(prev->left == node){
			deleteByMerging(prev->left);
		}else{
			deleteByMerging(prev->right);
		}
	}else if(root != 0){
		cout << "Elemento" << el << "n�o est� na �rvore!" << endl;
	}else{
		cout << "A �rvore est� vazia!" << endl;
	}
}

int main(){
	
	BST<int> arvore1;
	int el;
	int *pesq;
	setlocale( LC_ALL, "" ); //Apenas para acentuar
	//Inserir elementos na �rvore
	arvore1.insert(10);
	arvore1.insert(14);
	arvore1.insert(9);
	arvore1.insert(-1);
	arvore1.insert(2);
	arvore1.insert(4);
	arvore1.insert(30);
	arvore1.insert(5);
	arvore1.insert(28);
	arvore1.insert(12);
	
	//Percursos:
	cout << "\n Percurso in-order:";
	arvore1.inorder();
	cout << "\n Percurso pr�-order:";
	arvore1.preorder();
	cout << "\n Percurso p�s-order:";
	arvore1.postorder();
	cout << endl;
	arvore1.breadthFirst();	
	
	arvore1.findAndDeleteByMerging(30);
	
	cout << "\n Percurso in-order:";
	arvore1.inorder();
	cout << "\n Percurso pr�-order:";
	arvore1.preorder();
	cout << "\n Percurso p�s-order:";
	arvore1.postorder();
	cout << endl;
	arvore1.breadthFirst();	
	
	return 0;
}

