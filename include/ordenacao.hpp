#ifndef ORDENACAO_H
#define ORDENACAO_H
#include <string>
#include <iostream>
#include "ITEM.hpp"
#include "TipoItem.hpp"
#include "TipoPilha.hpp"
void QuickSort(Item *Vet, int n, int *comp, int *nCopys);//quicksort recursivo
void hybrid_quick_sort(Item *Vet, int Left, int Right, int m, int *comp, int *nCopys);//quicksort de selecao
void QuickSortMed(int Left, int Right, Item *Vet, int k, int *comp, int *nCopys); //quicksort mediana
void QuickSortNaoRec(Item *A, int n, int *comp, int *nCopys); // quicksort não recursivo
void smartQuickSortNaoRec(Item *A, int n, int *comp, int *nCopys); //quicksort inteligente
void mergeSort(Item *Vet, int const begin, int const end, int *comp, int *nCopys);//mergesort
void heapSort(Item *Vet, int n, int *comp, int *nCopys);//heapsort
#endif
