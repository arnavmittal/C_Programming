// This program does the job of making or printing a N * N 2D array counter clockwise, clockwise or just normally.
// Currently only for counter clockwise.

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
  char* gap= " ";	// stuffing for missing places
  char input_string[100] = "ABCDEFGHIJKLMNOP";
  int new_len=0;
  int old_length=0;
  // Finding length of the string
  old_length = strlen(input_string);

  // Getting input for size of array.
  printf("Enter the size of array that you want:");
  scanf("%d",&n);
  
  // Getting input string
  new_len = n*n - old_length;
  for (i=0;i<new_len;i++)
  {
    strcat(input_string,gap);
  }  
 
  // Finding length of the string
  length = strlen(input_string);

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
      data[i][j]= 'X';
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
  int i=0;		// loop counter variables
  int j=0;		// loop counter variables
  int dir=0;  		// direction of travel in 2D Array
  int add=0;
  int limit = n-1;

  /*  dir = 1 = UP
      dir = 2 = DOWN
      dir = 3 = LEFT
      dir = 4 = RIGHT  */
  
  // Counter-Clockwise direction
  dir=3;
  i=0;
  j=limit;
  while(add != length)
  {
    while((dir == 3) && (i >= 0) && (i <= limit) && (j >= 0) && (j <= limit) && array[i][j] == 'X')
    {
      array[i][j]=input[add];
      add++;
      j--;
    }
    dir = 2;
    j++;
    i++;
    while((dir == 2) && (i >= 0) && (i <= limit) && (j >= 0) && (j <= limit) && array[i][j] == 'X')
    {
      array[i][j]=input[add];
      add++;
      i++;
    }
    dir = 4;
    i--;
    j++;
    while((dir == 4) && (i >= 0) && (i < n) && (j >= 0) && (j <= limit) && array[i][j] == 'X')
    {
      array[i][j]=input[add];
      add++;
      j++;
    }
    dir = 1;
    i--;
    j--;
    while((dir == 1) && (i > 0) && (i <= limit) && (j >= 0) && (j <= limit) && array[i][j] == 'X')
    {
      array[i][j]=input[add];
      add++;
      i--;
    }
    dir = 3;
    i++;
    j--;
  }
  print_array(array, n);
} 
