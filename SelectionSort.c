#include <stdio.h>

/*                  Ordenação por Seleção
    - Seleciona o primeiro elemento do vetor e compara com o menor
    - Se for menor, troca as posições
    - Segue fazendo assim com cada elemento do vetor
*/

#define QUANT 8 // quantidade de elementos do vetor

void imprimirListaOrdenada(int vetor[], int tamanho);
int  ordenar_selecao(int vetor[], int n); 
int  menor_elemento(int vetor[], int n, int primeiro); 
void trocar(int *a, int *b); 


void main(){
    int numeros[QUANT];
    int i;

    printf("\nINSIRA OS NUMEROS PARA A ORDENACAO:\n\n");
    for ( i = 0; i < QUANT; i++)
    {
        printf("%do Numero: ", i+1);
        scanf("%d", &numeros[i]);
    }

    ordenar_selecao(numeros, QUANT);
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
// Para cada elemento do vetor é feito uma comparação com os seguintes
// O índice do menor elemento é guardado em "menor" e é feito a troca
int ordenar_selecao(int vetor[], int n) {
    int i, menor;
    for (i = 0; i < n; i++) {
        menor = menor_elemento(vetor, n, i);
        trocar(&vetor[i], &vetor[menor]);
    }
}

// Recebe o vetor, número de elementos (n) e o índice do elemento que está sendo apontado (primeiro)
// Se o elemento comparado for menor que o primeiro a variável menor é atualizada com seu índice
// Retorna o índice do menor elemento
int menor_elemento(int vetor[], int n, int primeiro) {
    int i, menor = primeiro;
    for (i = primeiro + 1; i < n; i++) {
        if (vetor[i] < vetor[menor]){
            menor = i;
        }
    }
    return menor;
}

// Troca a posição dos valores utilizando uma variável auxiliar
// Usa o endereço de mamória dos ítens como parâmetro
void trocar(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}




