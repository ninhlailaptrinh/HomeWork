#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

// Hàm loại bỏ khoảng trắng thừa và đếm số từ
int chuanHoaVaDemTu(char *s) {
    int len = strlen(s);
    int i, j = 0;
    int soTu = 0;
    int daDemTu = 0;
    
    // Xóa khoảng trắng đầu
    while (s[0] == ' ') {
        for(i = 0; i < len; i++) {
            s[i] = s[i+1];
        }
        len--;
    }
    
    // Xóa khoảng trắng cuối
    while (len > 0 && s[len-1] == ' ') {
        s[len-1] = '\0';
        len--;
    }
    
    // Xử lý khoảng trắng giữa các từ
    for(i = 0; i < len; i++) {
        if (s[i] == ' ') {
            if (!daDemTu) {
                soTu++;
                daDemTu = 1;
            }
            if (s[i+1] == ' ') continue;
        } else {
            daDemTu = 0;
        }
        s[j] = s[i];
        j++;
    }
    s[j] = '\0';
    
    if (!daDemTu && j > 0) soTu++;
    return soTu;
}

// Hàm viết hoa chữ cái đầu mỗi từ
void vietHoaChuCaiDau(char *s) {
    int i;
    int dauTu = 1;
    
    for(i = 0; s[i] != '\0'; i++) {
        if (dauTu && isalpha(s[i])) {
            s[i] = toupper(s[i]);
            dauTu = 0;
        }
        else if (s[i] == ' ') {
            dauTu = 1;
        }
    }
}

// Hàm tìm từ dài nhất
void timTuDaiNhat(char *s) {
    char tuDaiNhat[MAX_LENGTH] = "";
    char tuHienTai[MAX_LENGTH] = "";
    int maxLen = 0;
    int i, j = 0;
    
    for(i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ') {
            tuHienTai[j] = s[i];
            j++;
        } else {
            tuHienTai[j] = '\0';
            if (strlen(tuHienTai) > maxLen) {
                strcpy(tuDaiNhat, tuHienTai);
                maxLen = strlen(tuHienTai);
            }
            j = 0;
        }
    }
    
    // Kiểm tra từ cuối cùng
    tuHienTai[j] = '\0';
    if (strlen(tuHienTai) > maxLen) {
        strcpy(tuDaiNhat, tuHienTai);
    }
    
    printf("Tu dai nhat: %s\n", tuDaiNhat);
}

int main() {
    char s[MAX_LENGTH];
    printf("Nhap chuoi: ");
    fgets(s, MAX_LENGTH, stdin);
    s[strcspn(s, "\n")] = '\0';  // Xóa ký tự newline
    
    // a) Chuẩn hóa và đếm số từ
    int soTu = chuanHoaVaDemTu(s);
    printf("So luong tu trong chuoi: %d\n", soTu);
    printf("Chuoi sau khi chuan hoa: %s\n", s);
    
    // b) Viết hoa chữ cái đầu
    vietHoaChuCaiDau(s);
    printf("Chuoi sau khi viet hoa chu cai dau: %s\n", s);
    
    // c) Tìm từ dài nhất
    timTuDaiNhat(s);
    
    return 0;
}
