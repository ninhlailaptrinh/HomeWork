// Bài 40: Tính tổng các giá trị dương trong mảng 1 chiều các số thực   

#include <stdio.h>

void Nhap(float arr[] , int n )
{
	for(int i = 0 ; i < n ; i++)
	{
		printf("Phan tu %d la : " ,i);
		scanf("%f",&arr[i]);
	}
}

void Xuat(float arr[] , int n )
{
	printf("Mang vua nhap la : ");
	for(int i = 0 ; i < n ; i++)
	{
		printf(" %.1f ",arr[i]);
	}
	printf("\n");
}

float tinhTong(float arr[] , int n )
{
	int tong = 0  ; 
	for(int  i = 0 ; i < n ; i++)
	{
		if( arr[i] > 0 )
		{
		tong = tong + arr[i] ; 
		}
	}
	return tong;
}

int main() 
{
    int n ;// Số lượng phần tử trong mảng
	printf("Nhap vao phan tu N : ");
    scanf("%d",&n);
	float arr[100];
	Nhap(arr,n);
	Xuat(arr,n);
	float kq = tinhTong(arr,n);
	printf("Tong so duong cua mang la : %.1f " ,kq);
}
