/* CS261- Assignment 1 - Q. 0*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fooA(int* iptr){
  
     /*Print the value and address of the integer pointed to by iptr*/
     printf("iptr Address: %p", &x);
     /*Increment the value of the integer pointed to by iptr by 5*/
          
     /*Print the address of iptr itself*/
}


void fooB(int* jptr){
  
     /*Print the value and address of the integer pointed to by jptr*/
               
     /*Decrement jptr by 1*/
      
     /*Print the address of jptr itself*/
}


int main(){
    srand(time(NULL));
    /*Declare an integer x and initialize it randomly to a value in [0,10] 
*/
    int x = rand() % 11;
    /*Print the value and address of x*/
    printf(x);
    /*Call fooA() with the address of x*/
    fooA(&x);
    /*Print the value of x*/
    
    /*Call fooB() with the address of x*/
    
    /*Print the value and address of x*/
 
    
    return 0;
}

