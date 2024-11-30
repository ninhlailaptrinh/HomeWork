#include <stdio.h>
#include <string.h>

struct NHANVIEN {
    char MaNhanVien[5];
    char TenNhanVien[30];
    float Luong;
};

void nhapNhanVien(struct NHANVIEN *nv) {
    printf("Nhap ma nhan vien: ");
    scanf("%s", nv->MaNhanVien);
    while (getchar() != '\n');
    
    printf("Nhap ten nhan vien: ");
    fgets(nv->TenNhanVien, sizeof(nv->TenNhanVien), stdin);
    nv->TenNhanVien[strcspn(nv->TenNhanVien, "\n")] = '\0';
    
    printf("Nhap luong: ");
    scanf("%f", &nv->Luong);
    while (getchar() != '\n');
}

void nhapDanhSachNhanVien(struct NHANVIEN *ds, int *n) {
    do {
        printf("Nhap so luong nhan vien (1-100): ");
        scanf("%d", n);
        while (getchar() != '\n');
        
        if (*n <= 0 || *n > 100) {
            printf("So luong khong hop le. Vui long nhap lai!\n");
        }
    } while (*n <= 0 || *n > 100);
    
    for(int i = 0; i < *n; i++) {
        printf("\nNhap thong tin nhan vien thu %d:\n", i + 1);
        nhapNhanVien(&ds[i]);
    }
}

void xuatNhanVien(struct NHANVIEN nv) {
    printf("Ma nhan vien: %s\n", nv.MaNhanVien);
    printf("Ten nhan vien: %s\n", nv.TenNhanVien);
    printf("Luong: %.2f\n", nv.Luong);
}

void xuatDanhSachNhanVien(struct NHANVIEN *ds, int n) {
    printf("\nDanh sach nhan vien:\n");
    for(int i = 0; i < n; i++) {
        printf("\nNhan vien thu %d:\n", i + 1);
        xuatNhanVien(ds[i]);
    }
}

void timNhanVienLuongThapNhat(struct NHANVIEN *ds, int n) {
    int viTriMin = 0;
    for(int i = 1; i < n; i++) {
        if(ds[i].Luong < ds[viTriMin].Luong) {
            viTriMin = i;
        }
    }
    
    printf("\nNhan vien co luong thap nhat:\n");
    xuatNhanVien(ds[viTriMin]);
}

void hienThiMenu() {
    printf("\n=== MENU ===\n");
    printf("1. Nhap danh sach nhan vien\n");
    printf("2. Xuat danh sach nhan vien\n");
    printf("3. Tim nhan vien luong thap nhat\n");
    printf("4. Thoat\n");
    printf("Chon chuc nang (1-4): ");
}

int main() {
    struct NHANVIEN danhSach[100];
    int n = 0;
    int luaChon;
    
    do {
        hienThiMenu();
        scanf("%d", &luaChon);
        
        switch(luaChon) {
            case 1:
                nhapDanhSachNhanVien(danhSach, &n);
                break;
            case 2:
                xuatDanhSachNhanVien(danhSach, n);
                break;
            case 3:
                timNhanVienLuongThapNhat(danhSach, n);
                break;
            case 4:
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while(luaChon != 4);
    
    return 0;
}
