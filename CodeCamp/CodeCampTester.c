#include<stdio.h>
#include<stdbool.h>


// CodeCampTester.c -- EE 312 Project 1 -- Tester class

/* Student information for assignment:
 * 
 * Name: Osama Iqbal
 * email address: osamaiqbal1127@gmail.com
 * UTEID: oi723
 * Section 5 digit ID: 16030
 *  
 */

//function prototypes. These will be completed in CodeCamp.c
int hammingDistance(int aList[], int bList[], int len);
int sum3or5Multiples();
bool lastDigit(int num1, int num2);
int reverseInt(int num); 
//****************************

int main() {
  
  // test 1, hammingDistance
  int O_h1[] = {1, 1, 1, 1, 1, 1, 1, 1};
  int O_h2[] = {1, 1, 1, 1, 1, 1, 1, 1};
  int expected = 0;
  int actual = hammingDistance(O_h1,O_h2, 8);
  printf("Test 1 hamming distance: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 1, hamming distance\n\n");
  else 
     printf("**** FAILED **** test 1, hamming distance\n\n");

  // test 2, hamming distance
  int O_h3[] = { 6, 6, 6, 6, 6, 6, 6, 6, 6};
  int O_h4[] = { -6, -6, -6, -6, -6, -6, -6, -6, -6};
  expected = 9;
  actual = hammingDistance(O_h3, O_h4, 9);
  printf("Test 2 hamming distance: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 2, hamming distance\n\n");
  else 
     printf("**** FAILED **** test 2, hamming distance\n\n");

  // test 3, last digit
  int n1 = 145;
  int n2 = 789;
  expected = false;
  actual = lastDigit(n1, n2);
  printf("Test 3 last digit: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 4, last digit\n\n");
  else 
     printf("**** FAILED **** test 4, last digit\n\n");

  // test 4, last digit
  n1 = -8790;
  n2 = 16750;
  expected = true;
  actual = lastDigit(n1, n2);
  printf("Test 4 last digit: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
    printf("passed test 5, last digit\n\n");
  else 
     printf("**** FAILED **** test 5, last digit\n\n");

  // test 6, sum of multiples of 3 or 5
  expected = 233168;
  actual = sum3or5Multiples();
  printf("Test 6, sum of multiples: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 6, sum of multiples of 3 or 5\n\n");
  else 
     printf("**** FAILED **** test 6, sum of multiples of 3 or 5\n\n");

  // test 7, reverse int
  n1 = -908;
  expected = -809;
  actual = reverseInt(n1);
  printf("Test 7 reverse int: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 7, reverse int\n\n");
  else 
     printf("**** FAILED **** test 7, reverse int\n\n");

  // test 8, reverse int
  n1 = 51;
  expected = 15;
  actual = reverseInt(n1); 
  printf("Test 8 reverse int: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 8, reverse int\n\n");
  else 
     printf("**** FAILED **** test 8, reverse int\n\n");

  // test 10, reverse int
}

