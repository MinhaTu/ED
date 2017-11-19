#include <iostream>
#include <new>

using namespace std;
// Declaração dos nós da lista
template <typename T>
struct Noh<T>{
	T elem;
	Noh<T> *prox;
};
/*
========================================================
=============GRAFO VIA LISTA DE ADJACÊNCIA==============
========================================================
*/

struct GrafoLista{
	int n; //número de vértices;
	Noh<int> **v; //ponteiro duplo, que aponta para os vértices;
};

bool iniciarlizar_grafo(GrafoLista &G, int n){
	G.n = n;
	G.v = new (nothrow) Noh<int> *[n];
	if(G.v){
		for(int i = 0; i < n; ++i){
			G.v[i] = NULL;
		}
		return false; // sem erro
	}else{
		return true;// com erro
	}
}

bool adicionar_aresta(GrafoLista &G, int u, int v){
	Noh<int> *n = new (nothrow) Noh<int>;
	if(n){
		n->elem = v;
		n->prox = G.v[u];
		G.v[u] = n;
		return false; // sem erro;
	}else{
		return true; // com erro
	}
}

void terminar_grafo(GrafoLista &G){
	for(int i = 0; i < G.n; ++i){
		Noh<int> *n = G.v[i];
		while(n =! NULL){
			Noh<int> *a = n;
			n = n->prox;
			delete a;
		}
	}
	delete [] G.v;
}

bool inv (int v, int n, int sair){
	if (v < 0 || v >= n){
		if( v != sair){
			cout << "´vertice invalido" << endl;
			return true.
		}
	}else{
		return false;
	}
}