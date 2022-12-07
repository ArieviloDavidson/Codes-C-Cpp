#include <iostream>

using namespace std;

// CLASSE SIMPLES PARA ESTUDO A CÁLCULO DA ÁREA DE UM TRIÂNGULO A PARTIR DE SUA BASE E ALTURA

class tri{
	private:
		float base;
		float altura;
		float area = 0;
		
	public:
		void ReceberDados(){
			do{
				cout << endl << "Base: ";
				cin >> base;
				cout << "Altura: ";
				cin >> altura;
				
				if(base <= 0){
					cout << endl << "Base INVALIDA!" << endl ;
				}
				if(altura <= 0){
					cout << endl << "Altura INVALIDA!" << endl;
				}
				
			}while(base <= 0 || altura <= 0);
			
		}
		
		void ExibirDados(){
			cout << endl << "----- PROPRIEDADES DO TRIANGULO -----" << endl << endl;
			cout << "Base: " << base << endl;
			cout << "Altura: " << altura << endl;
			area = (base*altura) / 2;
			cout << "Area do Triangulo: " << area << " u.a." << endl;
		}
		
};

int main(){
	
	tri t1;
	
	cout << "----- Dados do Triangulo -----" << endl;
	t1.ReceberDados();
	t1.ExibirDados();
	
	return 0;
}
