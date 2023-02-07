#include "ordenacao.hpp"
using namespace std;

//particao do quicksort recursivo
void partAux(int Left, int Right, int *i, int *j, Item *vet, int *comp, int *nCopys)
{
    Item x, w;
    *i = Left;
    *j = Right;
    x = vet[(*i + *j) / 2];

    do
    {
        while (x.Chave > vet[*i].Chave){
            (*comp)++;
            (*i)++;
        }
        while (x.Chave < vet[*j].Chave){
            (*j)--;
        }
        if (*i <= *j)
        {
            w = vet[*i];
            vet[*i] = vet[*j];
            (*nCopys)++;
            vet[*j] = w;
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

//ordenacao do quicksort recursivo
void orderAux(int Left, int Right, Item *vet, int *comp, int *nCopys)
{
    int i, j;
    partAux(Left, Right, &i, &j, vet, comp, nCopys);
    if (Left < j)
        orderAux(Left, j, vet, comp, nCopys);
    if (i < Right)
        orderAux(i, Right, vet, comp, nCopys);
}

//chamada para autilização do quicksort recursivo
void QuickSortAux(Item *vet, int n, int *comp, int *nCopys)
{
    orderAux(0, n - 1, vet, comp, nCopys);
}

//retorna a mediana de um vetor de k posicoes
Item mediank(Item *Vet, int k, int Left, int Right, int *comp, int *nCopys){
    Item *vet = new Item[k];
    for(int i = 0; i< k; i++){
       vet[i].Chave = Vet[Left + rand()%(Right - Left+1)].Chave;
       (*nCopys)++;
    }
   QuickSortAux(vet,k, comp, nCopys);
    return vet[k/2];
}

//ordena a particao do vetor de acordo com a mediana retornada por mediank
void particaoMed(int Left, int Right, int *i, int *j, Item *Vet, int k, int *comp, int *nCopys)
{
    Item x, w;
    *i = Left;
    *j = Right;
    x = mediank(Vet, k, Left, Right, comp, nCopys);

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
            Vet[*i] = Vet[*j];
            (*nCopys)++;
            Vet[*j] = w;
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
    return;
}

//chamada para ordenar as particoes
void orderMed(int Left, int Right, Item *Vet, int k, int *comp, int *nCopys)
{
    int i, j;
    particaoMed(Left, Right, &i, &j, Vet, k, comp, nCopys);
    if (Left < j)
        orderMed(Left, j, Vet, k, comp, nCopys);
    if (i < Right)
        orderMed(i, Right, Vet, k, comp, nCopys);
}

void QuickSortMed(int Left, int Right, Item *Vet, int k, int *comp, int *nCopys)
{
    orderMed(Left, Right, Vet, k, comp, nCopys);
}
