/* CS261- Assignment 1 - Q.2*/
/* Name: Kevin Harvell
 * Date: 7/6/2018 
 * Solution description: This is an exercise in understanding pointer swapping.
 * The conclusion I came to was that swapping the pointer addresses does not
 * also swap the values of the variables.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo(int* a, int* b, int c){
    /*Swap the addresses stored in the pointer variables a and b*/
    int* tempPtr;
    tempPtr = a;
    a = b;
    b = tempPtr; 
    /*Decrement the value of integer variable c*/
    c--;
    /*Return c*/
    return c;
}

int main(){
    srand(time(NULL));	
    /*Declare three integers x,y and z and initialize them randomly to values in [0,10] */
    int x = rand() % 10,
	y = rand() % 10,
	z = rand() % 10;
    /*Print the values of x, y and z*/
    printf("x: %d\ny: %d\nz: %d\n", x, y, z);
    /*Call foo() appropriately, passing x,y,z as parameters*/
    int fooReturn = foo(&x, &y, z);
    /*Print the values of x, y and z*/
    printf("x: %d\ny: %d\nz: %d\n", x, y, z);
    /*Print the value returned by foo*/
    printf("foo() return value is: %d\n", fooReturn);  
    
    return 0;
}

/* a) Yes, the return value is different than the value of integer z. It is different
 * because integer z is passed by value only. Anything the foo() function performs on the
 * value of z will not affect the actual variable itself.
 * b) The values of integers x and y are not different before and after calling the function
 * foo(). This is because the swap occurred on the addresses of the integers, not the integers
 * themselves. This would be similar to changing the address of my house. It is still going
 * to be my same house even if the location of the address changes.*/ 
    
    


