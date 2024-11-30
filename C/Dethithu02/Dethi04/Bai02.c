#include <stdio.h>
#include <string.h>

struct HOCSINH {
    char HoTen[30];
    int DiemToan, DiemVan;
    float DiemTB;
};

void nhapThongTin(struct HOCSINH *hs, int n) {
    char temp[2];
    for(int i = 0; i < n; i++) {
        printf("\nNhap thong tin hoc sinh thu %d:\n", i+1);
        printf("Ho ten: ");
        fgets(temp, sizeof(temp), stdin);
        fgets(hs[i].HoTen, sizeof(hs[i].HoTen), stdin);
        hs[i].HoTen[strcspn(hs[i].HoTen, "\n")] = '\0';
        
        do {
            printf("Diem Toan (0-10): ");
            while (scanf("%d", &hs[i].DiemToan) != 1) {
                printf("Vui long nhap so hop le!\n");
                printf("Diem Toan (0-10): ");
                while (getchar() != '\n'); // Xóa buffer
            }
        } while(hs[i].DiemToan < 0 || hs[i].DiemToan > 10);
        
        do {
            printf("Diem Van (0-10): ");
            while (scanf("%d", &hs[i].DiemVan) != 1) {
                printf("Vui long nhap so hop le!\n");
                printf("Diem Van (0-10): ");
                while (getchar() != '\n'); // Xóa buffer
            }
        } while(hs[i].DiemVan < 0 || hs[i].DiemVan > 10);
        
        while (getchar() != '\n'); // Xóa buffer sau khi nhập xong
        hs[i].DiemTB = (float)(hs[i].DiemToan + hs[i].DiemVan) / 2;
    }
}

void inThongTin(struct HOCSINH *hs, int n) {
    printf("\nDanh sach hoc sinh:\n");
    for(int i = 0; i < n; i++) {
        printf("\nHoc sinh %d:\n", i+1);
        printf("Ho ten: %s\n", hs[i].HoTen);
        printf("Diem Toan: %d\n", hs[i].DiemToan);
        printf("Diem Van: %d\n", hs[i].DiemVan);
        printf("Diem Trung binh: %.2f\n", hs[i].DiemTB);
    }
}

void timDiemCaoNhat(struct HOCSINH *hs, int n) {
    float maxDiem = hs[0].DiemTB;
    int viTri = 0;
    
    for(int i = 1; i < n; i++) {
        if(hs[i].DiemTB > maxDiem) {
            maxDiem = hs[i].DiemTB;
            viTri = i;
        }
    }
    
    printf("\nHoc sinh co diem cao nhat:\n");
    printf("Ho ten: %s\n", hs[viTri].HoTen);
    printf("Diem Toan: %d\n", hs[viTri].DiemToan);
    printf("Diem Van: %d\n", hs[viTri].DiemVan);
    printf("Diem Trung binh: %.2f\n", hs[viTri].DiemTB);
}

int main() {
    struct HOCSINH hs[100];
    int n, luaChon;
    char temp[2];
    
    do {
        printf("\n=== MENU ===\n");
        printf("1. Nhap thong tin hoc sinh\n");
        printf("2. In thong tin hoc sinh\n");
        printf("3. Tim hoc sinh diem cao nhat\n");
        printf("4. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &luaChon);
        
        switch(luaChon) {
            case 1:
                do {
                    printf("\nNhap so luong hoc sinh (1-100): ");
                    scanf("%d", &n);
                    fgets(temp, sizeof(temp), stdin);
                } while(n <= 0 || n > 100);
                nhapThongTin(hs, n);
                break;
            case 2:
                inThongTin(hs, n);
                break;
            case 3:
                timDiemCaoNhat(hs, n);
                break;
            case 4:
                printf("\nCam on ban da su dung chuong trinh!\n");
                break;
            default:
                printf("\nLua chon khong hop le!\n");
        }
    } while(luaChon != 4);
    
    return 0;
}
