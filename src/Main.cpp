#include <iostream>
#include "ordenacao.hpp"
#include <fstream>
#include <getopt.h>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;
#include "msgassert.h"
#include "memlog.h"
#include <sys/resource.h>

int comp = 0; //salva a quantidade de comparações entre chaves
int nCopys = 0; //salva a quantidade de cópias de chaves

struct rusage resources;
    int rc;
    double utime, stime, total_time;

typedef struct opt
{
    char lognome[100];
    int regmem;
    char inFile[100];
    char outFile[100];
    char seed;
    char medk;
    char mselect;
    char vQuick;
} opt_tipo;

void get_args(int argc, char **argv, opt_tipo *opt)
{
    // variaveis externas do getopt
    extern char *optarg;

    // variavel auxiliar
    int c;

    opt->regmem = 0;
    opt->lognome[0] = 0;
    opt->medk = 0;
    opt->seed = 0;
    opt->mselect = 0;
    opt->vQuick = 0;

    while ((c = getopt(argc, argv, ":i:o:p:l:v:s:k:m:")) != EOF)
    {
        switch (c)
        {
        case 'i':
            erroAssert(strlen(optarg) > 4, "Arquivo não existe, o nome do arquivo deve seguir o modelo: nome.txt");
            erroAssert(optarg[strlen(optarg) - 3] == 't', "o arquivo não é do tipo .txt");
            erroAssert(optarg[strlen(optarg) - 2] == 'x', "o arquivo não é do tipo .txt");
            erroAssert(optarg[strlen(optarg) - 1] == 't', "o arquivo não é do tipo .txt");
            strcpy(opt->inFile, optarg);
            break;
        case 'o':
            erroAssert(strlen(optarg) > 4, "A saída do arquivo deve seguir o modelo: nome.txt");
            erroAssert(optarg[strlen(optarg) - 3] == 't', "o arquivo não é do tipo .txt");
            erroAssert(optarg[strlen(optarg) - 2] == 'x', "o arquivo não é do tipo .txt");
            erroAssert(optarg[strlen(optarg) - 1] == 't', "o arquivo não é do tipo .txt");
            strcpy(opt->outFile, optarg);
            break;
        case 'v':
            strcpy(&opt->vQuick, optarg);
            break;
        case 's':
            strcpy(&opt->seed, optarg);
            break;
        case 'k':
            strcpy(&opt->medk, optarg);
            break;
        case 'm':
           strcpy(&opt->mselect, optarg);
            break;
        case 'p':
            strcpy(opt->lognome, optarg);
            break;
        case 'l':
            opt->regmem = 1;
            break;
        default:
            exit(1);
            break;
        }
    };
}

int main(int argc, char *argv[])
{
    opt_tipo opt;

    get_args(argc, argv, &opt);

    
    ifstream file(opt.inFile, ios::in);

    fstream myFile;
    myFile.open(opt.outFile, ios::out);

    if(file.is_open()){
        string linha;
        int linhas;
        int elementos;
        getline(file, linha);
        stringstream s(linha);
        s >> linhas;//lê a quantidade de linhas da entrada
        for(int i = 0; i< linhas; i++){
            getline(file, linha);
            stringstream e(linha);
            e >> elementos;
            Item *vet = new Item[elementos];//cria vetor
                srand(atoi(argv[4]));
                for(int i=0 ; i<elementos; i++){
                    Item aux;
                    aux.Chave = rand();
                    vet[i] = aux;
                }
//qual variação do quicksort será executada
            switch(atoi(argv[2])){
            case 1:
                QuickSort(vet,elementos, &comp, &nCopys);
                break;
            case 2:
                QuickSortMed(0, elementos -1, vet,atoi(argv[4]), &comp, &nCopys);
                break;
            case 3:
                hybrid_quick_sort(vet, 0, elementos-1, 3, &comp, &nCopys);
                break;
            case 4:
                QuickSortNaoRec(vet,elementos, &comp, &nCopys);
                break;
            case 5:
                smartQuickSortNaoRec(vet,elementos, &comp, &nCopys);
                break;
            default:
                erroAssert(atoi(argv[2])>0, "operação informada não existe");
                erroAssert(atoi(argv[2])<6, "operação informada não existe");
                break;
            }
            //mergeSort(vet, 0,elementos-1, &comp, &nCopys);
            //heapSort(vet, elementos, &comp, &nCopys);

            if((rc = getrusage(RUSAGE_SELF, &resources)) != 0)
            perror("getrusage failed");
            utime = (double) resources.ru_utime.tv_sec
            + 1.e-6 * (double) resources.ru_utime.tv_usec;
            stime = (double) resources.ru_stime.tv_sec
            + 1.e-6 * (double) resources.ru_stime.tv_usec;
            total_time = utime+stime;
            //escreve no arquivo de saída
            if (myFile.is_open()){
                myFile <<"Comparações: "<<comp <<" "<< " Cópias:"<< nCopys<<" User time"<<utime <<" System Time"<<stime<<" Total Time"<<total_time<<endl;
            }
            comp = 0;
            nCopys = 0;
            utime = 0;
            stime =0;
            total_time = 0;   
            delete[] vet;     
    }
        
   
    file.close();

   

    
   
    // cout<<"comparações: "<<comp<<endl;
    // cout<<"cópias: "<<nCopys<<endl;
    // if((rc = getrusage(RUSAGE_SELF, &resources)) != 0)
    //     perror("getrusage failed");
    //     utime = (double) resources.ru_utime.tv_sec
    //     + 1.e-6 * (double) resources.ru_utime.tv_usec;
    //     stime = (double) resources.ru_stime.tv_sec
    //     + 1.e-6 * (double) resources.ru_stime.tv_usec;
    //     total_time = utime+stime;
    //     printf("User time %.3f, System time %.3f, Total Time %.3f\n",
    //     utime, stime, total_time);
    }
    
     return 0;
}