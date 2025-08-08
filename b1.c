#include <stdio.h>

void linear_search(int arr[], int size) {
    int searchValue;
    int foundIndex = -1;
    printf("Enter an element to search for: ");
    scanf("%d", &searchValue);
    for (int i = 0; i < size; i++) {
        if (arr[i] == searchValue) {
            foundIndex = i;
            printf("Element %d found at index %d.\n", searchValue, foundIndex);
        }
    }
    if (foundIndex == -1) {
        printf("Element %d was not found in the array.\n", searchValue);
    }
}
int main() {
    int array[] = {10, 5, 22, 17, 8, 31, 14};
    int size = sizeof(array) / sizeof(array[0]);

    printf("The initialized array is: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    linear_search(array, size);
    return 0;
}