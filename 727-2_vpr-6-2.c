#include <stdio.h>


int sort(int * arr, int arr_len)
{

	int j;
for (int k = arr_len / 2; k > 0; k /= 2)
	{
		for (int i = k; i < arr_len; i++)
		{
			int t = arr[i];
			for (j = i; j >= k; j -= k)
			{
				if (t < arr[j - k]) {
					arr[j] = arr[j - k];
				}
				else {
					break;
				}
			}
			arr[j] = t;
		}
	}

	printf("%d", arr[0]);
	for (int i = 1; i < arr_len; i++) {
		printf(" %d", arr[i]);
	}
	printf("\n");

	return 0;
}

int main() {
	int n = 0;
	int a[1000];

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	sort(a, n);

	return 0;
}
