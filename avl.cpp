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

Noh* rotacaoDireita(DicAVL &D,Noh* p, bool m){ // para desbalanceamento em sub-árvore esquerda
	Noh* aux = p->esq;
	p->esq = aux->dir;
	aux->pai = p->pai;
	if(p->pai != NULL){
		if(m == 0){ //essa condição é necessária para o caso de rotação dupla
			p->pai->esq = aux;
		}else{
			p->pai->dir = aux;
		}
	}
	p->pai = aux;
	aux->dir = p;
	if(p == D.raiz){
		D.raiz = D.raiz->pai;
	}
	p->h = maior(altura(p->esq),altura(p->dir)) + 1; // o cálculo das alturas deve ser feito aqui, uma vez que,
	aux->h = maior(altura(aux->esq),altura(aux->dir)) + 1; // caso essa função tenha sido chamada pela rotação dupla, ja esteja com as alturas certasd
	return aux;
}

Noh* rotacaoEsquerda(DicAVL &D, Noh* p, bool m){
	Noh* aux = p->dir;
	p->dir = aux->esq;
	aux->pai = p->pai;
	if(p->pai != NULL){
        if(m == 0){
            p->pai->dir = aux;
        }else{
            p->pai->esq = aux;
        }
	}
	p->pai = aux;
	aux->esq = p;
	if(p == D.raiz){
		D.raiz = D.raiz->pai;
	}
    p->h = maior(altura(p->esq),altura(p->dir)) + 1;
	aux->h = maior(altura(aux->esq),altura(aux->dir)) + 1;
	return aux;

}

Noh* rotacaoDuplaLF(DicAVL &D, Noh* p){//Rotacao dupla esquerda-direita
    rotacaoEsquerda(D,p->esq, 1);
    return (rotacaoDireita(D,p,0));
}
Noh* rotacaoDuplaRF(DicAVL &D, Noh* p){// Rotacao dupla direita-esquerda
    rotacaoDireita(D,p->dir, 1);
    return (rotacaoEsquerda(D,p,0));
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
	while(p){
		if(bal(p) == -2){
			if(c < p->esq->chave){
				p = rotacaoDireita(D,p,0);
			}else{
				p = rotacaoDuplaLF(D,p);//rotação dupla FAZER UMA ROTAÇÃO ESQUERDA NO P->ESQ
			}
		}else if(bal(p) == 2){
			if(c > p->dir->chave){
				p = rotacaoEsquerda(D,p,0);
			}else{
				p = rotacaoDuplaRF(D,p);
			}
		}
		p->h = maior(altura(p->esq),altura(p->dir)) + 1;
		p = p->pai;
	}
	/*if(D.raiz->pai != NULL){
		D.raiz = D.raiz->pai;
	}*/
	return n;
}
void imprimir(Noh* n){
	if(n){
		imprimir(n->esq);
		cout << "  " << n->chave;
		imprimir(n->dir);
	}
}
 // Retorna um ponteiro para o no0vo n´o, ou nulo se erro de aloca¸c~ao

Noh* procurar (DicAVL &D, TC c){
	Noh* p = D.raiz;
	while(p){
		if(c == p->chave){
			return p;
		}else if(c < p->chave){
			p = p->esq;
		}else{
			p = p->dir;
		}
	}
	return p;
} // Retorna um ponteiro para o n´o da
// chave procurada, ou nulo se a chave
// n~ao estiver em D.
 // ’n’ aponta para o n´o a ser removido
