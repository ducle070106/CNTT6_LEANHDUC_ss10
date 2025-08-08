#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Khai báo các hàm
void print_menu();
void add_element(int arr[], int *size);
void remove_element(int arr[], int *size);
void update_element(int arr[], int size);
void find_element(int arr[], int size);
void display_array(int arr[], int size);
void bubble_sort(int arr[], int size);

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice;

    do {
        print_menu();
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_element(arr, &size);
                break;
            case 2:
                remove_element(arr, &size);
                break;
            case 3:
                update_element(arr, size);
                break;
            case 4:
                find_element(arr, size);
                break;
            case 5:
                display_array(arr, size);
                break;
            case 6:
                bubble_sort(arr, size);
                break;
            case 7:
                printf("Thoat chuong trinh. Tam biet!\n");
                exit(0);
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 7);

    return 0;
}

// Hàm hiển thị menu
void print_menu() {
    printf("\n---------- Quan ly danh sach so nguyen ----------\n");
    printf("1. Them phan tu vao vi tri bat ky\n");
    printf("2. Xoa phan tu o vi tri bat ky\n");
    printf("3. Cap nhat gia tri tai vi tri bat ky\n");
    printf("4. Tim kiem phan tu trong mang\n");
    printf("5. Hien thi mang\n");
    printf("6. Sap xep mang (Bubble Sort)\n");
    printf("7. Thoat chuong trinh\n");
    printf("---------------------------------------------------\n");
}

// Hàm thêm phần tử vào mảng
void add_element(int arr[], int *size) {
    if (*size >= MAX_SIZE) {
        printf("Mang da day. Khong the them phan tu.\n");
        return;
    }

    int position, value;
    printf("Nhap gia tri can them: ");
    scanf("%d", &value);
    printf("Nhap vi tri can them (tu 0 den %d): ", *size);
    scanf("%d", &position);

    if (position < 0 || position > *size) {
        printf("Vi tri khong hop le.\n");
        return;
    }

    // Dịch chuyển các phần tử để tạo khoảng trống
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = value;
    (*size)++;
    printf("Da them phan tu thanh cong.\n");
}

// Hàm xóa phần tử khỏi mảng
void remove_element(int arr[], int *size) {
    if (*size == 0) {
        printf("Mang rong. Khong the xoa phan tu.\n");
        return;
    }

    int position;
    printf("Nhap vi tri can xoa (tu 0 den %d): ", *size - 1);
    scanf("%d", &position);

    if (position < 0 || position >= *size) {
        printf("Vi tri khong hop le.\n");
        return;
    }

    // Dịch chuyển các phần tử để lấp đầy khoảng trống
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--;
    printf("Da xoa phan tu thanh cong.\n");
}

// Hàm cập nhật giá trị phần tử
void update_element(int arr[], int size) {
    if (size == 0) {
        printf("Mang rong. Khong the cap nhat.\n");
        return;
    }

    int position, new_value;
    printf("Nhap vi tri can cap nhat (tu 0 den %d): ", size - 1);
    scanf("%d", &position);

    if (position < 0 || position >= size) {
        printf("Vi tri khong hop le.\n");
        return;
    }

    printf("Nhap gia tri moi: ");
    scanf("%d", &new_value);
    arr[position] = new_value;
    printf("Da cap nhat phan tu thanh cong.\n");
}
void find_element(int arr[], int size) {
    if (size == 0) {
        printf("Mang rong. Khong the tim kiem.\n");
        return;
    }
    int value;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &value);
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            printf("Tim thay phan tu %d tai vi tri %d.\n", value, i);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay phan tu %d trong mang.\n", value);
    }
}
void display_array(int arr[], int size) {
    if (size == 0) {
        printf("Mang rong.\n");
        return;
    }

    printf("Cac phan tu trong mang la: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void bubble_sort(int arr[], int size) {
    if (size <= 1) {
        printf("Mang khong can sap xep.\n");
        return;
    }
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Da sap xep mang theo thu tu tang dan.\n");
}