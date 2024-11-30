#include <stdio.h>

void Nhap(int arr[] , int n )
{
	for(int i = 0 ; i < n ; i++)
	{
		printf("Phan tu %d la : " ,i);
		scanf("%d",&arr[i]);
	}
}

void Xuat(int arr[], int n )
{
	printf("Mang vua nhap la : \n");
	for(int i = 0 ; i < n ; i++)
	{
		printf(" %d \n",arr[i]);
	}
}

int kiemTra(int arr[] , int n )
{
	int tong = 0 ;
	for(int i = 0 ; i < n ; i++)
	{
		if( (arr[i] / 10) % 10 ==5)
		{
			tong+= arr[i];
			printf("%d co chu so hang chuc la 5\n", arr[i]);  // In ra số thỏa mãn
		}
	}
	return tong ; 
}

int main()
{
	int n ;
	printf("Nhap vao N : ");
	scanf("%d",&n);
	int arr[100] ;
	Nhap(arr,n);
	Xuat(arr,n);
	int kq = kiemTra(arr,n) ; 
	printf("Tong cua cac phan tu co hang chuc la 5 trong mang la : %d\n",kq);
}
