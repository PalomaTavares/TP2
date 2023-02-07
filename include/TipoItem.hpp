#ifndef TIPOITEM_H
#define TIPOITEM_H
class TipoItem
{
    public:
    TipoItem(){
        prox = NULL;
    }
    int dir; //última posição do vetor
    int esq;//primeira posição do vetor

    private:
    TipoItem *prox;
    friend class TipoPilha;
};
#endif