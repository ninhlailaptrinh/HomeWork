#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *fInt, *fReal;
    float soThuc, tongInt = 0, tongReal = 0;
    int i;
    
    // Khởi tạo seed cho hàm random
    srand(time(NULL));
    
    // Ghi vào file INTEGER.DAT
    fInt = fopen("INTEGER.DAT", "w");
    if (fInt == NULL) {
        printf("Không thể mở file INTEGER.DAT\n");
        return 1;
    }
    for(i = 0; i < 5; i++) {
        soThuc = (float)rand()/RAND_MAX * 100; // Số thực từ 0-100
        fprintf(fInt, "%.2f\n", soThuc);
    }
    fclose(fInt);
    
    // Ghi vào file REAL.DAT
    fReal = fopen("REAL.DAT", "w");
    if (fReal == NULL) {
        printf("Không thể mở file REAL.DAT\n");
        return 1;
    }
    for(i = 0; i < 5; i++) {
        soThuc = (float)rand()/RAND_MAX * 100; // Số thực từ 0-100
        fprintf(fReal, "%.2f\n", soThuc);
    }
    fclose(fReal);
    
    // Đọc và tính trung bình từ INTEGER.DAT
    fInt = fopen("INTEGER.DAT", "r");
    for(i = 0; i < 5; i++) {
        fscanf(fInt, "%f", &soThuc);
        tongInt += soThuc;
    }
    fclose(fInt);
    
    // Đọc và tính trung bình từ REAL.DAT
    fReal = fopen("REAL.DAT", "r");
    for(i = 0; i < 5; i++) {
        fscanf(fReal, "%f", &soThuc);
        tongReal += soThuc;
    }
    fclose(fReal);
    
    // In kết quả
    printf("Trung bình cộng các số trong INTEGER.DAT: %.2f\n", tongInt/5);
    printf("Trung bình cộng các số trong REAL.DAT: %.2f\n", tongReal/5);
    
    return 0;
}
