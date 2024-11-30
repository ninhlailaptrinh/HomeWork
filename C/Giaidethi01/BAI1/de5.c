/*Bài 1: Viết chương trình thực hiện những yêu cầu sau:
a) Nhập mảng n số nguyên ngẫu nhiên, với n được nhập từ bàn phím; (2 điểm)
b) Tìm vị trí của số nguyên tố cuối cùng trong mảng; (2 điểm)
c) Tính tổng các số lẻ chia hết cho 3 có trong mảng và in ra giá trị tổng.(2 điểm)*/

#include <math.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void nhap(int arr[] ,int n )
{
	srand(time(NULL));
	for (int i = 0; i < n ;i ++) {
		arr[i] = rand() % 100 ;
	}
}

void xuat(int arr[] ,int n)
{
	for (int i = 0; i < n ;i++) {
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int kiemTra(int n)
{
	if( n < 2)return 0;	
	if(n == 2)return 1;
	if (n % 2 == 0)return 0;
	
	for (int i = 3; i <= sqrt(n); i += 2) {
		if(n % i == 0)
		return 0;
	}
	return 1;
}

void timSNT(int arr[], int n)
{
    int viTriCuoi = -1;  // Khởi tạo vị trí là -1 (trường hợp không có số nguyên tố)
    
    // Duyệt từ đầu đến cuối mảng
    for(int i = 0; i < n; i++)
    {
        if(kiemTra(arr[i]))
        {
            viTriCuoi = i;  // Cập nhật vị trí mới nhất
        }
    }
    
    // Kiểm tra và in kết quả
    if(viTriCuoi != -1)
    {
        printf("Vi tri so nguyen to cuoi cung la: %d\n", viTriCuoi);
    }
    else
    {
        printf("Khong co so nguyen to trong mang\n");
    }
}
int main()
{
	int n ; 
	int arr[100];

	printf("Nhap vao N : ");
	scanf("%d",&n);

	nhap(arr, n);
	xuat(arr, n);

	timSNT(arr, n);

}













