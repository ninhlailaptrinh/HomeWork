#include <stdio.h>
#include <math.h>
#include <strings.h>

void nhap(int arr[],int n )
{
	for (int i = 0; i < n ; i++) {
		printf("Phan tu thu %d : ",i);
		scanf("%d",&arr[i]);
	}
	printf("\n");
}
void xuat(int arr[],int n)
{
	printf("Mang la : ");
	for(int i = 0 ; i < n ; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int kiemTra(int arr[],int n)
	{
		for(int i = 1 ; i < n ; i++)
		{
			if (arr[i] < arr[i - 1]) {
			printf("Khong phai mang tang dan\n");
				return 0;
			}
		}
		printf("Mang tang dan !\n");
		return 1;
	}
void xoaK(int arr[],int *n,int k)
{
	int i = 0;
	while ( i < *n ) {
		if(arr[i] == k )
		{
			for (int j = i ; j < *n - 1 ; j++) {
				arr[j]	= arr[j + 1 ]  ; 
			}
			(*n)--;
		}
		else {
		i++;
		}
	}
}
int soNTo(int n)
{
	if (n < 2) {
		return 0;
	}
	if (n == 2) {
		return 1;	
	}
	if (n % 2 == 0) {
		return 0;	
	}
	for (int i = 3 ;i <= sqrt(n);i+= 2) {
			if (n % 2 == 0) {
				return 0;	
			}	
	}
	return 1;
}
int tinhTong(int arr[],int n)
{
	int tong = 0 ; 
	for(int i = 0  ; i < n ; i++)
	{
		if (soNTo(arr[i] == 1)) {
			tong = tong + arr[i];	
		}
	}
	return tong ; 
}
void inSoNTo(int arr[],int  n )
{
	for (int i = 0 ;i < n ; i++) {
			if (soNTo(arr[i] == 1 )) {
			}	
	}
	xuat(arr,n);
}
int main()
{
	int n , k ; 
	int arr[100];
	printf("nhap N : ");
	scanf("%d",&n);
	nhap(arr,n);
	xuat(arr,n);
	
	kiemTra(arr,n);


	printf("Nhap vao K :\n");
	scanf("%d",&k);
	xoaK(arr, &n, k);
	printf("Mang sau khi xoa K la : \n");
	xuat(arr, n);

	int ketQua = tinhTong(arr,n);
	printf("Tong cua mang so nguyen to la : %d ",ketQua);
}
