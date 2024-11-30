#include <stdio.h>
#include <string.h>

struct MATHANG {
    char TenMatHang[20];
    long DonGia;
    long SoLuongTon;
};

void nhapMatHang(struct MATHANG *mh) {
    while (getchar() != '\n');
    
    printf("Nhap ten mat hang: ");
    fgets(mh->TenMatHang, sizeof(mh->TenMatHang), stdin);
    mh->TenMatHang[strcspn(mh->TenMatHang, "\n")] = '\0';
    
    printf("Nhap don gia: ");
    scanf("%ld", &mh->DonGia);
    printf("Nhap so luong ton: ");
    scanf("%ld", &mh->SoLuongTon);
}

void nhapDanhSachMatHang(struct MATHANG *ds, int *n) {
    printf("Nhap so luong mat hang: ");
    scanf("%d", n);
    
    for(int i = 0; i < *n; i++) {
        printf("\nNhap thong tin mat hang thu %d:\n", i + 1);
        nhapMatHang(&ds[i]);
    }
}

void xuatMatHang(struct MATHANG mh) {
    printf("Ten mat hang: %s\n", mh.TenMatHang);
    printf("Don gia: %ld\n", mh.DonGia);
    printf("So luong ton: %ld\n", mh.SoLuongTon);
}

void xuatDanhSachMatHang(struct MATHANG *ds, int n) {
    printf("\nDanh sach mat hang:\n");
    for(int i = 0; i < n; i++) {
        printf("\nMat hang thu %d:\n", i + 1);
        xuatMatHang(ds[i]);
    }
}

void timMatHangTonNhieuNhat(struct MATHANG *ds, int n) {
    int viTriMax = 0;
    for(int i = 1; i < n; i++) {
        if(ds[i].SoLuongTon > ds[viTriMax].SoLuongTon) {
            viTriMax = i;
        }
    }
    
    printf("\nMat hang co so luong ton cao nhat:\n");
    xuatMatHang(ds[viTriMax]);
}

void hienThiMenu() {
    printf("\n=== MENU ===\n");
    printf("1. Nhap danh sach mat hang\n");
    printf("2. Xuat danh sach mat hang\n");
    printf("3. Tim mat hang ton nhieu nhat\n");
    printf("4. Thoat\n");
    printf("Chon chuc nang (1-4): ");
}

int main() {
    struct MATHANG danhSach[100];
    int n = 0;
    int luaChon;
    
    do {
        hienThiMenu();
        scanf("%d", &luaChon);
        
        switch(luaChon) {
            case 1:
                nhapDanhSachMatHang(danhSach, &n);
                break;
            case 2:
                xuatDanhSachMatHang(danhSach, n);
                break;
            case 3:
                timMatHangTonNhieuNhat(danhSach, n);
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
