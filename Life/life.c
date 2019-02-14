// life.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void populateWorld(char fname[], char *grid[], int *numRows, int *numCols){
    FILE *ptrtoGrid;
    ptrtoGrid = fopen(fname, "r");

    if (ptrtoGrid == NULL) {
        printf("you're a fuck up!\n");
        exit(-1);
    }
    else {
        printf("success!\n");
    }

    char buf[BUFSIZ];
    *numCols=0;
    //numRows=strlen(buf);

    while (fgets(buf, sizeof(buf),ptrtoGrid)){
        int i=0;
        grid[i] =(char *) malloc(strlen(buf));
        strcpy(grid[i], buf);
        printf("%s", grid[i]);
        i++;
       *numCols= i;
    }
    printf("Columns = %d\n", *numCols);

}

void showWorld(char *grid[], int numRows, int numCols){

}

void iterateGeneration(char *grid[], int numRows, int numCols){

}