// Bài 37: Viết hàm tính tổng các giá trị âm trong mảng 1 chiều các số thực 
#include <stdio.h>
// kiem tra xem n < 0 =>> true (tinhtong) flase => bo qua .
void nhap(float arr[] , int n )
{
	for(int i = 0 ; i < n ;i++ )
	{
		printf("Phan tu thu %d la : ", i);
		scanf("%f",&arr[i]);
	}
}
void xuat(float arr[] , int  n )
{
	printf("Mang vua nhap la : ");
	for(int  i = 0 ; i <n ; i++ )
	{
		printf("%.2f ",arr[i] );
	}
}

float tinhTong( float arr[], int  n )
{
	int tong = 0; 
	for(int i = 0 ; i < n ; i++)
	{
		if( arr[i] < 0 )
		{
			tong += arr[i]; 
		}
	}
	return tong;
}
int main()
{
	int n ; 
	float arr[100];
	printf("Nhap vao N : ");
	scanf("%d",&n);
	nhap(arr,n);
	xuat(arr,n);
	printf("\n");
	int ketQua = tinhTong(arr, n);  // Lưu kết quả từ hàm tinhTong
    printf("Tong cac so am trong mang la: %d\n", ketQua);
}
