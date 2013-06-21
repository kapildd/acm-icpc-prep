/*
ID: kapiley1
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
char trans[1000][1000],orig[1000][1000],fin[1000][1000],temp[1000][1000];
int N;
bool check()
{
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	{
		if(trans[i][j]!=fin[i][j])
		return false;
	}
	return true;
}
void trans1(bool five)
{	
	char t[1000][1000];
	if(!five)
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	t[i][j]=orig[i][j];
	else
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	t[i][j]=trans[i][j];
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	{
		temp[i][j]=t[N-i-1][j];
	}
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	{
		trans[i][j]=temp[j][i];
	}
}
void trans2(bool five)
{
	char t[1000][1000];
	if(!five)
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	t[i][j]=orig[i][j];
	else
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	t[i][j]=trans[i][j];
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	{
		temp[i][j]=t[N-i-1][j];
	}
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	{
		trans[i][j]=temp[j][i];
	}
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	{
		temp[i][j]=trans[i][j];
	}
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	{
		trans[i][j]=temp[N-i-1][j];
	}
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	{
		temp[i][j]=trans[i][j];
	}
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	{
		trans[i][j]=temp[j][i];
	}
}
void trans3(bool five)
{
	char t[1000][1000];
	if(!five)
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	t[i][j]=orig[i][j];
	else
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	t[i][j]=trans[i][j];
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	{
		temp[i][j]=t[N-i-1][j];
	}
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	{
		trans[i][j]=temp[j][i];
	}
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	{
		temp[i][j]=trans[i][j];
	}
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	{
		trans[i][j]=temp[N-i-1][j];
	}
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	{
		temp[i][j]=trans[i][j];
	}
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	{
		trans[i][j]=temp[j][i];
	}
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	{
		temp[i][j]=trans[i][j];
	}
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	{
		trans[i][j]=temp[N-i-1][j];
	}
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	{
		temp[i][j]=trans[i][j];
	}
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	{
		trans[i][j]=temp[j][i];
	}
}
void trans4()
{
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	{
		trans[i][j]=orig[i][N-j-1];
	}
}
void trans6()
{
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	{
		trans[i][j]=orig[i][j];
	}
}
int transform()
{
	trans1(false);
	if(check())
	return 1;
	trans2(false);
	if(check())
	return 2;
	trans3(false);
	if(check())
	return 3;
	trans4();
	if(check())
	return 4;
	
	trans4();
	trans1(true);
	
	if(check())
	return 5;
	
	trans4();
	trans2(true);
	
	if(check())
	return 5;
	
	trans4();
	trans3(true);
	
	if(check())
	return 5;
	
	trans6();
	if(check())
	return 6;
	
	return 7;
}
int main() {
    freopen("transform.out","w",stdout);
    freopen("transform.in","r",stdin);
    int n;
    scanf("%d",&n);
    N=n;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
    char c=0;
    
    while(c!='@' && c!='-')
    scanf("%c",&c);
    orig[i][j]=c;
    }
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
		char c=0;
		while(c!='@' && c!='-')
		scanf("%c",&c);
		fin[i][j]=c;
    }
    printf("%d\n",transform());
    fclose(stdout);
    fclose(stdin);
    return 0;
}
