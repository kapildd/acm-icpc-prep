/*
ID: kapiley1
PROG: preface
LANG: C++
*/
#include<stdio.h>
int main()
{
	freopen("preface.in","r",stdin);
	freopen("preface.out","w",stdout);
	int t;
	scanf("%d",&t);
	int count[7]{0};
	char letter[]={'I','V','X','L','C','D','M'};
	int point=0;
	for(int x=1;x<=t;x++)
	{
		point=0;
		int n=x;
		while(n)
		{
			int mod5=n%5,mod10=n%10;
			if(mod5<4)
			{
				count[point]+=mod5;
				if(mod10==5)
				count[point+1]++;
			}else
			{
				if(mod10==9)
				count[point+2]++;
				if(mod10==4)
				count[point+1]++;
			
				count[point]++;
			}
			n/=10;
			point+=2; 
		}
	}
	for(int i=0;i<7;i++)
	if(count[i])
	printf("%c %d\n",letter[i],count[i]);
}
