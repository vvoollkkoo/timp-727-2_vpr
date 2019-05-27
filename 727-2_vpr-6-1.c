#include <stdio.h>


int sort(int *arr, int arr_len) 
{

	int k = 0;
	double factor = 1.2473309;

	double step = arr_len - 1;
while (step >= 1)
	{
		for (int i = 0; i + step < arr_len; ++i)
		{
			int t = i + step;
			if (arr[i] > arr[t])
			{
				int d = arr[i];
				arr[i] = arr[t];
				arr[t] = d;

				k++;
			}
		}
		step = step / factor;
	}

	for (int i = 0; i < arr_len - 1; i++)
	{
		int exchange = 0;
		for (int j = 0; j < arr_len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1]) {

				int d = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = d;

				exchange = 1;
				++k;
			}
		}

		if (exchange == 0) {
			break;
		}
	}

	printf("%d", arr[0]);
	for (int i = 1; i < arr_len; i++) {
		printf(" %d", arr[i]);
	}
	printf("\n");


	return k;
}

int main() 
{
	int a[1000];
	int n = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
 {
		scanf("%d", &a[i]);
	}

	sort(a, n);

	return 0;
}
