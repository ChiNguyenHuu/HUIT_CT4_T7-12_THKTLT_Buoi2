#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void generateRandomArray(int a[], int *n, int minSize);
void generateEvenArray(int a[], int n, int evenArray[], int *evenSize);
int linearSearch(int a[], int n, int x);
void interchangeSort(int a[], int n, int ascending);
int binarySearch(int a[], int n, int x);
void selectionSort(int a[], int n);
void quickSort(int a[], int low, int high);
int partition(int a[], int low, int high);

void printArray(int a[], int n);

int main() {
    int a[MAX], evenArray[MAX];
    int n = 0, evenSize = 0, x, choice, result;
    
    srand(time(0));
    
    do {
        printf("\nMenu:\n");
        printf("1. Tạo mảng ngẫu nhiên\n");
        printf("2. Tạo mảng chứa toàn số chẵn\n");
        printf("3. Tìm kiếm tuyến tính\n");
        printf("4. Sắp xếp Interchange Sort\n");
        printf("5. Tìm kiếm nhị phân\n");
        printf("6. Sắp xếp Selection Sort\n");
        printf("7. Sắp xếp Quick Sort\n");
        printf("8. Thoát\n");
        printf("Lựa chọn của bạn: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generateRandomArray(a, &n, 15);
                printf("Mảng ngẫu nhiên: ");
                printArray(a, n);
                break;
            case 2:
                generateEvenArray(a, n, evenArray, &evenSize);
                printf("Mảng chứa toàn số chẵn: ");
                printArray(evenArray, evenSize);
                break;
            case 3:
                printf("Nhập giá trị cần tìm kiếm: ");
                scanf("%d", &x);
                result = linearSearch(a, n, x);
                if (result != -1) {
                    printf("Giá trị %d được tìm thấy tại vị trí %d\n", x, result);
                } else {
                    printf("Không tìm thấy giá trị %d trong mảng\n", x);
                }
                break;
            case 4:
                printf("1. Sắp xếp tăng dần\n");
                printf("2. Sắp xếp giảm dần\n");
                printf("Lựa chọn của bạn: ");
                scanf("%d", &result);
                interchangeSort(a, n, result == 1);
                printf("Mảng sau khi sắp xếp: ");
                printArray(a, n);
                break;
            case 5:
                printf("Nhập giá trị cần tìm kiếm: ");
                scanf("%d", &x);
                selectionSort(a, n);  // Sắp xếp tăng dần trước khi tìm kiếm nhị phân
                result = binarySearch(a, n, x);
                if (result != -1) {
                    printf("Giá trị %d được tìm thấy tại vị trí %d\n", x, result);
                } else {
                    printf("Không tìm thấy giá trị %d trong mảng\n", x);
                }
                break;
            case 6:
                selectionSort(a, n);
                printf("Mảng sau khi sắp xếp Selection Sort: ");
                printArray(a, n);
                break;
            case 7:
                quickSort(a, 0, n - 1);
                printf("Mảng sau khi sắp xếp Quick Sort: ");
                printArray(a, n);
                break;
            case 8:
                printf("Thoát chương trình.\n");
                break;
            default:
                printf("Lựa chọn không hợp lệ. Vui lòng chọn lại.\n");
                break;
        }
    } while (choice != 8);

    return 0;
}

void generateRandomArray(int a[], int *n, int minSize) {
    *n = minSize + rand() % (MAX - minSize + 1);
    for (int i = 0; i < *n; i++) {
        a[i] = rand() % 100;  // Số ngẫu nhiên từ 0 đến 99
    }
}

void generateEvenArray(int a[], int n, int evenArray[], int *evenSize) {
    *evenSize = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            evenArray[*evenSize] = a[i];
            (*evenSize)++;
        }
    }
}

int linearSearch(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return i;
        }
    }
    return -1;
}

void interchangeSort(int a[], int n, int ascending) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((ascending && a[i] > a[j]) || (!ascending && a[i] < a[j])) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int binarySearch(int a[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == x) {
            return mid;
        } else if (a[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIdx]) {
                minIdx = j;
            }
        }
        int temp = a[minIdx];
        a[minIdx] = a[i];
        a[i] = temp;
    }
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;
    return i + 1;
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
