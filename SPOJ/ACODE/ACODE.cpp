#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
long long dp[5007];
long long poss(string s)
{
	int n=s.size();
	dp[0]=1;
	if(((s[0]=='2')&&(s[1]<='6'))||((s[0]=='1')))
	{
		dp[1]=2;
	}else
	{
		dp[1]=1;
	}
	if(s[1]=='0')
	dp[1]=1;
	for(int i=2;i<n;i++)
	{
		if(s[i]=='0')
		{
			dp[i]=dp[i-2];
		}else if((s[i-1]=='1')||((s[i-1]=='2')&&(s[i]<='6')))
		{
			dp[i]=dp[i-1]+dp[i-2];
		}else
		{
			dp[i]=dp[i-1];
		}
	}
	return dp[n-1];
}
int main()
{
	string s;
	cin>>s;
	while(s[0]!='0')
	{
		printf("%lld\n",poss(s));
		cin>>s;
	}
	return 0;
}
