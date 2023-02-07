#include "ordenacao.hpp"
using namespace std;

//ordena partição (pedaço do vetor) das chaves entre os índices Left e Right
void part(int Left, int Right, int *i, int *j, Item *Vet, int *comp, int *nCopys)
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
        if (*i <= *j)//ordena as chaves
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

//define os valores de índices que serão passados à partição, passa como parâmetro o que deve ser ordenado
void order(int Left, int Right, Item *Vet, int *comp, int *nCopys)
{
    int i, j;
    part(Left, Right, &i, &j, Vet, comp, nCopys);
    if (Left < j){
        order(Left, j, Vet, comp, nCopys);
    }
    if (i < Right)
        order(i, Right, Vet, comp, nCopys);
}
void QuickSort(Item *Vet, int n, int *comp, int *nCopys)
{
    order(0, n - 1, Vet, comp, nCopys);
}
