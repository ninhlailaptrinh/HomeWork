#include <stdio.h>
	
void Nhap(int arr[] , int n )
{
	for(int i = 0 ; i < n ; i++)
	{
		printf("Phan tu %d la : " ,i);
		scanf("%d",&arr[i]);
	}
}

void Xuat( int arr[] , int n )
{
	printf("Mang vua nhap la : ");
	for(int i = 0 ; i < n ; i++)
	{
		printf(" %d ",arr[i]);
	}
	printf("\n");
}

int TimViTriMin(int arr[], int n)
{
    int min = arr[0];
    int viTri = 0;
    for(int i = 1; i < n; i++)
    {
        if(arr[i] < min)
        {
            min = arr[i];
            viTri = i;
        }
    }
    return viTri;  // Trả về vị trí của phần tử nhỏ nhất
}

int main() 
{
    int n ;// Số lượng phần tử trong mảng
	printf("Nhap vao phan tu N : ");
    scanf("%d",&n);
	int arr[100];
	Nhap(arr,n);
	Xuat(arr,n); 
	int viTri = TimViTriMin(arr, n) ;
    printf("Gia tri nho nhat trong mang la %d, tai vi tri %d\n", arr[viTri], viTri + 1);
	return 0; 
}
