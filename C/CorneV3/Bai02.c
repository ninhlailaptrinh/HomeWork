#include <stdio.h>
#include <string.h>

struct DIENTHOAI 
{
	char tenDienThoai[30];
	char hangDienThoai[20];
	int namSanXuat;
};

void nhapDienThoai(struct DIENTHOAI *dt)
{
	while(getchar() != '\n');

	printf("Nhap ten dien thoai : ");
	fgets(dt->tenDienThoai,sizeof(dt->tenDienThoai),stdin);
	dt->tenDienThoai[strcspn(dt->tenDienThoai,"\n")] = 0 ; 

	printf("Nhap hang san xuat : ");
	fgets(dt->hangDienThoai,sizeof(dt->hangDienThoai),stdin);
	dt->hangDienThoai[strcspn(dt->hangDienThoai,"\n")] = 0 ;

	printf("Nhap vao nam san xuat : ");
	scanf("%d",&dt->namSanXuat);
}

void nhapDanhSach(struct DIENTHOAI ds[],int n)
	{
		for (int i = 0 ; i < n ; i++) {
			printf("Nhap vao so luong dien thoai %d : \n", i + 1 );
			nhapDienThoai(&ds[i]);	
		}
	}

void xuatDienThoai(struct DIENTHOAI dt)
{
	printf("\nTen dien thoai : %s",dt.tenDienThoai);
	printf("\nHang san xuat : %s",dt.hangDienThoai);
	printf("\nNam san xuat : %d",dt.namSanXuat);
}

void xuatDanhSach(struct DIENTHOAI ds[],int n )
{
	printf("\n=== DANH SACH DIEN THOAI ===");
	for(int i = 0 ; i < n ; i++)
	{
		printf("\nThong tin dien thoai thu %d : ",i + 1);
		xuatDienThoai(ds[i]);
	}
}

void Menu()
{
	printf("\nDanh sach dien thoai ");

	printf("\n1. Nhap thong tin");
	printf("\n2. In danh sach dien thoai");
	printf("\n3. Sap xep theo chieu tang dan");
	printf("\n4. Thoat");
	printf("\n==================================");
	printf("Nhap vao lua chon : ");
}

void sapXepTheoNam(struct DIENTHOAI ds[],int n )
{
	struct DIENTHOAI temp ; 

	for (int i = 0 ; i < n - 1 ; i++) {
		for (int j = 0 ; i < n - i - 1 ; j++) {
			if (ds[j].namSanXuat > ds[j + 1].namSanXuat) {
				temp = ds[j];
				ds[j] = ds[j + 1 ] ;
				ds[j + 1 ] = temp ; 
			}	
		}
	
	}
}

int main ()
{
	struct DIENTHOAI dt[100];
	int n = 0 ; 
	int choice; 
	int daNhap = 0;

	do {
	Menu();
	scanf("%d",&choice);

	switch (choice) {
		case 1:
			printf("\nNhap so luong dien thoai : ");
			scanf("%d",&n);
			if (n <= 0 || n >= 100) {
			
				printf("So luong khong hop le !");
				break;
			}
			nhapDanhSach(dt,n);
			daNhap = 1;
			break;

		case 2:
			if (!daNhap) {
				printf("Vui long nhap du du lieu truoc !");
				break;
			}
			xuatDanhSach(dt,n);
			daNhap = 1 ; 
			break;

		case 3:
			if (!daNhap) {
				printf("Vui long nhap du lieu truoc !");
				break;	
			}
			sapXepTheoNam(dt,n);
			printf("\nDanh sach sau khi sap xep theo nam : \n");
			xuatDanhSach(dt,n);
			break;

		case 4:
			printf("Tam biet !");
			return 0;
	}
	}while (1);
	return 0;
}
