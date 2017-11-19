/*==============Conjunto Simples==================
===============LISTA SIMPLESMENTE ENCADEADA======
	inicializar_conjunto(D)
	inserir(C,e)
	Remover(C,e)
	Pertence(C)
	Vazio(C)
	terminar_conjunto(C)
	*/
#include <iostream>
using namespace std;

template <typename T>
struct Noh{
	T e;
	Noh<T> *prox;
};

template <typename T>
struct ConjuntoDin{
	Noh<T> *prim;	
};
template <typename T>
void inicializar_conjunto(ConjuntoDin<T> &C){
	C.prim = NULL;
}

template <typename T>
//PRÉ-CONDIÇÃO, O ELEMENTO JÁ NÃO PERTENCER AO CONJUNTO
bool inserir(ConjuntoDin<T> &C, T e){
	Noh<T> *n = new (nothrow) Noh<T>;
	if(n){
		n->elem = e;
		n->prox = C.prim;
		C.prim = n;
		return 0; // sem erro;
	}else{
		return 1; // com erro
	}
}

template <typename T>
bool pertence (ConjuntoDin<T> &C, T e){
	Noh<T> *n = new (nothrow) Noh<T>;
	for(n = C.prim; n; n = n->prox){
		if(n->elem = e){
			return 1;
		}
	}
	return 0;
}
template <typename T>
bool remover(ConjuntoDin<T> &C, T e){
	if(C.prim){
		Noh<T> *n = new (nothrow) Noh<T>;
		n = C.prim;''
		if(n->elem == e){
			C.prim = n->prox;
			return 1;
		}else{
			Noh<T> *a = n;
			for(;;){
				n = n->prox;
				if(n->prox == NULL){
					return 0;
				}
				if(n->elem = e){
					a->prox = n->pro;
					delete n;
					return 1;
				}
				a = a->prox;
			}
		}
	}else{
		return 0;
	}
}
template <typename T>
bool vazio(ConjuntoDin<T> &C){
	return !C.prim;
}
template <typename T>
bool terminar_conjunto(ConjuntoDin<T> &C){
	while(!C.prim){
		Noh<T> *n = C.prim;
		C.prim = n->prox;
		delete n;
	}

}
