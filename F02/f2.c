#include <stdio.h>
//1
float multInt1 (int n, float m){
    float r = 0;

    for(; n > 0; n--)
    {
        r += m;
    }
    printf("%.2f", r);
    return r;
}
//2.1
float multInt2 (int n, float m){

    float r = 0;

    while(n > 0)
    {
        if (n % 2 != 0) r += m;
        n /=2;
        m *=2;
    }
    return r;
}
//2.2
float multInt3 (int n, float m, int *count)
{
    float r = 0;
    while (n > 0)
    {
        if (n % 2 != 0) r += m;
        n /=2;
        m *=2;
        (*count)++;
    }
    return r;
}


//4.
int mdc1 (int a, int b)
{    
    // 1 - Encontrar o menor entre a e b
    // 2 - Percorrer os valores entre [menor..1] e ver qual deles divide a e também divide b
    // 3 - Se encontrar algum sair do ciclo
    int menor, r = 1;
    if(a>b) menor = b;
    else menor = a;
    
    while(menor>0 && r==1)
    {
        if(a%menor==0 && b%menor==0)
        {
            r = menor;
        }
        menor--;
}
    return r;
}

int mdc2 (int a, int b)
{
    while (a != 0 && b != 0)
    {
        if(a > b) a-=b;
        else b-=a;
    }
    return (a+b);
}

int mdc3 (int a, int b, int *count)
{
 
    while (a != 0 && b != 0)
    {
        if(a > b) a-=b;
        else b-=a;
        (*count)++;
    }
    return (a+b);
}

int mdc4 (int a, int b, int *count)
{
    while (a != 0 && b != 0)
    {
        if(a > b) a %= b;
        else b %= a;
        (*count)++;
    }
    return (a+b);
}

int fib (int n)
{
    int r;
    if(n < 2) r = n;
    else r = fib(n-1) + fib (n-2);
    return r;
}

int fastfib (int n)
{
    int r;
    if(n < 2) r = n;
    else r = fib(n-1) + fib (n-2);
    return r;
}