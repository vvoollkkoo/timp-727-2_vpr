#include<stdio.h>
 int main()
 {
    int n, i, x;
    scanf("%d", &n);
    int a[n];
    x=0;
    for(i = 0 ; i < n; i++)
    { 
        scanf("%d", &a[i]);
    }
    for(i = 0 ; i < n; i++)
    {
         if(a[i] >= 0)  
         x=x + 1;
    }
    printf("%d", x);
    return 0;
}

