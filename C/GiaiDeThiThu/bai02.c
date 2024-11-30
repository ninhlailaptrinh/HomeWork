#include <stdio.h>
#include <string.h>

struct DIENTHOAI
{
	char tenDienThoai[30];
	char hangDienThoai[20];
	int namSanXuat;
};

void nhapThongTin(struct DIENTHOAI ds[])
{
	while (getchar() != '\n') {
		printf("Nhap ten: \n");
		fgets(ds->tenDienThoai,sizeof(ds->tenDienThoai), stdin);
	    ds->tenDienThoai[strspn(ds->tenDienThoai, "\n")] = 0 ;
         
		printf("Nhap hang : ");
		fgets(ds->hangDienThoai,sizeof(ds->hangDienThoai),stdin);
		ds->hangDienThoai[strspn(ds->hangDienThoai, "\n")] = 0 ; 

		printf("Nhap nam :");
		scanf("%d",&ds->namSanXuat);
	}
}

void nhapDanhSach(struct DIENTHOAI ds[] , int n)
{
	for (int i = 0 ; i < n; i++) {
		printf("Nhap vao dien thoai thu %d : ",i + 1);
		nhapThongTin(ds);
	}
	printf("\n");
}	
