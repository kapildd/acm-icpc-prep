/*
ID: kapiley1
PROG: money
LANG: C++
*/
#include<stdio.h>

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int v,n,money[30];
	long long ways[10200]{0};
	scanf("%d%d",&v,&n);
	for(int i=0;i<v;i++)
	scanf("%d",&money[i]);
	ways[0]=1;
	for(int i=0;i<v;i++)
	for(int j=money[i];j<=n;j++)
	ways[j]+=ways[j-money[i]];
	printf("%lld\n",ways[n]);
	return 0;
}
