#include<stdio.h>
#include<map>
#include<algorithm>
using namespace std;
map<long long,long long> best_value;
long long getmax(long long n)
{
	if(n<=11)return n;
	if(best_value.count(n)==0)
	{
		best_value[n]=max(n,getmax(n/2)+getmax(n/3)+getmax(n/4));
	}
	return best_value[n];
	
}
int main()
{
	long long n;
	best_value.clear();
	best_value[0]=0;
	while(scanf("%lld",&n)!=-1)
	{
		printf("%lld\n",getmax(n));
	}
	return 0;
}
