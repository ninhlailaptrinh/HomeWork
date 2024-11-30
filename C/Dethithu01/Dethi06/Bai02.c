#include <stdio.h>
#include <string.h>

struct THOITRANG {
    char LoaiSanPham[30];
    char ChatLieu[30];
    int SoLuong;
    int GiaBan;
};

void nhapThongTin(struct THOITRANG sanPham[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap thong tin san pham thu %d:\n", i + 1);
        printf("Loai san pham: ");
        scanf("%s", sanPham[i].LoaiSanPham);
        printf("Chat lieu: ");
        scanf("%s", sanPham[i].ChatLieu);
        printf("So luong: ");
        scanf("%d", &sanPham[i].SoLuong);
        printf("Gia ban: ");
        scanf("%d", &sanPham[i].GiaBan);
    }
}

void inThongTin(struct THOITRANG sanPham[], int n) {
    printf("\nThong tin cac san pham:\n");
    for (int i = 0; i < n; i++) {
        printf("San pham thu %d:\n", i + 1);
        printf("Loai san pham: %s\n", sanPham[i].LoaiSanPham);
        printf("Chat lieu: %s\n", sanPham[i].ChatLieu);
        printf("So luong: %d\n", sanPham[i].SoLuong);
        printf("Gia ban: %d\n", sanPham[i].GiaBan);
    }
}

void inSanPhamGiaTu200kDen300k(struct THOITRANG sanPham[], int n) {
    printf("\nSan pham co gia tu 200000 den 300000 dong:\n");
    for (int i = 0; i < n; i++) {
        if (sanPham[i].GiaBan >= 200000 && sanPham[i].GiaBan <= 300000) {
            printf("San pham thu %d:\n", i + 1);
            printf("Loai san pham: %s\n", sanPham[i].LoaiSanPham);
            printf("Chat lieu: %s\n", sanPham[i].ChatLieu);
            printf("So luong: %d\n", sanPham[i].SoLuong);
            printf("Gia ban: %d\n", sanPham[i].GiaBan);
        }
    }
}

void menu() {
    printf("\nMenu:\n");
    printf("1. Nhap thong tin san pham\n");
    printf("2. In thong tin san pham\n");
    printf("3. In san pham co gia tu 200000 den 300000 dong\n");
    printf("4. Thoat\n");
}

int main() {
    int n, choice;
    struct THOITRANG sanPham[100];

    do {
        menu();
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap so luong san pham: ");
                scanf("%d", &n);
                nhapThongTin(sanPham, n);
                break;
            case 2:
                inThongTin(sanPham, n);
                break;
            case 3:
                inSanPhamGiaTu200kDen300k(sanPham, n);
                break;
            case 4:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 4);

    return 0;
}
