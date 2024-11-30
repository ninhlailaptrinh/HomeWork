// Bài 38: Viết hàm sắp xếp mảng 1 chiều các số thực tăng dần


#include <features.h>
#include <stdio.h>


void Nhap(float arr[] , int n )
{
	for(int i = 0 ; i < n ; i++)
	{
		printf("Phan tu %d la : " ,i);
		scanf("%f",&arr[i]);
	}
}

void Xuat( float arr[] , int n )
{
	printf("Mang vua nhap la : ");
	for(int i = 0 ; i < n ; i++)
	{
		printf(" %.2f ",arr[i]);
	}
	printf("\n");
}

void sapXep(float arr[], int n) {
    float temp;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    // Sửa cách in mảng
    printf("Mang sau khi sap xep: ");
    for(int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

int main()
{
	int n ;// Số lượng phần tử trong mảng
	printf("Nhap vao phan tu N : ");
    scanf("%d",&n);
	float arr[100];
	Nhap(arr,n);
	Xuat(arr,n);
	printf("\n");
	sapXep(arr,n);
	return 0;
}
