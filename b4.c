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
        temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}
void print_array(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int array[] = {64, 25, 12, 22, 11};
    int size = sizeof(array) / sizeof(array[0]);
    printf("Original array: \n");
    print_array(array, size);
    selection_sort(array, size);
    printf("Sorted array (ascending order): \n");
    print_array(array, size);

    return 0;
}