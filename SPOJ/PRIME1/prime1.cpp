#include<stdio.h>
#include<stdlib.h>
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
	int n,a,b,*no;
	fastRead(&n);
	while(n--)
	{	
		fastRead(&a);
		fastRead(&b);
		no=(int *)calloc(b-a+1,sizeof(int));
		int p=2;
		p=2;
		while(p*p<=b)
		{
			int i=a/p;
			i*=p;
			while(i<=b)
			{
				if((i>=a)&&(no[i-a]==0)&&(i!=p))
				{
					no[i-a]=1;
				}
				i+=p;
			}
			if(p==2)
			p++;
			else
			p+=2;
		}
		for(int i=0;i<b-a+1;i++)
		{
			if(no[i]==0&&(a+i)>1)
			printf("%d\n",(a+i));
		}
		printf("\n");
	}
	return 0;
} 
