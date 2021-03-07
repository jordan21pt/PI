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

        if (n % 2 != 0)
        {
            r += m;
        }

        n /=2;
        m *=2;
    }
    printf("%.2f", r);
    return r;
}
//2.2
float multInt3 (int n, float m, int *count){
    float r = 0;
    float countador = 0;

    while(n > 0)
    {

        if (n % 2 != 0)
        {
            r += m;
        }

        n /=2;
        m *=2;
        countador++;
    }

    printf("%.2f", countador);
    return countador;
}


//4.
int mdc1 (int a, int b){
    
    int resposta, temp, i;
    if (a == 0) resposta = b;
    else resposta = a;

        if (b < a)
        {
            temp = a;
            a = b;
            b = temp;
        }

        for(i = 1; i <= a; i++)
        {
            if(a % i == 0 && b % i == 0) resposta = i;
        }
    printf("%d", resposta);
    return resposta;
}

int mdc2 (int a, int b)
{
    while (a != 0 && b != 0)
    {
        if(a > b) a-=b;
        else b-=a;
    }
    if (a == 0) return b;
    else return a;
}

int mdc3 (int a, int b, int *count)
{
    int cont = 0;
        while (a != 0 && b != 0)
        {
            if(a > b) a-=b;
            else b-=a;
            cont++;
        }
        if (a == 0) return cont;
        else return cont;
}

int mdc4 (int a, int b, int *count)
{
    int cont = 0;
    while (a != 0 && b != 0)
    {
        if(a > b) a %= b;
        else b %= a;
        cont++;
    }
    if (a == 0) return cont;
    else return cont;
}

int fib (int n)
{
    if(n==0) return 0;
    else if (n < 2) return 1;
    else return fib(n-1) + fib (n-2);
}



int main()
{
    int ex, x;
    printf("Escolha o ex: \n");
    scanf("%d", &ex);
    switch (ex)
    {
        case 1:
            multInt1 (4, 4.0);
            printf("\n");
            multInt1 (81, 423);

            printf("\n");
            break;
        case 2:
            multInt2 (4, 4.0);
            printf("\n");
            multInt2 (81, 423);

            printf("\n");

            multInt3 (25000, 370, 0);
            printf("\n");
            multInt3 (81, 423, 0);

            printf("\n");
            break;
        case 3:
            mdc1 (20,24);
            printf("\n");
        case 4:
            x = mdc2 (126,45);
            printf("%d", x);
            printf("\n");
        case 5:
            x = mdc3 (126, 45, 0);
            printf("%d", x);
            printf("\n");
        case 6:
            x = mdc4 (126, 45, 0);
            printf("%d", x);
            printf("\n");
            break;
        case 7:
            x = fib (15);
            printf("%d", x);
            printf("\n");
        default:
            break;
    }
    
    return 0;
}
