#include<stdio.h>
#include<algorithm>
#define N 5700
using namespace std;
inline void readInt(int *a)
{
		int sign=1; 
	 register char c=0;
	 while (c<33) c=getchar_unlocked();
	 *a=0;
	 while (c>33)
	 {
	 	if(c=='-')
	 	sign=-1;
	 	else
	    *a=*a*10+c-'0';
	     c=getchar_unlocked();
	 }
	 *a=sign*(*a);
}
int row[N],rowPointer[N],col[N],colPointer[N];
int main()
{
	char c;
	int a,b,z;
	for(int i=0;i<N;i++)
	{
		row[i]=col[i]=rowPointer[i]=colPointer[i]=i;
	}
	while(scanf("%c",&c)!=EOF)
	{
		switch(c)
		{
			case 'R':
			readInt(&a);
			readInt(&b);
			swap(row[a],row[b]);
			swap(rowPointer[row[a]],rowPointer[row[b]]);
			break;
			case 'C':
			readInt(&a);
			readInt(&b);
			swap(col[a],col[b]);
			swap(colPointer[col[a]],colPointer[col[b]]);
			break;
			case 'Q':
			readInt(&a);
			readInt(&b);
			printf("%d\n",((row[a]-1)*5678+col[b]));
			break;
			case 'W':
			readInt(&z);
			printf("%d %d\n",(rowPointer[(z-1)/5678+1]),(colPointer[(z-1)%5678+1]));
		}
	}
}
