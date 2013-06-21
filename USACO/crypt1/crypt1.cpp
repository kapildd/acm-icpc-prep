/*
ID: kapiley1
PROG: crypt1
LANG: C++
*/
#include<stdio.h>
#include<iostream>
using namespace std;
bool nums[10]={false};
bool valid(int n,int k)
{
	bool val=true;
	while(n)
	{
		if(!nums[n%10])
		val=false;
		n/=10;
		k--;
	}
	return (val && k==0);
}
int main()
{
	freopen("crypt1.in","r",stdin);
	freopen("crypt1.out","w",stdout);
	int n,t;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&t);
		nums[t]=true;
	}
	int count=0;
	for(int i=100;i<=999;i++)
	{
		if(valid(i,3))
		{
			for(int j=10;j<=99;j++)
			{
				if(valid(j,2))
				{
					int l1=(j%10)*i,l2=(j/10)*i;
					if(valid(l1,3)&&valid(l2,3))
					{
						int ans=i*j;
						if(valid(ans,4))
						count++;
					}
				}
			}
		}
	}
	printf("%d\n",count);
	return 0;
}

