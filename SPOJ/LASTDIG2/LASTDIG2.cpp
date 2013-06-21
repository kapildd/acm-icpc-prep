#include<stdio.h>
inline void fastRead(unsigned long long int *n)
{
	*n=0;
	register char c=getchar_unlocked();
	while(c<33)c=getchar_unlocked();
	while(c>33)
	{
		*n=*n*10+c-'0';
		c=getchar_unlocked();
	}
}
int main()
{
	int i[][4]={{0,0,0,0},{1,1,1,1},{6,2,4,8},{1,3,9,7},{6,4,6,4},{5,5,5,5},{6,6,6,6},{1,7,9,3},{6,8,4,2},{1,9,1,9}};
	int t;
	scanf("%d",&t);
	unsigned long long int b;
	int x,y;
	while(t--)
	{
		int d;
		int c=getchar_unlocked();
		while(c<33)c=getchar_unlocked();
		while(c>33)
		{
			x=c-48;
			c=getchar_unlocked();
		}
		
		fastRead(&b);
		y=b%(4);
		if(b==0)
		printf("1\n");
		else
		printf("%d\n",i[x][y]);
	}
	return 0;
}



