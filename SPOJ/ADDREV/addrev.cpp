#include<stdio.h>
long int revsum(int a,int b,int al,int bl)
{
	int ax[10]={0},bx[10]={0};
	register int k=10;
	for(int i=al-1;i>=0;i--)
	{
		ax[i]=a%k;
		a=a/10;
	}
	for(int i=bl-1;i>=0;i--)
	{
		bx[i]=b%k;
		b=b/10;
	}
	a=0;
	if(bl>al)
	al=bl;
	for(int i=0;i<al;i++)
	{
		if(ax[i]+bx[i]<=9)
		ax[i]=ax[i]+bx[i];
		else
		{
		ax[i]=(ax[i]+bx[i])%10;
		ax[i+1]++;
		}
	}
	int i=0;
	while(ax[i]!=0)
	{
		a=a*10+ax[i++];
	}
	return a;
}
inline int fastRead(int *a)
{
	 register char c=0;
	 register int count=0;
	
	 while (c<33) c=getchar_unlocked();
	 *a=0;
	 while (c>33)
	 {
	 count++;
	     *a=*a*10+c-'0';
	     c=getchar_unlocked();
	 }
	 return count;
}
int main()
{
	int n,a,b,al,bl,d;
	fastRead(&n);
	while(n--)
	{	
		al=fastRead(&a);
		bl=fastRead(&b);
		d=revsum(a,b,al,bl);
		printf("%d\n",d);
	}
	return 0;
} 
