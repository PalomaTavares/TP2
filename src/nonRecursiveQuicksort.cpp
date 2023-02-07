#include "ordenacao.hpp"
using namespace std;

//ordena as chaves da particao
void ParticaoNR(int Esq, int Dir, int *i, int *j, Item *A, int *comp, int *nCopys)
{
    Item x, w;
    *i = Esq;
    *j = Dir;
    x = A[(*i + *j) / 2]; /* obtem o pivo x */
     do
    {
        while (x.Chave > A[*i].Chave){
            (*comp)++;
            (*i)++;
        }
        while (x.Chave < A[*j].Chave){
            (*comp)++;
            (*j)--;
        }
        if (*i <= *j)
        {
            w = A[*i];
            (*nCopys)++;
            A[*i] = A[*j];
            A[*j] = w;
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

void QuickSortNaoRec(Item *A, int n, int *comp, int *nCopys)
{
    TipoPilha pilha;//cria a pilha
    TipoItem item; //cria elemento da pilha
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
            ParticaoNR(esq, dir, &i, &j, A, comp, nCopys);

            item.dir = j;
            item.esq = esq;
            pilha.Empilha(item);//coloca nova partição na pilha
            esq = i;
        }
        else
        {
            dir = pilha.topo->dir;
            esq = pilha.topo->esq;
            pilha.Desempilha();//retira particao já ordenada da pilha
        }
    }while (!pilha.Vazia());
}