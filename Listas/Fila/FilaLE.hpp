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
