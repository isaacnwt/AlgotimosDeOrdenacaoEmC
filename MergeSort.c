#include <stdio.h>

/*                 Ordenação por Intercalação
    - Organiza o vetor por recursão
    - Dividindo o vetor em no meio e cada subvetor no meio novamente até não dividir mais
    - Organiza os subvetores inserindo um elemento de cada subvetor em um auxiliar
*/

#define QUANT 8 // quantidade de elementos do vetor

void imprimirListaOrdenada(int vetor[], int tamanho);
void ordenar_intercalacao(int vetor[], int ini, int fim);
int  intercalar(int vetor[], int ini, int meio, int fim);

void main(){
    int numeros[QUANT];
    int i;

    printf("\nINSIRA OS NUMEROS PARA A ORDENACAO:\n\n");
    for ( i = 0; i < QUANT; i++)
    {
        printf("%do Numero: ", i+1);
        scanf("%d", &numeros[i]);
    }

    ordenar_intercalacao(numeros, 0, 7);
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

// Recebe o vetor, seu índice inicial e final
// Define o índice da posição do meio em uma variável
// Por recursão, organiza o vetor por intercalação
void ordenar_intercalacao(int vetor[], int ini, int fim) {
    int meio;
    if (ini < fim) {
        meio = (ini + fim) / 2;
        ordenar_intercalacao(vetor, ini, meio);
        ordenar_intercalacao(vetor, meio + 1, fim);
        intercalar(vetor, ini, meio, fim);
    }
}

// Recebe o vetor, a posição inicial, a do meio e a final
// Compara uma metade do vetor com a outra e vai colocando em ordem no vetor auxiliar em // intercala
// Insere o elemento que sobrar no subvetor em // copia resto de cada subvetor
// O vetor recebe o auxiliar organizado
int intercalar(int vetor[], int ini, int meio, int fim) {
    int auxiliar[QUANT]; // vetor auxiliar
    int i = ini, j = meio + 1, k = 0; // índices dos vetores

    // intercala
    while(i <= meio && j <= fim) {
        if (vetor[i] <= vetor[j])
            auxiliar[k++] = vetor[i++];
        else
            auxiliar[k++] = vetor[j++];
    }

    // copia resto de cada subvetor
    while (i <= meio) auxiliar[k++] = vetor[i++];
    while (j <= fim) auxiliar[k++] = vetor[j++];

    // copia de auxiliar para vetor
    for (i = ini, k=0; i <= fim; i++, k++)
    vetor[i] = auxiliar[k];
}



