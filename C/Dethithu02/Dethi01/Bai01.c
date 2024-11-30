#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void taoMang(int a[], int *n) {
    printf("Nhap so phan tu n = ");
    scanf("%d", n);
    
    srand(time(NULL));
    for(int i = 0; i < *n; i++) {
        a[i] = rand() % 81 - 30; // Sinh số ngẫu nhiên trong [-30,50]
    }
}

void xuatMang(int a[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void timMinMax(int a[], int n) {
    int min = a[0], max = a[0];
    for(int i = 1; i < n; i++) {
        if(a[i] < min) min = a[i];
        if(a[i] > max) max = a[i];
    }
    printf("Phan tu nho nhat: %d\n", min);
    printf("Phan tu lon nhat: %d\n", max);
}

void xoaPhanTuTrungMax(int a[], int *n) {
    int max = a[0];
    int viTriMax = 0;
    
    // Tìm max và vị trí đầu tiên của max
    for(int i = 1; i < *n; i++) {
        if(a[i] > max) {
            max = a[i];
            viTriMax = i;
        }
    }
    
    // Xóa các phần tử trùng với max (trừ phần tử đầu tiên)
    for(int i = *n - 1; i > viTriMax; i--) {
        if(a[i] == max) {
            for(int j = i; j < *n - 1; j++) {
                a[j] = a[j + 1];
            }
            (*n)--;
        }
    }
}

int main() {
    int a[MAX], n;
    
    // a) Tạo và xuất mảng
    taoMang(a, &n);
    printf("Mang sau khi tao:\n");
    xuatMang(a, n);
    
    // b) Tìm min, max
    timMinMax(a, n);
    
    // c) Xóa các phần tử trùng với max
    xoaPhanTuTrungMax(a, &n);
    printf("Mang sau khi xoa cac phan tu trung voi max:\n");
    xuatMang(a, n);
    
    return 0;
}
