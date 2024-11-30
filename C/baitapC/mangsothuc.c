#include <stdio.h>
#define MAX 100
// nhap mang 
void nhap(float arr[] , int n )
{
	for(int i = 0 ; i < n ; i++)
	{
		printf("Phan tu thu %d cua mang la : ", i );
		scanf("%f",&arr[i]);
	}
}
//xuat mang 
void xuat(float arr[] , int n )
{
	printf("Mang vua nhap la : ");
	for(int  i = 0 ; i < n ; i++ )
	{
		printf("%.2f ",arr[i]);
	}
	printf("\n");
}

// tim max
float Max(float arr[] , int  n )
{
	 float max = arr[1];
	for(int  i = 1 ; i <= n ; i++)
	{
		if( arr[i] >= max)
		{
			max = arr[i] ; 
		}
	}	
	printf("Phan tu lon nhat trong mang tim duoc la %f . ",max);
	return max;
}

int main()
{
	int n ;
	float max ;
	printf("Nhap n : ");
	scanf("%d",&n);
	float arr[MAX] ; 

	nhap(arr,n);
	xuat(arr,n);
	Max(arr,n);
}
