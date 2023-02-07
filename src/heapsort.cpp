// C++ program for implementation of Heap Sort
#include "ordenacao.hpp"
using namespace std;

void swap(int* a, int* b)
{ 
    int temp = *a;
    *a = *b;
    *b = temp;
}


void heapify(Item *Vet, int n, int i, int *comp, int *nCopys)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && Vet[l].Chave > Vet[largest].Chave){
		largest = l;
		(*comp)++;
	}
	// If right child is larger than largest so far
	if (r < n && Vet[r].Chave > Vet[largest].Chave)
		{
			largest = r;
			(*comp)++;
		}

	// If largest is not root
	if (largest != i) {
		swap(&Vet[i].Chave, &Vet[largest].Chave);
		(*nCopys)++;
		// Recursively heapify the affected sub-tree
		heapify(Vet, n, largest, comp, nCopys);
	}
}


void heapSort(Item *Vet, int n, int *comp, int *nCopys)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(Vet, n, i, comp, nCopys);

	// One by one extract an element from heap
	for (int i = n - 1; i >= 0; i--) {
		// Move current root to end
		swap(&Vet[0].Chave, &Vet[i].Chave);

		// call max heapify on the reduced heap
		heapify(Vet, i, 0, comp, nCopys);
	}
}