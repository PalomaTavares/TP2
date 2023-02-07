#ifndef PILHA_H
#define PILHA_H
using namespace std;
class TipoPilha
{
public:
    TipoPilha()
    {
        tamanho = 0;
    }
    int GetTamanho()
    {
        return tamanho;
    }
    bool Vazia()
    {
        return tamanho == 0;
    }
    void Empilha(TipoItem item)
    {
        TipoItem *nova;
        nova = new TipoItem();
        nova->dir = item.dir;
        nova->esq = item.esq;
        nova->prox = topo;
        topo = nova;
        tamanho ++;
    }

    void Desempilha()
    {
       TipoItem *p;
        if(tamanho == 0)
            throw "A pilha está vazia!";
        p = topo;
        topo = topo->prox;
        delete p;
        tamanho--;
    }

    TipoItem *topo;
    protected:
        int tamanho;
        
};
#endif