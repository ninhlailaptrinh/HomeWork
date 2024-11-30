#include <stdio.h>
#include <math.h>

void nhap(int arr[],int n)
{
	for (int i = 0; i < n ; i++) {
		printf("Phan tu thu %d : ",i);
		scanf("%d",&arr[i]);			
	}
}

void xuat(int arr[],int n )
{
	printf("Mang vua nhap la : ");
	for(int i = 0 ;i < n ; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int kiemTra(int arr[] ,int n )
{
	for(int i = 1 ; i < n ; i++)
	{
		if(arr[i] < arr[i - 1])
		{
			printf("Khong phai mang tang dan !");
			return 0;
		}
	}
	printf("\nMang vua nhap la mang tang dan !");
	return 1;
}

void xoaK(int arr[], int *n , int k )
{
	int i = 0;
	while (i < *n )
	{
		if(arr[i] == k )
		{
			for (int j = i ; j  < *n - 1; j++) {
				arr[j] = arr[j + 1] ;
			}
			(*n)--;
		}
		else {
			i++;
		}
	}	
}

int tong(int arr[] , int n )
{
	int tong = 0; 

	for(int i = 0 ; i < n ; i++)
	{
		tong = tong + arr[i] ; 
	}
	return tong;
}

int kiemTraNT(int n)
	{
		if(n < 2 )
		{
			return 0;
		}

		for(int i = 2 ; i < sqrt(n);i++)
		{
			if(n % i == 0)
			{
				return 0;
			}
		}
		return 1 ; 
	}
void duyetSNT(int arr[], int n)
{
	for(int i = 0 ; i < n ; i++)
	{
		if(kiemTraNT(arr[i]))
		{
			printf("%d",arr[i]);
		}
	}
	printf("\n");
}
int main()
{
	int n , k ; 
	int arr[100];
	printf("\nNhap vao N : ");
	scanf("%d",&n);
	nhap(arr,n);
	xuat(arr,n);
	kiemTra(arr,n);
	printf("\nNhap vao phan tu K muon xoa : ");
	scanf("%d",&k);
	xoaK(arr,&n,k);

	printf("Mang sau khi xoa phan tu K %d: \n",k);
	xuat(arr,n);
	tong(arr,n);
	int kq1 = tong(arr,n);
	printf("Tong cua mang vua nhap la : %d\n",kq1);
	printf("\n");	
	duyetSNT(arr, n);
	return 0;
}
