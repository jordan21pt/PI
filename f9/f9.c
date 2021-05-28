
#include <time.h>

typedef struct nodo{
    int valor;
    struct nodo *esq, *dir;
}*ABin; 

int altura(Abin a){
    int alt = 0, e, d;
    if (a != NULL){
        e = altura (a -> esq);
        d = altura (a -> dir);

        if (e > d) alt = 1 + e;
        else alt = 1 + d;
    }
    return alt;
}

int max(alt a, int b){
    int maior;
    if (a > b) maior = a;
    else maior = b;
    return maior;
}

int altura2(Abin a){
    int alt = 0;
    if (a != NULL) alt = 1 + max(altura2(a->esq), altura2(a->dir));
    return alt;
}

int nFolhas(ABin a){
    int n = 0, e, d;
    if (a != NULL){
        if(a->esq == NULL && a->dir == NULL){
            n = 1;
        }
        else{
            e = nFolhas(a->esq);
            d = nFolhas(a->dir);
            n = e + d;
            // n = nFolhas(a->esq) + nFolhas(a->dir);
        }
    }
    return n;    
}

ABin maisEsquerda (ABin a){
    if (a != NULL){
        while (a->esq != NULL) a = a->esq;
    }
    return a;
}

void imprimeNivel (ABin a, int l){
    if (a != NULL){
        if (l == 0){
            printf("%d", a->valor);
        } 
        else {
            imprimeNivel(a->esq, l-1);
            imprimeNivel(a->dir, l-1);
        }
    }
}

int procuraE (ABin a, int x){
    int r = 0;
    if (a != NULL){
        if (a->valor == x){
            r = 1;
        }
        else{
            r = procuraE(a->esq, x) || procuraE(a->dir, x);
        }
    }
    return r;
    // return(a!=null && (a->valor == x || procuraE(a->esq, x) || procuraE(a->dir, x)));
}


//2.
struct nodo *procura (ABin a, int x){
    while (a != NULL && a->valor != x){
        if (x < a->valor) a = a->esq;
        else a = a->dir;
    }
    return a;
}

int nivel (ABin a, int x){
    int res;

    for (r = 0; a->valor != NULL && a->valor != x; r++){
        if (x < a->valor){
            a = a->esq;
        }
        else a = a->dir;
    }   

    if (a == NULL) res = -1;

    return res;
}

void imprimeAte (ABin a, int x){
    if (a != NULL){
        imprimeAte(a->esq, x);
        if (a->valor < x){
            printf("%d", a->valor);
            imprimeAte(a->dir, x);   
        }
    }
}