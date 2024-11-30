#include <stdio.h>
// Bài 43: Tính tổng các giá trị lớn hơn giá trị đứng liền trước nó trong mảng 1 chiều các số thực
void Nhap(float arr[] , int n )
{
	for(int i = 0 ; i < n ; i++)
	{
		printf("Phan tu thu %d la : " ,i );
		scanf("%f",&arr[i]);
	}
}
void Xuat(float arr[] , int  n)
{
	printf("Mang vua nhap la : \n");
	for( int i = 0 ; i < n ; i++ )
	{
		printf(" %.1f ",arr[i]);
	}
}

float tinhTong(float arr[] , int n )
{
	float tong = 0 ;
	for(int i = 1 ; i < n   ; i++)
	{
		if( arr[i] > arr[i -1 ])
		{
			tong += arr[i] ; 
		}
	}
	return tong ; 	
}

int main()
{
	float arr[100] ; 
	int n ; 
	printf("Nhap vao N : ");
	scanf("%d",&n);

	Nhap(arr,n);
	Xuat(arr,n);
	
	float kq = tinhTong(arr,n);
	printf("Tong = %.1f ", kq );
}
