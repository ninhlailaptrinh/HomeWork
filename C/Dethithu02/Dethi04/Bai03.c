#include <stdio.h>

int main() {
    char line[1000];
    int lineNumber = 1;
    
    // Đọc từng dòng từ input (có thể là từ file qua chuyển hướng input)
    while (fgets(line, sizeof(line), stdin) != NULL) {
        // In số dòng (căn lề phải 3 ký tự) và nội dung của dòng
        printf("%3d: %s", lineNumber, line);
        lineNumber++;
    }
    
    return 0;
}
