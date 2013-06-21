/*
ID: kapiley1
PROG: sort3
LANG: C++
*/
#include<stdio.h>
int main()
{
	freopen("sort3.in","r",stdin);
	freopen("sort3.out","w",stdout);
	int a[1007],move[4][4],n1=0,n2=0,n3=0;
	int N;
	scanf("%d",&N);
	for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	move[i][j]=0;
	
	for(int i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==1)
		n1++;
		else if(a[i]==2)
		n2++;
		else
		n3++;
	}
	for(int i=0;i<N;i++)
	{
		if(i<n1)
		{
			if(a[i]==2)
			move[1][0]++;
			else if(a[i]==3)
			move[2][0]++;
		}else if(i<n1+n2)
		{
			if(a[i]==1)
			move[0][0]++;
			else if(a[i]==3)
			move[2][1]++;
		}else
		{
			if(a[i]==1)
			move[0][1]++;
			else if(a[i]==2)
			move[1][1]++;
		}
	}
	int count=0;
	
	int k=move[0][0]<move[1][0]?move[0][0]:move[1][0];
	move[0][0]-=k;
	move[1][0]-=k;
	count+=k;
	k=move[1][1]<move[2][1]?move[1][1]:move[2][1];
	move[1][1]-=k;
	move[2][1]-=k;
	count+=k;
	k=move[0][1]<move[2][0]?move[0][1]:move[2][0];
	move[0][1]-=k;
	move[2][0]-=k;
	count+=k;
	
	int pc=0;
	for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	pc+=move[i][j];
	
	count+=((pc*2)/3);
	
	printf("%d\n",count);
}
