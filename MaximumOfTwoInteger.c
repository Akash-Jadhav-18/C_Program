/*
 Accept 2 numbers fro user and return the maximum and minimum number.
*/

#include<stdio.h>

/////////////////////////////////////////////////////////////
//
//  Function name:  	Maximum
//  Input :             Integer, Integer
//  Output :            Integer
//  Description :       It is used to find out the largest number
//  
/////////////////////////////////////////////////////////////

int Maximum(int iValue1, int iValue2)
{
    if(iValue1 > iValue2)
    {
        return iValue1;
    }
    else
    {
        return iValue2;
    }
}


int main()
{
    int iNo1 = 0;
    int iNo2 = 0;
    int iRet = 0;
    
    printf("Enter first number\n");
    scanf("%d",&iNo1);
    
    printf("Enter second number\n");
    scanf("%d",&iNo2);
    
    iRet = Maximum(iNo1,iNo2);
    
    printf("Maximum number is : %d\n",iRet);
    return 0;
}
