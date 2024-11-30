#include <stdio.h>

void nhapMang(int a[], int *n) {
    do {
        printf("Nhap so phan tu n = ");
        scanf("%d", n);
    } while (*n <= 0);
    
    for(int i = 0; i < *n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}

void timSoChiaHet(int a[], int n) {
    printf("\nCac so chia het cho 3 nhung khong chia het cho 9 la: ");
    for(int i = 0; i < n; i++) {
        if(a[i] % 3 == 0 && a[i] % 9 != 0) {
            printf("%d ", a[i]);
        }
    }
}

void sapXepSoDuong(int a[], int n) {
    int b[100], k = 0;
    
    // Đưa các số dương vào mảng tạm
    for(int i = 0; i < n; i++) {
        if(a[i] > 0) {
            b[k++] = a[i];
        }
    }
    
    // Đưa các số còn lại vào mảng tạm
    for(int i = 0; i < n; i++) {
        if(a[i] <= 0) {
            b[k++] = a[i];
        }
    }
    
    // Copy mảng tạm về mảng gốc
    for(int i = 0; i < n; i++) {
        a[i] = b[i];
    }
}

void xuatMang(int a[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

int main() {
    int a[100], n;
    
    // Câu a: Nhập mảng
    nhapMang(a, &n);
    
    // Câu b: Tìm số chia hết cho 3 nhưng không chia hết cho 9
    timSoChiaHet(a, n);
    
    // Câu c: Sắp xếp số dương lên đầu
    printf("\nMang sau khi sap xep so duong len dau: ");
    sapXepSoDuong(a, n);
    xuatMang(a, n);
    
    return 0;
}
