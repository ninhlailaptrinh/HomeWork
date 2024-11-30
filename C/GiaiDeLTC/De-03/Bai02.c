#include <stdio.h> 

void nhap(int arr[],int n )
{
	for (int i = 0; i < n ; i++) {
		printf("Phan tu thu %d :",i);
		scanf("%d",&arr[i]);
	}
}

void xuat(int arr[],int n )
{
	printf("Mang la :");
	for (int i = 0; i < n ; i++) {
	printf("%d ",arr[i]);
	}
	printf("\n");
}
void xoak(int arr[],int *n,int k )
{
	int i = 0;
	while(i < *n)
	{
		if(arr[i] == k)
		{
			for (int j = i; i < *n - 1 ; j++) {
				arr[j] = arr[j + 1]	;
			}
			(*n)--;
		}
		else {
		i++;
		}
	}
}
int main()
{
	int n ,k;
	int arr[100];
	printf("Nhap vao N : ");
	scanf("%d",&n);

	nhap(arr,n);
	xuat(arr,n);
	
	printf("Nhap vao K : ");
	scanf("%d",&k);
	xoak(arr,&n,k);

	printf("Mang sau khi xoa phan tu %d la :",k);
	xuat(arr, n);
	return 0;
}
