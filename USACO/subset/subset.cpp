/*
ID: kapiley1
PROG: subset
LANG: C++
*/
#include<stdio.h>
int main()
{
	freopen("subset.in","r",stdin);
	freopen("subset.out","w",stdout);
	int t,count=0;
	scanf("%d",&t);
	
	long long dp[1000];
	int N=t*(t+1)/2;
	
	if(N%2)
	{
	printf("0\n");
	return 0;
	}
	
	for(int i=0;i<1000;i++)
	dp[i]=0;
	dp[0]=1;
	for(int i=1;i<=t;i++)
	for(int j=i*(i+1)/2;j>=i;j--)
	{
		dp[j]+=dp[j-i];
	}
	
	printf("%lld\n",dp[N/2]/2);
}	
