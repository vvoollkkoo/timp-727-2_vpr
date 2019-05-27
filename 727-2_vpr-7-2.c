#include <stdio.h>
#include <stdlib.h>

int heapsort(int *arr, int root, int size)
{
	int max;
	int done = 0;
	while ((root * 2 <= size) && (!done))
	{
if (root * 2 == size) {
			max = root * 2;
		}
		else if (arr[root * 2] > arr[root * 2 + 1]) 
		{
			max = root * 2;
		}
		else {
			max = root * 2 + 1;
		}
		if (arr[root] < arr[max])
		{
			int temp =arr[root];
			arr[root] = arr[max];
			arr[max] = temp;
			root = max;
		}
		else
			done = 1;
	}
}

int sort(int *arr, int array_size)
{
	for (int i = (array_size / 2) - 1; i >= 0; i--)
		heapsort(arr, i, array_size);
	for (int i = array_size - 1; i >= 1; i--)
	{
		int temp = arr[0];
		arr[0] =arr[i];
		arr[i] = temp;
		heapsort(arr, 0, i - 1);
	}
}
int main()
{
	int n, i;
	scanf("%d", &n);
	int m[n];

	for (i = 0; i < n; i++) 
	{
		scanf("%d", &m[i]);
	}
	sort(m, n);

	for (i = 0; i < n - 1; i++)
	{
		printf("%d ", m[i]);
	}
	printf("%d\n", m[n - 1]);
	return 0;
}
