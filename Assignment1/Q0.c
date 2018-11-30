/* CS261- Assignment 1 - Q. 0*/
/* Name: Kevin Harvell
 * Date: 7/5/2018 
 * Solution description: This problem was beneficial in my understanding of 
 * pointers in C and using the printf function.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fooA(int* iptr){
  
     /*Print the value and address of the integer pointed to by iptr*/
     printf("Integer Address: %p\n", iptr);
     printf("Integer Value: %d\n", *iptr);
     /*Increment the value of the integer pointed to by iptr by 5*/
     *iptr += 5;     
     /*Print the address of iptr itself*/
     printf("iptr Address: %p\n", &iptr);
}


void fooB(int* jptr){
  
     /*Print the value and address of the integer pointed to by jptr*/
     printf("Integer Address: %p\n", jptr);
     printf("Integer Value: %d\n", *jptr);     
     /*Decrement jptr by 1*/
     (*jptr)--; 
     /*Print the address of jptr itself*/
     printf("jptr Address: %p\n", &jptr);
}


int main(){
    srand(time(NULL));
    /*Declare an integer x and initialize it randomly to a value in [0,10] 
*/
    int x = rand() % 11;
    /*Print the value and address of x*/
    printf("Random x: %d\n", x);
    /*Call fooA() with the address of x*/
    fooA(&x);
    /*Print the value of x*/
    printf("x after fooA(&x): %d\n", x);
    /*The value of x is different than when printed at first because its
     * location was passed into fooA, allowing the original x variable to
     * be altered.*/
    /*Call fooB() with the address of x*/
    fooB(&x);
    /*Print the value and address of x*/
    printf("x after fooB(&x): %d\n", x);
    printf("x Address: %p\n", &x);
    /*The value of x is different than before fooB() because x's location
     * was passed into fooB, allowing the original x variable to be altered.
     * However, the address location of x has always been constantly the same
     * because when we defined it the address was established it to be in a constant
     * memory address */
    
    return 0;
}


