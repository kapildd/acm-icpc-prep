#include<stdio.h>
#include<math.h>
inline void readLongLong(long long *a)
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
	long long t,a,b,c,d,e,f,A,B,C,D,E,F;
	double v;
	readLongLong(&t);
	while(t--)
	{
		readLongLong(&a);
		readLongLong(&b);
		readLongLong(&c);
		readLongLong(&d);
		readLongLong(&e);
		readLongLong(&f);
		A=a*a;
		B=b*b;
		C=c*c;
		D=d*d;
		E=e*e;
		F=f*f;
		v=A*F*(-(A+F)+(B+E)+(C+D))+B*E*((A+F)-(B+E)+(C+D))+C*D*((A+F)+(B+E)-(C+D))-((A+F)*(B+E)*(C+D))/2+((A-F)*(B-E)*(C-D))/2;
		v=sqrt(v)/12;
		if(v<0)v=-v;
		printf("%.4lf\n",v);
	}
	return 0;
}
