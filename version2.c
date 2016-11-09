#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "memcheck.h"
#include <assert.h>
#include <time.h>

int update(int *cells, int num_cells);
int print_row(int *cells, int num_cells);

int update(int *cells, int num_cells) {
    int i;
    int *temp;
    int *cell_before = cells;
    int *cell_after = cells;
    temp = (int *) malloc(num_cells * sizeof(int));
   /* cell_before = (int *) malloc((num_cells - 1) * sizeof(int));
    cells_after = (int *) malloc((num_cells - 1) * sizeof(int));
*/

    /* Make first cell random*/
    *temp = rand() % 2;
    temp ++;

    /* Set cells, cell_before, and cell_after to the right starting numbers. */
    cells += 2;
    cell_after ++;


    /* Fill in the reset of the next generation by the given pattern. */    
    for(i = 1; i < num_cells; i ++){
        if(*cells == 0) {
            if((*cell_before == 1) & (*cell_after == 0)){
                *temp = 1;
            } else if((*cell_before == 0) & (*cell_after == 1)) {
                *temp = 1;
            }
        } else {
            *temp = 0;
        }

        /* Increment all pointers. */
        temp ++;
        cells ++;
        cell_before ++;
        cell_after ++;
    }
    /*free(temp);*/
    return temp;
}

int print_row(int *cells, int num_cells) {
    int i = 0;
    /* Print */
    for(i = 0; i < num_cells; i ++) {
        if(*cells == 0) {
            printf(".");
        } else {
            printf("*");
        }

        cells ++;
    }
    printf("\n");
    return 0;
}

int main(int argc, char *argv[]) {
    int num_cells;
    int num_generations;
    int *cells;
    int i = 0;
    /*time_t t;*/

    /* Get inpupt from command line. */
    if(!(argc == 3)) {
        /*incorrect number of elements. Must throw error. */
        fprintf(stderr, "usage: %s should have 2 arguments; the number cells and the number of generations.\n", argv[0]);
        exit(1);
    }

    num_cells = atoi(argv[1]);
    num_generations = atoi(argv[2]);

    printf("cells = %d, generations = %d\n", num_cells, num_generations);

    /* Allocate memory for num_cell ints. */
    cells = (int *)malloc(num_cells * sizeof(int));

    /* Intialize random number generator. */
    srand(time(NULL));

    /* Fill cells with 0 or 1 */
    /*First and last cells are 0. */
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

    /*free(cells);*/
    return 0;
}
