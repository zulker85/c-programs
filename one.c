#include <stdio.h>

int main() {
    int i, j, n, m, a[10][1023];

    printf("Enter the size of rows and columns in matrix:\n");
    scanf("%d %d", &m, &n);  // m is rows, n is columns

    printf("Enter the elements of matrix:\n");
    for (i = 0; i < m; i++) {  // Loop through rows
        for (j = 0; j < n; j++) {  // Loop through columns
            scanf("%d", &a[i][j]);  // Read into the matrix
        }
    }

    printf("The matrix is:\n");
    for (i = 0; i < m; i++) {  // Loop through rows
        for (j = 0; j < n; j++) {  // Loop through columns
            printf("%d ", a[i][j]);  // Print each element
        }
        printf("\n");  // New line after each row
    }

    return 0;  // Return 0 to indicate successful execution
}
