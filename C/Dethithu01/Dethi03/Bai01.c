#include <stdio.h>
#include <math.h>

// Hàm kiểm tra số chính phương
int isPerfectSquare(int n) {
    int sqrt_n = sqrt(n);
    return sqrt_n * sqrt_n == n;
}

// Hàm kiểm tra 3 số liên tiếp có tạo thành cấp số nhân không
int checkGeometricSequence(int a, int b, int c) {
    if (b * b == a * c) {
        return 1;
    }
    return 0;
}

int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    
    int arr[100];
    
    // a) Nhập mảng
    printf("Nhap cac phan tu cua mang:\n");
    for(int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    
    // b) Kiểm tra cấp số nhân
    printf("\nCac bo 3 so lien tiep tao thanh cap so nhan:\n");
    int found = 0;
    for(int i = 0; i < n-2; i++) {
        if(checkGeometricSequence(arr[i], arr[i+1], arr[i+2])) {
            printf("Vi tri: %d, %d, %d\n", i, i+1, i+2);
            found = 1;
        }
    }
    if(!found) {
        printf("Khong tim thay bo 3 so lien tiep tao thanh cap so nhan\n");
    }
    
    // c) Tính tổng các số chính phương
    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(isPerfectSquare(arr[i])) {
            sum += arr[i];
        }
    }
    printf("\nTong cac so chinh phuong trong mang: %d\n", sum);
    
    return 0;
}
