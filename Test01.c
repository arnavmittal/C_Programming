// This program does the job of printing a N * N 2D array counter clockwise, clockwise or just normally.
  
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void direction(char**, char*, int, int);
void print_array(char**, int);
  
int main()
{ 
  // Variable Initialization  
  int n; 		// # of rows and columns in Array
  int i; 		// loop counter
  int j; 		// loop counter
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
  
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      data[i][j]= '\0';
    }
  }
  print_array(data, n);
  direction(data,input_string, n, length);
} 

void print_array(char** array, int n)
{
  int i;
  int j;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      printf("%c ", array[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}
  
void direction(char** array, char* input, int n, int length)
{ 
  int dir=0;  		// direction of travel in 2D Array
  char gap=' ';	 	// stuffing for missing places
  int add=0;
  /*  dir = 1 = UP
      dir = 2 = DOWN
      dir = 3 = LEFT
      dir = 4 = RIGHT  */
  
  // Counter-Clockwise diredtion hence initialization = 3
  dir=3;
  
  while(dir)
  {
    
   break; 
  }
} 
