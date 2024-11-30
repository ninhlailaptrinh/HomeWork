#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void taoMangNgauNhien(int arr[], int n) {
    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 551 - 50; // Sinh số ngẫu nhiên trong [-50, 500]
    }
}

void xuatMang(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sapXepGiamDan(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void chenPhanTu(int arr[], int *n, int x) {
    int i = 0;
    while(i < *n && arr[i] > x) {
        i++;
    }
    for(int j = *n; j > i; j--) {
        arr[j] = arr[j-1];
    }
    arr[i] = x;
    (*n)++;
}

int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    
    int arr[100];
    
    // a) Tạo và xuất mảng ngẫu nhiên
    printf("\nMang ngau nhien:\n");
    taoMangNgauNhien(arr, n);
    xuatMang(arr, n);
    
    // b) Sắp xếp giảm dần
    printf("\nMang sau khi sap xep giam dan:\n");
    sapXepGiamDan(arr, n);
    xuatMang(arr, n);
    
    // c) Chèn phần tử x
    int x;
    printf("\nNhap gia tri x can chen: ");
    scanf("%d", &x);
    chenPhanTu(arr, &n, x);
    printf("Mang sau khi chen %d:\n", x);
    xuatMang(arr, n);
    
    return 0;
}
