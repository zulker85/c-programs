#include <stdio.h>
#include <string.h>

#define MAX_NAMES 100
#define MAX_LENGTH 50

void sortNames(char names[][MAX_LENGTH], int n) {
    for (int i = 1; i < n; i++) {
        char key[MAX_LENGTH];
        strcpy(key, names[i]);
        int j = i - 1;

        // Move elements of names[0..i-1] that are greater than key
        while (j >= 0 && strcmp(names[j], key) > 0) {
            strcpy(names[j + 1], names[j]);
            j--;
        }
        strcpy(names[j + 1], key);
    }
}

int binarySearch(char names[][MAX_LENGTH], int n, char *target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        int comparison = strcmp(names[mid], target);
        if (comparison == 0) {
            return mid; // Name found
        }
        if (comparison < 0) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }
    return -1; // Name not found
}

int main() {
    char names[MAX_NAMES][MAX_LENGTH];
    int n;

    printf("Enter the number of names: ");
    scanf("%d", &n);

    printf("Enter the names:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]); // Input names
    }

    sortNames(names, n); // Sort names

    char target[MAX_LENGTH];
    printf("Enter the name to search: ");
    scanf("%s", target); // Input name to search

    int result = binarySearch(names, n, target);
    if (result != -1) {
        printf("Name '%s' found at index %d.\n", target, result);
    } else {
        printf("Name '%s' not found in the list.\n", target);
    }

    return 0;
}
