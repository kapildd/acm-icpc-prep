#include<stdio.h>
#include<math.h>
int main()
{
	int t;
	double a,b,c,ag,bg,cg,m,s,r;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf %lf %lf %lf",&a,&ag,&bg,&cg);
		s=(3.*a*ag/2.0);
		b=2.*s/3./bg;
		c=2.*s/3./cg;
		r=a*b*c/4.0/s;
		m=4.0*(r*r-(a*a+b*b+c*c)/9.0);
		m = (m<0.0) ? 0.0 : m;
		printf("%.3lf %.3lf\n",s,sqrt(m));
	}
	return 0;
}
