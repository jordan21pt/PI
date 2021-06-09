#include <stdio.h>

void dumpV (int v[], int N){
    int i;
    putchar ('{');
    for (i=0; i<N; i++) printf ("%2d ", v[i]);
    putchar ('}');
}
void simNao (int x){
    if (!x) printf (" não ");
}

int ordenado (int a[], int N){
    int i, j, r;
    for (i = 0, j = 1; i < N-1, j < N; i++, j++)
    {
        if (a[i] <= a[j]) r = 1;
        else r = 0;
    }
    
    printf("r = %d", r);
    
    return r;
}

void merge (int a[], int na, int b[], int nb, int r[]){
    int i,j;
    for (i = 0; i < na; i++)
    {
        r[i] = a[i];
    }
    for (i = na, j = 0; i < na+nb, j <nb; i++, j++)
    {
        r[i] = b[j];
    }
}

int qntsMenor(int v[], int N, int x){
    int i, qnts;
    for (i = 0; i < N; i++)
    {
        if (v[i] <= x) qnts++; 
    }
    
    return qnts;
}

int quaisMen(int v[], int N, int x, int menores){
    int i, aux[menores];
    for (i = 0; i < N; i++)
    {
        if (v[i] <= x) aux[i] = v[i];
    }
    return *aux;
}

int partition (int v[], int N, int x){
    
    int menores = qntsMenor(v, N, x);

    int aux[menores];
    aux[menores] = quaisMen(v, N, x, menores);

    return *aux;
}

int main() {  
    int a [15] = {10, 3,45,56, 8,23,13,42,77,31,18,88,24,45, 1},
        b [10] = { 4,12,34,45,48,52,61,73,84,87}, 
        c [10] = { 1, 3, 8,22,33,35,38,41,44,49}, 
        d [50];
    int x;
    
    printf ("Testes\n\n");

    printf ("O array "); dumpV(a,15);
    simNao (ordenado (a,15)); printf (" está ordenado\n");
    printf ("O array "); dumpV(b,10);
    simNao (ordenado (b,10)); printf (" está ordenado\n");
    
    
    printf ("\n\nMerge dos arrays "); dumpV (b,10);
    printf ("\ne                "); dumpV (c,10); 
    merge (b, 10, c, 10, d);
    printf ("\nresulta em       "); dumpV (d,20);

    printf ("\n\n\nA partição do array  "); dumpV (a,15);
    printf ("\nusando 30 resulta em "); 
    x = partition (a,15,30); 
    dumpV (a,15); printf (" e retorna %d \n", x);

    printf ("\nFim dos testes\n");
    return 0;
}