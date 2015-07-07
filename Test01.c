// This program does the job of making or printing a N * N 2D array counter clockwise direction.

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

void direction(char**, char*, int, int);
void print_array(char**, int);
  
int main()
{ 
  // Variable Initialization  
  int n; 			// # of rows and columns in Array
  int i; 			// loop counter
  int j; 			// loop counter
  int length = 0;	 	// length of the newest string
  char* gap= " ";		// stuffing for missing places
  char input_string[100];	// input user string
  int new_len=0;                // legnth of calculated # of spaces[gaps] in the input string
  double old_length=0; 		// length os user input string
  double calculation=0;

  // Getting string from the user
  printf("Enter the string: ");
  scanf("%s",input_string);
  
  // Finding length of the string from user
  old_length = strlen(input_string);

  // Size of array.
  calculation = sqrt(old_length);
  if((int)calculation == calculation)
  {
    n = floor(calculation);
  }
  else
  {
    n = floor(calculation)+1;
  }
  
  // Getting new string for adding to 2D array
  new_len = n*n - old_length;
  for (i=0;i<new_len;i++)
  {
    strcat(input_string,gap);
  }  
 
  // Finding length of the final string
  length = strlen(input_string);

  // Initializing a 2D Array.
  char **data = malloc(n*sizeof(char*));
  for(i=0;i<n;i++)
  {
    data[i]=malloc(n*sizeof(char));
  }
  
  // Initializing the 2D array to be NULL.
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      data[i][j]= '\0';
    }
  }
  // Function call
  direction(data,input_string, n, length);
} 

// Just prints the 2D array
void print_array(char** array, int n)
{
  int i;		// loop counter variable
  int j;		// loop counter variable
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
  int add=0;  		// # of letters from user input added
  int limit = n-1;      // 2D array max-index

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
    while((dir == 3) && (i >= 0) && (i <= limit) && (j >= 0) && (j <= limit) && array[i][j] == '\0')
    {
      array[i][j]=input[add];
      add++;
      j--;
    }
    dir = 2;
    j++;
    i++;
    while((dir == 2) && (i >= 0) && (i <= limit) && (j >= 0) && (j <= limit) && array[i][j] == '\0')
    {
      array[i][j]=input[add];
      add++;
      i++;
    }
    dir = 4;
    i--;
    j++;
    while((dir == 4) && (i >= 0) && (i < n) && (j >= 0) && (j <= limit) && array[i][j] == '\0')
    {
      array[i][j]=input[add];
      add++;
      j++;
    }
    dir = 1;
    i--;
    j--;
    while((dir == 1) && (i > 0) && (i <= limit) && (j >= 0) && (j <= limit) && array[i][j] == '\0')
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
