/*
ID: kapiley1
PROG: calfflac
LANG: C++
*/
#include<stdio.h>
#include<iostream>
using namespace std;
struct PAL
{
	int len,mi,mj;
};
int maxPalLen=0,tLen=0;
char text[20007];
char convert(char a)
{
	if(a>=65 && a<=90)
	return (char)(a+32);
	return a;
}
PAL maxPalFinder(int i,int j)
{
	int cnt=0,mi=i,mj=j,odd=0;
	while(i>=0 && (text[i]<65 || (text[i]>90 && text[i]<97) || text[i]>122))
	i--;
	while(j<tLen && (text[j]<65 || (text[j]>90 && text[j]<97) || text[j]>122))
	j++;
	while(i>=0 && j<tLen && convert(text[i])==convert(text[j]))
	{
	mi=i;mj=j;
	if(i==j)
	odd=1;
	cnt++;
	i--;j++;
	while(i>=0 && (text[i]<65 || (text[i]>90 && text[i]<97) || text[i]>122))
	i--;
	while(j<tLen && (text[j]<65 || (text[j]>90 && text[j]<97) || text[j]>122))
	j++;
	}
	PAL t;
	t.len=cnt*2-odd;
	t.mi=mi;
	t.mj=mj+1;
	return t;
}
int main()
{
	freopen("calfflac.in","r",stdin);
	freopen("calfflac.out","w",stdout);
	int c,p=0;
	while((c=getchar_unlocked())!=-1)
	{
		text[p++]=(char)c;
	}
	tLen=p;
	PAL maxPal;
	maxPal.mi=0;
	maxPal.mj=0;
	maxPal.len=0;
	PAL tmp;
	
	int i=0;
	while(i<tLen-1)
	{
		tmp=maxPalFinder(i,i);
		if(maxPal.len<tmp.len)
		maxPal=tmp;
		tmp=maxPalFinder(i,i+1);
		if(maxPal.len<tmp.len)
		maxPal=tmp;
		i++;
	}
	printf("%d\n",maxPal.len);
	for(int i=maxPal.mi;i<maxPal.mj;i++)
	printf("%c",text[i]);
	printf("\n");
	return 0;
}

