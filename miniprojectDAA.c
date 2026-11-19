#include <stdio.h>

// Linear Search Function
void linearSearch(int arr[], int n, int key) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Linear Search: Element %d found at index %d\n", key, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Linear Search: Element %d not found in the array.\n", key);
    }
}

// Binary Search Function (Divide & Conquer)
int binarySearch(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (key < arr[mid])
            return binarySearch(arr, low, mid - 1, key);
        else
            return binarySearch(arr, mid + 1, high, key);
    }
    return -1;
}

// Find Min and Max Function (Divide & Conquer)
void findMinMax(int arr[], int low, int high, int *min, int *max) {
    if (low == high) {
        *min = *max = arr[low];
    } else if (high == low + 1) {
        if (arr[low] < arr[high]) {
            *min = arr[low];
            *max = arr[high];
        } else {
            *min = arr[high];
            *max = arr[low];
        }
    } else {
        int mid = (low + high) / 2;
        int min1, max1, min2, max2;
        findMinMax(arr, low, mid, &min1, &max1);
        findMinMax(arr, mid + 1, high, &min2, &max2);
        *min = (min1 < min2) ? min1 : min2;
        *max = (max1 > max2) ? max1 : max2;
    }
}

int main() {
    int arr[100], n, key, choice;

    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d array elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n========== MENU ==========\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search (Sorted Array)\n");
        printf("3. Find Min & Max (Divide & Conquer)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to search using Linear Search: ");
                scanf("%d", &key);
                linearSearch(arr, n, key);
                break;

            case 2: {
                printf("Note: Make sure the array is sorted for Binary Search!\n");
                printf("Enter element to search using Binary Search: ");
                scanf("%d", &key);
                int index = binarySearch(arr, 0, n - 1, key);
                if (index != -1)
                    printf("Binary Search: Element %d found at index %d\n", key, index);
                else
                    printf("Binary Search: Element %d not found.\n", key);
                break;
            }

            case 3: {
                int min, max;
                findMinMax(arr, 0, n - 1, &min, &max);
                printf("Minimum element = %d\n", min);
                printf("Maximum element = %d\n", max);
                break;
            }

            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please enter 1–4.\n");
        }

    } while (choice != 4);

    return 0;
}