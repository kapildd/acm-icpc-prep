#include<stdio.h>
int main()
{
	unsigned long long t;
	scanf("%llu",&t);
	if((t&(t-1))==0)
	printf("TAK\n");
	else
	printf("NIE\n");
	return 0;
}
