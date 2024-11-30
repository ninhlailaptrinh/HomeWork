/*a) Tạo ngẫu nhiên mảng một chiều n phần tử nguyên có giá trị chứa trong đoạn [-30, 50] và
xuất mảng. (2 điểm)
b) Dùng một vòng lặp for, hãy tìm và in phần tử có trị nhỏ nhất và lớn nhất của mảng. (2
điểm)
c) Hãy xóa các phần tử trong mảng có giá trị trùng với giá trị lớn nhất của mảng, trừ
phần tử tìm được đầu tiên. (2 điểm)*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// a) Tạo mảng ngẫu nhiên trong đoạn [-30, 50]
void nhap(int arr[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 81 - 30;  // Công thức: rand() % (max - min + 1) + min
    }
}

void xuat(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// b) Tìm min, max và vị trí của chúng
void MINMAX(int arr[], int n)
{
    int min = arr[0];
    int max = arr[0];
    int viTriMin = 0;
    int viTriMax = 0;
    
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
            viTriMin = i;
        }
        if (arr[i] > max) {
            max = arr[i];
            viTriMax = i;
        }
    }
    printf("Min: %d tai vi tri: %d\n", min, viTriMin);
    printf("Max: %d tai vi tri: %d\n", max, viTriMax);
}

// c) Xóa các phần tử trùng với max
void xoaPhanTu(int arr[], int *n, int viTri)
{
    for (int i = viTri; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

void xoaTrungMax(int arr[], int *n)
{
    // Tìm max
    int max = arr[0];
    for (int i = 1; i < *n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    // Tìm vị trí max đầu tiên
    int viTriMaxDau = 0;
    for (int i = 0; i < *n; i++) {
        if (arr[i] == max) {
            viTriMaxDau = i;
            break;
        }
    }
    
    // Xóa các phần tử trùng max, trừ phần tử đầu tiên
    for (int i = *n - 1; i > viTriMaxDau; i--) {
        if (arr[i] == max) {
            xoaPhanTu(arr, n, i);
        }
    }
}

int main()
{
    int n;
    int arr[100];
    
    printf("Nhap so phan tu n: ");
    scanf("%d", &n);
    
    // a) Tạo và xuất mảng
    nhap(arr, n);
    printf("Mang ban dau: ");
    xuat(arr, n);
    
    // b) Tìm và in min, max
    MINMAX(arr, n);
    
    // c) Xóa các phần tử trùng max
    xoaTrungMax(arr, &n);
    printf("Mang sau khi xoa cac phan tu trung max: ");
    xuat(arr, n);
    
    return 0;
}
