#include <stdio.h>

/*                  Ordenação por Inserção
    - Compara cada elemento do vetor com seus anteriores
    - Se algum dos anteriores for maior que o comparado
    - Reposiciona os elementos a frente, a partir do maior, e entra na sua posição correta
*/

#define QUANT 8 // quantidade de elementos do vetor

void imprimirListaOrdenada(int vetor[], int tamanho);
int  ordenar_insercao(int vetor[], int n);
int  posicao_elemento(int vetor[], int ultimo, int elemento);
void deslocar_subvetor(int vetor[], int primeiro, int ultimo);

void main(){
    int numeros[QUANT];
    int i;

    printf("\nINSIRA OS NUMEROS PARA A ORDENACAO:\n\n");
    for ( i = 0; i < QUANT; i++)
    {
        printf("%do Numero: ", i+1);
        scanf("%d", &numeros[i]);
    }

    ordenar_insercao(numeros, QUANT);
    imprimirListaOrdenada(numeros, QUANT);
}

void imprimirListaOrdenada(int vetor[], int tamanho){
    int i;
    
    printf("\nLISTA ORDENADA:\n\n");
    for ( i = 0; i < tamanho; i++)
    {
        printf("%d  ", vetor[i]);
    }
    
}

// Recebe o vetor e o número de elementos (n) que ele possui
// Guarda o elemento que será posicionado, a partir do vetor[1], (o vetor[0] já está posicionado)
// Compara com os anteriores e recebe o índice do que for maior em "posicao"
// Com os elementos posicionados a frente, posiciona o elemento comparado na posição que deve ficar
int ordenar_insercao(int vetor[], int n) {
    int i, posicao;
    int elemento;
    for (i = 1; i < n; i++) {
        elemento = vetor[i];
        posicao = posicao_elemento(vetor, i-1, elemento);
        deslocar_subvetor(vetor, posicao, i-1);
        vetor[posicao] = elemento;
    }
    }

// Recebe o vetor, o index do vetor anterior ao elemento (ultimo) e o elemento comparado
// O elemento é comparado com todos os antecessores no vetor
// Se o elemento for menor que algum dos anteriores, é retornado o índice desse elemento
int posicao_elemento(int vetor[], int ultimo, int elemento) {
    int i;
    for (i = 0; i <= ultimo && vetor[i] <= elemento; i++);
    return i;
}

// Recebe o vetor, o elemento que é maior ao comparado (primeiro) e o elemento comparado (ultimo)
// Repociciona todos os elementos entre eles uma posição a frente
void deslocar_subvetor(int vetor[], int primeiro, int ultimo) {
    int i;
    for (i = ultimo; i >= primeiro; i--) {
        vetor[i+1] = vetor[i];
    }
}