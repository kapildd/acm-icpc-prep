/*
ID: kapiley1
PROG: milk3
LANG: C++
*/
#include<stdio.h>
#include<algorithm>
#include<vector>
#define min(a,b) a<b?a:b
using namespace std;
int A,B,C;
int seen[21][21],cway[21];
int pour(int a,int b,int c)
{
	if(seen[a][b])return 0;
	if(!(a>=0 && b>=0 && c>=0 && a<=20 && b<=20 && c<=20))return 0;
	seen[a][b]=1;
	if(a==0)cway[c]=1;
	
	int t=min(B-b,c);
	pour(a,b+t,c-t);
	t=min(A-a,c);
	pour(a+t,b,c-t);
	t=min(A-a,b);
	pour(a+t,b-t,c);
	t=min(B-b,a);
	pour(a-t,b+t,c);
	t=min(C-c,a);
	pour(a-t,b,c+t);
	t=min(C-c,b);
	pour(a,b-t,c+t);
	return 0;
}
int main()
{
	freopen("milk3.in","r",stdin);
	freopen("milk3.out","w",stdout);
	scanf("%d %d %d",&A,&B,&C);
	int a=pour(0,0,C);
	vector<int> v;
	for(int i=0;i<21;i++)
	if(cway[i])v.push_back(i);
	for(int i=0;i<v.size();i++)
	printf("%d%c",v[i],i!=v.size()-1?' ':'\n');
	return 0;
}

