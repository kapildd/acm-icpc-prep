/*
ID: kapiley1
PROG: holstein
LANG: C++
*/
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;
bool satisfies(vector<int> v,int *p)
{
	for(int i=0;i<v.size();i++)
	if(v[i]>p[i])
	return false;
	return true;
}
int count(int n)
{
	int c=0;
	while(n)
	{
		if(n%2)
		c++;
		n>>=1;
	}
	return c;
}
int main()
{
	freopen("holstein.in","r",stdin);
	freopen("holstein.out","w",stdout);
	
	int V,G,sumMin=0;
	
	scanf("%d",&V);
	vector<int> min(V);
	for(int i=0;i<V;i++)
	{
	scanf("%d",&min[i]);
	sumMin+=min[i];
	}
	scanf("%d",&G);
	vector<vector<int> > feeds(G);
	vector<int> sum(G),point(G);
	int t;
	for(int i=0;i<G;i++)
	{
		int s=0;
		for(int j=0;j<V;j++)
		{
			scanf("%d",&t);
			s+=t;
			feeds[i].push_back(t);
		}
		sum[i]=s;
		point[i]=i+1;
	}
	/*for(int i=0;i<G;i++)
	for(int j=0;j<V;j++)
	printf("%d%c",feeds[i][j],j<V-1?' ':'\n');
	*/
	int* tot=(int*)calloc(V,sizeof(int));
	
	int best=131071;
	for(int x=0;x<(1<<G);x++)
	{
		if(count(best)>count(x))
		{
			for(int i=0;i<V;i++)
			tot[i]=0;
	
			int t=x,c=0;
			while(t)
			{
				if(t%2)
				for(int k=0;k<V;k++)
				tot[k]+=feeds[c][k];
			
				t>>=1;
				c++;
			}
		
			bool valid=true;
			for(int i=0;i<V;i++)
			if(min[i]>tot[i])
			valid=false;
		
			if(valid)best=x;
		}
	}
	
	vector<int> P;
	int c=0;
	while(best)
	{
		if(best%2)
		P.push_back(c+1);
		best>>=1;
		c++;
	}
	
	printf("%d ",P.size());
	sort(P.begin(),P.end());
	for(int k=0;k<P.size();k++)
	printf("%d%c",P[k],k<P.size()-1?' ':'\n');
		
}
