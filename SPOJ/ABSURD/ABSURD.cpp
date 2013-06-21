#include<stdio.h>
unsigned long long c;
int absurd(int s)
{
	int abs=0,d;
	while(s%10==0)
	s/=10;
	d=s%10;
	while(s)
	{abs++;s/=10;}
	if(d==5)
	return abs*2-1;
	else
	return abs*2;
}
main()
{
      int t,f=0,d;
      scanf("%d",&t);
      while(t--){
                 scanf("%llu",&c);
                 f=c%10;
                 d=0;
                 while(c){d++;c/=10;}
         	if(((f!=5)&&())||(d==1)||((f==9)))
                {
	        printf("absurd\n");
		}else
                printf("not absurd\n");
         }
      return 0;
}
 
