/*
ID: kapiley1
PROG: frac1
LANG: C++
*/
#include<stdio.h>
#include<map>
#include<algorithm>
using namespace std;

int n;
	
int frac(int a,int b,int c,int d)
{
	if(a+c<=n && b+d<=n)
	{
		frac(a,b,a+c,b+d);
		printf("%d/%d\n",a+c,b+d);
		frac(a+c,b+d,c,d);
	}
}
int main()
{
	freopen("frac1.in","r",stdin);
	freopen("frac1.out","w",stdout);
	scanf("%d",&n);
	printf("%d/%d\n",0,1);
	frac(0,1,1,1);
	printf("%d/%d\n",1,1);	
}
