#include<stdio.h>
#define M 1000000009
inline void readInt(long long *a)
{
		int sign=1; 
	 register char c=0;
	 while (c<33) c=getchar_unlocked();
	 *a=0;
	 while (c>33)
	 {
	 	if(c=='-')
	 	sign=-1;
	 	else
	    *a=*a*10+c-'0';
	     c=getchar_unlocked();
	 }
	 *a=sign*(*a);
}
long long modxp(long long p) {
long long r = 1, b = 2;
while(p>0) {
p--;
r <<=1;
r%=M;
}
return r;
}
int main()
{
	int t,n;
	long long x,max,maxCnt,zCnt,sum;
	scanf("%d",&t);
	while(t--)
	{
		maxCnt=1;
		sum=0;
		zCnt=0;
		max=-99999999;
		scanf("%d",&n);
		while(n--)
		{
			readInt(&x);
			if((x<0)&&(max==x))
			maxCnt++;
			if(max<x)
			{
				max=x;
				maxCnt=1;
			}
			if(x==0)
			zCnt++;
			if(x>0)
			sum+=x;
		}
		if(max<0)
		printf("%lld %lld\n",max,maxCnt);
		else if(max==0)
		printf("%lld %lld\n",(long long)0,modxp(zCnt)-1);
		else
		printf("%lld %lld\n",sum,modxp(zCnt));
	}
	return 0;
}
