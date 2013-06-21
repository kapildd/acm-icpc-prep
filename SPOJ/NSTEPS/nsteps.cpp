#include<stdio.h>

inline void fastInput(int *a)
{
	 register char c=0;
	 while (c<33) c=getchar_unlocked();
	 *a=0;
	 while (c>33)
	 {
	     *a=*a*10+c-'0';
	     c=getchar_unlocked();
	 }
}
int main()
{
	int t,a,b;
	scanf("%d",&t);
	while(t--)
	{
		fastInput(&a);
		fastInput(&b);
		if(a-b==0||a-b==2)
		{
			if(a%2==0)
			printf("%d\n",(a+b));
			else
			printf("%d\n",(a+b-1));
		}else
		{
			printf("No Number\n");	
		}
	}
}
