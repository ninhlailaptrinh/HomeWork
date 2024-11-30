#include <stdio.h>
#include <math.h>
#define MAX 100 

void Nhap(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);  // Thêm scanf để nhập giá trị
    }
}

void Xuat(int arr[], int n) {
    printf("\nMang vua nhap la: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int ktsoNguyenTo(int n) {
    if(n < 2) return 0;
    if(n == 2) return 1;
    
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Hàm đếm số lượng số nguyên tố
int demSoNguyenTo(int arr[], int n) {
    int dem = 0;
    for(int i = 0; i < n; i++) {
        if(ktsoNguyenTo(arr[i])) {
            dem++;
        }
    }
    return dem;
}

// Hàm tính trung bình cộng
float tinhTrungBinh(int arr[], int n) {
    int tong = 0;
    int dem = 0;
    
    for(int i = 0; i < n; i++) {
        if(ktsoNguyenTo(arr[i])) {
            printf("%d la so nguyen to\n", arr[i]);
            tong += arr[i];
            dem++;
        }
    }
    
    if(dem == 0) return 0;  // Tránh chia cho 0
    return (float)tong / dem;
}

int main() {
    int n;
    int arr[MAX];
    
    do {
        printf("Nhap vao N (0 < N <= 100): ");
        scanf("%d", &n);
    } while(n <= 0 || n > MAX);
    
    Nhap(arr, n);
    Xuat(arr, n);
    
    float tbc = tinhTrungBinh(arr, n);
    printf("\nTrung binh cong cac so nguyen to: %.2f\n", tbc);
    
    return 0;
}
