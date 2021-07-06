#include<stdio.h>
#include<string.h>
#include<stdarg.h>
#include<stdlib.h>

int printfX(char * s,...)
{
	char *check = s;
	int iCnt = 0;
	while(*check != '\0')
	{
		
		if( ((*check ) == '@') &&  (*(check + 1) == '\0')  )    
		{
			printf("Error at -> %c \n At %d character\n",*check,(iCnt+1)  ); 
			exit(0);
		}
		iCnt++;
		check++;
	}
	
	iCnt = 0;
	va_list vl;
	
	va_start(vl,s);
	
	char c;
	int d;
	
	float f;
	char* p;
	int li;
	double ld;
	
	while(*s != '\0')
	{
		
		if(*s == '%')
		{
			char ch = *(s + 1);
			switch(ch)
			{
				case 'c' : 
							c = va_arg(vl,int);
							
							printf("%c",c);
							
							break;
				
				case 'd' : 
							 d = va_arg(vl,int);
							
							printf("%d",d);
							
							break;
				
				case 'f' : 
							f = va_arg(vl,double);
							
							printf("%f",f);
							
							break;
				
				case 's' : 
							p = va_arg(vl,char*);
							
							printf("%s",p);
							
							break;
				
				case 'l' : 
							
							if(*(s + 2) == 'd')
							{
								li = va_arg(vl,long int);
								
								printf("%ld",li);
								s++;
							}
							else if(*(s + 2) == 'f')
							{
								ld = va_arg(vl,double);
								
								printf("%lf",ld);
								s++;
							}
							
							
							break;
				case '\0' :
							printf("");
							break;
				
				default :
							printf("%c",*(s + 1));
							break;
				
			}
			s++;
			
			if(*s == '\0')
			{
				return iCnt + 1;
			}
			
		}
		else
		{
			printf("%c",*s);
		}
		iCnt++;
		s++;
		
	}
	
	return iCnt;
	
}

int main()
{
	int iCnt = printfX("%s %ld %c %lf	Hii\n","Akash",10,'A',24.34);
	// printf("%");
	
	// char *p = "%d";
	
	printfX("\nlength is %d",iCnt);
	
	return 0;
}