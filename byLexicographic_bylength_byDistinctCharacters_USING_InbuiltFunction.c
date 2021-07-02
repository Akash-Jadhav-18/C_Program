/*

Given an array of strings, you need to implement a "string_sort" function which sorts the strings according to a comparison function, i.e, you need to implement the function :

void string_sort(const char **arr,const int cnt, int (*cmp_func)(const char* a, const char* b))
{
    
}

The arguments passed to this function are:
		an array of strings : arr
		length of string array: cnt
		pointer to the string comparison function: cmp_func
		



		
You also need to implement the following four string comparison functions:

	1. lexicographic_sort(const char*, const char*) :-  to sort the strings
														in lexicographically non-decreasing order.

	2. lexicographic_sort_reverse(const char*, const char*):- to sort the strings in lexicographically 
																non-increasing order.

	3. sort_by_number_of_distinct_characters(const char*, const char*) :- to sort the strings in non-decreasing 
																			order of the number of distinct characters 
																			present in them. If two strings have the 
																			same number of distinct characters present 
																			in them, then the lexicographically smaller 
																			string should appear first.

	4. sort_by_length(const char*, const char*) :- to sort the strings in non-decreasing order of their lengths. If two strings have the same length, then the lexicographically smaller string should appear first



Input Format :	You just need to complete the function string\_sort and implement the four 
				string comparison functions.

Constraints :	No. of Strings 
				Total Length of all the strings 
				You have to write your own sorting function and you cannot use the inbuilt  function
				The strings consists of lower-case English Alphabets only.


Output Format : The locked code-stub will check the logic of your code. The output consists of the strings 
				sorted according to the four comparsion functions in the order mentioned in the problem statement



Sample Input 0:		4
					wkue
					qoi
					sbv
					fekls

Sample Output 0:	fekls
					qoi
					sbv
					wkue

					wkue
					sbv
					qoi
					fekls

					qoi
					sbv
					wkue
					fekls

					qoi
					sbv
					wkue
					fekls


*/


#include<string.h>
#include<stdio.h>
#include<stdlib.h>


#define SWAP 1
#define NO_SWAP -1


int sort_by_length(const char* , const char* ); // declaration






///////////////////////////////////////////////////////////////////////////////
//
//  Function name : lexicographic_sort
//  Input : const char*,const char*
//  Output : Integer
//  Description : to sort the strings in lexicographically non-decreasing order
//
///////////////////////////////////////////////////////////////////////////////


int lexicographic_sort(const char* a, const char* b) {
    
    
    return strcmp(a,b);
}





///////////////////////////////////////////////////////////////////////////////
//
//  Function name : lexicographic_sort_reverse
//  Input : const char*,const char*
//  Output : Integer
//  Description : to sort the strings in lexicographically non-increasing order.
//
///////////////////////////////////////////////////////////////////////////////


int lexicographic_sort_reverse(const char* a, const char* b) 
{
    return strcmp(b,a);
}



///////////////////////////////////////////////////////////////////////////////
//
//  Function name : sort_by_number_of_distinct_characters
//  Input : const char*,const char*
//  Output : Integer
//  Description : to sort the strings in non-decreasing order of the 
//					number of distinct characters present in them. 
//					If two strings have the same number of distinct characters 
//					present in them, then the lexicographically smaller string 
//					should appear first.
//
///////////////////////////////////////////////////////////////////////////////


int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    
	 int a_size = strlen(a);
    int b_size = strlen(b);
    int aCnt = 0;
    int bCnt = 0;
	
	int aArr[128] = {0};
	int bArr[128] = {0};
	
	
	for(int i = 0; i < a_size; i++)
	{
		aArr[a[i]]++;
	}
	
	for(int i = 0; i < b_size; i++)
	{
		bArr[b[i]]++;
	}
	
	for(int i = 0; i < 128; i++)
	{
		if(aArr[i] > 0)
		{
			aCnt++;
		}
		
		if(bArr[i] > 0)
		{
			bCnt++;
			
		}
	}
	
    if(  ((bCnt) == (aCnt)))  
    {
        return lexicographic_sort(a,b);
    }
	else if(aCnt > bCnt)
	{
		return SWAP;
	}
	else
	{
		return NO_SWAP;
	}
	
}



///////////////////////////////////////////////////////////////////////////////
//
//  Function name : sort_by_length
//  Input : const char*,const char*
//  Output : Integer
//  Description :  to sort the strings in non-decreasing order of their lengths. 
//					If two strings have the same length, then the lexicographically 
//					smaller string should appear first.
//
///////////////////////////////////////////////////////////////////////////////


int sort_by_length(const char* a, const char* b) {
    
    if(strlen(a) > strlen(b))
    {
        return SWAP;
    }
    else if(strlen(a) == strlen(b))
    {
        return lexicographic_sort(a,b);
    }
    else
    {
        return NO_SWAP;
    }
	
}



///////////////////////////////////////////////////////////////////////////////
//
//  Function name : string_sort
//  Input : char** ,const int,int (*cmp_func)(const char*, const char*)
//  Output : Nothing
//  Description : sort the array
//
///////////////////////////////////////////////////////////////////////////////

												//   function Ponter
void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    
	
    for(int i = 0; i < len - 1; i++)
    {
        for(int j = i + 1; j < len; j++)
        {
            int iRet = cmp_func(*(arr + i),*(arr + j));
            
            if(iRet > 0)
            {
                char *temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
				
            }   
        }	
    }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
	
	printf("\n\n");
	
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
	
	
	for(int i = 0; i < n; i++)
	{
		free(arr[i]);
	}
	
	free(arr);
	
	
	return 0;
}














