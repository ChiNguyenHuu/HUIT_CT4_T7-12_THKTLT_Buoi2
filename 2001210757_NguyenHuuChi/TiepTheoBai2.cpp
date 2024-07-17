#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

const int MAX_SIZE = 20; // Kích th??c t?i ?a cho m?ng

// Struct ??nh ngh?a h?n s?
typedef struct {
    int phanNguyen;
    int phanDu;
} HonSo;

// Hàm ?? t?o m?ng m?t chi?u ng?u nhiên
void createRandomArray(int a[], int n) {
    srand(time(NULL)); // Kh?i t?o seed cho hàm rand() d?a trên th?i gian hi?n t?i
    for (int i = 0; i < n; ++i) {
        a[i] = rand() % 101; // Sinh s? ng?u nhiên t? 0 ??n 100
    }
}

// Hàm ?? in m?ng ra màn hình
void printArray(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Hàm ?? in m?ng h?n s? ra màn hình
void printHonSoArray(HonSo b[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d + %d/%d ", b[i].phanNguyen, b[i].phanDu, 100); // 100 là m?u s? c? ??nh cho phân s?
    }
    printf("\n");
}

// Hàm ?? ki?m tra s? nguyên t?
int isPrime(int number) {
    if (number < 2) {
        return 0; // Không ph?i s? nguyên t?
    }
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) {
            return 0; // Không ph?i s? nguyên t?
        }
    }
    return 1; // Là s? nguyên t?
}

// Bài 1: Tìm h?n s? x trong m?ng b theo gi?i thu?t Linear Search
void findHonSoLinearSearch(HonSo b[], int n) {
    int phanNguyen, phanDu;
    printf("Nhap phan nguyen cua hon so can tim: ");
    scanf("%d", &phanNguyen);
    printf("Nhap phan du cua hon so can tim: ");
    scanf("%d", &phanDu);

    int found = 0;
    for (int i = 0; i < n; ++i) {
        if (b[i].phanNguyen == phanNguyen && b[i].phanDu == phanDu) {
            printf("Hon so (%d + %d/%d) duoc tim thay tai vi tri %d.\n", phanNguyen, phanDu, 100, i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay hon so (%d + %d/%d) trong mang.\n", phanNguyen, phanDu, 100);
    }
}

// Bài 2: S?p x?p m?ng b sao cho các ph?n t? có ph?n nguyên ch?n lên ??u, ph?n t? có ph?n nguyên l? ? cu?i m?ng
void sortHonSoEvenFirst(HonSo b[], int n) {
    // S? d?ng ph??ng pháp s?p x?p n?i b?t cho ??n gi?n
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (b[j].phanNguyen % 2 != 0 && b[j + 1].phanNguyen % 2 == 0) {
                // Hoán ??i hai ph?n t?
                HonSo temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }

    printf("Mang sau khi sap xep phan nguyen chan len dau, le xuong cuoi: ");
    printHonSoArray(b, n);
}

// Bài 3: Tìm h?n s? x theo gi?i thu?t Binary Search trong m?ng b ?ã ???c s?p x?p
int binarySearchHonSo(HonSo b[], int n, int phanNguyen, int phanDu) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (b[mid].phanNguyen == phanNguyen && b[mid].phanDu == phanDu) {
            return mid;
        }
        else if (b[mid].phanNguyen < phanNguyen || (b[mid].phanNguyen == phanNguyen && b[mid].phanDu < phanDu)) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1; // Không tìm th?y
}

// Bài 4: Chia m?ng b thành 2 m?ng s1 và s2, v?i s1 ch?a các ph?n nguyên, s2 ch?a phân s?
void divideHonSoArray(HonSo b[], int n, int s1[], int* lenS1, HonSo s2[], int* lenS2) {
    *lenS1 = 0;
    *lenS2 = 0;
    for (int i = 0; i < n; ++i) {
        if (b[i].phanDu == 0) {
            s1[(*lenS1)++] = b[i].phanNguyen;
        }
        else {
            s2[(*lenS2)++] = b[i];
        }
    }
}

// Bài 5: Xóa ph?n t? th? k trong m?ng b
void deleteElementHonSo(HonSo b[], int* n, int k) {
    if (k < 0 || k >= *n) {
        printf("Vi tri xoa khong hop le.\n");
        return;
    }

    for (int i = k; i < *n - 1; ++i) {
        b[i] = b[i + 1];
    }
    (*n)--;
}

// Bài 6: Thêm h?n s? x vào m?ng b t?i v? trí k
void insertElementHonSo(HonSo b[], int* n, int k, int phanNguyen, int phanDu) {
    if (k < 0 || k > *n) {
        printf("Vi tri them khong hop le.\n");
        return;
    }

    // D?i các ph?n t? sang ph?i ?? làm ch? tr?ng cho ph?n t? m?i
    for (int i = *n; i > k; --i) {
        b[i] = b[i - 1];
    }

    // Thêm ph?n t? m?i vào v? trí k
    b[k].phanNguyen = phanNguyen;
    b[k].phanDu = phanDu;
    (*n)++;
}

// Hàm ?? tính ??c chung l?n nh?t c?a hai s?
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Bài 7: T?o m?ng c ch?a các ph?n t? là phân s? ???c ??i t? các ph?n t? h?n s? c?a m?ng b
void convertToFractionArray(HonSo b[], int n, double c[]) {
    for (int i = 0; i < n; ++i) {
        c[i] = (double)b[i].phanNguyen + (double)b[i].phanDu / 100; // Chuy?n h?n s? thành phân s?
    }
}

// Bài 8: Tính t?ng các ph?n t? c?a m?ng b
double sumHonSoArray(HonSo b[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += (double)b[i].phanNguyen + (double)b[i].phanDu / 100;
    }
    return sum;
}

// Bài 9: Tìm ph?n t? l?n nh?t c?a m?ng
HonSo findMaxHonSo(HonSo b[], int n) {
    HonSo maxHonSo = b[0];
    for (int i = 1; i < n; ++i) {
        if (b[i].phanNguyen > maxHonSo.phanNguyen || (b[i].phanNguyen == maxHonSo.phanNguyen && b[i].phanDu > maxHonSo.phanDu)) {
            maxHonSo = b[i];
        }
    }
    return maxHonSo;
}

// Bài 10: Tính trung bình c?ng c?a m?ng b
double averageHonSoArray(HonSo b[], int n) {
    double sum = sumHonSoArray(b, n);
    return sum / n;
}

// Bài 11: ??m s? l??ng s? nguyên t? trong m?ng b
int countPrimeHonSo(HonSo b[], int n) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        int phanNguyen = b[i].phanNguyen;
        if (isPrime(phanNguyen)) {
            count++;
        }
    }
    return count;
}

