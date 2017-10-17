#include <iostream>

using namespace std;

template <typename T>
//LISTA SIMPLESMENTE ENCADEADA
struct Noh{
	T elem;
	Noh<T> *prox;
};
// LIFO (LAST IN, FIRST OUT)
template <typename T>
struct Pilha{
	Noh<T> *topo;
};
template <typename T>
void inicializar_pilha(Pilha<T>&P){
	P.topo = NULL;
}
template <typename T>
bool empilhar(Pilha<T>&P, T e){
	Noh<T> *n = new (nothrow) Noh<T>;
	/* Cria-se um novo nó e fazemos o ponteiro prox
	   apontar para onde o topo esta apontando, em seguida,
		fazemos o topo apontar para o novo nó.
	*/
	if(n != NULL){
		n->elem = e;
		n->prox = P.topo;
		P.topo = n;
		return 1;//sem erro; 
	}else{
		return 0;// com erro
	}
}


template <typename T>
//PRÉ-CONDIÇão: pilha não estar vazia
T desempilhar(Pilha<T>&P){
	T e = P.topo->elem;
	if(P.topo->prox)
	P.topo = P.topo->prox;
	return e;
}

template <typename T>
//PRÉ-CONDIÇão: pilha não estar vazia
T consultar_topo(Pilha<T>&P){
	T e = P.topo->elem;
	return e;
}
template <typename T>
bool vazia (Pilha<T>&P){
	return P.topo->prox;
}

template <typename T>
void terminar_pilha(Pilha<T>&P){
	Noh<T> *n = P.topo;
	while(n){
		P.topo = n;
		n = P.topo->prox;
		delete P.topo;
	}
	delete n;
}
int main(int argc, char const *argv[])
{	Pilha<int> P;
	inicializar_pilha(P);
	int n=3;
	char o;
	do{
		cout << "Informa operacao:" <<endl;
		cin >> o;
		if(o == 'e'){
			cin >> n;
			cout << empilhar(P,n);
		}else if(o == 'd'){
			if(vazia(P)){
				cout << desempilhar(P) << endl;
			}else{
				cout << "pilha vazia" << endl;
			}
		}else if(o == 'c'){
			if(vazia(P)){
				cout << consultar_topo(P) << endl;;
			}else{
				cout << "pilha vazia" << endl;
			}
		}
	}while(n > 0);
	return 0;
}