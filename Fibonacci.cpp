#include <iostream>
using namespace std;

int fib(int x){
	if(x < 2){
		return x;
	}else{
		return fib(x-2) + fib(x-1);
	}
} // USO DA RECURSIVIDADE E DA DEFINIÇÃO DA SEQUÊNCIA

int main(){
	
	for(int x = 0; x <= 30; x++){
		cout << fib(x) << endl;
	}
	
	return 0;
}
