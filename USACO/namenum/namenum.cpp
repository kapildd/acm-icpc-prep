/*
ID: kapiley1
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> dict[12];
int r[15],N,cnt=0,z=0;
char key[][3]={{-1,-1,-1},{'A','B','C'},{'D','E','F'},{'G','H','I'},{'J','K','L'},{'M','N','O'},{'P','R','S'},{'T','U','V'},{'W','X','Y'}};

void gen(int k,string t)
{
	if(k==-1)
	{
		if(count(dict[N-1].begin(),dict[N-1].end(),t)==1)
		{
			cout<<t<<endl;
			cnt++;
		}
		//z++;
		//cout<<t<<endl;
	return;
	}
	int i=r[k]-1;
	for(int j=0;j<=2;j++)
	{
	gen(k-1,(t+key[i][j]));
	}
}

int main() {
    freopen("namenum.out","w",stdout);
    freopen("dict.txt","r",stdin);
    string tmp;
    while(cin>>tmp)
    {
    	dict[tmp.length()-1].push_back(tmp);
    }
    fclose(stdin);
    freopen("namenum.in","r",stdin);
    long long n;
    scanf("%lld",&n);
    int c=0;
    long long TEN=10,ZERO=0;
    while(n>ZERO)
    {
    	r[c++]=n%TEN;
    	n=n/TEN;
    }
    N=c;
    
    string s="";
    gen(c-1,s);
    if(!cnt)
    printf("NONE\n");
    fclose(stdout);
    fclose(stdin);
    return 0;
}
