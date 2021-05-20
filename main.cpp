#include <iostream>

using namespace std;

void printLista(int *lista,int n){
    int ii;
    for (ii = 0; ii < n; ii++) {
        cout << lista[ii] << endl;
    }
}

void copyList(int *listaOriginal, int *listaDestino,int ini, int fim,int kk){
    int ii;

    for(ii=ini; ii<fim; ii++){
        listaDestino[kk] = listaOriginal[ii];
        kk++;
    }
}

void algMerge(int *B, int *C, int *A, int p, int q){
    int ii=0,jj=0,kk=0;
    while((ii<p)&&(jj<q)){
        if(B[ii]<=C[jj]){
            A[kk] = B[ii];
            ii++;
        }
        else{
            A[kk] = C[jj];
            jj++;
        }
        kk++;
    }
    if(ii==p)
        copyList(C,A,jj,q,kk);
    else
        copyList(B,A,ii,p,kk);
}

// algoritmo mergesort
void mergeSort(int *A, int n){
    int B[100]={0}, C[100]={0},tamC=n/2;
    if(n%2==1)
        tamC++;
    if(n>1){
       copyList(A,B,0,n/2,0);
       copyList(A,C,n/2,n,0);
       mergeSort(B,n/2);
       mergeSort(C,tamC);
       algMerge(B,C,A,n/2,tamC);
    }
}


int main()
{
    int lista[100] = {101,10,20,55,30,1,9,10,99,35};
    int tamanho_lista = 10,ii;
    mergeSort(lista,tamanho_lista);
    printLista(lista,tamanho_lista);
    return 0;
}
