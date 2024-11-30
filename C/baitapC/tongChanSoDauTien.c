#include <stdio.h>

void Nhap(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);  // Đổi i thành i+1 cho người dùng dễ hiểu
        scanf("%d", &arr[i]);
    }
}

void Xuat(int arr[], int n) {
    printf("\nMang vua nhap la: ");  // Thay đổi cách in cho đẹp hơn
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int layCSdau(int n) {
    if(n < 0) {
        n = -n;
    }
    while(n >= 10) {
        n = n / 10;
    }
    return n;
}

int tinhTong(int arr[], int n) {
    int tong = 0;
    printf("\nCac so co chu so dau tien chan:\n");  // Thêm tiêu đề
    for(int i = 0; i < n; i++) {
        int chuSoDau = layCSdau(arr[i]);
        if(chuSoDau % 2 == 0) {
            tong += arr[i];
            printf("%d (chu so dau: %d)\n", arr[i], chuSoDau);
        }
    }
    return tong;
}

int main() {
    int n;
    do {
        printf("Nhap so phan tu N (0 < N <= 100): ");
        scanf("%d", &n);
    } while(n <= 0 || n > 100);  // Thêm kiểm tra điều kiện nhập n
    
    int arr[100];
    Nhap(arr, n);
    Xuat(arr, n);
    
    int ketQua = tinhTong(arr, n);
    printf("\nTong cac so co chu so dau chan: %d\n", ketQua);
    
    return 0;
}
