/*
ID: kapiley1
PROG: sprime
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
bool isPrime(int n)
{
	if(n<2)return false;
	if(n==2)return true;
	if(n%2==0)return false;
	for(int i=3;i*i<=n;i+=2)
	{
		if(n%i==0)return false;
	}
	return true;
}
int srib[4]={2,3,5,7};
void prime_rib(int n,int depth,int i)
{
	if(i==depth)
	{
		if(isPrime(n))
		{
			printf("%d\n",n);
		}
		return;
	}
	if(i==0)
	for(int j=0;j<4;j++)
	{
		prime_rib(srib[j],depth,i+1);
	}else
	for(int j=0;j<5;j++)
	{
		int x=n*10+j*2+1;
		if(isPrime(x))
		prime_rib(x,depth,i+1);
	}
}
int main()
{
	freopen("sprime.in","r",stdin);
	freopen("sprime.out","w",stdout);
	int depth;
	scanf("%d",&depth);
	prime_rib(0,depth,0);
	return 0;
}
