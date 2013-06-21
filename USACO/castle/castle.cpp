/*
ID: kapiley1
PROG: castle
LANG: C++
*/
#include<stdio.h>
int graph[53][53],comp[53][53],count[2600]={0};
int M,N;
int compNum=1;
class walls
{
	public:
	bool W=0,N=0,E=0,S=0;
	walls(int n)
	{
		if(n>=8)
		{
			S=1;
			n-=8;
		}
		if(n>=4)
		{
			E=1;
			n-=4;
		}
		if(n>=2)
		{
			N=1;
			n-=2;
		}
		if(n>=1)
		{
			W=1;
			n-=1;
		}
	}
	void setE()
	{
		E=1;
		N=0;
	}
	void setN()
	{
		N=1;
		E=0;
	}
	bool getE()
	{
		return E;
	}
	bool getN()
	{
		return N;
	}
};
void floodfill(int X,int Y)
{
	int numV=0;
	do
	{
		numV=0;
		for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
		{
			if(comp[i][j]==-2)
			{
				
				comp[i][j]=compNum;
				count[compNum]++;
				walls e(graph[i][j]);
				if(!e.N && comp[i-1][j]==-1)comp[i-1][j]=-2;
				if(!e.W && comp[i][j-1]==-1)comp[i][j-1]=-2;
				if(!e.S && comp[i+1][j]==-1)comp[i+1][j]=-2;
				if(!e.E && comp[i][j+1]==-1)comp[i][j+1]=-2;
				numV++;
			}
		}
	}while(numV>0);
}
void components()
{
		for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
		{
			if(comp[i][j]==-1)
			{
				comp[i][j]=-2;
				floodfill(i,j);
				compNum++;
			}
		}
}
int main()
{
	freopen("castle.in","r",stdin);
	freopen("castle.out","w",stdout);
	
	scanf("%d%d",&M,&N);
	for(int i=0;i<N;i++)
	for(int j=0;j<M;j++)
	{
		scanf("%d",&graph[i][j]);
		comp[i][j]=-1;
	}
	components();
	
	/*for(int i=0;i<N;i++)
	for(int j=0;j<M;j++)
	printf("%d%c",comp[i][j],j<M-1?' ':'\n');
	*/
	printf("%d\n",compNum-1);
	
	int MAXR=0;
	for(int i=0;i<compNum;i++)
	{
		if(MAXR<count[i])
		MAXR=count[i];
	}
	
	int MAX=-1,X=-1,Y=-1;
	walls w(0);
	int c=0;
	for(int j=0;j<M;j++)
	for(int i=N-1;i>=0;i--)
	{
		if(i>0 && comp[i][j]!=comp[i-1][j])
		{
			c=count[comp[i][j]]+count[comp[i-1][j]];
			if(c>MAX)
			{
				MAX=c;
				X=i;
				Y=j;
				w.setN();
			}
		}
		
		if(j<M-1 && comp[i][j]!=comp[i][j+1])
		{
			c=count[comp[i][j]]+count[comp[i][j+1]];
			if(c>MAX)
			{
				MAX=c;
				X=i;
				Y=j;
				w.setE();
			}
		}
		
	}
	printf("%d\n%d\n%d %d %c\n",MAXR,MAX,X+1,Y+1,w.E?'E':'N');
	return 0;
}

