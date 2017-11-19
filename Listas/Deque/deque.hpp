#include <iostream>
#include <new>
/* O deque é uma estrutua de dados que permite inserções a esquerda 
a direita */
using namespace std;
template <typename T>
struct NohD{
	T elem;
	NohD<T> *ant, *prox;
};
template <typename T>
struct Deque{
	NohD<T> *ini, *fim;
};
template <typename T>
void inicializar_deque(Deque<T> &D){
	D.ini = D.fim = NULL;
}
template <typename T>
bool inserir_esq(Deque<T> &D, T e){
	NohD<T> *n = new (nothrow) NohD<T>;
	if(n){
		n->elem = e;
		n->ant = NULL;
		n->prox = D.ini;
		if(D.ini == NULL){
			D.fim = n;
		}else{
			D.ini->ant = n;
		}
		D.ini = n;
		return 1; // sem erro
	}else{
		return 0;// com erro
	}
}
template <typename T>
bool inserir_dir(Deque<T> &D, T e){
	NohD<T> *n = new (nothrow) NohD<T>;
	if(n){
		n->elem = e;
		n->prox = NULL;
		n->ant = D.fim;
		if(D.fim == NULL){
			D.ini == n;
		}else{
			D.fim->prox = n;
		}
		D.fim = n;
		return 1; // sem erro
	}else{
		return 0; // com erro;
	}
}
template <typename T>
T remover_esq(Deque<T> &D){
	T e = D.ini->elem;
	NohD<T> *n = D.ini;
	if(D.ini == D.fim){
		D.ini = D.fim = NULL;
	}else{
		D.ini = D.ini->prox;
	}
	delete n;
	return e;
}
template <typename T>
T remover_dir(Deque<T> &D){
	T e = D.fim->elem; 
	NohD<T> *n = D.fim;
	if(D.ini == D.fim){
		D.fim = D.ini = NULL;
	}else{
		D.fim = D.fim->ant;
	}
	delete n;
	return e;
}
template <typename T>
bool vazia(Deque<T> &D){
	return !(D.fim=NULL);
}
template <typename T>
void terminar_deque(Deque<T> &D){
	D.fim = NULL;
	while(D.ini != D.fim){
		D.ini = D.ini->prox;
		delete D.ini->ant;
	}
}

