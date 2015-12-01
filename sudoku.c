#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "logic.h"

int main(void)
{
	int ch;
	int row = 0;
	int col = 0;

	int arr[9][9] = {                              		/*  [^^]  */
					 	2, 0, 8,  4, 0, 0,  0, 0, 9,  
					 	0, 9, 0,  5, 0, 0,  0, 0, 3,
					 	0, 0, 0,  0, 9, 0,  0, 0, 4,

					 	3, 0, 4,  0, 0, 2,  6, 9, 0,
					 	9, 2, 0,  6, 8, 4,  0, 5, 7,
					 	0, 6, 5,  9, 0, 0,  2, 0, 1,

					 	5, 0, 0,  0, 7, 0,  0, 0, 0,
					 	7, 0, 0,  0, 0, 1,  0, 3, 0,
					 	1, 0, 0,  0, 0, 5,  8, 0, 6
					};

	menu();

	ch = choice();

	if (ch == 1)
	{
		system("clear");

		set_sudoku(arr);

		backtrack_algo(arr, row, col);  	/* starting with [0,0] --> row, column */
	}

	else if (ch == 2)
	{	
		system("clear");

		printf("Program Terminated...\n");
	}

	return 0;
}
