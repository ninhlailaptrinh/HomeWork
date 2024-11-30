#include <stdio.h>
#include <string.h>

struct TIVI {
    char TenSanPham[30];
    char HangSanXuat[20];
    int KichThuoc;
    int SoLuong;
};

void nhapTivi(struct TIVI *tv) {
    printf("Nhap ten san pham: ");
    while (getchar() != '\n');
    fgets(tv->TenSanPham, sizeof(tv->TenSanPham), stdin);
    tv->TenSanPham[strcspn(tv->TenSanPham, "\n")] = 0;
    
    printf("Nhap hang san xuat: ");
    fgets(tv->HangSanXuat, sizeof(tv->HangSanXuat), stdin);
    tv->HangSanXuat[strcspn(tv->HangSanXuat, "\n")] = 0;
    
    printf("Nhap kich thuoc (inch): ");
    while (scanf("%d", &tv->KichThuoc) != 1) {
        printf("Vui long nhap so hop le: ");
        while (getchar() != '\n');
    }
    
    printf("Nhap so luong: ");
    while (scanf("%d", &tv->SoLuong) != 1) {
        printf("Vui long nhap so hop le: ");
        while (getchar() != '\n');
    }
}

void inTivi(struct TIVI tv) {
    printf("\nTen san pham: %s", tv.TenSanPham);
    printf("\nHang san xuat: %s", tv.HangSanXuat);
    printf("\nKich thuoc: %d inch", tv.KichThuoc);
    printf("\nSo luong: %d", tv.SoLuong);
    printf("\n------------------------");
}

void nhapDanhSach(struct TIVI *ds, int n) {
    for(int i = 0; i < n; i++) {
        printf("\nNhap thong tin TIVI thu %d:\n", i + 1);
        nhapTivi(&ds[i]);
    }
}

void inDanhSach(struct TIVI *ds, int n) {
    printf("\nDANH SACH TIVI:");
    for(int i = 0; i < n; i++) {
        printf("\n\nTIVI thu %d:", i + 1);
        inTivi(ds[i]);
    }
}

void inTiviLon(struct TIVI *ds, int n) {
    printf("\nDANH SACH TIVI CO KICH THUOC >= 50 INCH:");
    int found = 0;
    for(int i = 0; i < n; i++) {
        if(ds[i].KichThuoc >= 50) {
            printf("\n\nTIVI thu %d:", i + 1);
            inTivi(ds[i]);
            found = 1;
        }
    }
    if(!found) {
        printf("\nKhong co TIVI nao co kich thuoc >= 50 inch!");
    }
}

void hienThiMenu() {
    printf("\n=== MENU QUAN LY TIVI ===");
    printf("\n1. Nhap danh sach TIVI");
    printf("\n2. In danh sach TIVI");
    printf("\n3. In TIVI co kich thuoc >= 50 inch");
    printf("\n4. Thoat");
    printf("\nChon chuc nang (1-4): ");
}

int main() {
    struct TIVI dsTivi[100];
    int n = 0;
    int choice;
    int daNhap = 0;
    
    do {
        hienThiMenu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nNhap so luong TIVI: ");
                scanf("%d", &n);
                if (n <= 0 || n > 100) {
                    printf("\nSo luong khong hop le!");
                    break;
                }
                nhapDanhSach(dsTivi, n);
                daNhap = 1;
                break;
                
            case 2:
                if(!daNhap) {
                    printf("\nVui long nhap danh sach TIVI truoc!");
                    break;
                }
                inDanhSach(dsTivi, n);
                break;
                
            case 3:
                if(!daNhap) {
                    printf("\nVui long nhap danh sach TIVI truoc!");
                    break;
                }
                inTiviLon(dsTivi, n);
                break;
                
            case 4:
                printf("\nCam on ban da su dung chuong trinh!");
                break;
                
            default:
                printf("\nLua chon khong hop le. Vui long chon lai!");
        }
    } while(choice != 4);
    
    return 0;
}
