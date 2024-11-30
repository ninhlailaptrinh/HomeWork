#include <stdio.h>


void Nhap(int arr[],int n )
{
	for (int i = 0; i < n ; i++) {
		{
			printf("Phan tu thu %d : ",i);
			scanf("%d",&arr[i]);
		}
	}
	printf("\n");
}

void Xuat(int arr[],int n )
{
	printf("Mang vua nhap la : \n");
	for (int i = 0; i < n ; i++) {
		printf("%d ",arr[i]);
	}
}

void kiemTra(int arr[],int n)
{
	for(int i = 0 ;i < n - 2 ; i++)
	{	
		if (arr[i] * arr[i+2] == arr[i+1] * arr[i+1]) {
            printf("Các phần tử tại vị trí %d, %d, %d tạo thành cấp số nhân: %d, %d, %d\n", 
                   i, i+1, i+2, arr[i], arr[i+1], arr[i+2]);
        }
	}
}

// Hàm kiểm tra xem một số có phải là số chính phương không
int la_so_chinh_phuong(int num) {
    if (num < 0) return 0; // Số âm không thể là số chính phương
    for (int i = 0; i * i <= num; i++) {
        if (i * i == num) {
            return 1;
        }
    }
    return 0;
}

// Hàm tính tổng các số chính phương trong mảng
int tong_so_chinh_phuong(int arr[], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        if (la_so_chinh_phuong(arr[i])) {
            tong += arr[i];
        }
    }
    return tong;
}


int main()
{
	int arr[100];
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("Nhap vao N : ");
	scanf("%d",&n);

	Nhap(arr,n);
	Xuat(arr,n);

	kiemTra(arr, n);

    int tong = tong_so_chinh_phuong(arr, n);
    printf("Tổng các số chính phương trong mảng là: %d\n", tong);
    return 0;
	
}
