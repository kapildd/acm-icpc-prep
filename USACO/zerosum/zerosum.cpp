/*
ID: kapiley1
PROG: zerosum
LANG: C++
*/
#include<stdio.h>
int n;
char a[18];
void dfs(int lv)
{
	if(lv==n-1)
	{
		int sum=0,i=1,preNum=a[0];
		char op='+';
		a[lv*2]=lv+1;
		while(i<=lv*2)
		{
			if(a[i]=='+' || a[i]=='-')
			{
				if(op=='+')
				{
				sum+=preNum;
				preNum=0;
				}else if(op=='-')
				{
				sum-=preNum;
				preNum=0;
				}
				op=a[i];
			}else if(a[i]==' ')
			{
					preNum*=10;
			}else
			{
				preNum+=a[i];
			}
			i++;
		}
		if(op=='+')
		{
		sum+=preNum;
		}else if(op=='-')
		{
		sum-=preNum;
		}
		
		int L=(n-1)*2;
		if(sum==0)
		{
		for(int i=0;i<L;i++)
		printf("%c",a[i]<10?a[i]+'0':a[i]);
		printf("%c\n",(lv+1)+'0');
		}
		
		return;
	}
	a[lv*2]=lv+1;
	a[lv*2+1]=' ';
	dfs(lv+1);
	a[lv*2+1]='+';
	dfs(lv+1);
	a[lv*2+1]='-';
	dfs(lv+1);
}
int main()
{
	freopen("zerosum.in","r",stdin);
	freopen("zerosum.out","w",stdout);
	scanf("%d",&n);
	dfs(0);
	return 0;
}
