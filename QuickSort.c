#include <stdio.h>

/*                 Ordenação por Particionamento
    - Organiza o vetor por recursão
    - Dividindo o vetor em no meio, menores à esquerda e maiores à direira
    - Faz isso comparando sempre o elemento final com o resto e trocando as posições dos elementos
*/

#define QUANT 8 // quantidade de elementos do vetor

void imprimirListaOrdenada(int vetor[], int tamanho);
void quick_sort(int vetor[], int ini, int fim);
int  particionar(int vetor[], int ini, int fim);
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

    quick_sort(numeros, 0, 7);
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

// Recebe o vetor, o índice inicial e o final
// Divide o vetor ao meio e organiza por recurção dividindo cada subvetor ao meio novamente
void quick_sort(int vetor[], int ini, int fim) {
    int pos;

    if (ini < fim){
        pos = particionar(vetor, ini, fim);
        quick_sort(vetor, ini, pos - 1);
        quick_sort(vetor, pos, fim);
    }
}

// Recebe o vetor, o índice inicial e o final
// Compara o último elemento (pivo) com os outros...
// Do inicio ao fim: se o pivo for maior ou igual, é guardado a posição
// Do fim ao início: se o pivo for menor, é guardado a posição
// É feito a troca dos elementos das posições guardadas
int particionar(int vetor[], int ini, int fim) {
    int pivo;

    pivo = vetor[fim];

    while (ini < fim) {
        while (ini < fim && vetor[ini] <= pivo)
            ini++;
        while (ini < fim && vetor[fim] > pivo)
            fim--;
        trocar(&vetor[ini], &vetor[fim]);
    }
    return ini; // ini é a posição do primeiro elemento grande
}

// Troca a posição dos valores utilizando uma variável auxiliar
// Usa o endereço de mamória dos ítens como parâmetro
void trocar(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}