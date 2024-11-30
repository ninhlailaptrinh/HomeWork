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
    
    // Khởi tạo mảng động
    int *arr = (int*)malloc(n * sizeof(int));
    
    // Khởi tạo seed cho random
    srand(time(NULL));
    
    // a) Nhập mảng số nguyên ngẫu nhiên từ 0-99
    printf("Mang ngau nhien la: ");
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 100;  // Số ngẫu nhiên từ 0-99
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // b) Tìm vị trí số nguyên tố đầu tiên
    int viTriNguyenTo = -1;
    for(int i = 0; i < n; i++) {
        if(laSoNguyenTo(arr[i])) {
            viTriNguyenTo = i;
            break;
        }
    }
    
    if(viTriNguyenTo != -1) {
        printf("Vi tri so nguyen to dau tien la: %d\n", viTriNguyenTo);
    } else {
        printf("Khong co so nguyen to trong mang\n");
    }
    
    // c) Tính tổng các số chia hết cho 4
    int tong = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] % 4 == 0) {
            tong += arr[i];
        }
    }
    printf("Tong cac so chia het cho 4 la: %d\n", tong);
    
    // Giải phóng bộ nhớ
    free(arr);
    return 0;
}