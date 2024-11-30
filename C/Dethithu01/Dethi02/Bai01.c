#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Hàm kiểm tra số nguyên tố
int laSoNguyenTo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    
    // a) Tạo mảng ngẫu nhiên
    int arr[100];
    srand(time(NULL));
    printf("Mang ngau nhien: ");
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Giới hạn số ngẫu nhiên từ 0-99
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // b) Kiểm tra 3 phần tử liên tiếp tạo thành cấp số cộng
    int timThay = 0;
    for(int i = 0; i < n-2; i++) {
        if(arr[i+1] - arr[i] == arr[i+2] - arr[i+1]) {
            printf("Tim thay cap so cong tai vi tri: %d, %d, %d\n", i, i+1, i+2);
            printf("Cac so: %d, %d, %d\n", arr[i], arr[i+1], arr[i+2]);
            timThay = 1;
        }
    }
    if(!timThay) {
        printf("Khong tim thay 3 so lien tiep tao thanh cap so cong\n");
    }
    
    // c) Tính tổng các số nguyên tố
    int tong = 0;
    for(int i = 0; i < n; i++) {
        if(laSoNguyenTo(arr[i])) {
            tong += arr[i];
        }
    }
    printf("Tong cac so nguyen to trong mang: %d\n", tong);
    
    return 0;
}
