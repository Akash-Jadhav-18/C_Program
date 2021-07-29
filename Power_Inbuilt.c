#include<stdio.h>
#include<math.h>

int main()
{
	int iValue1 = 0, iValue2 = 0;
    int iRet = 0;
    
    printf("Enter first number\n");
    scanf("%d",&iValue1);
    
	printf("Enter second number\n");
    scanf("%d",&iValue2);
    
	iRet = (int)(pow(iValue1,iValue2) + 0.5); // double pow(double,double);
	
	// It may convert 5 to 4.999
	// Because of lossy conersion of int to double.
	// that's why we add 0.5 before coverison
	
	printf("Result is : %d\n",iRet);
		
	return 0;
}