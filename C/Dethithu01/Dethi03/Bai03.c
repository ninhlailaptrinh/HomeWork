#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SO_LUONG 5

// Hàm tìm số nhỏ nhất trong mảng số nguyên
int timMinNguyen(int arr[], int n) {
    int min = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Hàm tìm số nhỏ nhất trong mảng số thực
float timMinThuc(float arr[], int n) {
    float min = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main() {
    FILE *fInt, *fReal;
    int soNguyen[SO_LUONG];
    float soThuc[SO_LUONG];
    
    // Khởi tạo bộ sinh số ngẫu nhiên
    srand(time(NULL));
    
    // Ghi file số nguyên
    fInt = fopen("INTEGER.DAT", "w");
    if(fInt == NULL) {
        printf("Khong the mo file INTEGER.DAT\n");
        return 1;
    }
    
    printf("Cac so nguyen ngau nhien:\n");
    for(int i = 0; i < SO_LUONG; i++) {
        soNguyen[i] = rand() % 100; // Số ngẫu nhiên từ 0-99
        fprintf(fInt, "%d\n", soNguyen[i]);
        printf("%d ", soNguyen[i]);
    }
    fclose(fInt);
    
    // Ghi file số thực
    fReal = fopen("REAL.DAT", "w");
    if(fReal == NULL) {
        printf("Khong the mo file REAL.DAT\n");
        return 1;
    }
    
    printf("\nCac so thuc ngau nhien:\n");
    for(int i = 0; i < SO_LUONG; i++) {
        soThuc[i] = (float)rand()/RAND_MAX * 100; // Số thực ngẫu nhiên từ 0-100
        fprintf(fReal, "%.2f\n", soThuc[i]);
        printf("%.2f ", soThuc[i]);
    }
    fclose(fReal);
    
    // Đọc và tìm số nhỏ nhất
    printf("\n\nSo nguyen nho nhat: %d\n", timMinNguyen(soNguyen, SO_LUONG));
    printf("So thuc nho nhat: %.2f\n", timMinThuc(soThuc, SO_LUONG));
    
    return 0;
}
