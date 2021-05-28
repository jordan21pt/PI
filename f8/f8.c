typedef struct slist {
    int valor;
    struct slist * prox;
} * LInt;

typedef struct {
    LInt inicio,fim;
} Queue;

LInt newLInt (int x, LInt xs) {
    LInt r = malloc (sizeof(struct slist));
    if (r!=NULL) {
        r->valor = x; t->prox = xs;
    }
    return r;
}

void initQueue (Queue *q){
    (*q).inicio = NULL;  // (q*). <==> q->
    (*q).fim = NULL;
}

int QisEmpty (Queue q){
    return (q.inicio == NULL);
}

int enqueue (Queue *q, int x){
    LInt nova = newLInt(x, NULL);
    int r = 1;
    if (nova != NULL){
        r = 0;
        if (QisEmpty(*q))// if(q-> inicio == NULL)
            q->inicio = q->fim = nova;
        else
            q->fim = q->fim->prox = nova;
    }
    return r;
}

int dequeue (Queue *q, int *x){
    int r = 1;
    LInt aux;
    if (q->inicio != NULL){
        r = 0;
        aux = q->inicio;
        *x = q->inicio->valor;
        if (q->inicio == q->fim)
            q->inicio = q->fim = NULL;
        else
            q->inicio = q->inicio->prox;
        free(aux);
    }
    return r;
}

int front (Queue q, int *x){
    int r = 1;
    if (q.inicio != NULL){
        r = 0;
        *x = q.inicio->valorvalor;
    }
    return r;
}

int main(){
    
    return 0;
}