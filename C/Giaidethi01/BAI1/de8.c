/*a) Tạo ngẫu nhiên mảng một chiều n phần tử nguyên có giá trị chứa trong đoạn [-50, 500] và xuất
mảng. (2 điểm)
b) Hãy sắp xếp các phần tử trong mảng theo thứ tự giảm dần. In mảng sau khi sắp xếp. (2 điểm)
c) Hãy chèn một phần tử x vào trong mảng đã được sắp giảm dần mà vẫn giữ nguyên tính giảm
dần của nó. (2 điểm)*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void nhap(int arr[] , int n )
{
    srand(time(NULL));
	for (int i = 0; i < n ; i++) {
		arr[i] = rand() % 500 - 50;
	
	}
}
void xuat(int arr[] , int n )
{
	for (int i = 0; i < n ; i++) {
		printf("%d ", arr[i]);
	}
    printf("\n");
}

void sapXep(int arr[] , int n )
{
    for (int i = 0; i < n ; i++) {
        for (int j = i + 1; j < n ; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void chenPhanTu(int arr[] , int *n , int x )
{
    arr[*n] = x;
    (*n)++;
    sapXep(arr,*n);
}

int main()
{
    int n;
    int arr[100];
    printf("Nhap vao N : ");
    scanf("%d",&n);
    nhap(arr,n);
    xuat(arr,n);
    sapXep(arr,n);
    printf("Mang sau khi sap xep : ");
    xuat(arr,n);
    int x;
    printf("Nhap vao X : ");
    scanf("%d",&x);
    chenPhanTu(arr,&n,x);
    printf("Mang sau khi chen : ");
    xuat(arr,n);
}
