#include <stdio.h>
#include <string.h>

struct DIENTHOAI {
    char tenDienThoai[30];
    char hangSanXuat[20];
    int namSanXuat;
};

void nhapDienThoai(struct DIENTHOAI *dt) {
    while(getchar() != '\n');
    
    printf("Nhap ten dien thoai: ");
    fgets(dt->tenDienThoai, sizeof(dt->tenDienThoai), stdin);
    dt->tenDienThoai[strcspn(dt->tenDienThoai, "\n")] = 0;
    
    printf("Nhap hang san xuat: ");
    fgets(dt->hangSanXuat, sizeof(dt->hangSanXuat), stdin);
    dt->hangSanXuat[strcspn(dt->hangSanXuat, "\n")] = 0;
    
    printf("Nhap nam san xuat: ");
    scanf("%d", &dt->namSanXuat);
}

void nhapDanhSach(struct DIENTHOAI ds[], int n) {
    for(int i = 0; i < n; i++) {
        printf("\nNhap thong tin dien thoai thu %d:\n", i + 1);
        nhapDienThoai(&ds[i]);
    }
}

void xuatDienThoai(struct DIENTHOAI dt) {
    printf("\nTen dien thoai: %s", dt.tenDienThoai);
    printf("\nHang san xuat: %s", dt.hangSanXuat);
    printf("\nNam san xuat: %d\n", dt.namSanXuat);
}

void xuatDanhSach(struct DIENTHOAI ds[], int n) {
    printf("\n=== DANH SACH DIEN THOAI ===\n");
    for(int i = 0; i < n; i++) {
        printf("\nThong tin dien thoai thu %d:", i + 1);
        xuatDienThoai(ds[i]);
    }
}

void menu()
	{
		printf("Danh sách dien thoai \n"); 

		printf("1. Nhap thong tin \n");
		printf("2. In ra danh sach dien thoai \n");
		printf("3. Sap xep nam theo chieun tang dan \n");
		printf("4. Thoat\n");
		printf("=========================================\n");
		printf("Nhap lua chon cua ban : ");
	}

void sapXepTheoNam(struct DIENTHOAI ds[], int n) {
    struct DIENTHOAI temp;
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(ds[j].namSanXuat > ds[j+1].namSanXuat) {
                temp = ds[j];
                ds[j] = ds[j+1];
                ds[j+1] = temp;
            }
        }
    }
}

int main() {
    struct DIENTHOAI dt[100];
    int n = 0; 
    int luaChon; 
    int daNhap = 0;
    
    do {
        menu();
        scanf("%d", &luaChon);
        
        switch(luaChon) {
            case 1:
                printf("\nNhap so luong dien thoai: ");
                scanf("%d", &n);
                if(n <= 0 || n >= 100) {
                    printf("So luong khong hop le!\n");
                    break;
                }
                nhapDanhSach(dt, n);
                daNhap = 1;
                break;
                
            case 2:
                if(!daNhap) {
                    printf("Vui long nhap du lieu truoc!\n");
                    break;
                }
                xuatDanhSach(dt, n);
                break;
                
            case 3:
                if(!daNhap) {
                    printf("Vui long nhap du lieu truoc!\n");
                    break;
                }
                sapXepTheoNam(dt, n);
                printf("\nDanh sach sau khi sap xep theo nam:\n");
                xuatDanhSach(dt, n);
                break;
                
            case 4:
                printf("Tam biet!\n");
                return 0;
        }
    } while(1);
    
    return 0;
}
