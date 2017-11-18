/*==============Conjunto Simples==================
===============LISTA SIMPLESMENTE ENCADEADA======
	Inicializar_conjunto(D)
	Inserir(C,e)
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


int main(){ 
}