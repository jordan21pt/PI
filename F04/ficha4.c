#include <stdio.h>
#include <string.h>

int contaVogais (char *s) {
    int vogais = 0;
    while(*s){
        if (*s == 'a' || *s == 'e' || *s == 'i' || *s == 'o' || *s == 'u' || 
            *s == 'A' || *s == 'E' || *s == 'I' || *s == 'O' || *s == 'U') vogais++;
        *s++;  
    }
    return vogais;
}

int retiraVogaisRep (char *s){
    int qnt = 0, j, i;
    char aux[strlen(s)];
    for (i = 0, j = 0; i < strlen(s); i++)
    {
        if ((*s == 'a' || *s == 'e' || *s == 'i' || *s == 'o' || *s == 'u' || 
             *s == 'A' || *s == 'E' || *s == 'I' || *s == 'O' || *s == 'U') && (s[i] == s[i+1]))
        {
            qnt++;
            aux[j] == s[i];
        }
        else
        {
            aux[j] = s[i];
            j++;
        }
    }
    aux[j] = '\0';
    strcpy(s, aux);
    return qnt;
}


int duplicaVogais (char *s){
    char aux[strlen(s)];
    int qnt = 0, i, j;

    for (i = 0, j = 0; i < strlen(s); i++)
    {
        if ( *s == 'a' || *s == 'e' || *s == 'i' || *s == 'o' || *s == 'u' || 
             *s == 'A' || *s == 'E' || *s == 'I' || *s == 'O' || *s == 'U'   )
        {
            qnt++;
            aux[j++] = s[i];
            aux[j++] = s[i];
        }
        else
        {
            aux[j++] = s[i];
        }
        
    }
    aux[j] = '\0';
    strcpy(s, aux);
    return qnt;
}

int main()
{   char s1 [100] = "Estaa e umaa string coom duuuplicadoos";
    char s2 [100] = "Esta e uma string com duplicados";
    int x;
    
    printf ("Testes\n");
    printf ("A string \"%s\" tem %d vogais\n", s2, contaVogais (s2));
    
    //x = retiraVogaisRep (s1);
    //printf ("Foram retiradas %d vogais, resultando em \"%s\"\n", x, s1);
    
    x = duplicaVogais (s2);
    printf ("Foram acrescentadas %d vogais, resultando em \"%s\"\n", x, s2);
    
    printf ("\nFim dos testes\n");

    return 0;
}