#include <stdio.h>
#include <stdlib.h>

typedef struct slist {
    int valor;
    struct slist *prox;
} *LInt;

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

int retiraNeg (int v[], int N) {
    int i, j = 0, count = 0;
    int sobra[N];

    for (i = 0; i < N; i++){
        if (v[i] >= 0){
            sobra[j] = v[i]; 
            j++;
        }
        else count++;
    }
    for (i = 0; i < (N-count); i++){
        v[i] = sobra[i];
    }
    
    return N-count;
}

int difConsecutivos (char s[]);

int maximo (LInt l) {
    int r = 0;
    while (l){
        if (l->valor > r) r = l->valor;
        else l = l->prox;
    }
    return r;
}

int removeAll (LInt *l, int x) {
    int r = 0;
    while (l){
        if ((*l)->valor == x) {
            (*l) = (*l)->prox;
            r++;
        }
        else l = &((*l)->prox);
    }
    return r;
}

LInt arrayToList (int v[], int N);

int minheapOK (ABin a) {
    int r = 1;
    if (a){
        if (a->esq) r = (a->valor < a->esq->valor && minheapOK(a->dir));
        if (a->dir) r = (a->valor < a->dir->valor && minheapOK(a->esq));
    }
    return r;
}

int maxHeap (ABin a) {
    int r = a->dir ? maxHeap(a->dir) : a->valor;
    int l = a->esq ? maxHeap(a->esq) : a->valor;

    return (l < r ? r : l);
}

void removeMin (ABin *a) {
    
}

int main() {

struct nodo *tree = &(struct nodo){20, &(struct nodo){35, &(struct nodo){80},
                                                          &(struct nodo){43}},
                                       &(struct nodo){85}};
    int r = maxHeap(tree);
    printf("%d\n", r);
    return 0;
}