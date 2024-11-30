#include <stdio.h>
#include <string.h>
#define MAX 1000

int main() {
    char s[100], line[MAX];
    FILE *f;
    int lineNum = 0;
    
    printf("Nhap chuoi can tim: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = 0;
    
    f = fopen("input.txt", "r");
    if (f == NULL) {
        printf("Khong mo duoc file!\n");
        return 1;
    }
    
    while (fgets(line, MAX, f) != NULL) {
        lineNum++;
        char *pos = line;
        int found = 0;
        
        while ((pos = strstr(pos, s)) != NULL) {
            if (!found) {
                printf("\nDong %d: ", lineNum);
                found = 1;
            }
            printf("%d ", (int)(pos - line + 1));
            pos++;
        }
    }
    
    fclose(f);
    return 0;
}
