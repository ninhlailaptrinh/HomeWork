#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Hàm tạo số ngẫu nhiên kiểu int
int taoSoNgauNhienInt() {
    return rand() % 100; // Số ngẫu nhiên từ 0-99
}

// Hàm tạo số ngẫu nhiên kiểu float
float taoSoNgauNhienFloat() {
    return (float)rand() / RAND_MAX * 100; // Số thực ngẫu nhiên từ 0-100
}

// Hàm ghi file số nguyên
void ghiFileInt(const char* tenFile) {
    FILE *f = fopen(tenFile, "w");
    if (f == NULL) {
        printf("Không thể mở file %s\n", tenFile);
        return;
    }
    
    for(int i = 0; i < 5; i++) {
        fprintf(f, "%d\n", taoSoNgauNhienInt());
    }
    fclose(f);
}

// Hàm ghi file số thực
void ghiFileFloat(const char* tenFile) {
    FILE *f = fopen(tenFile, "w");
    if (f == NULL) {
        printf("Không thể mở file %s\n", tenFile);
        return;
    }
    
    for(int i = 0; i < 5; i++) {
        fprintf(f, "%.2f\n", taoSoNgauNhienFloat());
    }
    fclose(f);
}

// Hàm đọc và tính trung bình số nguyên
float tinhTBInt(const char* tenFile) {
    FILE *f = fopen(tenFile, "r");
    if (f == NULL) {
        printf("Không thể mở file %s\n", tenFile);
        return 0;
    }
    
    int sum = 0, num;
    int count = 0;
    
    while(fscanf(f, "%d", &num) == 1) {
        sum += num;
        count++;
    }
    fclose(f);
    
    return count > 0 ? (float)sum/count : 0;
}

// Hàm đọc và tính trung bình số thực
float tinhTBFloat(const char* tenFile) {
    FILE *f = fopen(tenFile, "r");
    if (f == NULL) {
        printf("Không thể mở file %s\n", tenFile);
        return 0;
    }
    
    float sum = 0, num;
    int count = 0;
    
    while(fscanf(f, "%f", &num) == 1) {
        sum += num;
        count++;
    }
    fclose(f);
    
    return count > 0 ? sum/count : 0;
}

int main() {
    srand(time(NULL)); // Khởi tạo seed cho random
    
    // Ghi file
    ghiFileInt("INTEGER.DAT");
    ghiFileFloat("REAL.DAT");
    
    // Tính và in kết quả
    printf("Trung binh cong cac so nguyen: %.2f\n", tinhTBInt("INTEGER.DAT"));
    printf("Trung binh cong cac so thuc: %.2f\n", tinhTBFloat("REAL.DAT"));
    
    return 0;
}
