/* One-dimensional cellular automata using pointer arithmetic. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "memcheck.h"
#include <assert.h>
#include <time.h>

int * update(int *cells, int num_cells);
int print_row(int *cells, int num_cells);

/* Updates a row using pointer arithmetic. 
 * Arguments is a pointer to an array of integers 
 * and the number of cells in the array.
 * Return value is a pointer to an array of the new row.
 */

int * update(int *cells, int num_cells) {
    int i;
    int *temp;
    int *prev;
    int *next;
    temp = (int *) calloc(num_cells, sizeof(int));
    prev = cells;
    next = cells;

    /* Make first cell random. */
    temp[0] = rand() % 2;

    /* cells needs to start at 2nd cell. */
    cells ++;
    /* next needs to start at 3rd cell. */
    next ++;
    next ++;

    /* Fill in the reset of the next generation by the given pattern. */    
    for(i = 1; i < num_cells; i ++) {
        if(*cells == 0) {
            if((*(prev) == 1) & (*(next) == 0)) {
                temp[i] = 1;
            } else if((*(prev) == 0) & (*(next) == 1)) {
                temp[i] = 1;
            } else {
                temp[i] = 0;
            }
        } else {
            temp[i] = 0;
        }
        cells ++;
        prev ++;
        next ++;
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
    
    /* Get input from command-line. */
    num_cells = atoi(argv[1]);
    num_generations = atoi(argv[2]);

    /* Allocate memory for num_cell ints. */
    cells = (int *) calloc(num_cells, sizeof(int));

    /* Intialize random number generator. */
    srand(time(NULL));

    /* Fill cells with 0 or 1 */
    /* First and last cells are 0. */
    cells[0] = 0;
    cells[num_cells - 1] = 0;

    for(i = 1; i < num_cells - 1; i ++) {
        cells[i] = rand() % 2;
    }

    for(i = 0; i < num_generations; i ++) {
        cells = update(cells, num_cells);
        print_row(cells, num_cells);
    }
    
    print_memory_leaks();
    return 0;
}
