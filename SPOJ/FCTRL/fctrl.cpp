#include<stdio.h>
inline void fastRead(int *a)
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
	int test,n,a;
	fastRead(&test);
	while(test--)
	{	
		fastRead(&n);
		a=0;
		while(n>0)
		{
			a+=n/5;
			n/=5;
		}
		printf("%d\n",a);
	}
	return 0;
} 
