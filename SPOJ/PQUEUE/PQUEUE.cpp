#include<stdio.h>
#include<queue>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		queue<int> q1,q2;
		priority_queue<int> q3;
		int n,pos,val;
		scanf("%d%d",&n,&pos);
		for(int i=0;i<n;i++)
		{
			q1.push(i);
			scanf("%d",&val);
			q2.push(val);
			q3.push(val);
		}
		int time=0;
		while(q3.size()&&q2.size()&&q1.size())
		{
			while(q2.front()!=q3.top())
			{
				int tmp=q2.front();
				q2.pop();
				q2.push(tmp);
				tmp=q1.front();
				q1.pop();
				q1.push(tmp);
			}
			
			if(q1.front()==pos)
			{printf("%d\n",time+1);break;}
			else
			{
			q1.pop();
			q2.pop();
			q3.pop();
			time++;
			}
			
		}
	}
}
