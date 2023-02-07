#include "ordenacao.hpp"
using namespace std;

void Particao(int Left, int Right, int *i, int *j, Item *Vet, int *comp, int *nCopys)
{
    Item x, w;
    *i = Left;
    *j = Right;
    x = Vet[(*i + *j) / 2];

     do
    {
        while (x.Chave > Vet[*i].Chave){
            (*comp)++;
            (*i)++;
        }
        while (x.Chave < Vet[*j].Chave){
            (*comp)++;
            (*j)--;
        }
        if (*i <= *j)
        {
            w = Vet[*i];
            (*nCopys)++;
            Vet[*i] = Vet[*j];
            Vet[*j] = w;
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

void smartQuickSortNaoRec(Item *A, int n, int *comp, int *nCopys)
{
    TipoPilha pilha;
    TipoItem item; 
    int esq, dir, i, j;
    esq = 0;
    dir = n - 1;
    item.dir = dir;
    
    item.esq = esq;
    
    pilha.Empilha(item);
    do
    {
        if (dir > esq)
        {
            Particao(esq, dir, &i, &j, A, comp, nCopys);
            if ((j - esq) > (dir - i))
            {
                item.dir = j;
                item.esq = esq;
                pilha.Empilha(item);
                esq = i;
            }
            else
            {
                item.esq = i;
                item.dir = dir;
                pilha.Empilha(item);
                dir = j;
            }
        }
        else
        {
            dir = pilha.topo->dir;
            esq = pilha.topo->esq;
            pilha.Desempilha();

        }
    }while (!pilha.Vazia());
}