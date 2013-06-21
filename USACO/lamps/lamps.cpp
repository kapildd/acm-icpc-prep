/*
ID: kapiley1
PROG: lamps
LANG: C++
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<set>
#include<algorithm>
#define PB push_back
using namespace std;
int n,c;
bool lamp[102],bt[4][102];
vector<int> ON,OFF;
vector<vector<bool> > ans;
	
int nbits(int x)
{
	int n=0;
	while(x)
	{
		if(x%2)n++;
		x>>=1;
	}
	return n;
}
void applyBT(int x)
{
	int pointer=0;
	memset(lamp,1,n);
	while(x)
	{
		if(x%2)
		{
			for(int i=0;i<n;i++)
			lamp[i]^=bt[pointer][i];
		}
		pointer++;
		x>>=1;
	}
}
bool checkBT()
{
	for(int i=0;i<ON.size();i++)
	if(!lamp[ON[i]-1])
	return false;
	for(int i=0;i<OFF.size();i++)
	if(lamp[OFF[i]-1])
	return false;
	return true;
}
int compare(const vector<bool> a,const vector<bool> b)
{
	for(int i=0;i<a.size();i++)
	{
		if(a[i]!=b[i])return a[i]?0:1;
	}
	return 1;
}
void printBT()
{
	sort(ans.begin(),ans.end(),compare);
	ans.erase(unique(ans.begin(),ans.end()),ans.end());
	for(int i=0;i<ans.size();i++)
	{
	vector<bool> a(ans[i]);
	for(int j=0;j<a.size();j++)
	printf("%d",a[j]?1:0);
	printf("\n");
	}
	
}

int main()
{
	freopen("lamps.in","r",stdin);
	freopen("lamps.out","w",stdout);
	for(int i=0;i<101;i++)
	{
		bt[0][i]=1;
		bt[3][i]=0;
		if(i%2)
		{
		bt[1][i]=1;
		bt[2][i]=0;
		}else
		{
		bt[1][i]=0;
		bt[2][i]=1;
		}
		if(i%3==0)
		bt[3][i]=1;
	}
	scanf("%d",&n);
	scanf("%d",&c);
	
	int tmp;
	scanf("%d",&tmp);
	while(tmp!=-1)
	{
		ON.PB(tmp);
		scanf("%d",&tmp);
	}
	scanf("%d",&tmp);
	while(tmp!=-1)
	{
		OFF.PB(tmp);
		scanf("%d",&tmp);
	}
	
	for(int x=0;x<16;x++)
	{
		applyBT(x);
		
		if(nbits(x)<=c &&  checkBT())
		{
				vector<bool> A(lamp,lamp+n);
				ans.PB(A);
				
		}
	}
	if(ans.size()==0)
	printf("IMPOSSIBLE\n");
	else 
	printBT();
				
}
