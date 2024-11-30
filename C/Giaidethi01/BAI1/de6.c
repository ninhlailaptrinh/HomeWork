/*Bài 1: Viết chương trình thực hiện những yêu cầu sau:
a) Nhập mảng n số nguyên, với n được nhập từ bàn phím; (2 điểm)
b) Tìm các số chia hết cho 3 nhưng không chia hết cho 9; (2 điểm)
c) Sắp xếp lại để các số dương đứng đầu mảng.(2 điểm)*/


#include <stdio.h>

void nhap(int arr[],int n)
{
	for (int i = 0; i < n ; i++) {
		printf("Phan tu thu %d : ",i + 1);
		scanf("%d",&arr[i]);	
	}
}
void xuat(int arr[] , int n)
{
	for (int i = 0 ; i < n ; i++) {
		printf("%d ",arr[i]);	
	}
	printf("\n");
}

int tinhTong(int arr[], int n)
{
	int tong = 0;
	for (int i = 0; i < n ; i++) {
		if(arr[i] % 3 == 0 && arr[i] % 9 != 0)
		{
			tong = tong + arr[i];
		}
	}
	return tong;
}

void sapXep(int arr[] , int n)
{
	int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // Nếu arr[i] là số âm và arr[j] là số dương, hoán đổi
            if ((arr[i] <= 0 && arr[j] > 0)) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
	int n ; 
	int arr[100];

	printf("Nhap vao N :");
	scanf("%d",&n);
     
	nhap(arr, n);
	xuat(arr, n);

	int ketQua = tinhTong(arr, n);
	printf("Tong cua cac so chia het cho 3 nhung khong chia het cho 9 la : %d ",ketQua);
	
	sapXep(arr, n);
	printf("Mang sau khi sap xep (cac so duong dung dau): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

}




