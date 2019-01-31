#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

// CodeCamp.c -- EE 312 Project 1

/* Student information for project:
 *
 * Replace <NAME> with your name.
 *
 * On my honor, Osama Iqbal, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Osama Iqbal
 * email address: osamaiqbal1127@gmail.com
 * UTEID: oi723
 * Section 5 digit ID: 16030
 *
 */



/* Determine the hamming distance between two int arrays.
   pre: aList != null, bList != null, aList.length == bList.length == len
   post: return hamming distance between the two arrays of ints.
   Neither parameter should be altered by this function.
*/

int hammingDistance(int aList[], int bList[], int len) {
    int hammingdistance= 0;
    int i = 0;
    int alistcurrent;
    int blistcurrent;


    for ( i; i < len; i++) {
        alistcurrent = aList[i];
        blistcurrent = bList[i];
        if (alistcurrent != blistcurrent)
            hammingdistance = hammingdistance + 1;
    }

    return hammingdistance;
}
/* Determine if two ints have the same last digit.
   Note that the last digit of 0 is 0 and the last digit of -12 is 2. 
   post: return true if num1 and num2 have the same last digit, false otherwise.
*/

bool lastDigit(int num1, int num2) {
    if ( num1 < 0)
        num1 = num1 * -1;
    if ( num2 < 0 )
        num2 = num2 * -1;

    while(num1 > 10) {
        num1 = num1 % 10;
    }
    while(num2 > 10) {
        num2 = num2 % 10;
    }

    if ( num1 == num2)
        return true;
    else
        return false;
}

/* Determine the sum of the positive integers less than 1000 that are multiples of 3 or 5 (or both).
   post: return the sum of the integers from 1 to 1000 that are multiples of 3 or 5 or both.
*/

int sum3or5Multiples() {
    int counter1= 999;
    int total= 0;


    while (counter1 > 0) {

        if ( (counter1 % 3) == 0)
            total = total + counter1;
        else
        if ( (counter1 % 5) == 0)
            total = total + counter1;
        counter1--;

    }
    return (total);


}

/* Reverse the digits of an integer. Return the reversed number if it is in the range of type int, 0 otherwise.
   post: return num with digits reversed if the reverse can be stored as an int, 0 otherwise.
*/

int reverseInt(int num) {
    int array[23] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int currentnumber = 0;
    int i = 0;
    int exponent_counter = 1;
    int exponent_holder = 0;
    int negcond = 0;                        //Variable that will indicate if the number is negative
                                            //so the appropriate steps can be taken

    if (num < 0)
        negcond = 1;
    if (num < 0)
        num = num * -1;

    while (num > 10) {
        currentnumber = num % 10;
        array[i] = currentnumber;
        num = num / 10;
        i++;
    }

    //This is sort of the initialization of step 2: putting the number back together.
    array[i] = num;
    int j = 0;
    exponent_holder = i;


    while (j <= exponent_holder){
        if (j == 0)
            currentnumber = array[i];
        else
            currentnumber = currentnumber+ (array[i] * exponent_counter);
        j++;
        i--;
        exponent_counter = exponent_counter * 10;
    }
    if (negcond == 1)
        currentnumber = currentnumber * -1;
    return(currentnumber);
}

  

