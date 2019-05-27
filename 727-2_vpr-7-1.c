#include <stdio.h>

int func (int * arr, int back, int up)
{
    int p = arr[up], k = (back - 1);

    for (int i = back; i <= up - 1; i++)
	{
        if (arr[i] <= p)
        {
            k++;
            int t = arr[k];
            arr[k] = arr[i];
            arr[i] = t;
        }
    } 
 int t = arr[k + 1];
    arr[k + 1] = arr[up];
    arr[up] = t;
    return (k + 1);
}

int quicksort(int *arr, int back, int up)
{
    if (back < up)
    {
        int t = func(arr, back, up);
        quicksort(arr, back, t - 1);
        quicksort(arr, t + 1, up);
    }
    return 0;
}

int sort(int *arr, int arr_len)
{
    
    quicksort(arr, 0, arr_len-1);

    printf("%d", arr[0]);
    for (int i = 1; i < arr_len; i++)
	{
        printf(" %d", arr[i]);
    }
    printf("\n");
       
	return 0;
}

int main (){
    int n = 0;
    int a[1000];
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
	{
        scanf("%d", &a[i]);
    }
    
    sort(a, n);
    
    return 0;
}
