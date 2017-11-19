/* ====CONJUNTO DINÂMICA REFINADO=====
   ===LISTA CIRCULAR DUPLAMENTE ENCADEADA=
  */
#include <iostream>
using namespace std;

template <typename TE, typename TC, TC& chave(TE &e)>
struct NohDE{
	TE elem;
	NohDE<TE> *ant, *prox;
}

template <typename TE, typename TC, TC& chave(TE &e)>
struct ConjuntoRefinado{
	NohDE<TE> *sent;
};

template <typename TE, typename TC, TC& chave(TE &e)>
bool inicializar_cr(ConjuntoRefinado<TE,TC, chave> &C){
	C.sent = new (nothrow) NohDE<TE>;
	if(C.sent){
		C.sent->prox = C.sent->ant = C.sent;
		return true;
	}else{
		return false;
	}
}

template <typename TE, typename TC, TC& chave(TE &e)>
NohDE<TE> *inserir(ConjuntoRefinado<TE,TC, chave> &C, TE elem){
	NohDE<TE> *n = new (nothrow) NohDE<TE>;
	if(n){
		n->elem = e;
		n->ant = C.sent;
		n->prox = C.sent->prox;
		C.sent->prox = n->prox->ant = n;
	}
	return n;
}
template<typename TE, typename TC, TC& chave(TE &e)>
NohDE<TE> *procurar(ConjuntoRefinado<TE,TC, chave> &C, TC c){
	chave(C.sent->elem) = c;
	NohDE<TE> *n = C.sent->prox;
	while(chave(n->elem) != c){
		n = n->prox;
	}
	return ? (n == C.sent): NULL:n;
 }

 template <typename TE, typename TC, TC& chave(TE &e)>
 TE remover(ConjuntoRefinado<TE,TC,chave> &C, NohDE<TE> *n){
 	 TE e = n->elem;
 	 n->prox->ant = n->ant;
 	 n->ant->prox-> = n->prox;
 	 delete n;
 	 return n;
 }
 template <typename TE, typename TC, TC& chave(TE &e)>
 bool vazio(ConjuntoRefinado<TE, TC, chave> &C){
 	return (C.sent->prox == C.sent);
 }

 template <typename TE, typename TC, TC& chave(TE &e)>
void terminar(ConjuntoRefinado<TE, TC, chave &C){
 	NohDE<TE> *n = C.sent->prox;
 	while(n != C.sent){
 		NohDE<TE> *a = n;
 		n = n->prox;
 		delete a;
 	}
 	delete n;
 }