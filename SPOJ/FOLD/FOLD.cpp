#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int n;
	string c,t;
	while(true)
	{	
		cin>>c;
		if(c==t)break;
		int count=1;
		bool a=false;
		for(int i=0;i<c.size();i++)
		{
			if((c[i]=='A')&&!a)
			{
				count++;
				a=!a;
			}else if(c[i]=='V')
			{
				if(a)a=!a;
			}
		}
		printf("%d\n",count);
		t=c;
	}
	return 0;
}
