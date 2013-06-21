/*
ID: kapiley1
PROG: concom
LANG: C++
*/
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int g[107][107],n,visit[107]{0};
class owns{
public:
int x,y;};
int compare(const owns a,const owns b)
{
	return a.x<b.x | (a.x==b.x && a.y<b.y);
}
int ownership[107];
vector<owns> o;	
void recurse(int v,int k)
{
	for(int i=1;i<=100;i++)
	{
		ownership[i]+=g[k][i];
	}
	visit[k]=1;
	for(int i=1;i<=100;i++)
	{
		if(!visit[i] && ownership[i]>50)
		{
			owns w;
			w.x=v;
			w.y=i;
			o.push_back(w);
			recurse(v,i);	
		}
	}
	
}

void floodFill()
{
	for(int i=1;i<=100;i++)
	{
		for(int j=0;j<=100;j++)
		ownership[j]=visit[j]=0;
		recurse(i,i);
	}
}

int main()
{
	freopen("concom.in","r",stdin);
	freopen("concom.out","w",stdout);
	
	for(int i=1;i<=100;i++)
	for(int j=1;j<=100;j++)
	g[i][j]=0;
	
	scanf("%d",&n);
	int x,y,z;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		g[x][y]=z;
	}
	
	floodFill();
	sort(o.begin(),o.end(),compare);
	for(int i=0;i<o.size();i++)
	printf("%d %d\n",o[i].x,o[i].y);
	return 0;
}
