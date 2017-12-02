#include <iostream>
using namespace std;
//ESCREVER AS FUNÇÕES DE FILA DE PRIORIDADE
template<typnename TE, typnename TC, TC chave(TE e)>
struct FilaPrMax{
	int tam_max, n;
	TE *v;
}

template<typnename TE, typnename TC, TC chave(TE e)>

double chave_de_double(double e){
	return e;
}
//O(nlogn)
bool ordernar(double *v, int n){//heapsort
	FilaPrMax<double,double,chave_de_double> F;
	if(inicializar(F,n)){
		return true; // houve erro
	};
	int i;
	for(i = 0; i < n; ++i){
		inserir(F,v[i]);
	}
	for(i = (n-1); i > -1; --i){
		v[i] = remover_max(F);
	}
	terminar(F);
	return false;
}
/*Construção de um monte a partir de um vetor:
*/
template <typnename TE, typnename TC, TC chave (TE e)>
void construir_monte(FilaPrMax<TE,TC,chave> &F, TE *v, int n){
	F.v = v;
	F.tam_max = n;
	F.n = n;
	for(int i = 1; i < n; ++i){
		subir(F,i);
	}
}

template <...>
void construir_monte_linear(...&F, TE *v, int n){
	F.v = v;
	F.tam_max = n;
	F.n = n;
	int prim = (n-2)/2; /*((n-1)-1)/2. paai do último*/
	for(int i =prim; i!= -1; --i){
		descer(F,i);
	}
}
//Implementar a ordenação por seleção: colocar o maior no final do vetor, e depois "reduzir" o tamanho do vetor e repetir o processo
// O(n+ n-1 + n-2 + ... + 1) = OO(n²)
int main(){

}

