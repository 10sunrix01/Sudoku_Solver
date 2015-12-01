/****************************************/
/******* Functions - by sunrix **********/
/****************************************/

/* FOR A NEW PUZZLE DON'T FORGET TO CHANGE THE PUZZLE FORMAT/PROBLEM IN THE ARRAY */
/* Symbol for --> change here : [^^] */

/* Im using the backtracking method .....well...something like that :) */

//======================================================================
// ===============

void menu(void);
int choice(void);
void set_sudoku(int [][9]);
int check_row(int [][9], int, int);
int check_col(int [][9], int, int);
int check_grid(int [][9], int, int, int);
void print_sudoku(int [][9]);
void backtrack_algo(int [][9], int, int);

// ================

void menu(void)
{
	system("clear");

	printf("\n\n\t\t*******************************************\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*  [S][U][D][O][K][U] [S][O][L][V][E][R]  *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*                                         *\n");
	printf("\t\t*\t[1] Use.                          *\n");
	printf("\t\t*\t[2] Exit.                         *\n");
	printf("\t\t*******************************************\n\n");
}

// ==========================================================================

int choice(void)
{
	int c;

	do
	{
		printf("Enter in a choice: ");
		scanf("%d", &c);

	}while (c < 1 || c > 2);

	return c;
}

// =============================================================================

void set_sudoku(int array[][9])
{
	int i, j;

	printf("*_*_*_*[THE PROBLEM]:*_*_*_*\n\n");

	printf("-------------------------\n");

	for (i = 0; i < 9; i++)
	{
		if (i == 3 || i == 6)
		{
			printf("-------------------------\n");

		}

		for (j = 0; j < 9; j++)
		{	
			if (j % 3 == 0)
			{
				printf("| ");

			}

			printf("%d ", array[i][j]);
		}

		printf("|");

		printf("\n");
	}

	printf("-------------------------\n");

}

// =====================================================================

int check_row(int array[][9], int row, int n)
{
	int col;

	for (col = 0; col < 9; col++)
	{
		if (array[row][col] == n)
		{
			return 1;
			break;
		}

	}

	return 0;
}

// =======================================================================

int check_col(int array[][9], int col, int n)
{
	int row;

	for (row = 0; row < 9; row++)
	{
		if (array[row][col] == n)
		{
			return 1;
			break;	
		}

	}

	return 0;
}

// =======================================================================

int check_grid(int array[][9], int row, int col, int n)
{
	row = (row / 3) * 3;
	col = (col / 3) * 3;

	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (array[row + x][col + y] == n)
			{
				return 1;
				break;
			}

		}

	}

	return 0;
}

// ===============================================================

void print_sudoku(int array[][9])
{

	printf("\n\n");

	int i, j;

	printf("*_*_*_*[THE SOLUTION]:*_*_*_*\n\n");

	printf("-------------------------\n");

	for (i = 0; i < 9; i++)
	{
		if (i == 3 || i == 6)
		{
			printf("-------------------------\n");

		}

		for (j = 0; j < 9; j++)
		{	
			if (j % 3 == 0)
			{
				printf("| ");

			}

			printf("%d ", array[i][j]);
		}

		printf("|");

		printf("\n");
	}

	printf("-------------------------\n");

}

// =====================================================

void backtrack_algo(int array[][9], int row, int col) /* backtrack method */
{
	int ch, c1, c2, c3;			

	if (row > 8)		/* if managed to complete the whole puzzle just print it */
	{
		print_sudoku(array);

		exit(0);		
	}
		
	if (array[row][col] == 0)   /* if grid empty try to place the number and check if valid. */
	{
		for (ch = 1; ch <= 9; ch++)
		{
			c1 = check_row(array, row, ch);
			c2 = check_col(array, col, ch);
			c3 = check_grid(array, row, col, ch);

			if ((c1 == 0) && (c2 == 0) & (c3 == 0))
			{
				array[row][col] = ch;

				backtrack_algo(array, row, col);						
			}

		}

		array[row][col] = 0;	/* if there was a conflict keep it 0 and [BACKTRACK.]*/

	}

	else   /* if grid not empty, move on to the next cell. */
	{
		if (col < 8)
		{
			col++;

			backtrack_algo(array, row, col);
		}

		else
		{
			row++;

			backtrack_algo(array, row, 0);
		}
	}
	
}

// ======================================================================
