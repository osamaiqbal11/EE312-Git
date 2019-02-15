//life_driver.c
//
//Life Driver program
//Roger Priebe 9/5/2018
//EE 312


/* Student information for project:
 *
 * Replace <NAME> with your name.
 *
 * On my honor, <NAME>, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Osama Iqbal
 * email address: osamaiqbal1127@gmail.com
 * UTEID: oi723
 * Section 5 digit ID:16030
 *
 */

//This file is a driver program for the life.c module.
//This program must work with your implementations life.h and life.c
//Do not change the function definitions for populateWorld, showWorld or
//iterateGeneration.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "life.h"


int main(int argc, char *argv[]) {

   //edit these two lines and use the command line arguments

   char fName[] = "0";
   strcpy(fName, argv[1]);
   int Gens = atoi(argv[2]);
   const int numGenerations  = Gens; //set to a smaller number for debugging
    
   const int MAX_ROWS = 80; //we want the world to fit on one screen

   //array of strings that will hold the grid
   char *world[MAX_ROWS];
   int numRows;
   int numCols;

   populateWorld(fName, world, &numRows, &numCols);

   showWorld(world, numRows, numCols);

   for (int iteration = 0; iteration < numGenerations; iteration++) {

     // code to clear screen goes here
     system("clear");
     iterateGeneration(world, numRows, numCols);

     showWorld(world, numRows, numCols);
  }

  return 0;
}



