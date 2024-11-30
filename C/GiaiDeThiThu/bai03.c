#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	FILE *fInt , *fRead ;	
	int soThuc  , tongInt =  0 , tongReal = 0 ; 
	int i = 0 ; 
	srand(time(NULL));

	fInt = fopen("INTEGER.DAT", "w");
	if (fInt == NULL) {
		printf("\nKhong mo duoc file INTEGER.DAT");
		return 1;	
	}

			
}
