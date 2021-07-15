/*
		Print a pattern of numbers from  to  as shown below. 
		Each of the numbers is separated by a single space.

                            4 4 4 4 4 4 4  
                            4 3 3 3 3 3 4   
                            4 3 2 2 2 3 4   
                            4 3 2 1 2 3 4   
                            4 3 2 2 2 3 4   
                            4 3 3 3 3 3 4   
                            4 4 4 4 4 4 4   

		Input Format

		The input will contain a single integer .

		Constraints


		Sample Input 0

		2
		Sample Output 0

		2 2 2
		2 1 2
		2 2 2
		Sample Input 1

		5
		Sample Output 1

		5 5 5 5 5 5 5 5 5 
		5 4 4 4 4 4 4 4 5 
		5 4 3 3 3 3 3 4 5 
		5 4 3 2 2 2 3 4 5 
		5 4 3 2 1 2 3 4 5 
		5 4 3 2 2 2 3 4 5 
		5 4 3 3 3 3 3 4 5 
		5 4 4 4 4 4 4 4 5 
		5 5 5 5 5 5 5 5 5
		Sample Input 2

		7
		Sample Output 2

		7 7 7 7 7 7 7 7 7 7 7 7 7 
		7 6 6 6 6 6 6 6 6 6 6 6 7 
		7 6 5 5 5 5 5 5 5 5 5 6 7 
		7 6 5 4 4 4 4 4 4 4 5 6 7 
		7 6 5 4 3 3 3 3 3 4 5 6 7 
		7 6 5 4 3 2 2 2 3 4 5 6 7 
		7 6 5 4 3 2 1 2 3 4 5 6 7 
		7 6 5 4 3 2 2 2 3 4 5 6 7 
		7 6 5 4 3 3 3 3 3 4 5 6 7 
		7 6 5 4 4 4 4 4 4 4 5 6 7 
		7 6 5 5 5 5 5 5 5 5 5 6 7 
		7 6 6 6 6 6 6 6 6 6 6 6 7 
		7 7 7 7 7 7 7 7 7 7 7 7 7 
*/




#include<stdio.h>

void Display(int no)
{
	int end = (no * 2) -1;
	int i = 0;
	int j = 0;
	
	for(i = 1; i <= end; i++)
	{
		
		if(i == 1 ||  i == end)
		{
			for(j = 1; j <= end; j++)
			{
				printf("%d ",no);
			}
		}
		else if(i <= no)
		{
			for(j = 1; j <= end ; j++)
			{
				if(j <= i)
					printf("%d ",no - j + 1);
				else if(j >= (end - i + 1))
					printf("%d ",j - no + 1);
				else
					printf("%d ",no - i + 1);
			}
		}
		else
		{
			for(j = 1; j <= end ; j++)
			{
				if(j >= i)
					printf("%d ",j - no + 1);
				else if(j <= (end - i + 1))
					printf("%d ",no - j + 1);
				else
					printf("%d ",i - no + 1);
			}
		}
		
		printf("\n");
		
		
	}
}




int main()
{
	int no;
	
	printf("Enter the number\n");
	scanf("%d",&no);
	
	Display(no);
	return 0;
}