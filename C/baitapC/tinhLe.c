#include <stdio.h>

void Nhap(int arr[] , int n )
{
	for(int i = 0 ; i < n ; i++)
	{
		printf("Phan tu %d la : " ,i);
		scanf("%d",&arr[i]);
	}
}

void Xuat(int arr[] , int n )
{
	printf("Mang vua nhap la : ");
	for(int i = 0 ; i < n ; i++)
	{
		printf(" %d ",arr[i]);
	}
	printf("\n");
}

int kiemTraLe(int arr[], int n) {
	int tong = 0  ; 
	printf("\nCac so co chu so dau tien la so le:\n");
    for(int i = 0; i < n; i++) {
        int temp = arr[i];  // Lưu giá trị để xử lý
        
        // Tìm chữ số đầu tiên bằng cách chia dần cho 10
        while(temp >= 10) {
            temp = temp / 10;
        }
        
        // Kiểm tra số lẻ và in kết quả
        if(temp % 2 != 0) { 
			tong += arr[i] ; 
        }
    }
	return tong ; 
}
int main() 
{
    int n ;// Số lượng phần tử trong mảng
	printf("Nhap vao phan tu N : ");
    scanf("%d",&n);
	int arr[100];
	Nhap(arr,n);
	Xuat(arr,n);
	int kq = kiemTraLe(arr,n);
	printf("Tong so duong cua mang la : %d " ,kq);
	return 0; 
}
