// life.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void populateWorld(char fname[], char *grid[], int *numRows, int *numCols){
    FILE *ptrtoGrid;
    ptrtoGrid = fopen(fname, "r");
/*
    if (ptrtoGrid == NULL) {
        for(int j=0; j < 20; j++) {
            printf("you're a fuck up!\n");
        }
            exit(-1);
    }
    else {
        printf("success!\n");
    }
*/
    char buf[BUFSIZ];
    *numCols=0;
    int i=0;

    while (fgets(buf, sizeof(buf),ptrtoGrid)){
        grid[i] =(char *) malloc(strlen(buf));
        strcpy(grid[i], buf);
        i++;
       *numCols= i;
    }
    *numRows = strlen(grid[0]);
    *numRows = *numRows - 1;
//printf("Columns = %d\nRows = %d\n", *numCols, *numRows);

}

void showWorld(char *grid[], int numRows, int numCols){
    int i= 0;
//printf("%d\n", numCols);
    while(i< numCols){
        printf("%s", grid[i]);
        i++;
    }
}

void iterateGeneration(char *grid[], int numRows, int numCols){
       
}