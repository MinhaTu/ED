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
bool inserir_esq(Deque<T> &D);
int main(int argc, char const *argv[])
{
	
	return 0;
}
