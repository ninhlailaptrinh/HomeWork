#include <complex.h>
#include <stdio.h>
#include <string.h>

struct DIENTHOAI
{
  char tenDienThoai[30];
  char hangDienThoai[20];
  int  namSanXuat;
};
void nhapThongTin(struct DIENTHOAI *ds)
{
  while(getchar() != '\n')
  {
    printf("\nTen dien thoai : ");
    fgets(ds->tenDienThoai,sizeof(ds->tenDienThoai),stdin);
    ds->tenDienThoai[strspn(ds->tenDienThoai, "\n")] = 0 ; 

    printf("Hang dien thoai :");
    fgets(ds->hangDienThoai,sizeof(ds->hangDienThoai),stdin);
    ds->hangDienThoai[strspn(ds->hangDienThoai , "\n")] = 0 ; 

    printf("\nNam san xuat : ");
    scanf_s("%d",&ds->namSanXuat);
    getchar();
  }
}

void nhapDanhSach(struct DIENTHOAI ds[] , int soLuong)
{
  for (int i = 0 ; i < soLuong; i++) {
      printf("Nhap thong tin dien thoai thu %d ",i + 1);
      nhapThongTin(&ds[i]);
  }
}

void inThongTin(struct DIENTHOAI ds)
{
    printf("Ten : %s\n",ds.tenDienThoai);
    printf("Hang : %s\n",ds.hangDienThoai);
    printf("Nam : %d\n",ds.namSanXuat);
}

void InDanhSach(struct DIENTHOAI ds[] , int soLuong)
{
  for(int i = 0 ; i < soLuong ; i++)
    {
      printf("\nDien thoai thu %d ",i + 1);
      inThongTin(ds[i]);
  }
}
void menu()
{
  printf("\n1. Nhap thong tin");
  printf("\n2. In danh sach");
  printf("\n3. In ra danh sach theo nam tang dan");
  printf("\n4. Thoát");
}

 
int main()
{
  struct DIENTHOAI ds[100]; 
  int soLuong,k;
  int daNhap = 0; 
  int luaChon;
  
  do {
  menu();
  printf("\nNhap vao so luong dien thoai : ");
  scanf_s("%d",&soLuong);
 
  switch (luaChon) {
      
      case 1:
      if(soLuong <= 0 || soLuong >= 100)
      {
            printf("\nSo luong khong hop le !");
            break;
      }
      InDanhSach(ds,soLuong);
      daNhap = 1 ;
      break;

    case 2:
      if (!daNhap) {
        printf("\nSo luong khong hop le !");
      }
     ;
      break;



  }  
  }while (luaChon != 4);
  return 0;
}









