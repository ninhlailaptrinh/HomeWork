#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void RamDom(int arr[] , int n){
	for(int i = 0 ; i < n ; i++){
		arr[i] = rand() % 100 ; 
	}
}

void xuat(int arr[] , int n){
	for(int i = 0 ; i < n ; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int kiemTraCapSoNhan(int a , int b , int c){
	if(b == 0) return 0;
	return (b * b == a * c);
}

void timCapSoNhan(int arr[] , int n){
	for(int i = 0 ; i < n - 2 ; i++){
		if(kiemTraCapSoNhan(arr[i] , arr[i+1] , arr[i+2])){
			printf("Vi tri %d va %d la cap so nhan\n",i,i+1);
		}
	}
}



int main(){
	int n ; 
	int arr[100];
	srand(time(NULL));
	printf("Nhap so phan tu cua mang: ");
	scanf_s("%d",&n);
	RamDom(arr,n);
	xuat(arr,n);
}













