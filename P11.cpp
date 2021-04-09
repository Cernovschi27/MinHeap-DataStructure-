#pragma once
#include "P11.h"
void heapify(list<TElem>& elements, int i){
	//Daca pozitia i corespunde unei frunze indeplineste proprietatea
	int n = elements.size();
	if (i >= n / 2)
		return;
	//indexul celui mai mic element
	int minim=i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	list<TElem>::iterator it = elements.begin();
	advance(it, left);
	list<TElem>::iterator it2 = elements.begin();
	advance(it2,minim);
	//Salvez minimul dintre nodul din stanga si curentul nod 
	if (left < n and *it < *it2)
		minim = left;
	//Daca exista un nod de dreapta actualizez minimul
	list<TElem>::iterator it3 = elements.begin();
	advance(it3, right);
	list<TElem>::iterator it4 = elements.begin();
	advance(it4, minim);
	if (right < n and *it3 < *it4)
			minim = right;
	//Daca nodul curent nu corespunde proprietatii de min-heap reactulizam pentru minim
	if (minim != i)
	{	//Interschimbam elementul curent cu minimul in cazul in care a suferit modificari 
		list<TElem>::iterator it5 = elements.begin();
		advance(it5, minim);
		TElem aux;
		aux = *it2;
		*it2 = *it5;
		*it5 = aux;
		heapify(elements,minim);
		//Parcugem pana nodul curent devine root pentru subheap ul aferent sau devine frunza  
	}

}
void buildMinHeap(list<TElem>& elements){
	int n = elements.size();
	//Rearanjarea listei
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(elements, i);
}
void removeMin(list<TElem>& elements, int k){
	if (k < 1)
		throw exception("K invalid");
	int n = elements.size();
	//Worst case ar fi cand trebuie sa eleminat heap ul dar in cazul listei avem O(1)
	if (k >= n)
	{
		elements.clear();
		return;
	}

	buildMinHeap(elements);
	//Elementul minim se afla mereu pe prima pozitie 
	//Sterge O(1)
	//Reorganizare Heap O(log n)
	//loop k ori pentru a sterge k elemente O(k)
	for (int i = 0; i < k; i++)
	{
		list<TElem>::iterator it1 = elements.begin();
		list<TElem>::iterator it2 = elements.begin();
		advance(it2, n-1);
		*it1 = *it2;
		elements.pop_back();
		n--;
		//Restabilim proprietatea 
		heapify(elements,0);
		
	}

}