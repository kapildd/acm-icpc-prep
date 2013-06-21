#include<stdio.h>
#define inf 999999
int p[505],w[505],dp[505][10500];
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
int Min(int a,int b)
{
	return a<b?a:b;
}
int main()
{
	int t,e,f,maxw,n;
	readInt(&t);
	while(t--)
	{
		readInt(&e);
		readInt(&f);
		maxw=f-e;
		readInt(&n);
		for(int i=0;i<n;i++)
		{
			readInt(&p[i]);
			readInt(&w[i]);
		}
		for(int i=0;i<n;i++)
		{
			dp[i][0]=0;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=1;j<maxw+1;j++)
			{
				if(i==0&&j<w[i])
				{
					dp[i][j]=inf;
				}else if(i==0)
				{
					dp[i][j]=p[i]+dp[i][j-w[i]];
				}else if(j<w[i])
				{
					dp[i][j]=dp[i-1][j];
				}else
				{
					dp[i][j]=Min(dp[i-1][j],p[i]+dp[i][j-w[i]]);
				}
			}
		}
		if(dp[n-1][maxw]>=inf)
		{
			printf("This is impossible.\n");
		}
		else
		{
			printf("The minimum amount of money in the piggy-bank is %d.\n",dp[n-1][maxw]);
		}
	}
	return 0;
}
