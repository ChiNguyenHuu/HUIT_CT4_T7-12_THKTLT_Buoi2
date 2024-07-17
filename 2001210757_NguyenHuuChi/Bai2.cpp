#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a mixed number
typedef struct {
    int integer_part;
    int numerator;
    int denominator;
} MixedNumber;

// Function to generate a random integer in a specific range
int random_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to generate a random mixed number
MixedNumber generate_mixed_number() {
    MixedNumber mixed_num;
    mixed_num.integer_part = random_int(1, 10);      // Random integer part (1-10)
    mixed_num.numerator = random_int(1, 9);          // Random numerator (1-9)
    mixed_num.denominator = random_int(1, 9);        // Random denominator (1-9)
    while (mixed_num.numerator >= mixed_num.denominator) {
        mixed_num.numerator = random_int(1, 9);
        mixed_num.denominator = random_int(1, 9);
    }
    return mixed_num;
}

// Function to display mixed numbers in the array
void display_mixed_numbers(MixedNumber* arr, int size) {
    printf("Danh sach hon so:\n");
    for (int i = 0; i < size; i++) {
        printf("%d + %d/%d\n", arr[i].integer_part, arr[i].numerator, arr[i].denominator);
    }
}

// Function to compare two mixed numbers
int compare_mixed_numbers(MixedNumber num1, MixedNumber num2) {
    float value1 = num1.integer_part + (float)num1.numerator / num1.denominator;
    float value2 = num2.integer_part + (float)num2.numerator / num2.denominator;
    if (value1 < value2) return -1;
    else if (value1 > value2) return 1;
    else return 0;
}

// Function to convert mixed number to fraction
void mixed_number_to_fraction(MixedNumber mixed_num, int* integer_part, int* numerator, int* denominator) {
    *integer_part = mixed_num.integer_part;
    *numerator = mixed_num.numerator;
    *denominator = mixed_num.denominator;
}

// Function to convert fraction to mixed number
MixedNumber fraction_to_mixed_number(int integer_part, int numerator, int denominator) {
    MixedNumber mixed_num;
    mixed_num.integer_part = integer_part;
    mixed_num.numerator = numerator;
    mixed_num.denominator = denominator;
    return mixed_num;
}

// Function to perform arithmetic operations on mixed numbers
MixedNumber operate_on_mixed_numbers(MixedNumber num1, MixedNumber num2, char operation) {
    MixedNumber result;
    float value1 = num1.integer_part + (float)num1.numerator / num1.denominator;
    float value2 = num2.integer_part + (float)num2.numerator / num2.denominator;

    switch (operation) {
    case '+':
        result.integer_part = (int)(value1 + value2);
        result.numerator = (value1 + value2 - result.integer_part) * num1.denominator * num2.denominator;
        result.denominator = num1.denominator * num2.denominator;
        break;
    case '-':
        result.integer_part = (int)(value1 - value2);
        result.numerator = (value1 - value2 - result.integer_part) * num1.denominator * num2.denominator;
        result.denominator = num1.denominator * num2.denominator;
        break;
    case '*':
        result.integer_part = (int)(value1 * value2);
        result.numerator = (value1 * value2 - result.integer_part) * num1.denominator * num2.denominator;
        result.denominator = num1.denominator * num2.denominator;
        break;
    case '/':
        result.integer_part = (int)(value1 / value2);
        result.numerator = (value1 / value2 - result.integer_part) * num1.denominator * num2.denominator;
        result.denominator = num1.denominator * num2.denominator;
        break;
    default:
        printf("Phep tinh khong hop le.\n");
        exit(EXIT_FAILURE);
    }

    // Simplify the fraction
    int gcd = 1;
    int min = (result.numerator < result.denominator) ? result.numerator : result.denominator;
    for (int i = 2; i <= min; i++) {
        if (result.numerator % i == 0 && result.denominator % i == 0) {
            gcd = i;
        }
    }
    result.numerator /= gcd;
    result.denominator /= gcd;

    return result;
}

// Function to swap two mixed numbers
void swap(MixedNumber* a, MixedNumber* b) {
    MixedNumber temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bubble sort on array in ascending order
void bubble_sort_asc(MixedNumber* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (compare_mixed_numbers(arr[j], arr[j + 1]) > 0) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Function to perform selection sort on array in descending order
void selection_sort_desc(MixedNumber* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (compare_mixed_numbers(arr[j], arr[max_idx]) > 0) {
                max_idx = j;
            }
        }
        if (max_idx != i) {
            swap(&arr[i], &arr[max_idx]);
        }
    }
}

