// life.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Student information for project:
 *
 * Replace <NAME> with your name.
 *
 * On my honor, Osama, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Osama Iqbal
 * email address: osamaiqbal1127@gmail.com
 * UTEID: oi723
 * Section 5 digit ID:16030
 *
 */

void populateWorld(char fname[], char *grid[], int *numRows, int *numCols){
    FILE *ptrtoGrid;
    ptrtoGrid = fopen(fname, "r");
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
//    printf("populated");
}


void showWorld(char *grid[], int numRows, int numCols){
    int i= 0;
    int j= 0;
    char letter = grid[i][j];
    char periodt = '.';
    char asterisk = '*';


    while(i<numRows) {
        letter = grid[i][j];
        if (letter == '0')
            printf("%c", periodt);
        if (letter == '1')
            printf("%c", asterisk);
        j++;

        letter = grid[i][j];
        if (j == numCols) {
            printf("%c", letter);
            i++;
            j = 0;
        }
    }
//    printf("showed");
}

void iterateGeneration(char *grid[], int numRows, int numCols) {
    int i = 0;
    int j = 0;
    char *tempgrid[numRows];
    while (i < numRows) {
        tempgrid[i] = (char *) malloc(strlen(grid[i]));
        strcpy(tempgrid[i], grid[i]);
        i++;
    }
    int num[8];
    int neighbors = 0;
    int currentRow = 0;
    int currentCol = 0;
    int exitcond = 0;

//    printf("countingneighbors");
    //counting neighbors
    while (exitcond != 1) {

        //top row and top corners
        if (currentRow == 0) {
            //top left corner
            if (currentCol == 0) {
                num[0] = grid[currentRow][currentCol + 1];
                if (num[0] == 49)
                    neighbors++;
                num[1] = grid[currentRow + 1][currentCol + 1];
                if (num[1] == 49)
                    neighbors++;
                num[2] = grid[currentRow + 1][currentCol + 1];
                if (num[2] == 49)
                    neighbors++;
            }
            //top right corner
            if (currentCol == (numCols - 1)) {
                num[0] = grid[currentRow][currentCol - 1];
                if (num[0] == 49)
                    neighbors++;
                num[1] = grid[currentRow + 1][currentCol - 1];
                if (num[1] == 49)
                    neighbors++;
                num[2] = grid[currentRow + 1][currentCol];
                if (num[2] == 49)
                    neighbors++;
            }
            //the rest
            // on the same row
            else {
                num[0] = grid[currentRow][currentCol - 1];
                num[1] = grid[currentRow][currentCol + 1];
                num[2] = grid[currentRow + 1][currentCol - 1];
                num[3] = grid[currentRow + 1][currentCol];
                num[4] = grid[currentRow + 1][currentCol + 1];
                i = 0;
                while (i < 5) {
                    if (num[i] == 49)
                        neighbors++;
                    i++;
                }
            }
        }
        //bottom row and bottom corners
        if (currentRow == (numRows - 1)) {
            //bottom left corner
            if (currentCol == 0) {
                num[0] = grid[currentRow - 1][currentCol];
                num[1] = grid[currentRow - 1][currentCol + 1];
                num[2] = grid[currentRow][currentCol + 1];
                if (num[0] == 49)
                    neighbors++;
                if (num[1] == 49)
                    neighbors++;
                if (num[2] == 49)
                    neighbors++;
            }
            //bottom right corner
            if (currentCol == (numCols - 1)) {
                num[0] = grid[currentRow][currentCol - 1];
                num[1] = grid[currentRow - 1][currentCol - 1];
                num[2] = grid[currentRow - 1][currentCol];
                if (num[0] == 49)
                    neighbors++;
                if (num[1] == 49)
                    neighbors++;
                if (num[2] == 49)
                    neighbors++;
            }
                //the rest
                //on the same row
            if (0<currentCol){
                if(currentCol<(numCols-1)) {
                    num[0] = grid[currentRow][currentCol - 1];
                    num[1] = grid[currentRow][currentCol + 1];
                    num[2] = grid[currentRow - 1][currentCol - 1];
                    num[3] = grid[currentRow - 1][currentCol];
                    num[4] = grid[currentRow - 1][currentCol + 1];
                    i = 0;
                    while (i < 5) {
                        if (num[i] == 49)
                            neighbors++;
                        i++;
                    }
                }
            }
        }

        //left column
        if (currentCol == 0) {
            //no corners
            if (currentRow == 0) {
                j = 0;
            }
            if (currentRow == (numRows - 1)) {
                j = 0;
            }
            //

            else {
                num[0] = grid[currentRow - 1][currentCol];
                num[1] = grid[currentRow - 1][currentCol + 1];
                num[2] = grid[currentRow][currentCol + 1];
                num[3] = grid[currentRow + 1][currentCol + 1];
                num[4] = grid[currentRow + 1][currentCol];
                i = 0;
                while (i < 5) {
                    if (num[i] == 49)
                        neighbors++;
                    i++;
                }
            }
        }
        //right column
        if (currentCol == (numCols - 1)) {
            //no corners
            if (currentRow == 0)
                j = 0;
            if (currentRow == (numRows - 1))
                j = 0;
            //
            else {
                num[0] = grid[currentRow - 1][currentCol];
                num[1] = grid[currentRow - 1][currentCol - 1];
                num[2] = grid[currentRow][currentCol - 1];
                num[3] = grid[currentRow + 1][currentCol - 1];
                num[4] = grid[currentRow +1][currentCol];

                i = 0;
                while (i < 5) {
                    if (num[i] == 49)
                        neighbors++;
                    i++;
                }
            }
        }
        //everything else

        if (0 < currentRow){
            if (currentRow <(numRows -1)) {
                if (0 < currentCol ) {
                    if (currentCol < (numCols - 1)) {
                        num[0] = grid[currentRow][currentCol - 1];
                        num[1] = grid[currentRow - 1][currentCol - 1];
                        num[2] = grid[currentRow - 1][currentCol];
                        num[3] = grid[currentRow - 1][currentCol + 1];
                        num[4] = grid[currentRow][currentCol + 1];
                        num[5] = grid[currentRow + 1][currentCol + 1];
                        num[6] = grid[currentRow + 1][currentCol];
                        num[7] = grid[currentRow + 1][currentCol - 1];
                        i = 0;
                        while (i < 8) {
                            if (num[i] == 49)
                                neighbors++;
                            i++;
                        }
                    }
                }
            }
        }



        int currentnum = grid[currentRow][currentCol];
        //enforcing rules updating tempgrid
        if (currentnum == 48) {
            if (neighbors == 3) {
                tempgrid[currentRow][currentCol] = '1';
            }
        }
        if (currentnum == 49) {
            if (neighbors > 3) {
                tempgrid[currentRow][currentCol] = '0';
            }
            if (neighbors < 2) {
                tempgrid[currentRow][currentCol] = '0';
            }
        }
        //
        //iterate number
        neighbors = 0;
        currentCol++;
        if (currentCol == numCols) {
            currentRow++;
            currentCol = 0;
            if (currentRow == numRows)
                exitcond = 1;
        }

    }
//    printf("stringcopy");
    //string copy
    i = 0;
    while (i < numRows) {
        strcpy(grid[i], tempgrid[i]);
        i++;
    }
//    printf("free");
    //free
    i = 0;
    while (i < numRows) {
        free(tempgrid[i]);
        i++;
    }
}

