#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Su dung: %s <tap_tin_nguon> <tap_tin_dich>\n", argv[0]);
        return 1;
    }

    FILE *fin = fopen(argv[1], "r");
    if (fin == NULL) {
        printf("Khong the mo tap tin nguon %s\n", argv[1]);
        return 1;
    }

    FILE *fout = fopen(argv[2], "w");
    if (fout == NULL) {
        printf("Khong the tao tap tin dich %s\n", argv[2]);
        fclose(fin);
        return 1;
    }

    int c;
    while ((c = fgetc(fin)) != EOF) {
        fputc(toupper(c), fout);
    }

    fclose(fin);
    fclose(fout);
    
    printf("Da chuyen doi thanh cong tu %s sang %s\n", argv[1], argv[2]);
    return 0;
}
