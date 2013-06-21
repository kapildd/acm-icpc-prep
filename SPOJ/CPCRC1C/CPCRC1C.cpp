#include<stdio.h>
#include<math.h>
long long sum[10]={0,1,3,6,10,15,21,28,36,45};
long long sumdig(long long n)
{
	if(n/10==0)return sum[n];
	long long N=n,p;
	int i=0;
	while(N/10!=0)
	{
		i++;
		N/=10;
	}
	p=pow(10,i);
	return sum[N-1]*p+N*(n%p+1)+45*N*(p/10)*i+sumdig(n%p);
}
int main()
{
	long long a,b,n,k;
	while(true)
	{
		scanf("%lld",&a);
		scanf("%lld",&b);
		if(a!=-1)
		{
				printf("%lld\n",sumdig(b)-sumdig(a-1));
		}else
		break;
	}
	return 0;
}
