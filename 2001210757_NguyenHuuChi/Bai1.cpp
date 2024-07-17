//#include <stdio.h>
//#include <stdlib.h> // for rand() function
//#include <time.h>   // for srand() function
//
//// Hàm để tạo mảng một chiều ngẫu nhiên
//void createRandomArray(int a[], int n) {
//    srand(time(NULL)); // Khởi tạo seed cho hàm rand() dựa trên thời gian hiện tại
//    for (int i = 0; i < n; ++i) {
//        a[i] = rand() % 101; // Sinh số ngẫu nhiên từ 0 đến 100
//    }
//}
//
//// Hàm để kiểm tra số chẵn
//int isEven(int number) {
//    return number % 2 == 0;
//}
//
//// Hàm để tạo mảng chỉ chứa số chẵn từ mảng ban đầu
//void createEvenArray(int a[], int n, int evenArray[], int& evenCount) {
//    evenCount = 0;
//    for (int i = 0; i < n; ++i) {
//        if (isEven(a[i])) {
//            evenArray[evenCount++] = a[i];
//        }
//    }
//}
//
//// Hàm tìm kiếm tuyến tính
//int linearSearch(int a[], int n, int x) {
//    for (int i = 0; i < n; ++i) {
//        if (a[i] == x) {
//            return i; // Trả về vị trí đầu tiên tìm thấy x trong mảng
//        }
//    }
//    return -1; // Trả về -1 nếu không tìm thấy x trong mảng
//}
//
//// Hàm để in mảng
//void printArray(int a[], int n) {
//    for (int i = 0; i < n; ++i) {
//        printf("%d ", a[i]);
//    }
//    printf("\n");
//}
//
//// Hàm để hoán đổi giá trị
//void swap(int* xp, int* yp) {
//    int temp = *xp;
//    *xp = *yp;
//    *yp = temp;
//}
//
//// Hàm sắp xếp mảng theo Interchange Sort (Đổi chỗ)
//void interchangeSort(int a[], int n) {
//    for (int i = 0; i < n - 1; ++i) {
//        for (int j = i + 1; j < n; ++j) {
//            if (a[i] > a[j]) {
//                swap(&a[i], &a[j]);
//            }
//        }
//    }
//}
//
//// Hàm tìm kiếm nhị phân
//int binarySearch(int a[], int left, int right, int x) {
//    while (left <= right) {
//        int mid = left + (right - left) / 2;
//        if (a[mid] == x) {
//            return mid; // Trả về vị trí x nếu tìm thấy
//        }
//        else if (a[mid] < x) {
//            left = mid + 1;
//        }
//        else {
//            right = mid - 1;
//        }
//    }
//    return -1; // Trả về -1 nếu không tìm thấy x trong mảng
//}
//
//// Hàm sắp xếp mảng theo Selection Sort
//void selectionSort(int a[], int n) {
//    int minIndex;
//    for (int i = 0; i < n - 1; ++i) {
//        minIndex = i;
//        for (int j = i + 1; j < n; ++j) {
//            if (a[j] < a[minIndex]) {
//                minIndex = j;
//            }
//        }
//        if (minIndex != i) {
//            swap(&a[i], &a[minIndex]);
//        }
//    }
//}
//
//// Hàm sắp xếp mảng theo Quick Sort
//void quickSort(int a[], int left, int right) {
//    if (left < right) {
//        int pivot = a[right];
//        int i = left - 1;
//        for (int j = left; j <= right - 1; ++j) {
//            if (a[j] < pivot) {
//                ++i;
//                swap(&a[i], &a[j]);
//            }
//        }
//        swap(&a[i + 1], &a[right]);
//        int pi = i + 1;
//
//        quickSort(a, left, pi - 1);
//        quickSort(a, pi + 1, right);
//    }
//}
//
//int main() {
//    const int MAX_SIZE = 20; // Kích thước tối đa cho mảng
//    int a[MAX_SIZE];
//    int n = 15 + rand() % 16; // Số phần tử từ 15 đến 30
//
//    int choice;
//    int x;
//
//    while (1) {
//        printf("\n===== MENU =====\n");
//        printf("1. Tao mang ngau nhien\n");
//        printf("2. Tao mang chi chua so chan\n");
//        printf("3. Tim kiem phan tu trong mang (Linear Search)\n");
//        printf("4. Sap xep mang tang dan (Interchange Sort)\n");
//        printf("5. Tim kiem phan tu trong mang (Binary Search)\n");
//        printf("6. Sap xep mang tang dan (Selection Sort)\n");
//        printf("7. Sap xep mang tang dan (Quick Sort)\n");
//        printf("8. Thoat\n");
//        printf("Nhap lua chon cua ban: ");
//        scanf("%d", &choice);
//
//        switch (choice) {
//        case 1:
//            createRandomArray(a, n);
//            printf("Mang ngau nhien da tao: ");
//            printArray(a, n);
//            break;
//        case 2:
//        {
//            int evenArray[MAX_SIZE];
//            int evenCount;
//            createEvenArray(a, n, evenArray, evenCount);
//            printf("Mang chi chua so chan: ");
//            printArray(evenArray, evenCount);
//        }
//        break;
//        case 3:
//            printf("Nhap gia tri can tim trong mang: ");
//            scanf("%d", &x);
//            {
//                int pos = linearSearch(a, n, x);
//                if (pos != -1) {
//                    printf("Tim thay %d tai vi tri %d (tinh tu 0).\n", x, pos);
//                }
//                else {
//                    printf("Khong tim thay %d trong mang.\n", x);
//                }
//            }
//            break;
//        case 4:
//            interchangeSort(a, n);
//            printf("Mang sau khi sap xep tang dan: ");
//            printArray(a, n);
//            break;
//        case 5:
//            printf("Nhap gia tri can tim trong mang da sap xep tang dan: ");
//            scanf("%d", &x);
//            {
//                int pos = binarySearch(a, 0, n - 1, x);
//                if (pos != -1) {
//                    printf("Tim thay %d tai vi tri %d (tinh tu 0) sau khi sap xep tang.\n", x, pos);
//                }
//                else {
//                    printf("Khong tim thay %d trong mang sau khi sap xep tang.\n", x);
//                }
//            }
//            break;
//        case 6:
//            selectionSort(a, n);
//            printf("Mang sau khi sap xep tang dan bang Selection Sort: ");
//            printArray(a, n);
//            break;
//        case 7:
//            quickSort(a, 0, n - 1);
//            printf("Mang sau khi sap xep tang dan bang Quick Sort: ");
//            printArray(a, n);
//            break;
//        case 8:
//            printf("Thoat chuong trinh.\n");
//            return 0;
//        default:
//            printf("Lua chon khong hop le. Vui long chon lai.\n");
//        }
//    }
//
//    return 0;
//}
