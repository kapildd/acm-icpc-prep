/*
ID: kapiley1
PROG: hamming
LANG: C++
*/
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;
int hammD(int a,int b)
{
	int c=0;
	for(int i=0;i<=8;i++,a/=2,b/=2)
	if(a%2!=b%2)
	c++;
	return c;
}
int main()
{
	freopen("hamming.in","r",stdin);
	freopen("hamming.out","w",stdout);
	
	int N,B,D;
	vector<int> vis;

	scanf("%d%d%d",&N,&B,&D);
	
	for(int i=0;i<(1<<(B+1));i++)
	n[i]=0;
	
	n[0]=1;
	vis.push_back(0);
	int x=0,last=0;
	
	for(int x=1;x<(1<<(B+1));x++)
	{
		int okay=1;
		for(int i=0;i<vis.size();i++)
		if(hammD(x,vis[i])<D)
		{okay=0;break;}
		if(okay)
		vis.push_back(x);
		
		if(vis.size()==N)break;
	}
	
	int line=0;
	for(int i=0;i<vis.size();i++)
	{
		printf("%d%c",vis[i],line<9?(i<vis.size()-1?' ':'\n'):'\n');
		line=(line+1)%10;
	}
}
