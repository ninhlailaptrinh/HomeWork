#include <stdio.h>

// Bài 39: Tính tổng các phần tử trong mảng

void Nhap(int arr[] , int n )
{
	for(int i = 0 ; i < n ; i++)
	{
		printf("Phan tu %d la : " ,i);
		scanf("%d",&arr[i]);
	}
}

void Xuat( int arr[] , int n )
{
	printf("Mang vua nhap la : ");
	for(int i = 0 ; i < n ; i++)
	{
		printf(" %d ",arr[i]);
	}
	printf("\n");
}

int tinhTong(int arr[] , int n )
{
	int tong = 0  ; 
	for(int  i = 0 ; i < n ; i++)
	{
		tong = tong + arr[i] ; 
		tong ++ ; 
	}
	return tong;
}

int main() 
{
    int n ;// Số lượng phần tử trong mảng
	printf("Nhap vao phan tu N : ");
    scanf("%d",&n);
	int arr[100];
	Nhap(arr,n);
	Xuat(arr,n);
	int kq = tinhTong(arr,n);
	printf("Tong cua mang la : %d " ,kq  - n );
}
