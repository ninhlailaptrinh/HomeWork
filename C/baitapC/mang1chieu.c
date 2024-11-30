#include <stdio.h>
#define MAX 100

void nhap(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("Phan tu thu %d cua mang la: ", i);
        scanf("%d", &arr[i]); // Sửa lỗi: thêm dấu & trước arr[i]
    }
}

void xuat(int arr[], int n) // Sửa lỗi: đổi vị trí tham số
{
    printf("Mang vua nhap la: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]); // Thêm khoảng trắng để dễ đọc
    }
}

int main()
{
    int n, arr[MAX];
    printf("Nhap vao N: ");
    scanf("%d", &n);
    nhap(arr, n);
    xuat(arr, n);
}
