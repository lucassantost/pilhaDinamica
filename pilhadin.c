#include<stdio.h>
#include<stdlib.h>

typedef struct reg{
    int dado;
    struct reg *prox;
} REG;

typedef struct pilha{
    REG *topo;
} PILHA;

void startPilha(PILHA *p){
        p->topo = NULL;
};

void empilha(int valor, PILHA *p){
    REG *novoREG = (REG*)malloc(sizeof(REG));

    if (novoREG == NULL){
        printf("Erro de alocacao de novo registro");
        return;
    }else{
        novoREG->dado = valor;
        novoREG->prox = p->topo;
        p->topo = novoREG;
    }
};

int desempilha(PILHA *p){
    REG *novoREG = p->topo;
    int dado;
    if (novoREG == NULL){
        printf("Pilha vazia \n");
        return 0;
    }else{
        p->topo = novoREG->prox;
        novoREG->prox = NULL;
        dado = novoREG->dado;
        free(novoREG);
        return dado;
    }
}

void imprimePilha(PILHA *p){
    REG *novoREG = p->topo;
    if (novoREG == NULL){
        printf("Pilha vazia  \n");
        return;
    }else{
        while (novoREG != NULL)
        {
            printf("%i ", novoREG->dado);
            novoREG = novoREG->prox;
        }
        printf("\n");
    }
};


int main(){
    PILHA *p1 = (PILHA*)malloc(sizeof(PILHA));

    if (p1 == NULL){
        printf("Erro de alocacao de nova pilha");
        exit(0);
    }else{
        startPilha(p1);

        empilha(76, p1);
        empilha(56, p1);
        empilha(66, p1);
        empilha(26, p1);
        empilha(786, p1);

        imprimePilha(p1);

        desempilha(p1);

        imprimePilha(p1);
    }
    return 0;
}