/* CS261- Assignment 1 - Q.1*/
/* Name: Kevin Harvell
 * Date: 7/5/2018
 * Solution description: This is an exercise in dynamically allocating
 * an array of structs, assigning random ID's to each struct, and running
 * analytics on the data of the array of structs.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student *students = malloc(sizeof(struct student) * 10);
     /*Return the pointer*/
     return students;
}

void generate(struct student* students){
     /*Generate random and unique IDs and random scores for ten students, 
IDs being between 1 and 10, scores between 0 and 100*/
     // Fill an array with the numbers 1 through 10	
     int randNumArr[10];
     for(int i = 1; i <= 10; i++) {
	randNumArr[i - 1] = i;
     }     
     // Shuffle up the 1-10 array using Fisher-Yates Shuffle
     for(int i = 9; i > 0; i--) {
	int r = rand() % (i + 1);
	int temp = randNumArr[i];
	randNumArr[i] = randNumArr[r];
	randNumArr[r] = temp;
     }
     // Assign randomized 1-10 number array to each student's ID
     for(int i = 0; i < 10; i++) {
	students[i].id = randNumArr[i];
	students[i].score = rand() % 101;
     }
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
    for(int i = 0; i < 10; i++) {
	printf("ID%d %d\n", students[i].id, students[i].score);
    }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the 
ten students*/
	int min  = students[0].score,
	    max = students[0].score, 
	    sum = 0;
	double avg;
	for(int i = 0; i < 10; i++) {
	    if(students[i].score < min) {
		min = students[i].score;
	    } else if(students[i].score > max) {
		max = students[i].score;
	    }
	    sum += students[i].score;
	}
	avg = sum / 10.0;
     	
	printf("Minimum score: %d\n", min);
	printf("Maximum score: %d\n", max);
	printf("Average score: %f\n", avg);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
    free(stud);	
}

int main(){
    srand(time(NULL));
    struct student* stud = NULL;
    
    /*Call allocate*/
    stud = allocate();
    /*Call generate*/
    generate(stud);
    /*Call output*/
    output(stud);
    /*Call summary*/
    summary(stud); 
    /*Call deallocate*/
    deallocate(stud);
    return 0;
}

