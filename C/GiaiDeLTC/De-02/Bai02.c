#include <stdio.h>
#include <string.h>

struct MATHANG {
	char TenMatHang[20];
	long DonGia;
	long SoLuongTon;
};

void nhapThongTin(struct MATHANG *mh, int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("\nMat hang thu %d:\n", i + 1);
		getchar();
		
		printf("Nhap ten mat hang: ");	
		fgets(mh[i].TenMatHang, sizeof(mh[i].TenMatHang), stdin);
		mh[i].TenMatHang[strcspn(mh[i].TenMatHang, "\n")] = 0; // Xóa ký tự xuống dòng
		
		printf("Nhap don gia: ");	
		scanf("%ld", &mh[i].DonGia);		
		
		printf("Nhap so luong ton: ");
		scanf("%ld", &mh[i].SoLuongTon);
	}
}

void inThongTin(struct MATHANG *mh, int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("\nMat hang thu %d:\n", i + 1);
		printf("Ten mat hang: %s\n", mh[i].TenMatHang);
		printf("Don gia: %ld\n", mh[i].DonGia);
		printf("So luong ton: %ld\n", mh[i].SoLuongTon);
	}
}

void inMatHangTonNhieuNhat(struct MATHANG *mh, int n)
{
	if(n == 0) return;
	
	int viTriMax = 0;
	long maxTon = mh[0].SoLuongTon;
	
	for(int i = 1; i < n; i++)
	{
		if(mh[i].SoLuongTon > maxTon)
		{
			maxTon = mh[i].SoLuongTon;
			viTriMax = i;
		}
	}
	
	printf("\nMat hang ton nhieu nhat la:\n");
	printf("Ten mat hang: %s\n", mh[viTriMax].TenMatHang);
	printf("Don gia: %ld\n", mh[viTriMax].DonGia);
	printf("So luong ton: %ld\n", mh[viTriMax].SoLuongTon);
}

int main()
{
	struct MATHANG mh[100]; 
	int n = 0;
	int luaChon;
	int daNhap = 0;
	
	do {
		printf("\n===========MENU===========\n");
		printf("0. Nhap thong tin\n");
		printf("1. In ra thong tin\n");
		printf("2. In ra mat hang co so luong ton kho cao nhat\n");
		printf("3. Thoat khoi chuong trinh\n");
		printf("Nhap lua chon: ");
		scanf("%d", &luaChon);

		switch(luaChon)
		{
			case 0: 
				printf("Nhap so luong N: ");
				scanf("%d", &n);
				nhapThongTin(mh, n);
				daNhap = 1;
				break;
			
			case 1:
				if(!daNhap)
				{
					printf("\nVui long nhap thong tin truoc!\n");
					break;
				}
				printf("\nIn ra toan bo mat hang:");
				inThongTin(mh, n);
				break;

			case 2:
				if(!daNhap)
				{
					printf("\nVui long nhap thong tin truoc!\n");
					break;
				}
				inMatHangTonNhieuNhat(mh, n);
				break;

			case 3:
				printf("\nThoat khoi chuong trinh!\n");
				return 0;

			default:
				printf("\nLua chon khong hop le!\n");
				break;
		}
	} while(luaChon != 3);
	
	return 0;
}
