#include <stdio.h> 

/* 1 ESTADO E ATRIBUIÇOES */

/*
EX1
    int x, y;
    x = 3;
    y = x+1;
    x = x*y; y = x + y;
    printf("%d %d\n", x, y);

O EXERCICIO COMEÇA POR DAR VALOR A X = 3 E Y = X + 1 OU
SEJA, Y = 4
NA LINHA A SEGUIR, O X = X * Y, E VENDO A LINHA ANTERIOR
X = 3 * 4, LOGO X = 12
NA MESMA LINHA, TEMOS QUE Y = Y + X
LOGO, Y = 12 + 4, Y = 16

CONCLUIO QUE O OUTPUT É 
X = 12 E Y = 16
*/


/*
EX2 
    int x, y;
    x = 0;
    printf ("%d %d\n", x, y);

A FUNCAO COMEÇA COM O X = 0 E O Y NAO E INICIALIZADO, LOGO NO OUTPUT DA FUNÇAO
X = 0 E Y = 0
*/


/*
EX3
    char a, b, c;
    a = ’A’; b = ’ ’; c = ’0’;
    printf ("%c %d\n", a, a);
    a = a+1; c = c+2;
    printf ("%c %d %c %d\n", a, a, c, c);
    c = a + b;
    printf ("%c %d\n", c, c);

NO PRIMEIRO PRINTF:
A 65
NO SEGUNDO PRINTF:
B 66 2 50
NO TERCEIRO PRINTF: 
b 98 
*/

/*
EX4
    int x, y;
    x = 200; y = 100;
    x = x+y; y = x-y; x = x-y;
    printf ("%d %d\n", x, y);

O X = 200 , Y = 100
X = 300 , Y = 200 , X = 100
OUTPUT: 100 200
*/

/* 2 ESTRUTURAS DE CONTROLO */

/*
EXa
    int x, y;
    x = 3; y = 5;
    if (x > y)
    y = 6;
    printf ("%d %d\n", x, y);

COMO (3 > 5) É FALSO ENTAO 
OUTPUT: 3 5
*/

/*
EXb
    int x, y;
    x = y = 0;
    while (x != 11) {
    x = x+1; y += x;
    }
    printf ("%d %d\n", x, y);

O X E O Y COMEÇAM A 0 
ENQUANTO O X != 11 O X INCREMENTA UMA UNIDADE E O Y INCREMENTA O VALOR DO X
ENTAO
X Y
0 0
1 1
2 3
3 6
4 10
5 15
6 21
7 28
8 36
9 45
10 55
11 66
OUTPUT : 11 66
*/

/* 
EXc
    int i;
    for (i=0; (i<20) ; i++)
    if (i%2 == 0) putchar (’_’);
    else putchar (’#’);

PARA UM I COMECANDO EM 0 QUE VAI ATE 19
SE O I FOR UM PAR POMOS _
SE O I FOR IMPAR POMOS #

OUTPUT: _#_#_#_#_#_#_#_#_#_#
*/

/*
    void f (int n) {
    while (n>0) {
    if (n%2 == 0) putchar (’0’);
    else putchar (’1’);
    n = n/2;
    }
    putchar (’\n’);
    }
    
    int main () {
    int i;
    for (i=0;(i<16);i++)
    f (i);
    return 0;
    }

OUTPUT: 
1
11
11
111
111
111
111
1111
1111
1111
1111
1111
1111
1111
1111
*/

#include <stdio.h>


void quadrado (int n)
{
    int linha, coluna;
    for(linha = 0; linha < n; linha++)
    {
        for(coluna = 0; coluna < n; coluna++)
        {
            putchar('#');
        }
        printf("\n");
    }
}


void xadrez (int n)
{
    int linha, coluna;
    for(linha = 0; linha < n; linha++)
    {
        for(coluna = 0; coluna < n; coluna++)
        {
            if ((coluna % 2 == 0) && (linha % 2 == 0))
            {
                putchar('#');
            }
            else if ((coluna % 2 != 0) && (linha % 2 != 0))
            {
                putchar('#');
            }
            else 
            {
                putchar('_');
            }
        }
        printf("\n");
    }
}

void trianguloH (int n)
{
   int linha, coluna;
   for (linha = 0; linha < n; linha++)
   {
       for (coluna = 0; coluna <= linha; coluna++)
       {
           putchar('#');
       }
       printf("\n");
   }
    for (linha = n-1; linha >= 0; linha--)
    {
       for (coluna = 0; coluna <= linha-1; coluna++)
       {
           putchar('#');
       }
       printf("\n");
    }
}

void trianguloV (int n)
{
    int espacos, linha, simbolo;
    
    for(linha = 1; linha <= n; linha++)
    {
       // spaces
       for (espacos = 1; espacos <= (n-linha); espacos++)
       {
           putchar(' ');
       }
       
       //symbol
       for (simbolo = 1; simbolo <= ((2*linha)-1); simbolo++)
       {
           putchar('#');
       }
       
       printf("\n");
    }
   
}

/* Main function of the C program. */

int main()
{
    quadrado (5);
    xadrez (5);
    trianguloH (5);
    trianguloV (5);
    return 0;
}
