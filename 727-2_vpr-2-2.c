#include<stdio.h>
 int main()
 {
    int n, i, x;
    scanf("%d\n", &n);
    int a[n];
    x=0;
    for(i = 1 ; i < n+1; i++)
    { 
        scanf("%d", &a[i]);
    }
    for(i = 1 ; i < n+1; i++)
    {
        if ((i %2)!=0)
        x=x+a[i]*a[i];
    }
    printf ("%d\n", x);
    return 0;
}
