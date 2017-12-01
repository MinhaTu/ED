#include <iostream>
using namespace std;

typedef double TC; typedef float TV;
struct Noh { 
	TC chave; 
	TV valor; 
	Noh *esq, *dir, *pai; 
	int h; 
};

struct DicAVL { 
	Noh *raiz; 
};

void inicializar (DicAVL &D){
	D.raiz = NULL;
} 
// Inicializa D como uma ´arvore vazia.
int altura(Noh* n){
	return (n == NULL) ? -1: n->h;
}
int maior(int a, int b){
	if(a > b){
		return a;
	}else{
		return b;
	}
}

int bal (Noh* p) {
	return (altura(p->dir) - altura(p->esq));
}

Noh* direita(Noh* p){
	Noh* aux = p->esq;
	p->esq = aux->dir;
	aux->pai = p->pai;
	p->pai = aux;
	aux->dir = p;
	return p;
}
Noh* inserir (DicAVL &D, TC c, TV v){
	Noh* n = new (nothrow) Noh; // o novo nó sempre é uma folha
	if(!n){
		return n; // Erro de alocação;
	}
	n->chave = c;
	n->valor = v;
	n->esq = n->dir = NULL;
	n->h = 0;
	if(D.raiz == NULL){//se a raiz for null
		D.raiz = n;
		n->pai = NULL;
		return n;
	}
	Noh*p = D.raiz;
	for(;;){
		if(c < p->chave){
			if(p->esq == NULL){
				p->esq = n;
				n->pai = p;
				break;
			}else{
				p = p->esq;
			}
		}
		if(c > p->chave){
			if(p->dir == NULL){
				p->dir = n;
				n->pai = p;
				break;
			}else{
				p = p->dir;
			}
		}
	}
	while(p != NULL){
		if(bal(p) == -2){
			if(c < p->esq->chave){
				p = direita(p);
			}
		}
		p->h = maior(altura(p->esq),altura(p->dir)) + 1;
		p = p->pai;
	}
	if(D.raiz->pai != NULL){
		D.raiz = D.raiz->pai;
	}
	return n;
} // Retorna um ponteiro para o novo n´o, ou nulo se erro de aloca¸c~ao
/*Noh* procurar (DicAVL &D, TC c); // Retorna um ponteiro para o n´o da
// chave procurada, ou nulo se a chave
// n~ao estiver em D.
void remover (DicAVL &D, Noh *n); // ’n’ aponta para o n´o a ser removido
void terminar (DicAVL &D); // Desaloca os n´os da ´arvore.*/

int main()
{	
	DicAVL D;
	inicializar(D);
	inserir(D,5,5);
	inserir(D,4,4);
	inserir(D,2,2);
	inserir(D,1,1);
	inserir(D,0,0);
	Noh* p = D.raiz;
	cout << D.raiz->valor << endl;
	cout << D.raiz->esq->valor << endl;
	cout << D.raiz->esq->esq->valor << endl;
	cout << D.raiz->dir->valor << endl;
	return 0;
}