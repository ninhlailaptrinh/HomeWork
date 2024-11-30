#include <stdio.h>
#define MAX 100 
void nhap(  int arr[] , int  *n);
void xuat(int arr[] , int n); 
int soNguyenTo( int n );
int demNguyenTo(int arr[], int n); 



int main()
{
	int arr[MAX] , n ; 
	nhap(arr,&n);
	xuat(arr,n);
	int ketQua = demNguyenTo(arr, n);
    printf("So luong so nguyen to nho hon 100 trong mang la: %d", ketQua);
}

void nhap( int arr[] , int *n)
{

	printf("Nhap so luong phan tu N : ");
	scanf("%d", n);  // Thêm dòng này để nhập n
	for(int i = 0 ; i < *n ; i++) 
	{
		printf("\n");
		printf("Phan tu thu %d la : ",i+1);
		scanf("%d",&arr[i]); 
	}
}
void xuat(int arr[] , int n )
{
	printf("Mang vua nhap la : ");
	for(int i = 0 ; i < n ; i++)
	{
		printf(" %d \n",arr[i]); 
	}
}

int soNguyenTo(int n)
{
    if(n <= 1) return 0;  // Gộp điều kiện và bỏ printf
    if(n <= 3) return 1;
    if(n % 2 == 0) return 0;
    
    for(int i = 3; i * i <= n; i += 2)
    {
        if(n % i == 0) return 0;
    }
    return 1;
}

int demNguyenTo(int arr[] , int n)
{
	
	int count = 0 ; 		
	for(int i = 0 ; i < n  ;  i ++)
	{
		if( arr[i] < 100 && soNguyenTo(arr[i]))
		{
			count ++ ; 	
		}
	}
	return count;
}
