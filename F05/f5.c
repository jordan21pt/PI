#include <stdio.h>
#include <math.h>

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;

//////////////////////////////////
int nota (Aluno a);

void ordenaPorNum (Aluno t [], int N);
int procuraNum (int num, Aluno t[], int N);

void criaIndPorNum (Aluno t [], int N, int ind[]);
int procuraNumInd (int num, int ind[], Aluno t[], int N);

void criaIndPorNome (Aluno t [], int N, int ind[]);

void imprimeTurmaInd (int ind[], Aluno t[], int N);
/////////////////////////////////

void dumpV (int v[], int N){
    int i;
    for (i=0; i<N; i++) printf ("%d ", v[i]);
}
void imprimeAluno (Aluno *a){
    int i;
    printf ("%-5d %s (%d", a->numero, a->nome, a->miniT[0]);
    for(i=1; i<6; i++) printf (", %d", a->miniT[i]);
    printf (") %5.2f Nota final: %d\n", a->teste, nota(*a));
}

int nota (Aluno a){
    int i, notaF = 0;
    float somaMiniT = 0;

    for (i = 0; i < 6; i++)
        somaMiniT += a.miniT[i];

    somaMiniT = (somaMiniT * 20) / 12;

    if (somaMiniT >= 8 && a.teste >= 8)
        notaF = round(somaMiniT*0.3 + a.teste*0.7);

    return notaF;
}

int procuraNum (int num, Aluno t[], int N){
    int i, indice = -1;

    for (i = 0; i < N && t[i].numero < num; i++);

    if(i<N && t[i].numero == num)
      indice = i;

    return indice;
}

void ordenaPorNum (Aluno t [], int N){
  int i, j, min;
  Aluno tmp;

  for(i=0; i<N; i++){
    min = i;
    for(j=i+1; j<N; j++)
      if(t[j].numero < t[min].numero)
        min = j;

    tmp = t[i];
    t[i] = t[min];
    t[min] = tmp;
  }
}

int procuraNumInd (int num, int ind[], Aluno t[], int N){
    int i, indice = -1;

    for (i = 0; i < N && t[ind[i]].numero < num; i++);

    if(i<N && t[ind[i]].numero == num)
      indice = i; // ou indice = ind[i]; se quiser a posição no array original (sem estar ordenado)

    return indice;
}

void criaIndPorNum (Aluno t [], int N, int ind[]){
  
  int ind[])
  int i, j, min;
  int tmp;

  for(i=0; i<N; i++)
    ind[i] = i;

  for(i=0; i<N; i++){
    min = i;
    for(j=i+1; j<N; j++)
      if(t[ind[j]].numero < t[ind[min]].numero)
        min = j;
    
    //swap indices     
    tmp = ind[i];
    ind[i] = ind[min];
    ind[min] = tmp;
  }
}
/*
int bubbleInd(Aluno t [], int N, int ind[]){
  int i, maxIndTroca=0;
  int tmp;
   
  for(i=1; i<N; i++)
    if(t[ind[i]].numero < t[ind[i-1]].numero){
      tmp = ind[i-1];
      ind[i-1] = ind[i];
      ind[i] = tmp;
      maxIndTroca = i;
    }
  return maxIndTroca;
}

void criaIndPorNum (Aluno t [], int N, int ind[]){
  int i;
  for(i=0; i<N; i++)
    ind[i] = i;
  while(N = bubbleInd(t,N,ind));
}
*/

}
void criaIndPorNome (Aluno t [], int N, int ind[]){
    
}

void imprimeTurmaInd (int ind[], Aluno t[], int N){
  int i;

  for(i=0; i<N; i++)
    imprimeAluno (t + ind[i]);

}

int main() {
    Aluno Turma1 [7] = {{4444, "André", {2,1,0,2,2,2}, 10.5}
                       ,{3333, "Paulo", {0,0,2,2,2,1},  8.7}
                       ,{8888, "Carla", {2,1,2,1,0,1}, 14.5}
                       ,{2222, "Joana", {2,0,2,1,0,2},  3.5}
                       ,{7777, "Maria", {2,2,2,2,2,1},  5.5}
                       ,{6666, "Bruna", {2,2,2,1,0,0}, 12.5}
                       ,{5555, "Diogo", {2,2,1,1,1,0},  8.5}
                       } ;
    int indNome [7], indNum [7];
    int i;
    
    printf ("\n-------------- Testes --------------\n");
    
    // ordenaPorNum (Turma1, 7);

    // printf ("procura 5555: %d \n", procuraNum (5555, Turma1, 7));
    // printf ("procura 9999:%d \n", procuraNum (9999, Turma1, 7));

    for (i=0; i<7; imprimeAluno (Turma1 + i++));
    
    // criaIndPorNum (Turma1, 7, indNum);
    
    // criaIndPorNome (Turma1, 7, indNome);

    // imprimeTurmaInd (indNum, Turma1, 7);
    // imprimeTurmaInd (indNome, Turma1, 7);

    // printf ("procura 5555:%d \n",  procuraNumInd (5555, indNum, Turma1, 7));
    // printf ("procura 9999:%d \n",  procuraNumInd (9999, indNum, Turma1, 7));

    printf ("\n---------- Fim dos Testes ----------\n");
    
    return 0;
}
