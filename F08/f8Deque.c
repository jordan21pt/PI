typedef struct dlist {
    int valor;
    struct dlist *ant, *prox;
} *DList;

typedef struct {
    DList back, front;
} Deque;

void initDeque (Deque *q){

}

DList newDList(int x, DList ant, DList prox);

int pushBack (Deque *q, int x){
    DList nova = newDList (x, NULL, q->back);
    int r = 1;
    if (nova != NULL){
        r = 0;
        if (q->back == NULL)
            q->back = q->front = nova;
        else{
            q->back->ant = nova;
            q->back = nova;
            // q-> back = q->back->ant = nova;
        }
    }
    return r;
}

int pushFront (Deque *q, int x){
    DList nova = newDList (x, q->front, NULL);
    int r = 1;
    if (nova != NULL){
        r = 0;
        if (q->back == NULL)
            q->back = q->front = nova;
        else{
            q->front->prox = nova;
            q->front = nova;
            // q->front = q->front->prox = nova;
        }
    }
    return r;
}
