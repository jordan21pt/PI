typedef struct slist {
    int valor;
    struct slist * prox;
} * LInt;

LInt newLInt (int x, LInt xs) {
    LInt r = malloc (sizeof(struct slist));
    if (r!=NULL) {
        r->valor = x; t->prox = xs;
    }
    return r;
}

typedef LInt QueueC;

void initQueueC (QueueC *q){
    *q = NULL;
}

int QisEmptyC (QueueC q){
    return (q == NULL);
}

int enqueueC (QueueC *q, int x){
    LInt nova = newLInt (x,NULL);
    int r = 1;

    if (nova != NULL){
        r = 0;
        if (*q == NULL)
            *q = nova->prox = nova;
        else{
            nova->prox = (*q)->prox;
            (*q)->prox = nova;
            *q = nova;
        }
    }
    return r;
}

int dequeueC (QueueC *q, int *x){
    int r = 1;
    LInt aux;
    if (*q != NULL){
        r = 0;
        aux = (*q)->prox;
        *x = aux->valor; //(*q)->prox->valor; 
        if ((*q) == (*q)->prox)
            *q = NULL;
        else
            (*q)->prox = aux->prox;
        free(aux);
    }
    return r;
}

int frontC (QueueC q, int *x){

}
