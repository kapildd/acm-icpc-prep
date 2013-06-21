#include<stdio.h>
#include<math.h>
inline void readInt(int *a)
{
	 register char c=0;
	 while (c<33) c=getchar_unlocked();
	 *a=0;
	 while (c>33)
	 {
	     *a=*a*10+c-'0';
	     c=getchar_unlocked();
	 }
}
int main()
{
	int a,b,s,m,n;
	while(true)
	{
		readInt(&a);
		readInt(&b);
		readInt(&s);
		readInt(&m);
		readInt(&n);
		if(a|b|s|m|n)
		{
			long long dx=a*m;
			long long dy=b*n;
			double ang=atan2(dy,dx)*180/M_PI;
			double v=sqrt(dx*dx+dy*dy)/s;
			printf("%.2lf %.2lf\n",ang,v);
		}
		else
		break;
	}
	return 0;
}
