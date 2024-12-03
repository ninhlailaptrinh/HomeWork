#include <stdio.h>

int main()
{
	char string[1000];

	printf("Nhap vao chuoi : ");
	fgets(string, sizeof(string) , stdin);
	puts(string);
}
