#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void bubbleSort(int* v, int n) {
    // Caso base: se o tamanho do sub-array for 1 ou menos, já está ordenado.
    if (n <= 1) {
        return;
    }

    bool trocou = false;
    // Percorre o array até o penúltimo elemento do sub-array atual (n-1)
    for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
            // Troca os elementos
            int temp = v[i];
            v[i] = v[i + 1];
            v[i + 1] = temp;
            trocou = true;
        }
    }

    // O maior elemento do sub-array atual já está na posição correta (v[n-1]).
    // Chamada recursiva para o restante do array (n-1 elementos).
    // Se nenhuma troca ocorreu, o array já está completamente ordenado.
    if (!trocou) {
        return;
    }
    
    bubbleSort(v, n - 1);
}

void clear() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    srand(time(NULL));
    int n; // tamanho do vetor
   
    printf("Tamanho do vetor: ");
    scanf("%d", &n);
    int *v = malloc(sizeof(int) * n);
    
    if (v == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return 1;
    }
    
    // Preenche o vetor com valores aleatórios
    for (int i = 0; i < n; i++) {
       v[i] = rand() % 2025;
    }

   
    printf("---------------------Vetor Original---------------------\n ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n----------------------------------------------------\n ");

    bubbleSort(v, n);
    
    printf("---------------------Vetor Ordenado-----------------\n ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n----------------------------------------------------\n ");

    free(v);
    return 0;
}