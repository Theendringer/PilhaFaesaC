#include <stdio.h>
#include <stdlib.h>

struct fasesaprojeto1 {
    int topo;
    int capa;
    float *pElem;
};

void criarpilha(struct fasesaprojeto1 *p, int c) {
    p->topo = -1;
    p->capa = c;
    p->pElem = (float*) malloc(c * sizeof(float));
}

int estavazia(struct fasesaprojeto1 *p) {
    if (p->topo == -1)
        return 1;
    else
        return 0; 
}

int estacheia(struct fasesaprojeto1 *p) {
    if (p->topo == p->capa - 1)
        return 1;
    else
        return 0;
}

void empilhar(struct fasesaprojeto1 *p, float v) {
    p->topo++;
    p->pElem[p->topo] = v;
}

float desempilhar(struct fasesaprojeto1 *p) {
    float aux = p->pElem[p->topo];
    p->topo--;
    return aux;
}

float retornatopo(struct fasesaprojeto1 *p) {
    return p->pElem[p->topo];
}

int main() {
    struct fasesaprojeto1 minhapilha;
    int capacidade, op;
    float valor;

    printf("\nCapacidade da pilha? ");
    scanf("%d", &capacidade);

    criarpilha(&minhapilha, capacidade);

    while (1) {
        printf("\n1 - Empilhar\n");
        printf("2 - Desempilhar\n");
        printf("3 - Mostrar o topo\n");
        printf("4 - Sair\n");

        printf("\nOpcao? ");
        scanf("%d", &op);

        switch (op) {
            case 1: // Empilhar
                if (estacheia(&minhapilha))
                    printf("\nPILHA CHEIA!\n");
                else {
                    printf("\nValor? ");
                    scanf("%f", &valor);
                    empilhar(&minhapilha, valor);
                }
                break;

            case 2: // Desempilhar
                if (estavazia(&minhapilha))
                    printf("\nPILHA VAZIA!\n");
                else {
                    valor = desempilhar(&minhapilha);
                    printf("\n%.2f DESEMPILHADO!\n", valor);
                }
                break;

            case 3: // Mostrar o topo
                if (estavazia(&minhapilha))
                    printf("\nPILHA VAZIA!\n");
                else
                    printf("\nTOPO: %.2f\n", retornatopo(&minhapilha));
                break;

            case 4: // Sair
                free(minhapilha.pElem); // Liberar memória alocada
                exit(0);

            default:
                printf("\nOPÇÃO INVÁLIDA!\n");
        }
    }

    return 0;
}