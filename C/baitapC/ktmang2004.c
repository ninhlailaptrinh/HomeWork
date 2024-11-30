#include <stdio.h>

//Bài 35: Viết hàm kiểm tra trong mảng các số nguyên có tồn tại giá trị chẵn nhỏ hơn 2004 hay không

int kiemTra(int arr[], int n );
void nhap( int arr[] , int n ); 
void xuat( int arr[] ,int n); 


int main()
{
	int arr[100] ; 
	int  n ; 
	printf("Nhap vao N : ");
	scanf("%d",&n);
	nhap(arr,n);
	xuat(arr,n);
	if (kiemTra(arr,n) == 1  )
	{
		printf("Trong mang co ton tai phan tu co gia tri chan nho hon 2004 oke ! "); 
	}	
	if ((kiemTra(arr,n) == 0)) {
		
		printf("uuuuu"); 
	} 

	return 0;	
}


// nhap mang :)) 
void nhap(int arr[] , int n )
{
	for(int  i  = 0 ; i < n ; i++)
	{
		printf("Phan tu %d la : ",i);
		scanf("%d",&arr[i]);
	}
}
// xuat 
void xuat( int arr[] ,int n)
{
	
	printf("Mang vua nhap la : ");
	for(int i = 0 ; i < n ; i++)
	{	
		printf(" %d \n",arr[i]);
	}
}

int kiemTra(int arr[], int n )
{
	for(int i = 1 ; i < n ; i++)
	{ 
		if(arr[i] % 2 == 0 && arr[i] < 2004)
		{
			printf("oke");
			return 1 ;
		}
	}
	return 0 ; 
}






