#include <stdio.h>

void updateSector(int grid[3][3], int r, int c, int flag, int setclear);
void querySector(int grid[3][3], int r, int c);
void RunSystemDiagnostic(int grid[3][3]);

int main (void)
{
	int r,c, flag, setclear,n;
	int grid[3][3]={0};

	do{
		printf("\nMENU\n");
		printf("1. Update Sector Status\n2. Query Sector Status\n3. Run System Diagnostic\n4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &n);
		
		switch(n)
		{
			case 1:
				printf("Enter row and col: ");
				scanf("%d %d", &r, &c);
				printf("Enter flag (PowerStatus(0), Overload Warning(1), Maintenance Required(2)): ");
				scanf("%d", &flag);
				printf("Set(1) Clear(0): ");
				scanf("%d", &setclear);
				updateSector(grid, r, c, flag, setclear);
				break;
			case 2:
				printf("Enter row and col: ");
				scanf("%d %d", &r, &c);
				
				querySector(grid, r, c);
				break;
			case 3:
				RunSystemDiagnostic(grid);
				break;
			case 4:
				printf("Exiting...");
				break;
		}
	}while(n!=4);
		}	


void updateSector(int grid[3][3], int r, int c, int flag, int setclear)
{
	if (r>=3 || r<0 || c>=3 || c<0 || flag<0 || flag>2 )
	{
		printf("Invalid input\n");
		return;
	}
	if (setclear == 1)
	grid[r][c]|=(1<<flag);
	else
	{
		grid[r][c]&=~(1<<flag);
	}
	
	printf("Sector (%d,%d) updated successfully.\n", r, c);

}


void querySector(int grid[3][3], int r, int c)
{
	if (r>=3 || r<0 || c>=3 || c<0 )
	{
		printf("Invalid input\n");
		return;
	}
	if (grid[r][c]&(1<<0))
	{
		printf("Power Status: On\n");
	}
	else
	{
		printf("Power Status: Off\n");
	}
	if (grid[r][c]&(1<<1))
	{
		printf("Overload Warning: Overload\n");
	}
	else
	{
		printf("Overload Warning: Normal\n");
	}
	if (grid[r][c]&(1<<2))
	{
		printf("Maintenance Required :Yes\n");
	}
	else
	{
		printf("Maintenance Required :No\n");
	}
				 


}
void RunSystemDiagnostic(int grid[3][3])
{
	int i,j, maintainance =0, overloaded=0;
	for (i=0; i<3; i++)
	{
		for (j=0; j<3; j++)
		{
			if (grid[i][j]&((1<<1)))
			{
				overloaded++;				
			}
			if (grid[i][j]&((1<<2)))
			{
				maintainance++;	
			}
		}
	}
	printf("\nSYSTEM DIAGNOSTIC REPORT\n");
    printf("Total overloaded sectors: %d\n", overloaded);
    printf("Total sectors requiring maintenance: %d\n", maintainance);
}
