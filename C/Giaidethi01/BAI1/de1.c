#include <stdio.h>

void nhap(int arr[], int n)
{
	for(int i = 0 ; i  < n ; i++)
	{
		printf("Phan tu thu %d : ",i + 1);
		scanf("%d",&arr[i]);
	}
	printf("\n");
}

void xuat(int arr[] ,int n )
{
	for (int i = 0; i < n; i++) {
	
		printf("%d ",arr[i]);
	}
}

int kiemTra(int arr[], int n )
{
	for(int i = 1 ; i < n ; i++)
	{
		if(arr[i] < arr[i - 1])
		{
			printf("Khong phai mang tang dan !\n");
			return 0;
		}
	}
	printf("Mang vua nhap la mang tang dan !\n");
	return 1;
}

void xoaK(int arr[] , int *n , int k)
{
	int i = 0 ; 
	while(i < *n)
	{
		if (arr[i] == k ) {
			for (int j = i ; j < *n - 1; j++) {
				arr[j] = arr[j + 1] ; 	
			}	
			(*n) -- ;
		}
		else {
		i++;
		}
	}
}

int main()
{
	int n , k ; 
	int arr[100];

	printf("Nhap vao N :");
	scanf("%d",&n);

	nhap(arr, n);
	xuat(arr, n);

	kiemTra(arr,n);

	printf("Nhap vao phan tu K : ");
	scanf("%d",&k);
	xoaK(arr , &n , k);

	printf("Mang sau khi xoa phan tu %d : \n",k);
	xuat(arr, n);
}
