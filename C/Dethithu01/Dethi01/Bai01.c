#include <stdio.h>

void nhap(int arr[] , int n )
{
	for(int i = 0 ; i < n ; i++)
	{
		printf("Phan tu thu %d la : ", i);
		scanf("%d",&arr[i]); 
	}
}
void xuat(int arr[] , int n )
{
	printf("Mang vua nhap la : "); 
	for(int i = 0 ; i < n ; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int kiemTra(int arr[] , int n )
{ 
	for(int i = 1 ; i < n ; i++)
		{
			if (arr[i] < arr[i - 1]) 
			{
				printf("Mang khong tang dan ! ");
				return 0; 
			}
		}
	printf("Mang tang dan !"); 
	return 1 ; 
}

void xoaK(int arr[] , int *n , int k)
{
	int i = 0 ; 
	while ( i < *n )
	{
		if(arr[i] == k )
		{	
			for(int j = i ; j < *n - 1 ; j++)
			{
				arr[j] = arr[j + 1] ; 
			}
			(*n)-- ; 
		}
		else {
			i++ ; 
		}
	}
}
int main()
{
	int n, k ; 
	int arr[100] ; 
	do {
		printf("Nhap vao N (0 < N <= 100): ");
		scanf("%d", &n);
	} while (n <= 0 || n > 100);

	nhap(arr, n); 
	xuat(arr, n);
	
	kiemTra(arr, n);
	printf("\n"); 
	
	printf("Nhap vao phan tu K muon xoa: ");
	scanf("%d", &k);
	xoaK(arr, &n, k); 

	printf("Mang sau khi xoa phan tu %d:\n", k);
	xuat(arr, n);
	return 0;
}
