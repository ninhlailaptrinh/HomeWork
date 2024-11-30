/*Bài 44: Tính tổng các giá trị lớn hơn trị tuyệt đối của giá trị đứng liền sau nó trong mảng 1 chiều
các số thực */
#include <stdio.h>
#include <math.h>

void Nhap(float arr[] , int n )
	{
		for(int i = 0 ; i < n ; i++)
		{
			printf("Phan tu thu %d la : ",i);
			scanf("%f",&arr[i]);
		}
	}

void Xuat(float arr[] , int n )
	{
		printf("Mang vua nhap la : ");
		for(int i = 0 ; i < n ; i++)
		{
			printf("%f ",arr[i]);
		}
	}

float tinhTong(float arr[] , int n )
{
	float tong = 0 ; 
	for(int i = 0 ; i < n-1 ; i++)
	{
		if( arr[i] > fabs(arr[i + 1 ]))
		{
			tong += arr[i] ;
			printf("%.2f lon hon |%.2f|\n", arr[i], arr[i+1]);
		}
	}
	return tong;
}
int main()
{
	int n ; float arr[100] ; 
	printf("Nhap vao N : ");
	scanf("%d",&n);
	Nhap(arr,n);
	Xuat(arr,n);
	float kq = tinhTong(arr,n);
	printf("Ket qua = %.2f",kq);
}