void terminar (DicAVL &D){
	Noh* p = D.raiz;
	while(p){
		if(p->esq == p->dir){
			Noh* n = p;
			p = p->pai;
			if(p){
				if(p->esq == n){
					p->esq = NULL;
				}else{
					p->dir = NULL;
				}
			}
			//p->esq ou p->dir setar para NULL
			delete n;
		}else{
			if(p->dir){
				p = p->dir;
			}else{
				p = p->esq;
			}
		}
	}
	delete D.raiz;
	D.raiz = NULL;
} // Desaloca os n´os da ´arvore.*/
Noh* maiorLT(Noh* n){
	while(n->dir){
		n = n->dir;
	}
	return n;
}
void remover (DicAVL &D, Noh *n){//PRÉ-CONDIÇÃO: ÁRVORE NÃO ESTIVER VAZIA
	Noh* p;// nó de cima
	if(n->pai == NULL){
		p = D.raiz; // o nó a ser removido é a raiz
	}else{
		p = n->pai;
	}
	if(n->esq == NULL){
		if(n->pai){
			if(p->esq == n){
				p->esq = n->dir;
			}else{
				p->dir = n->dir;
			}
			if(n->dir){
                n->dir->pai = p;
			}
		}else{
			D.raiz = n->dir;
		}
	}else if(n->dir == NULL){
		if(n->pai){
			if(p->esq == n){
				p->esq = n->esq;
			}else{
				p->dir = n->esq;
			}
			if(n->esq){
                n->esq->pai = p;
			}
		}else{
			D.raiz = n->esq;
		}
	}else{ // no tem dois filhos, procurar o maior no da sub=árvore esquerda
		Noh *s = n->dir;
		if(s->esq == NULL){
			n->dir = s->dir;
			if(n->dir){
				n->dir->pai = n;
			}
		}else{
			do{
				s = s->esq;
			}while(s->esq);
			s->pai->esq = s->dir;
			if(s->dir){
				s->dir->pai = s->pai;
			}
		}
		s->esq = n->esq;
		s->esq->pai = s;
		s->dir = n->dir;
		if(s->dir){
			s->dir->pai = s;
		}
		s->pai = n->pai;
		if(n->pai){
			if(p->esq == n){
				p->esq = s;
			}else{
				p->dir = s;
			}
		}else{
			D.raiz = s;
		}
	}
	while(p){
		if(bal(p) == -2){
			if(c < p->esq->chave){
				p = rotacaoDireita(D,p,0);
			}else{
				p = rotacaoDuplaLF(D,p);//rotação dupla FAZER UMA ROTAÇÃO ESQUERDA NO P->ESQ
			}
		}else if(bal(p) == 2){
			if(c > p->dir->chave){
				p = rotacaoEsquerda(D,p,0);
			}else{
				p = rotacaoDuplaRF(D,p);
			}
		}
		p->h = maior(altura(p->esq),altura(p->dir)) + 1;
		p = p->pai;
	}
	delete n;
}
/*void remover (DicAVL &D, Noh *n)
  {
   Noh *pdc = (n->pai == NULL) ? D.raiz :
                  (n == n->pai->esq ) ? n->pai->esq : n->pai->dir ;

   if(n->esq == NULL) {
   		pdc = n->dir;
   		if (pdc) {
   			pdc->pai = n->pai;
   		}
   	}
   else if (n->dir == NULL) {
   		pdc = n->esq;
   		pdc->pai = n->pai;
   	}
   else{
    	Noh *s = n->dir;
      	if (s->esq == NULL) {
      		n->dir = s->dir;
      		if(n->dir) {
      			n->dir->pai = n;
      		}
      	}
		else{
        	do {
        		s = s->esq;
        	} while (s->esq);
        	s->pai->esq = s->dir;
        	if(s->dir) {
        		s->dir->pai = s->pai;
        	}
        } // else
      	s->esq = n->esq;
      	s->esq->pai = s;  // Sabemos que n->esq != nullptr.
      	s->dir = n->dir;
    	if(s->dir) {
     	s->dir->pai = s;
     	}
      	s->pai = n->pai;  pdc = s;
     }                 // else: n tem 2 filhos.
   delete n;
  }  */
int main()
{
	DicAVL D;
	inicializar(D);
	inserir(D,5,5);
	inserir(D,9,9);
	inserir(D,12,12);
	inserir(D,14,14);
	inserir(D,11,11);
	Noh* p = procurar(D,9);
	remover(D,p);
	cout << D.raiz->valor << endl;

	/*inserir(D,1,1);
	inserir(D,3,3);
	inserir(D,4,4);
	cout << D.raiz->valor << endl;
	cout << D.raiz->esq->valor << endl;
	cout << D.raiz->esq->esq->valor << endl;
	cout << D.raiz->dir->valor << endl;
	cout << D.raiz->dir->esq->valor << endl;
	cout << D.raiz->dir->dir->valor << endl;
	/*inserir(D,1,1);
	inserir(D,0,0);
	inserir(D,4,4);
	inserir(D,-1,-1);
	inserir(D,5,5);
	inserir(D,7,7);/*
	/*cout << D.raiz->valor << "  " << D.raiz->h << endl;
	cout << D.raiz->dir->valor << "  " << D.raiz->dir->h << endl;
	cout << D.raiz->dir->dir->valor <<  "  " << D.raiz->dir->dir->h << endl;
	cout << D.raiz->dir->esq->valor <<  "  " << D.raiz->dir->esq->h << endl;
	/*cout << D.raiz->valor << " ALTURA: " << D.raiz->h << endl;
	cout << D.raiz->esq->valor << " ALTURA: " << D.raiz->esq->h << endl;
	cout << D.raiz->esq->esq->valor << " ALTURA: " << D.raiz->esq->esq->h << endl;
	cout << D.raiz->dir->valor << " ALTURA: " << D.raiz->dir->h <<  endl;
	cout << D.raiz->dir->esq->valor << "ALTURA: " << D.raiz->dir->esq->h << endl;
	cout << D.raiz->dir->dir->valor << "ALTURA: " << D.raiz->dir->dir->h << endl;*/
		return 0;
}
