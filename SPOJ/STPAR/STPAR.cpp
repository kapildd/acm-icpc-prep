#include<stdio.h>
#include<stack>
using namespace std;
int main()
{
	int n,lm[1007];
	while(scanf("%d",&n))
	{
		if(n==0)break;
		stack<int> s;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&lm[i]);
		}
		int flag=1,k=0;
		for(int i=0;i<n;i++)
		{
			while(!s.empty()&&s.top()==k+1)
			{
				s.pop();
				k++;
			}
			if(lm[i]==k+1)
			{
				k++;
			}
			else if(!s.empty()&&s.top()<lm[i])
			{
				flag=0;
				break;
			}
			else
			{
				s.push(lm[i]);
			}
		}
		if(flag)
		printf("yes\n");
		else
		printf("no\n");
	}
	return 0;
}
