#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Khởi tạo seed cho số ngẫu nhiên
    srand(time(NULL));
    
    // Ghi file INTEGER.DAT
    FILE *intFile = fopen("INTEGER.DAT", "w");
    if(intFile == NULL) {
        printf("Khong the mo file INTEGER.DAT\n");
        return 1;
    }
    
    printf("Cac so nguyen ngau nhien:\n");
    int maxInt = -99999;
    for(int i = 0; i < 5; i++) {
        int num = rand() % 100;  // Số ngẫu nhiên từ 0-99
        fprintf(intFile, "%d\n", num);
        printf("%d ", num);
        if(num > maxInt) maxInt = num;
    }
    printf("\n");
    fclose(intFile);
    
    // Ghi file REAL.DAT
    FILE *realFile = fopen("REAL.DAT", "w");
    if(realFile == NULL) {
        printf("Khong the mo file REAL.DAT\n");
        return 1;
    }
    
    printf("Cac so thuc ngau nhien:\n");
    float maxReal = -99999.0f;
    for(int i = 0; i < 5; i++) {
        float num = (float)rand()/RAND_MAX * 100; // Số thực ngẫu nhiên từ 0-100
        fprintf(realFile, "%.2f\n", num);
        printf("%.2f ", num);
        if(num > maxReal) maxReal = num;
    }
    printf("\n");
    fclose(realFile);
    
    // Đọc và tìm số lớn nhất từ INTEGER.DAT
    intFile = fopen("INTEGER.DAT", "r");
    if(intFile == NULL) {
        printf("Khong the mo file INTEGER.DAT de doc\n");
        return 1;
    }
    
    int num, maxFromFile = -99999;
    while(fscanf(intFile, "%d", &num) == 1) {
        if(num > maxFromFile) maxFromFile = num;
    }
    printf("So nguyen lon nhat trong file: %d\n", maxFromFile);
    fclose(intFile);
    
    // Đọc và tìm số lớn nhất từ REAL.DAT
    realFile = fopen("REAL.DAT", "r");
    if(realFile == NULL) {
        printf("Khong the mo file REAL.DAT de doc\n");
        return 1;
    }
    
    float numReal, maxRealFromFile = -99999.0f;
    while(fscanf(realFile, "%f", &numReal) == 1) {
        if(numReal > maxRealFromFile) maxRealFromFile = numReal;
    }
    printf("So thuc lon nhat trong file: %.2f\n", maxRealFromFile);
    fclose(realFile);
    
    return 0;
}
