//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <limits.h>
//
//const int MAX_SIZE = 20; // Kích thước tối đa cho mảng
//
//// Hàm để tạo mảng một chiều ngẫu nhiên
//void createRandomArray(int a[], int n) {
//    srand(time(NULL)); // Khởi tạo seed cho hàm rand() dựa trên thời gian hiện tại
//    for (int i = 0; i < n; ++i) {
//        a[i] = rand() % 101; // Sinh số ngẫu nhiên từ 0 đến 100
//    }
//}
//
//// Hàm để in mảng ra màn hình
//void printArray(int a[], int n) {
//    for (int i = 0; i < n; ++i) {
//        printf("%d ", a[i]);
//    }
//    printf("\n");
//}
//
//// Hàm để kiểm tra số nguyên tố
//int isPrime(int number) {
//    if (number < 2) {
//        return 0; // Không phải số nguyên tố
//    }
//    for (int i = 2; i * i <= number; ++i) {
//        if (number % i == 0) {
//            return 0; // Không phải số nguyên tố
//        }
//    }
//    return 1; // Là số nguyên tố
//}
//
//// Bài 1: Liệt kê các số nguyên tố nhỏ hơn n
//void findPrimesLessThan(int n) {
//    int foundPrime = 0;
//    printf("Cac so nguyen to nho hon %d: ", n);
//    for (int i = 2; i < n; ++i) {
//        if (isPrime(i)) {
//            printf("%d ", i);
//            foundPrime = 1;
//        }
//    }
//    if (!foundPrime) {
//        printf("Khong ton tai so nguyen to nao nho hon %d.", n);
//    }
//    printf("\n");
//}
//
//// Hàm tính tổng các phần tử có chữ số đầu là chữ số lẻ
//int sumOfFirstDigitOdd(int a[], int n) {
//    int sum = 0;
//    for (int i = 0; i < n; ++i) {
//        int firstDigit = abs(a[i]);
//        while (firstDigit >= 10) {
//            firstDigit /= 10;
//        }
//        if (firstDigit % 2 != 0) {
//            sum += a[i];
//        }
//    }
//    return sum;
//}
//
//// Hàm đếm số lần xuất hiện của các phần tử trong mảng
//void countOccurrences(int a[], int n) {
//    printf("So lan xuat hien cua cac phan tu trong mang:\n");
//    for (int i = 0; i < n; ++i) {
//        int count = 1;
//        if (a[i] != -1) {
//            for (int j = i + 1; j < n; ++j) {
//                if (a[i] == a[j]) {
//                    count++;
//                    a[j] = -1; // Đánh dấu phần tử đã được đếm
//                }
//            }
//            printf("%d xuat hien %d lan\n", a[i], count);
//        }
//    }
//}
//
//// Hàm sắp xếp mảng có số chẵn tăng dần, số lẻ giảm dần
//void sortEvenOdd(int a[], int n) {
//    int evenCount = 0;
//    int oddCount = 0;
//    int even[MAX_SIZE], odd[MAX_SIZE];
//
//    // Phân loại phần tử chẵn và lẻ
//    for (int i = 0; i < n; ++i) {
//        if (a[i] % 2 == 0) {
//            even[evenCount++] = a[i];
//        }
//        else {
//            odd[oddCount++] = a[i];
//        }
//    }
//
//    // Sắp xếp mảng chẵn tăng dần
//    for (int i = 0; i < evenCount - 1; ++i) {
//        for (int j = i + 1; j < evenCount; ++j) {
//            if (even[i] > even[j]) {
//                int temp = even[i];
//                even[i] = even[j];
//                even[j] = temp;
//            }
//        }
//    }
//
//    // Sắp xếp mảng lẻ giảm dần
//    for (int i = 0; i < oddCount - 1; ++i) {
//        for (int j = i + 1; j < oddCount; ++j) {
//            if (odd[i] < odd[j]) {
//                int temp = odd[i];
//                odd[i] = odd[j];
//                odd[j] = temp;
//            }
//        }
//    }
//
//    // Gộp mảng đã sắp xếp
//    int index = 0;
//    for (int i = 0; i < evenCount; ++i) {
//        a[index++] = even[i];
//    }
//    for (int i = 0; i < oddCount; ++i) {
//        a[index++] = odd[i];
//    }
//}
//
//// Hàm tìm dãy con giảm dài nhất trong mảng
//void longestDecreasingSubarray(int a[], int n) {
//    int maxLen = 1;
//    int currentLen = 1;
//    int endIndex = 0;
//
//    for (int i = 1; i < n; ++i) {
//        if (a[i] < a[i - 1]) {
//            currentLen++;
//        }
//        else {
//            if (currentLen > maxLen) {
//                maxLen = currentLen;
//                endIndex = i - 1;
//            }
//            currentLen = 1;
//        }
//    }
//
//    // Kiểm tra dãy con cuối cùng
//    if (currentLen > maxLen) {
//        maxLen = currentLen;
//        endIndex = n - 1;
//    }
//
//    // In ra dãy con giảm dài nhất
//    printf("Day con giam dai nhat trong mang la: ");
//    for (int i = endIndex - maxLen + 1; i <= endIndex; ++i) {
//        printf("%d ", a[i]);
//    }
//    printf("\n");
//}
//
//// Hàm tìm số nhỏ thứ 2 trong mảng
//int secondSmallest(int a[], int n) {
//    if (n < 2) {
//        printf("Mang khong du so phan tu de tim so nho thu 2.\n");
//        return -1;
//    }
//
//    int first, second;
//    first = second = INT_MAX;
//
//    for (int i = 0; i < n; ++i) {
//        if (a[i] < first) {
//            second = first;
//            first = a[i];
//        }
//        else if (a[i] < second && a[i] != first) {
//            second = a[i];
//        }
//    }
//
//    return second;
//}
//
//// Hàm kiểm tra xem một số có chứa các chữ số của x không
//int containsDigits(int number, int x) {
//    while (x > 0) {
//        int digit = x % 10;
//        int found = 0;
//        int temp = number;
//        while (temp > 0) {
//            if (temp % 10 == digit) {
//                found = 1;
//                break;
//            }
//            temp /= 10;
//        }
//        if (!found) {
//            return 0;
//        }
//        x /= 10;
//    }
//    return 1;
//}
//
//// Hàm sắp xếp mảng sao cho các phần tử chẵn tăng dần, các phần tử lẻ giữ nguyên vị trí
//void sortEvenAscending(int a[], int n) {
//    int evenIdx = 0;
//    int temp[MAX_SIZE];
//
//    // Lọc các số chẵn vào mảng tạm
//    for (int i = 0; i < n; ++i) {
//        if (a[i] % 2 == 0) {
//            temp[evenIdx++] = a[i];
//        }
//    }
//
//    // Sắp xếp mảng chẵn
//    for (int i = 0; i < evenIdx - 1; ++i) {
//        for (int j = i + 1; j < evenIdx; ++j) {
//            if (temp[i] > temp[j]) {
//                int swap = temp[i];                  
//                temp[i] = temp[j];
//                temp[j] = swap;
//            }
//        }
//    }
//
//    // Gán lại các số chẵn đã sắp xếp vào mảng ban đầu
//    int idx = 0;
//    for (int i = 0; i < n; ++i) {
//        if (a[i] % 2 == 0) {
//            a[i] = temp[idx++];
//        }
//    }
//}
//
//// Hàm sắp xếp mảng sao cho số lẻ ở đầu mảng, số chẵn ở cuối mảng
//void sortOddEven(int a[], int n) {
//    int left = 0, right = n - 1;
//
//    while (left < right) {
//        // Tìm phần tử lẻ đầu tiên từ bên trái
//        while (a[left] % 2 != 0 && left < right) {
//            left++;
//        }
//        // Tìm phần tử chẵn đầu tiên từ bên phải
//        while (a[right] % 2 == 0 && left < right) {
//            right--;
//        }
//        // Hoán đổi để đưa số lẻ về đầu mảng, số chẵn về cuối mảng
//        if (left < right) {
//            int temp = a[left];
//            a[left] = a[right];
//            a[right] = temp;
//            left++;
//            right--;
//        }
//    }
//}
//
//// Hàm hiển thị menu và xử lý lựa chọn của người dùng
//void displayMenu(int a[], int n) {
//    int choice;
//    do {
//        printf("\nMenu:\n");
//        printf("1. Liệt kê các số nguyên tố nhỏ hơn n\n");
//        printf("2. Tính tổng các phần tử có chữ số đầu là chữ số lẻ\n");
//        printf("3. Liệt kê số lần xuất hiện của các phần tử trong mảng\n");
//        printf("4. Sắp xếp mảng có số chẵn tăng dần, số lẻ giảm dần\n");
//        printf("5. Tìm dãy con giảm dài nhất trong mảng\n");
//        printf("6. Tìm số nhỏ thứ 2 trong mảng\n");
//        printf("7. Tìm các phần tử trong mảng chứa các chữ số của x\n");
//        printf("8. Sắp xếp mảng sao cho các phần tử chẵn tăng dần, các phần tử lẻ giữ nguyên vị trí\n");
//        printf("9. Sắp xếp mảng sao cho số lẻ ở đầu mảng, số chẵn ở cuối mảng\n");
//        printf("0. Thoát\n");
//        printf("Chon chuc nang: ");
//        scanf("%d", &choice);
//
//        switch (choice) {
//        case 1:
//            printf("Nhap vao so nguyen n: ");
//            int num;
//            scanf("%d", &num);
//            findPrimesLessThan(num);
//            break;
//        case 2:
//            printf("Tong cac phan tu co chu so dau la chu so le: %d\n", sumOfFirstDigitOdd(a, n));
//            break;
//        case 3:
//            countOccurrences(a, n);
//            break;
//        case 4:
//            sortEvenOdd(a, n);
//            printf("Mang sau khi sap xep co so chan tang dan, so le giam dan: ");
//            printArray(a, n);
//            break;
//        case 5:
//            longestDecreasingSubarray(a, n);
//            break;
//        case 6:
//            printf("So nho thu 2 trong mang la: %d\n", secondSmallest(a, n));
//            break;
//        case 7:
//            printf("Nhap so x (2 chu so): ");
//            int x;
//            scanf("%d", &x);
//            printf("Cac phan tu trong mang chua cac chu so cua %d:\n", x);
//            for (int i = 0; i < n; ++i) {
//                if (containsDigits(a[i], x)) {
//                    printf("%d ", a[i]);
//                }
//            }
//            printf("\n");
//            break;
//        case 8:
//            sortEvenAscending(a, n);
//            printf("Mang sau khi sap xep cac so chan tang dan, giu nguyen vi tri cac so le: ");
//            printArray(a, n);
//            break;
//        case 9:
//            sortOddEven(a, n);
//            printf("Mang sau khi sap xep so le o dau, so chan o cuoi: ");
//            printArray(a, n);
//            break;
//        case 0:
//            printf("Thoat chuong trinh.\n");
//            break;
//        default:
//            printf("Lua chon khong hop le. Vui long chon lai.\n");
//            break;
//        }
//    } while (choice != 0);
//}
//
//int main() {
//    int a[MAX_SIZE];
//    int n = 15 + rand() % 16; // Số phần tử từ 15 đến 30
//
//    createRandomArray(a, n);
//    printf("Mang ngau nhien da tao: ");
//    printArray(a, n);
//
//    displayMenu(a, n);
//
//    return 0;
//}
