#include <stdio.h>
#include <string.h>

struct LAPTOP {
    char TenSanPham[30];
    char HangSanXuat[20]; 
    int KichThuoc;
    int GiaBan;
};

void nhapLaptop(struct LAPTOP *lt) {
    while (getchar() != '\n');
    
    printf("Nhap ten san pham: ");
    fgets(lt->TenSanPham, sizeof(lt->TenSanPham), stdin);
    lt->TenSanPham[strcspn(lt->TenSanPham, "\n")] = '\0';
    
    printf("Nhap hang san xuat: ");
    fgets(lt->HangSanXuat, sizeof(lt->HangSanXuat), stdin);
    lt->HangSanXuat[strcspn(lt->HangSanXuat, "\n")] = '\0';
    
    do {
        printf("Nhap kich thuoc (inch): ");
        if (scanf("%d", &lt->KichThuoc) != 1 || lt->KichThuoc <= 0) {
            printf("Kich thuoc khong hop le. Vui long nhap lai!\n");
            while (getchar() != '\n');
        } else break;
    } while (1);
    
    do {
        printf("Nhap gia ban (VND): ");
        if (scanf("%d", &lt->GiaBan) != 1 || lt->GiaBan <= 0) {
            printf("Gia ban khong hop le. Vui long nhap lai!\n");
            while (getchar() != '\n');
        } else break;
    } while (1);
}

void inLaptop(struct LAPTOP lt) {
    printf("\nTen san pham: %s", lt.TenSanPham);
    printf("\nHang san xuat: %s", lt.HangSanXuat);
    printf("\nKich thuoc: %d inch", lt.KichThuoc);
    printf("\nGia ban: %d VND", lt.GiaBan);
    printf("\n------------------------");
}

void nhapDanhSach(struct LAPTOP *ds, int n) {
    for(int i = 0; i < n; i++) {
        printf("\nNhap thong tin LAPTOP thu %d:\n", i + 1);
        nhapLaptop(&ds[i]);
    }
}

void inDanhSach(struct LAPTOP *ds, int n) {
    printf("\nDANH SACH LAPTOP:");
    for(int i = 0; i < n; i++) {
        printf("\n\nLAPTOP thu %d:", i + 1);
        inLaptop(ds[i]);
    }
}

void inLaptopGiaRe(struct LAPTOP *ds, int n) {
    printf("\nDANH SACH LAPTOP CO GIA DUOI 10 TRIEU:");
    int found = 0;
    for(int i = 0; i < n; i++) {
        if(ds[i].GiaBan < 10000000) {
            printf("\n\nLAPTOP thu %d:", i + 1);
            inLaptop(ds[i]);
            found = 1;
        }
    }
    if(!found) {
        printf("\nKhong co LAPTOP nao co gia duoi 10 trieu!");
    }
}

void hienThiMenu() {
    printf("\n=== MENU QUAN LY LAPTOP ===");
    printf("\n1. Nhap danh sach LAPTOP");
    printf("\n2. In danh sach LAPTOP");
    printf("\n3. In LAPTOP co gia duoi 10 trieu");
    printf("\n4. Thoat");
    printf("\nChon chuc nang (1-4): ");
}

int main() {
    struct LAPTOP dsLaptop[100];
    int n = 0;
    int choice;
    int daNhap = 0;
    
    do {
        hienThiMenu();
        while (scanf("%d", &choice) != 1) {
            printf("Vui long nhap so nguyen!\n");
            while (getchar() != '\n');
            hienThiMenu();
        }
        
        switch(choice) {
            case 1:
                do {
                    printf("\nNhap so luong LAPTOP (1-100): ");
                    if (scanf("%d", &n) != 1 || n <= 0 || n > 100) {
                        printf("So luong khong hop le. Vui long nhap lai!\n");
                        while (getchar() != '\n');
                    } else break;
                } while (1);
                nhapDanhSach(dsLaptop, n);
                daNhap = 1;
                break;
                
            case 2:
                if(!daNhap) {
                    printf("\nVui long nhap danh sach LAPTOP truoc!");
                    break;
                }
                inDanhSach(dsLaptop, n);
                break;
                
            case 3:
                if(!daNhap) {
                    printf("\nVui long nhap danh sach LAPTOP truoc!");
                    break;
                }
                inLaptopGiaRe(dsLaptop, n);
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
