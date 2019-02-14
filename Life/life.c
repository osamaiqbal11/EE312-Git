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
    *numRows=0;
    int i=0;

    while (fgets(buf, sizeof(buf),ptrtoGrid)){
        grid[i] =(char *) malloc(strlen(buf));
        strcpy(grid[i], buf);
        i++;
       *numRows= i;
    }
    *numCols = strlen(grid[0]);
    *numCols = *numCols - 1;
//printf("Columns = %d\nRows = %d\n", *numCols, *numRows);

}

void showWorld(char *grid[], int numRows, int numCols){


    int i= 0;
    int j= 0;
//    printf("it's there ===%c\n", grid[i][j]);
    char letter = grid[i][j];
    int intletter = grid[i][j];
   while(i<numRows) {
       intletter = grid[i][j];
       if (intletter == 48)
           printf(".");
       if (intletter == 49)
           printf("*");
       j++;

       letter = grid[i][j];
       int intletter = grid[i][j];
//printf("it'sthere ===%c\n intletter ===%d", grid[i][j], intletter);

        if (j == numCols) {
           printf("%c", letter);
           i++;
           j = 0;
           letter = grid[i][j];
           int intletter = grid[i][j];
       }
   }
}

void iterateGeneration(char *grid[], int numRows, int numCols){
    int i=0;
    int j=0;
    int whatisthere = grid[i][j];
    whatisthere= whatisthere -48;
   // printf("\n%d\n", whatisthere);
}