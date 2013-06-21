#include<stdio.h>
int main()
{
	int t,a,b,c;
	char ch;
	bool flag=false;
	scanf("%d",&t);
	while(t--)
	{
		a=b=c=0;
		while((ch=getchar_unlocked())!='+')
		{
			if(ch>=48&&ch<=57)
			a=a*10+ch-48;
			if(ch=='m')
			{
				flag=true;
			}
		}
		if(flag)
		{
			a=-1;
			flag=false;
		}
		while((ch=getchar_unlocked())!='=')
		{
			if(ch>=48&&ch<=57)
			b=b*10+ch-48;
			if(ch=='m')
			{
				flag=true;
			}
		}
		if(flag)
		{
			b=-1;
			flag=false;
		}
		while((ch=getchar_unlocked())!='\n')
		{
			if(ch>=48&&ch<=57)
			c=c*10+ch-48;
			if(ch=='m')
			{
				flag=true;
			}
		}
		if(flag)
		{
			c=-1;
			flag=false;
		}
		if(a<0)
		{
			a=c-b;
		}else if(b<0)
		{
			b=c-a;
		}else
		{
			c=a+b;
		}
		printf("%d + %d = %d\n",a,b,c);
	}
}
