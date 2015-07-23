// This program calculates how many moves a user can make in a jumpers game when the board is predefined.
// Constraints: User can jump over only another user's players on the board and not over their own player's.

/*  board =  0 1 0 0
             1 0 1 0 
             0 1 2 0
             0 0 1 0  */

#include<stdio.h>
#include<stdlib.h>

void print_array(int**);
void num_moves(int**,int, int, int);

int main()
{
  int i;		// loop counter variable
  int x=2;		// starting location's x coordinate
  int y=2;		// starting location's y coordinate
  int user;		// player # at x,y location of board

  // Mallocing memory for the 2D board
  int** board = malloc(sizeof(int*)*4);		
  for(i=0;i<4;i++)
  {
    board[i]=malloc(sizeof(int)*4);
  }
  
  // Initializing the board
  board[0][0]=board[0][2]=board[0][3]=0;
  board[0][1]=1;
  board[1][0]=1; // NOT WORKING IN THE CASE WHEN THIS == 1. 
  board[1][1]=board[1][3]=0;
  board[1][2]=1;
  board[2][0]=board[2][3]=0;
  board[2][1]=1;
  board[2][2]=2;
  board[3][0]=board[3][1]=board[3][3]=0;
  board[3][2]=1;
  
  // Printing th board
  printf("Initial Board print.\n");
  print_array(board);
  
  // Finding the user at location(x,y) of the board
  user = board[x][y];

  // Function call for calculating the number of moves from location(x,y)
  num_moves(board, x, y, user);
}

void print_array(int** array)
{
  int i;                // loop counter variable
  int j;                // loop counter variable
  int n=4;		// dimensions of the board
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      printf("%d ", array[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void num_moves(int** array, int x, int y, int user)
{
  /* Move is only possible in UP, DOWN, RIGHT, LEFT directions. */
  int done=9;
  int left=0;
  int right=0;
  int up=0;
  int down=0;
  // INITIALLY ISNTEAD OF 2's THERE WERE 1's HERE.
  int left_ck = y-2>=0?1:0;
  int right_ck = y+2<=3?1:0;
  int up_ck = x-2>=0?1:0;
  int down_ck = x+2<=3?1:0;

  printf("X:%d Y:%d CURRENT VALUE INTO NEXT MOVE\n",x,y);
  printf("Up: %d, Down: %d, Left: %d, Right: %d\n\n",up_ck,down_ck,left_ck,right_ck);

  if(up_ck)
  {
     if(array[x-1][y]!=0 && array[x-1][y]!=user && x >= 0 && x < 4 && y >= 0 && y < 4)
    {
      if(array[x-2][y]==0 && array[x-2][y]!=done && (x-2) >= 0)
      {
        printf("X:%d Y:%d GOING UP\n",x,y);
        up=1;
        array[x][y]=done;
        print_array(array);
        num_moves(array, x-2, y,user);
        printf("UP is done.\n");
      }
    }
  }

  if(down_ck)
  {
    if(array[x+1][y]!=0 && array[x+1][y]!=user && x >= 0 && x < 4 && y >= 0 && y < 4)
    { 
      if(array[x+2][y]==0 && array[x+2][y]!=done && (x+2) <= 3)
      {
        printf("X:%d Y:%d GOING DOWN\n",x,y);
        down=1;
        array[x][y]=done;
        print_array(array);
        num_moves(array, x+2, y,user);
        printf("DOWN is done.\n");
      }
    }
  }

  if(left_ck)
  {
    if(array[x][y-1]!=0 && array[x][y-1]!=user && x >= 0 && x < 4 && y >= 0 && y < 4)
    {
      if(array[x][y-2]==0 && array[x][y-2]!=done && (y-2) >= 0)
      {
        printf("X:%d Y:%d GOING LEFT\n",x,y);
        left=1;
        array[x][y]=done;
        print_array(array);
        num_moves(array, x, y-2,user);
        printf("LEFT is done.\n");
      }
    }
  }

  if(right_ck)
  {
    if(array[x][y+1]!=0 && array[x][y+1]!=user && x >= 0 && x < 4 && y >= 0 && y < 4)
    {
      if(array[x][y+2]==0 && array[x][y+2]!=done && (y+2) <= 3)
      {
        printf("X:%d Y:%d GOING RIGHT\n",x,y);
        right=1;
        array[x][y]=done;
        print_array(array);
        num_moves(array, x, y+2,user);
        printf("RIGHT is done.\n");
      }
    }
  }
}

