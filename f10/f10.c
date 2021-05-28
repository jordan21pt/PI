typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} * ABin;

ABin removeMenor (ABin *a) {
    ABin res = NULL;

    if (*a != NULL) {
        while ((*a)->esq != NULL) a = &((*a)->esq);
        res = *a;
        *a = (*a)->dir;
    }

    return res;
}

void removeRaiz (ABin *a) {
    ABin aux;
    
    if ((*a)->dir != NULL) {
        aux = removeMenor(&((*a)->dir));
        aux->esq = (*a)->esq;
        aux->dir = (*a)->dir;
    }
    else {
        aux = (*a)->esq;
    }
    free(*a);
    *a = aux;
}

int removeElem (ABin *a, int x) {
    int res = -1;
    
    while (*a != NULL && (*a)->valor != x) {
        if (x < (*a)->valor) {
            a = &((*a)->esq);
        }
        else a = &((*a)->dir);
    }

    if (*a != NULL){
        removeRaiz(a);
        res = 0;
    }
    
    return res;
}

/*-----------------------------*/
void rodaDireita (ABin *a){
    ABin aux = *a;
    *a = (*a)->esq;
    aux->esq = (*a)->dir;
    (*a)->dir = aux;
}

void rodaEsquerda (ABin *a){
    ABin aux = *a;
    *a = (*a)->dir;
    aux->dir = (*a)->esq;
    (*a)->esq = aux;
}

void promoveMenor (ABin *a) {
    if (*a != NULL && (*a)->esq != NULL) {
        promoveMenor(&((*a)->esq));
        rodaDireita(a);
    }
}

void promoveMaior (ABin *a) {
    if (*a != NULL && (*a)->dir != NULL) {
        promoveMaior(&((*a)->dir));
        rodaEsquerda(a);
    }
}

int constroiEspinhaAux (ABin * a, ABin * ult) {
    
}