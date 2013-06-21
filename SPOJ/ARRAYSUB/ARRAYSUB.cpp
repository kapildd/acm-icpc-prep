#include<stdio.h>
#include<map>
#define LEFT(n) 2*n+1
#define RIGHT(n) 2*(n+1)
#define PARENT(n) (n-1)/2
using namespace std;
map<int,int> memo;
int heap[200107];
int ptr[1000107];
long long heapl,length;
int k;
void heapify(long long i)
{
	long long large=i;
	if((LEFT(i)<heapl)&&(heap[large]<heap[LEFT(i)]))
	{
		large=LEFT(i);
	}
	if((RIGHT(i)<heapl)&&(heap[large]<heap[RIGHT(i)]))
	{
		large=RIGHT(i);
	}
	if(heap[large]>heap[i])
	{
		int t=heap[i];
		heap[i]=heap[large];
		heap[large]=t;
		ptr[memo[large]]=i;
		ptr[memo[i]]=large;
		t=memo[i];
		memo[i]=memo[large];
		memo[large]=t;
		heapify(large);
	}
}
void insert(int n,int i)
{
	heap[ptr[i-k]]=n;
	ptr[i]=ptr[i-k];
	memo[ptr[i-k]]=i;
	i=ptr[i-k];
	while(i!=0)
	{
	heapify(i);
	i=PARENT(i);
	}
	heapify(0);
}
int main()
{
	int num[1000107],max=-1,max2=-1,n=0,c=1000007;
	scanf("%d",&n);
	memo.clear();
	c=0;
	while(c<n)
	{
		scanf("%d",&num[c++]);
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
	heap[i]=num[i];
	ptr[i]=i;
	memo[i]=i;
	}
	heapl=k;
	for(int j=((k+1)/2);j>=0;j--)
	heapify(j);
	c=k;
	printf("%d",heap[0]);
	while(c<n)
	{
		insert(num[c],c);
		printf(" %d",heap[0]);
		c++;
	}
	return 0;
}
