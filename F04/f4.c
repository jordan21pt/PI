#include <stdio.h>
#include <string.h>

int retiraVogaisRep (char *s){
  char aux[strlen(s)];
  int r, w;
  for(r=0, w=0; s[r]!='\0'; r++)
    // Não quero escrever no aux: s[r]==s[r+1] && isVogal(s[r])
    // Quero escrever quando !(s[r]==s[r+1] && isVogal(s[r])) <==> s[r]!=s[r+1] || !(isVogal(s[r]))
    // !(a && b) <==> !a || !b
    if(s[r]!=s[r+1] || !(isVogal(s[r])))
      aux[w++] = s[r];

  aux[w]='\0';
  strcpy(s,aux);
  return (r-w);
}

int duplicaVogais (char *s){
  int vog = contaVogais(s);
  char aux[strlen(s)+vog];
  int r, w;
  for(r=0, w=0; s[r]!='\0'; r++){
    aux[w++]=s[r];
    if(isVogal(s[r]))
      aux[w++]=s[r];
  }
  aux[w]='\0';
  strcpy(s,aux);
  return vog;
}


int duplicaVogais (char *s){
  int vog = contaVogais(s);
  int r = strlen(s)-1;
  int w = r + vog;

  s[w+1] = '\0';

  while(r>=0){
    s[w--]=s[r--];
    if(isVogal(s[r]))
      s[w--]=s[r];
  }
  return vog;
}

int main(){
  char s1 [100] = "Estaa e umaa string coom duuuplicadoos";

  int x;
  printf ("Testes\n");
  printf ("A string \"%s\" tem %d vogais\n", s1, contaVogais (s1));

  x = retiraVogaisRep (s1);
  printf ("Foram retiradas %d vogais, resultando em \"%s\"\n", x, s1);

  x = duplicaVogais (s1);
  printf ("Foram acrescentadas %d vogais, resultando em \"%s\"\n", x, s1);
  printf ("\nFim dos testes\n");
  return 0;

}
