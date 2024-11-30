#include <stdio.h>
#include <math.h>

int kiemTraNguyenTo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void sapXepTangDan(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n, arr[100];
    
    // Nhập số phần tử của dãy
    do {
        printf("Nhap so phan tu cua day (0 < n < 100): ");
        scanf("%d", &n);
    } while (n <= 0 || n >= 100);
    
    // Nhập dãy số
    printf("Nhap %d so nguyen:\n", n);
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    
    // Hiển thị dãy số
    printf("\nDay so vua nhap la: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    // Tính tổng các số nguyên tố
    int tongNguyenTo = 0;
    for (int i = 0; i < n; i++) {
        if (kiemTraNguyenTo(arr[i])) {
            tongNguyenTo += arr[i];
        }
    }
    printf("\nTong cac so nguyen to trong day: %d", tongNguyenTo);
    
    // Sắp xếp và hiển thị dãy
    sapXepTangDan(arr, n);
    printf("\nDay so sau khi sap xep tang dan: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
