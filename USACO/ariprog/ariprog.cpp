/*
ID: kapiley1
PROG: ariprog
LANG: C++
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;
bool num[245005]={false};
int main()
{
	freopen("ariprog.in","r",stdin);
	freopen("ariprog.out","w",stdout);
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=0;i<=m;i++)
	for(int j=0;j<=i;j++)
	{
		v.push_back(i*i+j*j);
		num[i*i+j*j]=true;
	}
	sort(v.begin(),v.end());
	vector<pair<int,int> > ans;
	int count=0;
	for(int i=0;i<v.size();i++)
	{
		for(int j=i+1;j<v.size();j++)
		{
			int k=1,d=v[j]-v[i];
			if(d==0)continue;
			if(v[i]+n*d>=245005)break;
			while(k<=n)//check
			{
				if(!num[v[i]+k*d])break;
				else k++;
			}
			if(k>=n)
			{
				count=count+k-n+1;
				//printf("%d %d\n",v[i],d);
				ans.push_back(pair<int,int>(d,v[i]));
			}
		}
	}
	//printf("%d\n",count);
	ans.erase(unique(ans.begin(),ans.end()),ans.end());
	sort(ans.begin(),ans.end());
	for(int i=0;i<(int)ans.size();i++)
	printf("%d %d\n",ans[i].second,ans[i].first);
	if(ans.empty())
	printf("NONE\n");
	return 0;
}

