#include <iostream>
#include <new>
using namespace std;

template <typename T>
struct Noh{
	T elem;
	Noh<T> *prox;
};

template <typename T>
struct Fila{
	Noh<T> *ini, *fim;
};

template <typename T>
void inicializar_fila(Fila<T>&F){
	F.ini = NULL;
}

template <typename T>
bool enfilar(Fila<T>F, T e){
	Noh<T> *n = new (nothrow) Noh<T>;
	if(n){
		n->elem = e;
		n->prox = NULL;
		if(F.ini == NULL){
			F.ini = n;		

		}else{
			F.fim->prox = n;
		}
		F.fim = n;
		return 1;
	}else{ return 0;}	
}

template <typename T>
T desenfilar(Fila<T> F){
	Noh<T> *n = F.ini;
	T e = n->elem;
	F.ini = n->prox;
	delete n;
	return e;
}
int main(int argc, char const *argv[]){
	Fila<int> F;
	inicializar_fila(F);
	int n=3;
	char o;
	cout << enfilar(F,n);
	cout << desenfilar(F);
	/*do{
		cout << "Informa operacao:" <<endl;
		cin >> o;
		if(o == 'e'){
			cin >> n;
			cout << enfilar(F,n);
		}else if(o == 'd'){
			cout << desenfilar(F);
		}
	}while(n > 0);*/
	return 0;
}