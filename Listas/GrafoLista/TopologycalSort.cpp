#include <iostream>
#include "../Fila/filaLE.hpp"
#include <new>

using namespace std;

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
		while(n != NULL){
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
			return true;
		}
	}else{
		return false;
	}
}

//=====================================================================
int main(){
	int n;
	do{
		cout << "numero de vertices: " << endl;
		cin >> n;
	}while(n < 1);
	GrafoLista G;
	if(iniciarlizar_grafo(G,n)){
		cout << "Erro de alocação";
		return 1;
	}
	int i,j;
	const int sair = -1;
	Noh<int> *p;
	cout << "Digite as arestas(vertice de 0 a " << n-1 << "): " << endl << " sair= -1" << endl;
	for(;;){
		cin >> i;
		if(inv(i,n,sair)){
			break;
		}
		cin >> j;
		if(inv(j,n,sair)){
			break;
		}
		adicionar_aresta(G,i,j);
	}
	int *AC = new (nothrow) int [n];
	if(AC = NULL){
		return 2;
	}
	for(i = 0; i < n; ++i){
		AC[i] = 0;
	}
	for(i = 0; i < n; ++i){
		for(p = G.v[i]; (p); p->prox){
			++AC[p->elem];
		}
	}
	Fila<int> F; // fila dos vértices sem arestas;
	inicializar_fila(F);
	for(i = 0; i < n; ++i){
		if(AC[i] == 0){
			if(enfilar(F,i)){
				cout << "sem memória" << endl;
			}
		}
	}
	int vertices_impressos = 0;
	while(va)
}