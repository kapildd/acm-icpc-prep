/*
ID: kapiley1
PROG: prefix
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

int main()
{
	freopen("prefix.in","r",stdin);
	freopen("prefix.out","w",stdout);
	
	char prim[207][15];
	char *seq=new char[200225];
	
	
	int cnt=-1;
	do
	{
		cnt++;
		scanf("%s",prim[cnt]);
	}while(prim[cnt][0]!='.');
	
	
	char line[86];
	while(scanf("%s",line)==1)
	{
		strcat(seq,line);
	}
	
	int slen=strlen(seq);
	int i,j,k;
	bool start[200225];
	for(i=0;i<slen;i++)
	start[i]=false;
	start[0]=true;
	int last=-1;
	bool valid=true;
	int pjlen;
	for(i=0;i<slen;i++)
	{
		if(start[i])
		{
			for(j=0;j<cnt;j++)
			{
				if(seq[i]==prim[j][0])//if first char match,try to check remaining premitive
				{
					pjlen=strlen(prim[j]);
					if(i+pjlen<=slen)
					{
						valid=true;
						for(k=1;k<pjlen;k++)
						{
							if(seq[i+k]!=prim[j][k])
							{
								valid=false;
								break;
							}
						}
						if(valid)
						{
							start[i+pjlen]=true;
							last=last>i+pjlen-1?last:i+pjlen-1;
						}
					}
				}
			}
		}
	}
	printf("%d\n",last+1);
	return 0;
}

