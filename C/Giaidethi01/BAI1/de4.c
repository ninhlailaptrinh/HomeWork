/*Đề thi số 04:
Bài 1: Viết chương trình thực hiện những yêu cầu sau:
a) Nhập mảng n số nguyên ngẫu nhiên trong khoảng từ 0 đến 99, với n được nhập từ bàn phím; (2
điểm)
b) Tìm vị trí của số nguyên tố đầu tiên trong mảng; (2 điểm)
c) Tính tổng các số chia hết cho 4 có trong mảng và in ra giá trị tổng.(2 điểm)*/


#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void nhapMangNgauNhien(int arr[], int n)
{
	srand(time(NULL));
	for(int i = 0 ; i < n ; i++)
	{
		arr[i] = rand() % 100 ; 
	}
}

void XuatMangNgauNhien(int arr[] ,int n)
{
	for(int i = 0 ; i < n ; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int kiemTraSNT(int n)
{
	if( n < 2)
	{
		return 0;
	}
	if (n == 2) {
		return 1; 
	}
	if(n % 2 == 0)
	{
		return 0;
	}
	for (int i = 3;i <= sqrt(n) ; i+= 2) {
			if(n % i == 0)	
			{
				return 0;
			}
	}
	return 1; 
}

int tinhTong(int arr[] ,int n)
{
	int tong = 0;
	for(int i = 0 ; i < n ;i++)
	{
		if(arr[i] % 4 == 0)
		{
			tong = tong + arr[i] ;
		}
	}
	return tong;
}
void timSNT(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(kiemTraSNT(arr[i]))
        {
            printf("Vi tri so nguyen to dau tien la: %d\n", i);
            return; // Thoát ngay khi tìm thấy số nguyên tố đầu tiên
        }
    }
    printf("Khong co so nguyen to trong mang\n");
}

int main()
{ 
	int arr[100]; 
	int n ; 
	 
	printf("Nhap vao N : ");
	scanf("%d",&n);
	
	nhapMangNgauNhien(arr, n);
	XuatMangNgauNhien(arr, n);

	timSNT(arr, n);	


	int ketQua = tinhTong(arr, n);
	printf("Tong cua cac so chia het cho 4 la : %d ",ketQua);
}









