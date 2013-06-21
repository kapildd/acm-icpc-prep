/*
ID: kapiley1
PROG: runround
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<vector>
#include<set>
#include<algorithm>
#define PB push_back
using namespace std;
int n,ndig=0;
void itoa(long long n,char* a)
{
	long long x=0;
	while(n)
	{
		x=x*10+n%10;
		n/=10;
	}
	int i=0;
	while(x)
	{
		a[i++]=x%10+'0';
		x/=10;
	}
	a[i]='\0';
}
bool isZeroAndnDigs(long long n)
{
	ndig=0;
	bool zero=false;
	while(n)
	{
	ndig++;
	if(n%10==0)
	zero=true;
	n/=10;
	}
	return zero;
}
bool isRunRound(long long n)
{
	char a[20];
	bool v[10]{0};
	itoa(n,a);
	if(isZeroAndnDigs(n))return false;
	bool isrunr=true;
	int j=0,i=0;
	while(j<ndig)
	{
		int now=a[i]-'0';
		v[now]=1;
		i=(now+i)%ndig;
		if(j<ndig-1 && v[a[i]-'0'])
		isrunr=false;
		j++;
	}
	while(n)
	{
		if(!v[n%10])
		isrunr=false;
		n/=10;
	}
	return isrunr && i==0;
}
int main()
{
	freopen("runround.in","r",stdin);
	freopen("runround.out","w",stdout);

	scanf("%d",&n);
	long long  i;
	for(i=n+1;!isRunRound(i);i++);
	
	printf("%d\n",i);				
}
