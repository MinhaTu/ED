#include <iostream>
using namespace std;

template <typename T>
struct Noh{
	T elem;
	Noh<T> *prox;
};