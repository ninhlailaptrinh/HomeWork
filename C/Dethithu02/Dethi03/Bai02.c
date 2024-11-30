#include <stdio.h>
#include <string.h>

struct THISINH {
    char MaThiSinh[5];
    char HoTen[30];
    float DiemToan, DiemLy, DiemHoa;
    float DiemTong;
};

float nhapDiem(const char* monHoc) {
    float diem;
    do {
        printf("Diem %s: ", monHoc);
        scanf("%f", &diem);
        while(getchar() != '\n');
        if(diem < 0 || diem > 10) {
            printf("Diem khong hop le! Vui long nhap lai (0-10).\n");
        }
    } while (diem < 0 || diem > 10);
    return diem;
}

void nhapThongTin(struct THISINH *ts, int n) {
    for(int i = 0; i < n; i++) {
        printf("\nNhap thong tin thi sinh thu %d:\n", i+1);
        
        // Nhập và kiểm tra mã thí sinh
        do {
            printf("Ma thi sinh (toi da 4 ky tu): ");
            scanf("%4s", ts[i].MaThiSinh);
            while(getchar() != '\n');
            if(strlen(ts[i].MaThiSinh) > 4) {
                printf("Ma thi sinh qua dai! Vui long nhap lai.\n");
            }
        } while(strlen(ts[i].MaThiSinh) > 4);
        
        // Nhập họ tên
        printf("Ho ten: ");
        fgets(ts[i].HoTen, sizeof(ts[i].HoTen), stdin);
        ts[i].HoTen[strcspn(ts[i].HoTen, "\n")] = '\0';
        
        // Nhập điểm các môn
        ts[i].DiemToan = nhapDiem("Toan");
        ts[i].DiemLy = nhapDiem("Ly");
        ts[i].DiemHoa = nhapDiem("Hoa");
        
        ts[i].DiemTong = ts[i].DiemToan + ts[i].DiemLy + ts[i].DiemHoa;
    }
}

void inThongTin(struct THISINH *ts, int n) {
    printf("\nDanh sach thi sinh:\n");
    for(int i = 0; i < n; i++) {
        printf("\nThi sinh %d:\n", i+1);
        printf("Ma thi sinh: %s\n", ts[i].MaThiSinh);
        printf("Ho ten: %s\n", ts[i].HoTen);
        printf("Diem Toan: %.2f\n", ts[i].DiemToan);
        printf("Diem Ly: %.2f\n", ts[i].DiemLy);
        printf("Diem Hoa: %.2f\n", ts[i].DiemHoa);
        printf("Diem Tong: %.2f\n", ts[i].DiemTong);
    }
}

void timDiemCaoNhat(struct THISINH *ts, int n) {
    float maxDiem = ts[0].DiemTong;
    int viTri = 0;
    
    for(int i = 1; i < n; i++) {
        if(ts[i].DiemTong > maxDiem) {
            maxDiem = ts[i].DiemTong;
            viTri = i;
        }
    }
    
    printf("\nThi sinh co diem cao nhat:\n");
    printf("Ma thi sinh: %s\n", ts[viTri].MaThiSinh);
    printf("Ho ten: %s\n", ts[viTri].HoTen);
    printf("Diem Toan: %.2f\n", ts[viTri].DiemToan);
    printf("Diem Ly: %.2f\n", ts[viTri].DiemLy);
    printf("Diem Hoa: %.2f\n", ts[viTri].DiemHoa);
    printf("Diem Tong: %.2f\n", ts[viTri].DiemTong);
}

int main() {
    struct THISINH ts[100];
    int n = 0, luaChon;
    
    do {
        printf("\n=== MENU ===\n");
        printf("1. Nhap thong tin thi sinh\n");
        printf("2. In thong tin thi sinh\n");
        printf("3. Tim thi sinh diem cao nhat\n");
        printf("4. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &luaChon);
        
        switch(luaChon) {
            case 1:
                do {
                    printf("\nNhap so luong thi sinh (1-100): ");
                    scanf("%d", &n);
                    while(getchar() != '\n');
                } while (n <= 0 || n > 100);
                nhapThongTin(ts, n);
                break;
            case 2:
                if(n == 0) {
                    printf("\nChua co du lieu thi sinh! Vui long nhap du lieu truoc.\n");
                } else {
                    inThongTin(ts, n);
                }
                break;
            case 3:
                if(n == 0) {
                    printf("\nChua co du lieu thi sinh! Vui long nhap du lieu truoc.\n");
                } else {
                    timDiemCaoNhat(ts, n);
                }
                break;
            case 4:
                printf("\nCam on ban da su dung chuong trinh!\n");
                break;
            default:
                printf("\nLua chon khong hop le!\n");
        }
    } while(luaChon != 4);
    
    return 0;
}
