#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct DIENTHOAI {
    char tenDienThoai[30];
    char hangSanXuat[20];
    int namSanXuat;
};

void xoaXuongDong(char x[]) {
    size_t len = strlen(x);
    if (x[len-1] == '\n') {
        x[len-1] = '\0';
    }
}

void nhapDienThoai(struct DIENTHOAI *dt, int n) {
    printf("\n===== NHAP THONG TIN DIEN THOAI =====\n");
    for(int i = 0; i < n; i++) {
        printf("\nDien thoai thu %d:\n", i+1);
        
        printf("Ten dien thoai: ");
        fgets(dt[i].tenDienThoai, sizeof(dt[i].tenDienThoai), stdin);
        xoaXuongDong(dt[i].tenDienThoai);
        
        printf("Hang san xuat: ");
        fgets(dt[i].hangSanXuat, sizeof(dt[i].hangSanXuat), stdin);
        xoaXuongDong(dt[i].hangSanXuat);
        
        do {
            printf("Nam san xuat (1990-2024): ");
            scanf("%d", &dt[i].namSanXuat);
            getchar(); // Đọc ký tự xuống dòng
            if(dt[i].namSanXuat < 1990 || dt[i].namSanXuat > 2024) {
                printf("Nam san xuat khong hop le! Vui long nhap lai.\n");
            }
        } while(dt[i].namSanXuat < 1990 || dt[i].namSanXuat > 2024);
    }
}

void inMotDienThoai(struct DIENTHOAI dt) {
    printf("Ten DT: %-20s | Hang SX: %-15s | Nam SX: %d\n", 
           dt.tenDienThoai, dt.hangSanXuat, dt.namSanXuat);
}

void inDanhSachDienThoai(struct DIENTHOAI *dt, int n) {
    if(n == 0) {
        printf("\nDanh sach trong!\n");
        return;
    }
    printf("\n===== DANH SACH DIEN THOAI =====\n");
    printf("\n%-3s | %-20s | %-15s | %-8s\n", "STT", "Ten Dien Thoai", "Hang San Xuat", "Nam SX");
    printf("--------------------------------------------------------\n");
    for(int i = 0; i < n; i++) {
        printf("%-3d | ", i+1);
        inMotDienThoai(dt[i]);
    }
}

void sapXepTheoNam(struct DIENTHOAI *dt, int n) {
    if(n == 0) {
        printf("\nDanh sach trong!\n");
        return;
    }
    struct DIENTHOAI temp;
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(dt[i].namSanXuat > dt[j].namSanXuat) {
                temp = dt[i];
                dt[i] = dt[j];
                dt[j] = temp;
            }
        }
    }
    printf("\n===== DANH SACH SAU KHI SAP XEP THEO NAM =====\n");
    inDanhSachDienThoai(dt, n);
}

void hienThiMenu() {
    printf("\n====== QUAN LY DIEN THOAI ======\n");
    printf("1. Nhap danh sach dien thoai\n");
    printf("2. Hien thi danh sach dien thoai\n");
    printf("3. Sap xep theo nam san xuat\n");
    printf("0. Thoat chuong trinh\n");
    printf("===============================\n");
    printf("Nhap lua chon cua ban: ");
}

int main() {
    struct DIENTHOAI dt[100];
    int n = 0;
    int luaChon;
    
    do {
        hienThiMenu();
        scanf("%d", &luaChon);
        getchar(); // Đọc ký tự xuống dòng
        
        switch(luaChon) {
            case 1:
                printf("\nNhap so luong dien thoai: ");
                scanf("%d", &n);
                getchar();
                if(n <= 0 || n > 100) {
                    printf("So luong khong hop le!\n");
                    n = 0;
                    break;
                }
                nhapDienThoai(dt, n);
                break;
                
            case 2:
                inDanhSachDienThoai(dt, n);
                break;
                
            case 3:
                sapXepTheoNam(dt, n);
                break;
                
            case 0:
                printf("\nCam on ban da su dung chuong trinh!\n");
                break;
                
            default:
                printf("\nLua chon khong hop le!\n");
        }
    } while(luaChon != 0);
    
    return 0;
}
