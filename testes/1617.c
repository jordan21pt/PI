typedef struct slist {
    int valor;
    struct slist *prox;
} *LInt;

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

int limpaEspacos (char t[]){
    int i = 0;
    int r = 0;

    while (t){
        if (t[i] == ' ' && t[i+1] == ' '){
            t[r++] = t[i];
            i++;
        }
    }
    return r;    
}