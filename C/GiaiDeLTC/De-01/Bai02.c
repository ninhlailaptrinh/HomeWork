#include <stdio.h>


struct DIENTHOAI
{
	char tenDienThoai[30];
	char hangSanXuat[20];
	int	 namSanXuat;
};

void nhapDIENTHOAI(struct DIENTHOAI *dt , int n )
{
	for(int i = 0 ; i < n ; i++)
	{
		printf("Dien thoai thu %d:\n",i+1);
		getchar();
		printf("Ten dien thoai: \n");
		fgets(dt[i].tenDienThoai,sizeof(dt[i].tenDienThoai),stdin);

		printf("Hang san xuat: \n");
		fgets(dt[i].hangSanXuat,sizeof(dt[i].hangSanXuat),stdin);

		printf("Nam San Xuat: \n");
		scanf("%d",&dt[i].namSanXuat);
	}

}
void xuatDIENTHOAI(struct DIENTHOAI *dt , int n )
{
	for(int i = 0 ; i < n ; i++)
	{
		printf("Dien thoai thu : %d\n",i + 1);
		printf("Ten : %s \n",dt[i].tenDienThoai);
			
		printf("Hang: : %s \n",dt[i].hangSanXuat);
		
		printf("Nam : %d \n",dt[i].namSanXuat);
	}
}

void sapXepTheoNam(struct DIENTHOAI *dt , int n)
{
	struct DIENTHOAI temp ; 
	for(int i = 0 ; i < n -1  ; i++)
	{
		for(int j = 0 ; j < n - i - 1 ; j++)
		{
			if(dt[j].namSanXuat > dt[j+1].namSanXuat)
			{
				temp = dt[j];
				dt[j] = dt[j + 1 ] ; 
				dt[j+1] = temp;
			}
		}
	}
}

int main()
{
	struct DIENTHOAI dt[100] ; 
	int n = 0 ; 
	int luaChon ;
	int daNhap = 0 ; 

	do
	{
		printf("=============Menu=============\n");
		printf("0 . Nhap thong tin dien thoai\n");
		printf("1 . In thong tin dien thoai\n");
		printf("2 . Sap xep theo nam san xuat\n");
		printf("3 . Thoat\n");	
		printf("Nhap lua chon cua ban: ");
        scanf("%d", &luaChon);

		switch (luaChon)
		{
			case 0:
				printf("Nhap vao so luong dien thoai.\n");
				scanf("%d",&n);
				nhapDIENTHOAI(dt,n);
				daNhap = 1 ; 
				break;

			case 1:
				printf("In ra thong tin dien thoai.\n");
				xuatDIENTHOAI(dt,n);
				break ; 

			case 2:
				if(!daNhap)
				{
						printf("Vui long nhap thong tin dien thoai truoc !");
						break ; 
				}
				sapXepTheoNam(dt,n);
				printf("Dien thoai sau khi sap xep theo nam san xuat: \n");
				xuatDIENTHOAI(dt,n);
				break ; 

			case 3 :
				printf("Thoat chuong trinh !\n");
				return 0 ; 

			default :
				printf("Lua chon khong hop le !\n");
				break ; 
		}
		
	}while (luaChon != 3 );
	{
		return 0 ; 
	}
}


