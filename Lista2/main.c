#include <stdio.h>
#include <stdlib.h>
#define C 10


int main() {
    int lista[C] = {24, 3, 13, -11, -6, 10, -19, 2, -15, 16}, i;
    int metodo;
    printf("Numeros nao ordenados:\n\n");
    for (i = 0; i < C; i++) {
        printf("%d   ", lista[i]);
    }
    printf("\n\nEscolha um metodo de Ordenacao\n");
    printf("\n1 - Bubble Sort\n");
    printf("\n2 - Insertion Sort\n");
    printf("\n3 - Selection Sort\n");
    printf("\n4 - Merge Sort\n");
    printf("\n5 - Quick Sort\n\n");
    scanf("%d", &metodo );

    switch(metodo){

        case 1:
            bubbleSrt(lista, C);
            printf("\n\nBubble Sort \n");
            printf("\nNumeros ordenados:\n");
            for (i = 0; i < C; i++) {
                printf("%d   ", lista[i]);
            }
            printf("\n");
            break;

        case 2:
            insertionSrt(lista, C);
            printf("\n\nInsertion Sort \n");
            printf("\nNumeros ordenados:\n");
            for (i = 0; i < C; i++) {
                printf("%d   ", lista[i]);
            }
            printf("\n");
            break;

        case 3:
            selectionSrt(lista, C);
            printf("\n\nSelection Sort \n");
            printf("\nNumeros ordenados:\n");
            for (i = 0; i < C; i++) {
                printf("%d   ", lista[i]);
            }
            printf("\n");
            break;

        case 4:
            mergeSrt(lista, 0, C - 1);
            printf("\n\nMerge Sort \n");
            printf("\nNumeros ordenados:\n");
            for (i = 0; i < C; i++) {
                printf("%d   ", lista[i]);
            }
            printf("\n");
            break;

        case 5:
            quickSrt(lista, 0, C - 1);
            printf("\n\nQuick Sort \n");
            printf("\nNumeros ordenados:\n\n");
            for (i = 0; i < C; i++) {
                printf("%d   ", lista[i]);
            }
            printf("\n");
            break;

        default:
            printf("\nInsira uma Opcao valida\n");
            break;

    }

}


void bubbleSrt(int v[], int tam){
    int i, j, aux;

    for(i = 1; i < tam; i++){
        for(j = 0; j < tam - 1; j++){
            if(v[j] > v[j + 1]){
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

void insertionSrt(int v[], int tam){
    int i, j, aux;

    for(i = 0; i < tam - 1; i++){
        if(v[i] > v[i + 1]){
            aux = v[i + 1];
            v[i + 1] = v[i];
            v[i] = aux;
            j = i - 1;

            while(j >= 0){
                if(aux < v[j]){
                    v[j + 1] = v[j];
                    v[j] = aux;
                }else{
                    break;
                }
                j = j - 1;
            }
        }
    }
}

void selectionSrt(int v[],int tam){
    int i, j, menor, aux;

    for(i = 0; i < tam - 1; i++){
        menor = i;
        for(j = i + 1 ; j < tam; j++){
            if(v[menor] > v[j])
                menor = j;
        }
        if(i != menor){
            aux = v[i];
            v[i] = v[menor];
            v[menor] = aux;
        }
    }
}

void merge(int v[], int inicio, int meio, int fim) {
    int tam1 = meio - inicio + 1;
    int tam2 = fim - meio;

    int* LE = (int*)malloc(tam1 * sizeof(int));
    int* LD = (int*)malloc(tam2 * sizeof(int));

    int i, j, k;

    for (i = 0; i < tam1; i++)
        LE[i] = v[inicio + i];
    for (j = 0; j < tam2; j++)
        LD[j] = v[meio + 1 + j];

    i = 0;
    j = 0;
    k = inicio;

    while (i < tam1 && j < tam2) {
        if (LE[i] <= LD[j]) {
            v[k] = LE[i];
            i++;
        } else {
            v[k] = LD[j];
            j++;
        }
        k++;
    }

    while (i < tam1) {
        v[k] = LE[i];
        i++;
        k++;
    }

    while (j < tam2) {
        v   [k] = LD[j];
        j++;
        k++;
    }

    free(LD);
    free(LE);
}

void mergeSrt(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        mergeSrt(v, inicio, meio);
        mergeSrt(v, meio + 1, fim);

        merge(v, inicio, meio, fim);
    }
}

int part(int v[], int inicio, int fim) {

    int pivo = v[fim];
    int i = inicio - 1;
    int j, temp;

    for (j = inicio; j <= fim - 1; j++) {
        if (v[j] < pivo) {
            i++;
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }

    temp = v[i + 1];
    v[i + 1] = v[fim];
    v[fim] = temp;

    return i + 1;
}

void quickSrt(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int pivo = part(v, inicio, fim);
        quickSrt(v, inicio, pivo - 1);
        quickSrt(v, pivo + 1, fim);
    }
}

