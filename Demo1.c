#include<stdio.h>
#include<string.h>

int MyStrlen(char arr[])
{
	int i = 0;
	
	while(arr[i] != '\0')
	{
		i++;
	}
	
	return i;
}


int main()
{
	// Ways in which we can create he string
	
	char str1[] = "Hello";
	
	int iRet = 0;
	
	iRet = MyStrlen(str1);
	
	printf("%s\n",str1 + 1);
	
	
	
	
	
	return 0;
}