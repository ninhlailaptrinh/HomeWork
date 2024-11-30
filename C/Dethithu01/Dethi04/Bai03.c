#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    FILE *f;
    
    // Nhập chuỗi từ người dùng
    printf("Nhap chuoi s: ");
    fflush(stdin);
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = 0; // Xóa ký tự xuống dòng
    
    // Ghi chuỗi vào file
    f = fopen("STRING.DAT", "w");
    if(f == NULL) {
        printf("Khong the mo file STRING.DAT\n");
        return 1;
    }
    fprintf(f, "%s", s);
    fclose(f);
    
    // Đọc chuỗi từ file
    f = fopen("STRING.DAT", "r");
    if(f == NULL) {
        printf("Khong the mo file STRING.DAT\n");
        return 1;
    }
    fgets(s, sizeof(s), f);
    fclose(f);
    
    // In chuỗi đảo ngược
    printf("Chuoi dao nguoc la: ");
    for(int i = strlen(s) - 1; i >= 0; i--) {
        printf("%c", s[i]);
    }
    printf("\n");
    
    return 0;
}