// Bài 12: Xoá t?t c? các s? nguyên t? kh?i m?ng b
void deleteAllPrimeHonSo(HonSo b[], int* n) {
    int i = 0;
    while (i < *n) {
        if (isPrime(b[i].phanNguyen)) {
            deleteElementHonSo(b, n, i);
        }
        else {
            i++;
        }
    }
}

// Bài 13: Thêm m?t s? nguyên t? vào cu?i m?ng b
void addPrimeHonSo(HonSo b[], int* n) {
    int prime = 2; // Tìm s? nguyên t? ??u tiên là 2
    while (!isPrime(prime)) {
        prime++;
    }
    b[*n].phanNguyen = prime;
    b[*n].phanDu = 0;
    (*n)++;
}

// Bài 14: ??o ng??c m?ng b
void reverseHonSoArray(HonSo b[], int n) {
    for (int left = 0, right = n - 1; left < right; ++left, --right) {
        HonSo temp = b[left];
        b[left] = b[right];
        b[right] = temp;
    }
}

// Hàm main ?? th?c thi ch??ng trình
int main() {
    HonSo b[MAX_SIZE];
    int n;
    printf("Nhap so luong hon so (n <= %d): ", MAX_SIZE);
    scanf("%d", &n);

    // Nh?p m?ng h?n s?
    for (int i = 0; i < n; ++i) {
        printf("Nhap phan nguyen cua hon so thu %d: ", i + 1);
        scanf("%d", &b[i].phanNguyen);
        printf("Nhap phan du cua hon so thu %d: ", i + 1);
        scanf("%d", &b[i].phanDu);
    }

    printf("Mang hon so vua nhap:\n");
    printHonSoArray(b, n);

    // Th?c hi?n các ch?c n?ng trong menu

    int choice;
    do {
        printf("\n");
        printf("Lua chon chuc nang:\n");
        printf("1. Tim hon so theo giai thuat Linear Search\n");
        printf("2. Sap xep mang hon so sao cho phan nguyen chan len dau, le xuong cuoi\n");
        printf("3. Tim hon so theo giai thuat Binary Search\n");
        printf("4. Chia mang hon so thanh 2 mang s1 va s2\n");
        printf("5. Xoa phan tu thu k trong mang hon so\n");
        printf("6. Them hon so vao mang tai vi tri k\n");
        printf("7. Chuyen mang hon so thanh mang phan so\n");
        printf("8. Tinh tong cac phan tu cua mang hon so\n");
        printf("9. Tim hon so lon nhat trong mang\n");
        printf("10. Tinh trung binh cong cua mang hon so\n");
        printf("11. Dem so luong so nguyen to trong mang hon so\n");
        printf("12. Xoa tat ca cac so nguyen to trong mang hon so\n");
        printf("13. Them mot so nguyen to vao cuoi mang hon so\n");
        printf("14. Dao nguoc mang hon so\n");
        printf("0. Thoat chuong trinh\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            findHonSoLinearSearch(b, n);
            break;
        }
        case 2: {
            sortHonSoEvenFirst(b, n);
            break;
        }
        case 3: {
            // Tr??c tiên c?n ph?i s?p x?p m?ng b theo ph?n nguyên ?? th?c hi?n Binary Search
            sortHonSoEvenFirst(b, n);
            int phanNguyen, phanDu;
            printf("Nhap phan nguyen cua hon so can tim: ");
            scanf("%d", &phanNguyen);
            printf("Nhap phan du cua hon so can tim: ");
            scanf("%d", &phanDu);
            int result = binarySearchHonSo(b, n, phanNguyen, phanDu);
            if (result != -1) {
                printf("Hon so (%d + %d/%d) duoc tim thay tai vi tri %d.\n", phanNguyen, phanDu, 100, result);
            }
            else {
                printf("Khong tim thay hon so (%d + %d/%d) trong mang.\n", phanNguyen, phanDu, 100);
            }
            break;
        }
        case 4: {
            int s1[MAX_SIZE], lenS1 = 0;
            HonSo s2[MAX_SIZE];
            int lenS2 = 0;
            divideHonSoArray(b, n, s1, &lenS1, s2, &lenS2);
            printf("Mang s1 chua cac phan nguyen: ");
            printArray(s1, lenS1);
            printf("Mang s2 chua cac phan so: ");
            printHonSoArray(s2, lenS2);
            break;
        }
        case 5: {
            int k;
            printf("Nhap vi tri phan tu can xoa (0 <= k < %d): ", n);
            scanf("%d", &k);
            deleteElementHonSo(b, &n, k);
            printf("Mang sau khi xoa phan tu thu %d: ", k);
            printHonSoArray(b, n);
            break;
        }
        case 6: {
            int k, phanNguyen, phanDu;
            printf("Nhap vi tri can them (0 <= k <= %d): ", n);
            scanf("%d", &k);
            printf("Nhap phan nguyen cua hon so moi: ");
            scanf("%d", &phanNguyen);
            printf("Nhap phan du cua hon so moi: ");
            scanf("%d", &phanDu);
            insertElementHonSo(b, &n, k, phanNguyen, phanDu);
            printf("Mang sau khi them hon so moi: ");
            printHonSoArray(b, n);
            break;
        }
        case 7: {
            double c[MAX_SIZE];
            convertToFractionArray(b, n, c);
            printf("Mang sau khi chuyen doi thanh mang phan so:\n");
            for (int i = 0; i < n; ++i) {
                printf("%.2f ", c[i]);
            }
            printf("\n");
            break;
        }
        case 8: {
            double sum = sumHonSoArray(b, n);
            printf("Tong cac phan tu cua mang hon so: %.2f\n", sum);
            break;
        }
        case 9: {
            HonSo maxHonSo = findMaxHonSo(b, n);
            printf("Hon so lon nhat trong mang: %d + %d/%d\n", maxHonSo.phanNguyen, maxHonSo.phanDu, 100);
            break;
        }
        case 10: {
            double average = averageHonSoArray(b, n);
            printf("Trung binh cong cac phan tu cua mang hon so: %.2f\n", average);
            break;
        }
        case 11: {
            int count = countPrimeHonSo(b, n);
            printf("So luong so nguyen to trong mang hon so: %d\n", count);
            break;
        }
        case 12: {
            deleteAllPrimeHonSo(b, &n);
            printf("Mang sau khi xoa tat ca cac so nguyen to:\n");
            printHonSoArray(b, n);
            break;
        }
        case 13: {
            addPrimeHonSo(b, &n);
           
            printf("Mang sau khi them mot so nguyen to:\n");
            printHonSoArray(b, n);
            break;
        }
        case 14: {
            reverseHonSoArray(b, n);
            printf("Mang sau khi dao nguoc:\n");
            printHonSoArray(b, n);
            break;
        }
        case 0: {
            printf("Ket thuc chuong trinh.\n");
            break;
        }
        default: {
            printf("Lua chon khong hop le. Vui long chon lai.\n");
            break;
        }
        }
    } while (choice != 0);

    return 0;
}

