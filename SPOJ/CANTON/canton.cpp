#include<stdio.h>
#define MAX 4500
#define f(i,n) for(i;i<n;i++)
int sums[MAX];
void readInt(int* a)
{
	int c=getchar_unlocked();
	*a=0;
	while(c<33)
	{c=getchar_unlocked();}
	while(c>33)
	{
	*a=*a*10+(c-'0');
	c=getchar_unlocked();
	}
}
int main()
{
	char c,a;
	int t,n,i=0,num,den;
	sums[0]=0;
	i=1;
	f(i,MAX)
	{
		sums[i]=sums[i-1]+i;
	}
	readInt(&t);
	while(t--)
	{
		readInt(&n);
		i=0;
		while(sums[i]<=n)
		i+=10;
		while(sums[i]>=n)
		i--;
		if(i%2==0)
		{
		den=n-sums[i];
		num=i+2-den;
		printf("TERM %d IS %d/%d\n",n,num,den);
		}else
		{
		num=n-sums[i];
		den=i+2-num;
		printf("TERM %d IS %d/%d\n",n,num,den);
		}
	}
}
