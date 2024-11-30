#include <stdio.h>
#include <string.h>

struct DIENTHOAI {
    char tenDienThoai[30];
    char hangSanXuat[20];
    int namSanXuat;
};

void nhapThongTin(struct DIENTHOAI dt[], int n) {
    for(int i = 0; i < n; i++) {
        while (getchar() != '\n');
        
        printf("\nDien thoai thu %d", i+1);

        printf("\nNhap ten dien thoai: ");
        fgets(dt[i].tenDienThoai, sizeof(dt[i].tenDienThoai), stdin);
        dt[i].tenDienThoai[strcspn(dt[i].tenDienThoai, "\n")] = 0;

        printf("Nhap hang san xuat: ");
        fgets(dt[i].hangSanXuat, sizeof(dt[i].hangSanXuat), stdin);
        dt[i].hangSanXuat[strcspn(dt[i].hangSanXuat, "\n")] = 0;
        
        printf("Nhap nam san xuat: ");
        scanf("%d", &dt[i].namSanXuat);
    }
}

void inThongTin(struct DIENTHOAI dt[], int n) {
    printf("\n=== DANH SACH DIEN THOAI ===\n");
    for(int i = 0; i < n; i++) {
        printf("\nThong tin dien thoai thu %d:", i+1);
        printf("\nTen dien thoai: %s", dt[i].tenDienThoai);
        printf("\nHang san xuat: %s", dt[i].hangSanXuat);
        printf("\nNam san xuat: %d\n", dt[i].namSanXuat);
    }
}

int main() {
    struct DIENTHOAI dt[100];
    int n = 0;
    int daNhap = 0;
    int luaChon;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Nhap thong tin dien thoai\n");
        printf("2. In thong tin dien thoai\n");
        printf("3. Thoat\n");
        printf("--------------------\n");
        printf("Nhap lua chon: ");
        scanf("%d", &luaChon);
        
        switch (luaChon) {
            case 1:
                printf("\nNhap so luong dien thoai (1-100): ");
                scanf("%d", &n);
                if(n <= 0 || n > 100) {
                    printf("So luong khong hop le!\n");
                    break;
                }
                nhapThongTin(dt, n);
                daNhap = 1;
                break;
                
            case 2:
                if(!daNhap) {
                    printf("\nVui long nhap thong tin dien thoai truoc!\n");
                    break;
                }
                inThongTin(dt, n);
                break;
                 
            case 3:
                printf("\nCam on ban da su dung chuong trinh!\n");
                break;

            default:
                printf("\nLua chon khong hop le!\n");
        }
    } while (luaChon != 3);
    
    return 0;
}
