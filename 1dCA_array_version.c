/* One-dimensional cellular automata */
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "memcheck.h"
#include <assert.h>
#include <time.h>

int * update(int *cells, int num_cells);
int print_row(int *cells, int num_cells);

/* Updates a row. 
 * Arguments is a pointer to an array of integers 
 * and the number of cells in the array.
 * Return value is a pointer to an array of the new row.
 */

int * update(int *cells, int num_cells) {
    int i;
    int *temp;
    temp = (int *)malloc(num_cells * sizeof(int));

    /* Check if malloc failed. */
    if (temp == NULL) { 
        fprintf(stderr, "Error: malloc() failed.\n");
        exit(1);  /* Give up, abort program. */
    }

    /* Make first cell random */
    temp[0] = rand() % 2;

    /* Fill in the reset of the next generation by the given pattern. */    
    for(i = 1; i < num_cells; i ++) {
        if(cells[i] == 0) {
            if((cells[i - 1] == 1) & (cells[i + 1] == 0)) {
                temp[i] = 1;
            } else if((cells[i -1] == 0) & (cells[i + 1] == 1)) {
                temp[i] = 1;
            }
        } else {
            temp[i] = 0;
        }
    }


    return temp;
}

/* Prints a row as "*" or ".".
 * Arguments are a pointer to an array of integers and the number of cells.
 */

int print_row(int *cells, int num_cells) {
    int i = 0;
    /* Print */
    for(i = 0; i < num_cells; i ++) {
        if(cells[i] == 0) {
            printf(".");
        } else {
            printf("*");
        }
    }
    printf("\n");
    return 0;
}

int main(int argc, char *argv[]) {
    int num_cells;
    int num_generations;
    int *cells;
    int i = 0;

    /* Get inpupt from command line. */
    if(!(argc == 3)) {
        /* incorrect number of elements. Must throw error. */
        fprintf(stderr, "usage: %s should have 2 arguments; \
                the number cells and the number of generations.\n", argv[0]);
        exit(1);
    }

    /* Get input from command line. */
    num_cells = atoi(argv[1]);
    num_generations = atoi(argv[2]);

    /* Allocate memory for num_cell ints. */
    cells = (int *)malloc(num_cells * sizeof(int));

    /* Check if malloc failed. */
    if (cells == NULL) {
        fprintf(stderr, "Error: malloc() failed.\n");
        exit(1);  /* Give up, abort program. */
    }

    /* Intialize random number generator. */
    srand(time(NULL));

    /* Fill cells with 0 or 1 */
    /* First and last cells are 0. */
    cells[0] = 0;
    cells[num_cells - 1] = 0;

    for(i = 1; i < num_cells - 1; i ++) {
        cells[i] = rand() % 2;
    }
    print_row(cells, num_cells);

    for(i = 0; i < num_generations; i ++) {
        cells = update(cells, num_cells);
        print_row(cells, num_cells);
    }

    free(cells);

    print_memory_leaks();
    return 0;
}
