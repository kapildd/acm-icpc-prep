#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#define posD(a,b) a-b+13
using namespace std;
int *board;
bool *colUsed,*lDiag,*rDiag;
bool validBoard(int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j)continue;
			//if(board[i]==board[j])return false;
			if(fabs(board[i]-board[j])==fabs(i-j))return false;
		}
	}
	return true;
}
int cnt=0,mx=0;
void checker(int r,int rCurr)
{
	if(r == rCurr)
	{
		if(cnt<3)
		for(int i=0;i<r;i++)
		{
			printf("%d%c",board[i]+1,i==r-1?'\n':' ');
		}
		cnt++;
		return;
	}
	if(r>8 && rCurr==0)
	{
		if(r%2==0)
		for(int i=0;i<r/2;i++)
		{
			board[rCurr]=i;
			if(!colUsed[i] && !lDiag[i+rCurr] && !rDiag[posD(i,rCurr)])
			{
			colUsed[i]=true;
			lDiag[i+rCurr]=true;
			rDiag[posD(i,rCurr)]=true;
			checker(r,rCurr+1);
			colUsed[i]=false;
			lDiag[i+rCurr]=false;
			rDiag[posD(i,rCurr)]=false;
			}
		}else
		{
			for(int i=0;i<=r/2;i++)
			{
				board[rCurr]=i;
				if(!colUsed[i] && !lDiag[i+rCurr] && !rDiag[posD(i,rCurr)])
				{
				colUsed[i]=true;
				lDiag[i+rCurr]=true;
				rDiag[posD(i,rCurr)]=true;
				checker(r,rCurr+1);
				colUsed[i]=false;
				lDiag[i+rCurr]=false;
				rDiag[posD(i,rCurr)]=false;
				}
				if(i<r/2 && mx<cnt)mx=cnt;
			}
			
		}
	}
	else
	for(int i=0;i<r;i++)
	{
		board[rCurr]=i;
		if(!colUsed[i] && !lDiag[i+rCurr] && !rDiag[posD(i,rCurr)])
		{
		colUsed[i]=true;
		lDiag[i+rCurr]=true;
		rDiag[posD(i,rCurr)]=true;
		checker(r,rCurr+1);
		colUsed[i]=false;
		lDiag[i+rCurr]=false;
		rDiag[posD(i,rCurr)]=false;
		}
	}
}
int main()
{
	freopen("checker.in","r",stdin);
	freopen("checker.out","w",stdout);
	int r;
	scanf("%d",&r);
	board=new int[r];
	colUsed=new bool[r];
	lDiag=new bool[32];
	rDiag=new bool[32];
	for(int i=0;i<r;i++)
	{
		colUsed[i]=false;
		lDiag[i]=rDiag[i]=lDiag[13+i]=rDiag[13+i]=false;
	}
	checker(r,0);
	printf("%d\n",r>8?(r%2==0?cnt*2:(cnt+mx)):cnt);
	return 0;
}
