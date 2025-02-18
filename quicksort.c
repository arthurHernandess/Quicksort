// Theta(nLogn) mas melhor que que mergee por ter menos operações e menos frufru
// divisao e conquista tb
// partition no array, escolhe um pivo (ultimo numero) passa todo mundo que é menor que ele pra esquerda, coloca ele a esquerda do primeiro numero que é maior que ele
// retorna a posição do pivo, faz duas chamadas recursivas uma pra cada lado do pivo
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define erro -1
#define MAX 2

// int lista[MAX] = {4,6,2,7,1,8,0,9,3,5};
int lista[MAX] = {3,6};

void trocar(int* v1, int* v2){
    int aux;
    aux = *v1;
    *v1 = *v2;
    *v2 = aux;
}

int partition(int a[], int comeco, int fim){
    int pivo = a[fim]; // o pivo sera o ultimo elemento do array
    int i = comeco;

    //  começa com um indice auxiliar de inserção la na primeira posição
    for(int j = comeco; j < fim; j++){   // e começa tb com o j la da primeira posição 
        if(a[j] < pivo){    // se a[j] é menor que o pivo (ultimo elemento) 
            trocar(&a[i], &a[j]);   // coloca o valor de a[j] na posição que ta o auxiliar (i) e incrementa (lembrando que ele começa do 1o elemento tb)
            i++;
        }
    }

    trocar(&a[i], &a[fim]); // no final, coloca o pivo o mais a direita possível dos valores que voce veio colocando la do começo do array (vai ficar elementos menores que pivo a esquerda e maiores a direita)
    return i;
}

void quicksort(int a[], int comeco, int fim){
    if(comeco < fim){
        int pivo = partition(a, comeco, fim);

        quicksort(a, comeco, pivo-1);
        quicksort(a, pivo+1, fim);
    }
}

int main(){
    for(int i = 0; i <  MAX; i++)
        printf("%d, ", lista[i]);

    printf("\n");
    quicksort(lista, 0, MAX-1);

    for(int i = 0; i <  MAX; i++)
        printf("%d, ", lista[i]);

    return 0;
}