/*
ID: kapiley1
PROG: clocks
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>
using namespace std;

bool solved=false;
int a[9][9];
string ch[9];
bool isOK(int* clocks)
{
	for(int i=0;i<9;i++)
	if(clocks[i]!=12)
	return false;
	return true;
}
void apply(int* clocks,int s)
{
	for(int i=0;i<9;i++)
	clocks[i]+=a[s][i];
	for(int i=0;i<9;i++)
	if(clocks[i]==15)clocks[i]=3;
}
string best="";
void better(string n)
{
	if(best=="" || best.length()>n.length())
	best=n;
	else if(best.length()==n.length()){
		for(int i=0;i<best.length();i++)
		if(best[i]>n[i])
		{
			best=n;
			break;
		}
	}
}
int main() {
	ch[0]="ABDE";
	ch[1]="ABC";
	ch[2]="BCEF";
	ch[3]="ADG";
	ch[4]="BDEFH";
	ch[5]="CFI";
	ch[6]="DEGH";
	ch[7]="GHI";
	ch[8]="EFHI";
    
    for(int i=0;i<9;i++)
    {
    	int j=0;
    	while(ch[i][j]!='\0')
    	a[i][ch[i][j++]-'A']=3;
    }
    
    freopen("clocks.out","w",stdout);
    freopen("clocks.in","r",stdin);
    vector<int> clocks(9);
    for(int i=0;i<9;i++)
    scanf("%d",&clocks[i]);
    
    for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			for(int k=0;k<4;k++)
			{	
				for(int l=0;l<4;l++)
				{	
					for(int m=0;m<4;m++)
					{	for(int n=0;n<4;n++)
						{	for(int o=0;o<4;o++)
							{
								for(int p=0;p<4;p++)
								{
									for(int q=0;q<4;q++)
									{
										string s="";
										int c[9];
										for(int z=0;z<9;z++)
										c[z]=clocks[z];
										for(int ii=0;ii<i;ii++)
										{
											apply(c,0);
											s+='1';
										}
										for(int jj=0;jj<j;jj++)
										{
											apply(c,1);
											s+='2';
										}
										for(int kk=0;kk<k;kk++)
										{
											apply(c,2);
											s+='3';
										}	
										for(int ll=0;ll<l;ll++)
										{
											apply(c,3);
											s+='4';
										}	
										for(int mm=0;mm<m;mm++)
										{
											apply(c,4);
											s+='5';
										}	
										for(int nn=0;nn<n;nn++)
										{
											apply(c,5);
											s+='6';
										}
										for(int oo=o;oo<o;oo++)
										{
											apply(c,6);
											s+='7';
										}
										for(int pp=0;pp<p;pp++)
										{
											apply(c,7);
											s+='8';
										}
										for(int qq=0;qq<q;qq++)
										{
											apply(c,8);
											s+='9';
										}
										if(isOK(c))
										{
											for(int i=0;i<s.length();i++)
												printf("%c%c",s[i],i==s.length()-1?'\n':' ');
											fclose(stdout);
											fclose(stdin);
											return 0;
										}
									}
								}
							}
						}	
					}
				}
			}
		}
	}
	fclose(stdout);
    fclose(stdin);
    return 0;
}