// Function to perform insertion sort on array in ascending order
void insertion_sort_asc(MixedNumber* arr, int size) {
    for (int i = 1; i < size; i++) {
        MixedNumber key = arr[i];
        int j = i - 1;
        while (j >= 0 && compare_mixed_numbers(key, arr[j]) < 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Main function to run the program
int main() {
    srand(time(NULL));  // Seed for random number generation
    int choice, n;
    MixedNumber* b = NULL;

    while (1) {
        printf("\n======== MENU ========");
        printf("\n1. Tao mang hon so ngau nhien");
        printf("\n2. Xuat danh sach hon so");
        printf("\n3. So sanh 2 hon so");
        printf("\n4. Chuyen hon so -> phan so");
        printf("\n5. Chuyen phan so -> hon so");
        printf("\n6. Tinh tong, hieu, tich, thuong 2 hon so");
        printf("\n7. Sap xep mang");
        printf("\n8. Thoat");
        printf("\n\nNhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (b != NULL) free(b);  // Free memory if array already exists
            printf("Nhap so luong hon so muon tao: ");
            scanf("%d", &n);
            b = (MixedNumber*)malloc(n * sizeof(MixedNumber));
            for (int i = 0; i < n; i++) {
                b[i] = generate_mixed_number();
            }
            printf("Da tao mang hon so ngau nhien.\n");
            break;
        case 2:
            if (b == NULL) {
                printf("Mang chua duoc tao.\n");
            }
            else {
                display_mixed_numbers(b, n);
            }
            break;
        case 3:
            if (b == NULL || n < 2) {
                printf("Khong du hon so de so sanh.\n");
            }
            else {
                int idx1, idx2;
                printf("Nhap chi so cua hon so thu nhat: ");
                scanf("%d", &idx1);
                printf("Nhap chi so cua hon so thu hai: ");
                scanf("%d", &idx2);
                int result = compare_mixed_numbers(b[idx1], b[idx2]);
                if (result < 0) {
                    printf("%d/%d nho hon %d/%d\n", b[idx1].integer_part, b[idx1].numerator, b[idx1].denominator,
                        b[idx2].integer_part, b[idx2].numerator, b[idx2].denominator);
                }
                else if (result > 0) {
                    printf("%d/%d lon hon %d/%d\n", b[idx1].integer_part, b[idx1].numerator, b[idx1].denominator,
                        b[idx2].integer_part, b[idx2].numerator, b[idx2].denominator);
                }
                else {
                    printf("%d/%d bang %d/%d\n", b[idx1].integer_part, b[idx1].numerator, b[idx1].denominator,
                        b[idx2].integer_part, b[idx2].numerator, b[idx2].denominator);
                }
            }
            break;
        case 4:
            if (b == NULL || n == 0) {
                printf("Mang chua duoc tao hoac rong.\n");
            }
            else {
                int idx;
                printf("Nhap chi so cua hon so can chuyen: ");
                scanf("%d", &idx);
                MixedNumber mixed_num = b[idx];
                int integer_part = mixed_num.integer_part;
                int numerator = mixed_num.numerator;
                int denominator = mixed_num.denominator;
                printf("Hon so %d + %d/%d duoc chuyen thanh phan so: %d + %d/%d\n", integer_part, numerator,
                    denominator, integer_part, numerator, denominator);
            }
            break;
        case 5:
            if (b == NULL || n == 0) {
                printf("Mang chua duoc tao hoac rong.\n");
            }
            else {
                int integer_part, numerator, denominator;
                printf("Nhap phan nguyen cua phan so: ");
                scanf("%d", &integer_part);
                printf("Nhap tu so cua phan so: ");
                scanf("%d", &numerator);
                printf("Nhap mau so cua phan so: ");
                scanf("%d", &denominator);
                MixedNumber mixed_num = fraction_to_mixed_number(integer_part, numerator, denominator);
                printf("Phan so %d + %d/%d duoc chuyen thanh hon so: %d + %d/%d\n", integer_part, numerator,
                    denominator, mixed_num.integer_part, mixed_num.numerator, mixed_num.denominator);
            }
            break;
        case 6:
            if (b == NULL || n < 2) {
                printf("Khong du hon so de thuc hien phep tinh.\n");
            }
            else {
                int idx1, idx2;
                char operation;
                printf("Nhap chi so cua hon so thu nhat: ");
                scanf("%d", &idx1);
                printf("Nhap chi so cua hon so thu hai: ");
                scanf("%d", &idx2);
                printf("Nhap phep tinh (+, -, *, /): ");
                scanf(" %c", &operation);
                MixedNumber result = operate_on_mixed_numbers(b[idx1], b[idx2], operation);
                printf("Ket qua cua phep tinh %d + %d/%d %c %d + %d/%d la: %d + %d/%d\n", b[idx1].integer_part,
                    b[idx1].numerator, b[idx1].denominator, operation, b[idx2].integer_part, b[idx2].numerator,
                    b[idx2].denominator, result.integer_part, result.numerator, result.denominator);
            }
            break;
        case 7:
            if (b == NULL || n == 0) {
                printf("Mang chua duoc tao hoac rong.\n");
            }
            else {
                int sort_choice;
                printf("Chon thuat toan sap xep:\n");
                printf("1. Bubble sort tang dan\n");
                printf("2. Selection sort giam dan\n");
                printf("3. Insertion sort tang dan\n");
                printf("Nhap lua chon cua ban: ");
                scanf("%d", &sort_choice);
                switch (sort_choice) {
                case 1:
                    bubble_sort_asc(b, n);
                    printf("Da sap xep mang theo bubble sort tang dan.\n");
                    break;
                case 2:
                    selection_sort_desc(b, n);
                    printf("Da sap xep mang theo selection sort giam dan.\n");
                    break;
                case 3:
                    insertion_sort_asc(b, n);
                    printf("Da sap xep mang theo insertion sort tang dan.\n");
                    break;
                default:
                    printf("Lua chon khong hop le.\n");
                    break;
                }
            }
            break;
        case 8:
            printf("Thoat chuong trinh.\n");
            if (b != NULL) free(b);  // Free dynamically allocated memory
            return 0;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
            break;
        }
    }

    return 0;
}
