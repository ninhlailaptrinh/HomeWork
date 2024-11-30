#include <stdio.h>
#include <string.h>

struct GIAYDEP {
    char LoaiSanPham[30]; /* Loại sản phẩm */
    char HangSanXuat[20]; /* Hãng sản xuất */
    int Size; /* Kích cỡ */
    int GiaBan; /* Giá bán */
};

// Hàm nhập thông tin sản phẩm
void nhapThongTin(struct GIAYDEP giaydep[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap thong tin san pham thu %d:\n", i + 1);
        printf("Loai san pham: ");
        scanf("%s", giaydep[i].LoaiSanPham);
        printf("Hang san xuat: ");
        scanf("%s", giaydep[i].HangSanXuat);
        printf("Size: ");
        scanf("%d", &giaydep[i].Size);
        printf("Gia ban: ");
        scanf("%d", &giaydep[i].GiaBan);
    }
}

// Hàm in thông tin tất cả sản phẩm
void inThongTinTatCa(struct GIAYDEP giaydep[], int n) {
    printf("\nThong tin tat ca san pham:\n");
    for (int i = 0; i < n; i++) {
        printf("San pham thu %d:\n", i + 1);
        printf("Loai san pham: %s\n", giaydep[i].LoaiSanPham);
        printf("Hang san xuat: %s\n", giaydep[i].HangSanXuat);
        printf("Size: %d\n", giaydep[i].Size);
        printf("Gia ban: %d\n", giaydep[i].GiaBan);
    }
}

// Hàm in thông tin sản phẩm có size 37 và 38
void inThongTinSize3738(struct GIAYDEP giaydep[], int n) {
    printf("\nThong tin san pham co size 37 va 38:\n");
    for (int i = 0; i < n; i++) {
        if (giaydep[i].Size == 37 || giaydep[i].Size == 38) {
            printf("San pham thu %d:\n", i + 1);
            printf("Loai san pham: %s\n", giaydep[i].LoaiSanPham);
            printf("Hang san xuat: %s\n", giaydep[i].HangSanXuat);
            printf("Size: %d\n", giaydep[i].Size);
            printf("Gia ban: %d\n", giaydep[i].GiaBan);
        }
    }
}

// Hàm hiển thị menu
void hienThiMenu() {
    printf("\nMenu:\n");
    printf("1. Nhap thong tin san pham\n");
    printf("2. In thong tin tat ca san pham\n");
    printf("3. In thong tin san pham co size 37 va 38\n");
    printf("4. Thoat\n");
}

int main() {
    int n, choice;
    struct GIAYDEP giaydep[100]; // Giả sử tối đa 100 sản phẩm

    do {
        hienThiMenu();
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap so luong san pham: ");
                scanf("%d", &n);
                nhapThongTin(giaydep, n);
                break;
            case 2:
                inThongTinTatCa(giaydep, n);
                break;
            case 3:
                inThongTinSize3738(giaydep, n);
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
