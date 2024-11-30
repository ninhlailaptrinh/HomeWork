#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void MangRand(int arr[], int n)
{
	srand(time(NULL));
	for(int i = 0 ; i < n ; i++)
	{
		 arr[i] = rand() % 81 - 30 ; 
	}
}

void xuat(int arr[], int n)
{
	printf("\nMang ngau nhien tu -30 den 50 la:\n");
	for(int i = 0; i < n; i++)
	{
		printf("%4d", arr[i]);
	}
	printf("\n");
}

void minMax(int arr[], int n, int *min, int *max) 
{
	*min = *max = arr[0];
	for(int i = 1; i < n; i++)
	{
		if(arr[i] < *min) *min = arr[i];
		if(arr[i] > *max) *max = arr[i];
	}
	printf("\nMin: %d\nMax: %d\n", *min, *max);
}


void xoa(int arr[], int *n, int max)
{
	int firstMax = 0;
	for(int i = 0; i < *n; i++)
	{
		if(arr[i] == max)
		{
			if(firstMax == 0)
			{
				firstMax = 1;
				continue;
			}
			for(int j = i; j < *n - 1; j++)
			{
				arr[j] = arr[j + 1];
			}
			(*n)--;
			i--;
		}
	}
	printf("\nMang sau khi xoa:\n");
	for(int i = 0; i < *n; i++)
	{
		printf("%4d", arr[i]);
	}
}

int main()
{
	int arr[100] ; 
	int n ;
	int min , max ;
	
	printf("Nhap N: ");
	scanf("%d", &n);
	
	MangRand(arr, n);
	xuat(arr, n);
	minMax(arr, n, &min, &max);
	xoa(arr, &n, max);
	printf("\n");
	return 0;
}
