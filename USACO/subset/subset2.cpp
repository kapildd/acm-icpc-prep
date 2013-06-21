/*
ID: kapiley1
PROG: subset
LANG: C++
*/

#include<stdio.h>
#define abs(a) (a<0)?(-a):a
int sum(unsigned long long n)
{
	int s=0,i=1;
	while(n)
	{
		if(n%2)s+=i;
		i++;
		n>>=1;
	}
	return s;
}
int main()
{
	freopen("subset.in","r",stdin);
	freopen("subset.out","w",stdout);
	int t,count=0;
	scanf("%d",&t);
	
	int HalfSum=t*(t+1)/4;
	
	for(unsigned long long x=0;x<(1<<t);x++)
	{
		if(sum(x)==HalfSum)
		count++;
	}
	
	printf("%d\n",count/2);
}	
