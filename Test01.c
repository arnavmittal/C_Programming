// This program does the job of printing a N * N 2D array counter clockwise, clockwise or just normally.

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
void direction(char**, char*, int);

int main()
{
  // Variable Initialization  
  int n; 		// # of rows and columns in Array
  int i; 		// loop counter
  int length = 0; 	// length of the string
  char input_string[] = "ABCDEFGHIJKLMNOP" ;
  
  // Finding length of the string
  length = strlen(input_string);
  
  // Getting input for size of array.
  printf("Enter the size of array that you want:");
  scanf("%d",&n);
  
  // Initializing a 2D Array.
  char **data = malloc(n*sizeof(char*));
  for(i=0;i<n;i++)
  {
    data[i]=malloc(n*sizeof(char));
  }
   
  direction(data,input_string, n);
}

void direction(char** array, char* input, int n)
{
  int dir=0;  		// direction of travel in 2D Array
  char gap=' ';	 	// stuffing for missing places
}
