#include<stdio.h>
int main()
{
	long long n,k,t;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&k);
		long long sum=1;
		n--;k--;
		if (k>n-k)k=n-k;
		for(long long i=1;i<=k;i++)
		{
			sum*=(n-i+1);
			sum/=(i);
		}
		printf("%lld\n",sum);
	}
}
