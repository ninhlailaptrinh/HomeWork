#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *fInt, *fReal;
    int i;
    
    // Khởi tạo bộ sinh số ngẫu nhiên
    srand(time(NULL));
    
    // Ghi 5 số nguyên ngẫu nhiên vào INTERGER.DAT
    fInt = fopen("INTERGER.DAT", "w");
    if (fInt == NULL) {
        printf("Khong the mo file INTERGER.DAT\n");
        return 1;
    }
    
    printf("Cac so nguyen ngau nhien:\n");
    for (i = 0; i < 5; i++) {
        int num = rand() % 100; // Sinh số ngẫu nhiên từ 0-99
        fprintf(fInt, "%d\n", num);
        printf("%d ", num);
    }
    printf("\n");
    fclose(fInt);
    
    // Ghi 5 số thực ngẫu nhiên vào REAL.DAT
    fReal = fopen("REAL.DAT", "w");
    if (fReal == NULL) {
        printf("Khong the mo file REAL.DAT\n");
        return 1;
    }
    
    printf("Cac so thuc ngau nhien:\n");
    for (i = 0; i < 5; i++) {
        float num = (float)rand() / RAND_MAX * 100; // Sinh số thực từ 0-100
        fprintf(fReal, "%.2f\n", num);
        printf("%.2f ", num);
    }
    printf("\n");
    fclose(fReal);
    
    // Đọc và hiển thị lại các số từ file
    printf("\nDoc lai tu file:\n");
    printf("Cac so nguyen:\n");
    
    fInt = fopen("INTERGER.DAT", "r");
    int intNum;
    while (fscanf(fInt, "%d", &intNum) == 1) {
        printf("%d ", intNum);
    }
    printf("\n");
    fclose(fInt);
    
    printf("Cac so thuc:\n");
    fReal = fopen("REAL.DAT", "r");
    float realNum;
    while (fscanf(fReal, "%f", &realNum) == 1) {
        printf("%.2f ", realNum);
    }
    printf("\n");
    fclose(fReal);
    
    return 0;
}
