#include <stdio.h>

void selection_sort(int arr[], int size) {
    int i, j, min_index, temp;
    for (i = 0; i < size - 1; i++) {
        min_index = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            temp = arr[min_index];
            arr[min_index] = arr[i];
            arr[i] = temp;
        }
    }
}
int binary_search(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}
void print_array(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {

    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(array) / sizeof(array[0]);
    int search_value, result_index;
    printf("Original array: \n");
    print_array(array, size);
    selection_sort(array, size);
    printf("Sorted array (ascending order): \n");
    print_array(array, size);
    printf("\nEnter an integer to search for: ");
    scanf("%d", &search_value);
    result_index = binary_search(array, size, search_value);
    if (result_index != -1) {
        printf("Element %d found at index %d in the sorted array.\n", search_value, result_index);
    } else {
        printf("Element %d not found in the array.\n", search_value);
    }

    return 0;
}