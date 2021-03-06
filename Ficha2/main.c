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










int main()
{
    //1
    multInt1 (4, 4.0);
    printf("\n");
    multInt1 (81, 423);
    printf("\n");
    
    //2.a
    multInt2 (4, 4.0);
    printf("\n");
    multInt2 (81, 423);
    
    printf("\n");
    // 2.b  
    multInt3 (25000, 370, 0);
    printf("\n");
    multInt3 (81, 423, 0);
    
    
    
    
    return 0;
}