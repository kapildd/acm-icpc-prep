#include<stdio.h>
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
	int t,n;
	readInt(&t);
	while(t--)
	{
		readInt(&n);
		while((c=getchar_unlocked())>64)
		{
		a=c;
		}
		printf("%c\n",a);
	}
}
