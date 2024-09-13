#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct alunos {
    float hestudos;
    float nmedias;
    int aprovacao;
} Alunos;

typedef struct data {
    float distancia;
    int aprovacao;
} Data;

// Funções para operar na estrutura de heap
void heapify(Data *arr, int n, int i);
void buildHeap(Data *arr, int n);
void heapSort(Data *arr, int n);

int classificar(Alunos *alunos, int atreino, float mediateste, float horasteste, int k);

int main() {
    int atreino, ateste, k;
    float mteste, hteste;

    scanf("%d %d %d", &atreino, &ateste, &k);

    Alunos *alunos = (Alunos *)malloc(sizeof(Alunos) * atreino);

    for (int i = 0; i < atreino; i++) {
        scanf("%f %f %d", &alunos[i].nmedias, &alunos[i].hestudos, &alunos[i].aprovacao);
    }

    for (int i = 0; i < ateste; i++) {
        scanf("%f %f", &mteste, &hteste);

        if (classificar(alunos, atreino, mteste, hteste, k)) {
            printf("Aluno %d: (%.2f, %.2f) = Aprovado\n", i, mteste, hteste);
        } else {
            printf("Aluno %d: (%.2f, %.2f) = Reprovado\n", i, mteste, hteste);
        }
    }

    free(alunos);

    return 0;
}

int classificar(Alunos *alunos, int atreino, float mediateste, float horasteste, int k) {
    Data *distancias = (Data *)malloc(sizeof(Data) * k);
    int aprovados = 0, reprovados = 0;

    for (int i = 0; i < k; i++) {
        distancias[i].distancia = pow(mediateste - alunos[i].nmedias, 2) + pow(horasteste - alunos[i].hestudos, 2);
        distancias[i].aprovacao = alunos[i].aprovacao;
    }

    buildHeap(distancias, k);

    for (int i = k; i < atreino; i++) {
        float dist = pow(mediateste - alunos[i].nmedias, 2) + pow(horasteste - alunos[i].hestudos, 2);

        if (dist < distancias[0].distancia) {
            distancias[0].distancia = dist;
            distancias[0].aprovacao = alunos[i].aprovacao;
            heapify(distancias, k, 0);
        }
    }

    //heapSort(distancias, k);

    for (int i = 0; i < k; i++) {
        if (distancias[i].aprovacao == 1) {
            aprovados++;
        } else {
            reprovados++;
        }
    }

    free(distancias);

    if (aprovados > reprovados) {
        return 1;
    }

    return 0;
}

void heapify(Data *arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].distancia > arr[largest].distancia) {
        largest = left;
    }

    if (right < n && arr[right].distancia > arr[largest].distancia) {
        largest = right;
    }

    if (largest != i) {
        Data temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void buildHeap(Data *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void heapSort(Data *arr, int n) {
    for (int i = n - 1; i > 0; i--) {
        Data temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}