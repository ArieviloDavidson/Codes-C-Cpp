#include <iostream>
 using namespace std;
 
 int fatorial(int n){
 	if(n == 0){
 		return 1;
	 }else{
	 	return n*fatorial(n-1);
	 }
 } // DE FORMA RECURSIVA E INTUITIVA CALCULA O FATORIAL DE UM NÚMERO
 
 int main(){
 	
 	int res;
 	
 	cout << "Gostaria de saber o fatorial de: ";
 	cin >> res;
 	
 	cout << "Resultado: " << fatorial(res);
 	
 	return 0;
 }
