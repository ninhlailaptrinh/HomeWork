#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ramDom(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 100; 
    }
}

void xuat(int arr[], int n) {
    printf("a) Mang %d so nguyen ngau nhien la:\n", n);
    for(int i = 0; i < n; i++) {
        if(i % 10 == 0 && i != 0) printf("\n");
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void timCapSoCong(int arr[], int n) {
    printf("\nb) Kiem tra cap so cong:\n");
    int timThay = 0; 
    for(int i = 0; i < n - 2; i++) {
        int d = arr[i+1] - arr[i];
        if(arr[i+2] - arr[i+1] == d) {
            printf("- Tim thay 3 phan tu lien tiep tai vi tri: %d, %d, %d\n", i, i+1, i+2);
            printf("  Gia tri cac phan tu: %d, %d, %d\n", arr[i], arr[i+1], arr[i+2]);
            timThay = 1;       
        }
    }
    if(!timThay) {
        printf("Khong tim thay 3 phan tu lien tiep tao thanh cap so cong!\n");
    }
}

int laSoNguyenTo(int n) {
    if(n < 2) return 0;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return 0;
    }
    return 1;
}

void tinhTongNguyenTo(int arr[], int n) {
    printf("\nc) Tinh tong cac so nguyen to:\n");
    int tong = 0;
    printf("Cac so nguyen to trong mang: ");
    for(int i = 0; i < n; i++) {
        if(laSoNguyenTo(arr[i])) {
            printf("%d ", arr[i]);
            tong += arr[i];
        }
    }
    printf("\nTong cac so nguyen to = %d\n", tong);
}

int main() {
    int n;
    int arr[100]; 
    srand(time(NULL));
  
    printf("Nhap so phan tu cua mang (n): ");
    scanf("%d", &n);
    
    if(n <= 0 || n > 100) {
        printf("So phan tu khong hop le!");
        return 1;
    }
    
    ramDom(arr, n);
    xuat(arr, n);
    timCapSoCong(arr, n);
    tinhTongNguyenTo(arr, n);
    
    return 0;
}



