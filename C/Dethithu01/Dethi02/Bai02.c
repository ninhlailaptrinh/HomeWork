#include <stdio.h>
#include <string.h>

struct OTO {
    char TenXe[20];
    char PhienBan[5];
    char LoaiHopSo[3];
    int GiaNiemYet;
};

void nhapThongTin(struct OTO *oto, int n) {
    for(int i = 0; i < n; i++) {
        printf("\nNhap thong tin xe thu %d:\n", i + 1);
        
        printf("Ten xe: ");
        fflush(stdin);
        fgets(oto[i].TenXe, sizeof(oto[i].TenXe), stdin);
        oto[i].TenXe[strcspn(oto[i].TenXe, "\n")] = 0; // Xóa ký tự xuống dòng
        
        printf("Phien ban: ");
        fgets(oto[i].PhienBan, sizeof(oto[i].PhienBan), stdin);
        oto[i].PhienBan[strcspn(oto[i].PhienBan, "\n")] = 0;
        
        printf("Loai hop so: ");
        fgets(oto[i].LoaiHopSo, sizeof(oto[i].LoaiHopSo), stdin);
        oto[i].LoaiHopSo[strcspn(oto[i].LoaiHopSo, "\n")] = 0;
        
        printf("Gia niem yet (trieu dong): ");
        scanf("%d", &oto[i].GiaNiemYet);
        getchar(); // Xử lý ký tự xuống dòng
    }
}

void inThongTin(struct OTO *oto, int n) {
    printf("\nDanh sach oto:\n");
    for(int i = 0; i < n; i++) {
        printf("\nXe thu %d:\n", i + 1);
        printf("Ten xe: %s\n", oto[i].TenXe);
        printf("Phien ban: %s\n", oto[i].PhienBan);
        printf("Loai hop so: %s\n", oto[i].LoaiHopSo);
        printf("Gia niem yet: %d trieu dong\n", oto[i].GiaNiemYet);
    }
}

void inXeTren500Trieu(struct OTO *oto, int n) {
    printf("\nDanh sach xe co gia tren 500 trieu:\n");
    int timThay = 0;
    for(int i = 0; i < n; i++) {
        if(oto[i].GiaNiemYet > 500) {
            printf("\nXe thu %d:\n", i + 1);
            printf("Ten xe: %s\n", oto[i].TenXe);
            printf("Phien ban: %s\n", oto[i].PhienBan);
            printf("Loai hop so: %s\n", oto[i].LoaiHopSo);
            printf("Gia niem yet: %d trieu dong\n", oto[i].GiaNiemYet);
            timThay = 1;
        }
    }
    if(!timThay) {
        printf("Khong co xe nao co gia tren 500 trieu!\n");
    }
}

int main() {
    struct OTO oto[100];
    int n;
    int luaChon;
    
    do {
        printf("\n=== MENU QUAN LY OTO ===\n");
        printf("1. Nhap thong tin oto\n");
        printf("2. In tat ca thong tin oto\n");
        printf("3. In thong tin oto tren 500 trieu\n");
        printf("4. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &luaChon);
        getchar(); // Xử lý ký tự xuống dòng
        
        switch(luaChon) {
            case 1:
                printf("Nhap so luong oto: ");
                scanf("%d", &n);
                getchar();
                nhapThongTin(oto, n);
                break;
            case 2:
                inThongTin(oto, n);
                break;
            case 3:
                inXeTren500Trieu(oto, n);
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
