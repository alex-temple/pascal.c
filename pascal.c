#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    long rows;
    // i = row number, j = position in that row, k = number to print
    int i, j, k = 1, space;

    // check that number of arguments is correct
    if (argc != 2) {
        printf("This command requires ONE argument, <rows>\n");
        return 1;
    }

    // convert first argument to long int
    rows = strtol(argv[1], NULL, 10);
    
    // ensure rows is within required range
    if (rows < 1 || rows > 20) {
        printf("Number of rows must be between 1 and 20 (inclusive)\n");
        return 1;
    }

    // loop through numbers from 0 to <rows>
    for (i = rows - 1; i >= 0; i--) {
        // insert spaces to make it a pyramid
        for (space = 0; space <= (rows - i - 2); space++) {
            printf("   ");
        }

        for (j = 0; j <= i; j++) {
            // if first row or first number of row
            if (i == 0 || j == 0) {
                k = 1;
            }
            else {
                // algorithm to calculate any number in pascal's triangle using the row number (i), position (j) and previous number (k)
                k = k * (i - j + 1) / j;
            }
            // prints a 6-digit number since the largest number in 20 rows is 5 digits long. Layout gets funky after this.
            printf("%6d", k);
        }

        printf("\n");
    }

    return 0;
}