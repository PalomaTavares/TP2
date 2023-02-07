#include "ordenacao.hpp"
using namespace std;

void swapI(int *i, int *j){
    int aux = *i;
    *i = *j;
    *j = aux;
}

void selectionSort(Item *Vet, int Left, int Right, int *comp, int *nCopys)//ordena a partição usando o método de seleção
{
    int j, min_idx;
    int n = Right;
 
    for (int i = Left; i < n-1; i++)
    {
       
        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++){
            (*comp)++;
            if (Vet[j].Chave < Vet[min_idx].Chave)
                min_idx = j;
        }
 
        //altera a posição das chaves
        if(min_idx!=i){
            swapI(&Vet[min_idx].Chave, &Vet[i].Chave);
            (*nCopys)++;
        }
    }
}


int partition(Item *Vet, int Left, int Right, int *comp, int *nCopys)//ordena a partição utilizando quicksort
{
    int pivot = Vet[Right].Chave;
    int j;
    j = Left;
    for (int i = Left; i < Right; i++)
    {
        (*comp)++;
        if (Vet[i].Chave < pivot)
        {
            Item temp = Vet[i];
            Vet[i] = Vet[j];
            Vet[j] = temp;
            j += 1;
            (*nCopys)++;
        }
    }

    Item temp = Vet[j];
    Vet[j] = Vet[Right];
    Vet[Right] = temp;
    (*nCopys)++;
    return j;
}


void quick_sort(int Left, int Right, Item *Vet, int *comp, int *nCopys)//utilizado quando a ordenação acontece por quicksort
{
    if (Left < Right)
    {
        int pivot = partition(Vet, Left, Right, comp, nCopys);
        quick_sort(Left, pivot - 1, Vet, comp, nCopys);
        quick_sort(pivot + 1, Right, Vet, comp, nCopys);
    }
}

// Hybrid function -> Quick + Selection sort

void hybrid_quick_sort(Item *Vet, int Left, int Right, int m, int *comp, int *nCopys)
{
    while (Left < Right)
    {

        if (Right - Left + 1 < m)//se o tamanho da partição for menor que m é realizado o método de ordenação por seleção
        {
            selectionSort(Vet, Left, Right, comp, nCopys);
            break;
        }

        else//se for maior, é realizado o quicksort recursivo
        {
            int pivot = partition(Vet, Left, Right, comp, nCopys);

            if (pivot - Left < Right - pivot)
            {
                hybrid_quick_sort(Vet, Left, pivot - 1, m, comp, nCopys);
                Left = pivot + 1;
            }
            else
            {
                hybrid_quick_sort(Vet, pivot + 1, Right, m, comp, nCopys);
                Right = pivot - 1;
            }
        }
    }
}