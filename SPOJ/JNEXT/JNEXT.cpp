#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

bool myfunction (int i,int j) { return (i<j); }
int main()
{
	int t;
	scanf("%d",&t);
	int n,num[1000007],cnt[10];
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
			cnt[num[i]]++;
		}
		int tr=n-1;
		int a=-1,b;
		for(int i=0;i<n-1;i++)
		if(num[i]<num[i+1])a=i;
		
		if(a==-1)
		{
			printf("-1\n");
			continue;
		}
		for(int i=1;i<n;i++)
		if(num[a]<num[i])b=i;
		
		int temp=num[a];
		num[a]=num[b];
		num[b]=temp;
		
			for(int i = a+1, j = n-1; i<j ; i++, j--)
			{
			temp = num[i];
			num[i] = num[j];
			num[j] = temp;
			}
		
		tr=0;
		while(tr<n)
		printf("%d",num[tr++]);
		printf("\n");
	}
	return 0;
}
