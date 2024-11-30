#include <stdio.h>
#define MAX 100 

void Nhap(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i);
        scanf("%d", &arr[i]);
    }
}

void Xuat(int arr[], int n) {
    printf("Mang la: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int kiemTra(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        if(arr[i] < arr[i - 1]) {
            printf("Mang KHONG tang dan\n");
            return 0; 
        }
    }
    printf("Mang tang dan\n");
    return 1; 
}

void XoaK(int arr[], int *n, int k) {
    int i = 0;
    while(i < *n) {
        if(arr[i] == k) {
            // Dich trai cac phan tu 
            for(int j = i; j < *n - 1; j++) {
                arr[j] = arr[j + 1]; 
            }
            (*n)--;
            // Ko tang i vi phantu moi da dich vao vi tri i 
        } else {
            i++;
        }
    }
}

float tinhTong(int arr[] , int  n)
{
	float tong  = 0 ; 
	for(int i  = 0 ; i < n ; i++)
		{
			if(arr[i] > 0&& arr[i] % 3 == 0 || arr[i] % 4 == 0 )
			{
				tong += arr[i] ; 
			}
		}
	return tong; 
}

int main() {
    int n, k; 
    printf("Nhap vao N: ");
    scanf("%d", &n);
	int arr[MAX];

    Nhap(arr, n);
    Xuat(arr, n);
    
    kiemTra(arr, n);
    
    printf("Nhap vao phan tu k muon xoa: ");
    scanf("%d", &k);
    XoaK(arr, &n, k);
    
    printf("Mang sau khi xoa phan tu %d:\n", k);
    Xuat(arr, n);
	
	float ketQua = tinhTong(arr,n);

	printf("Tong cac so duong le la chco chu so cuoi la 3 : %.2f ", ketQua);
	return 0;
}
