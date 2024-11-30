#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void taoMangNgauNhien(int arr[], int n) {
    // Khởi tạo seed cho hàm rand()
    srand(time(NULL));
    
    for(int i = 0; i < n; i++) {
        // Công thức: rand() % (max - min + 1) + min
        arr[i] = rand() % (50 - (-30) + 1) + (-30);
    }
}

void xuatMang(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Nhap kich thuoc mang: ");
    scanf("%d", &n);
    
    int arr[100];
    
    printf("Mang ngau nhien tu -30 den 50 la:\n");
    taoMangNgauNhien(arr, n);
    xuatMang(arr, n);
    
    return 0;
}
