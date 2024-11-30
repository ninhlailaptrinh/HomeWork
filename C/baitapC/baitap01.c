#include <stdio.h>
#define MAX 100

void Nhap(int arr[],int n)
{
	for(int i = 0 ; i < n ; i++)
	{
		printf("Phan tu thu %d la : ",i);
		scanf("%d",&arr[i]);
	}
	printf("\n");
}

void Xuat(int arr[] , int n )
{
	printf("Mang vua nhap la : \n");
	for(int i =  0 ; i < n ; i++)
		{
			printf(" %d ",arr[i]);
		}
	printf("\n");
}

int kiemTra(int arr[] , int n )
{
	for(int i = 1 ; i < n ; i++ )
	{
		if(arr[i] < arr[i - 1 ])
		{
			printf("Khong phai mang tang dan .\n");
			return 0 ; 
		}
	}
	printf("Mang tang dan .\n");
	return 1 ; 
}

void xoaK(int arr[],int *n , int k)
{
	int i = 0 ; 
	while ( i < *n) {
		if(arr[i] == k )
		{
			for(int j = i ; j < *n - 1 ; j++)
			{
				arr[j] = (arr[j] + 1 ) ; 
			}
			(*n)--;
		}
		else {
			i++;
		}
	}
}

int main()
{
	int n , k ; 
	printf("Nhap vao N : ");
	scanf("%d",&n);
	int arr[MAX] ;

	Nhap(arr,n);
	Xuat(arr,n);

	kiemTra(arr,n);

	printf("Nhap vao phan tu K muon xoa : ");
	scanf("%d",&k);	
	xoaK(arr,&n,k);

	printf("Mang sau khi xoa %d la : \n" , k );
	Xuat(arr,n);

}
