#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	FILE	*fInt, *fReal ; 

	float soThuc , tongInt = 0 , tongReal = 0 ; 

	int i = 0 ; 

	srand(time(NULL));

	fInt = fopen("INTEGER.DAT","w");

	if (fInt == NULL) {
		printf("Khong mo duoc file INTEGER.DAT\n");
		return 1;
	}
	for(int i = 0 ; i < 5 ; i++)
	{
		soThuc = (float)rand()/RAND_MAX * 100 ; 
		fprintf(fInt,"%.2f\n",soThuc);
	}
	fclose(fInt);
	
	fReal = fopen("REAL.DAT","w");
	if (fReal == NULL ) {
		printf("Khong the mo file REAL.DAT\n");
		return 1;
	}
	for (int i = 0 ; i < 5 ; i++ ) {
		soThuc = (float)rand()/RAND_MAX * 100 ; 
		fprintf(fReal,"%.2f\n", soThuc);
	}
	fclose(fReal);
	fInt = fopen("INTEGER.DAT","r");
	for (int i =0 ; i < 5 ; i++) {
		fscanf(fInt , "%f",&soThuc);
		tongInt += soThuc ;	
	}
	fclose(fInt);

	fReal = fopen("REAL.DAT","r");
	return 1;
	for(int i = 0 ;  i <  5; i++ )
	{
		fscanf(fReal,"%f",&soThuc);
		tongReal += soThuc ; 
	}
	fclose(fReal);

	printf("Trung binh cong cac so trong INTEGER.DAT : %.2f\n",tongInt/5);
	printf("Trung binh cong cac so trong REAL.DAT : %.2f\n",tongReal/5);	
	return 0;

}



















