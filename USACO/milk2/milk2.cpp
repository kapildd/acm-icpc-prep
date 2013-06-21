/*
ID: kapiley1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> from,to;
set<int> timei;
    
bool milks_at_least_one(int t)
{
	vector<int>::iterator i,j;
	for(i=from.begin(),j=to.begin();i!=from.end();i++,j++)
	{
		if(*i<=t && *j>=t)
		return true;
	}
	return false;
}
int main() {
    freopen("milk2.out","w",stdout);
    freopen("milk2.in","r",stdin);
    
    scanf("%d",&n);
    //timei.insert(0);
    for(int i=0;i<n;i++)
    {
    	int x,y;
    	scanf("%d%d",&x,&y);
    	from.push_back(x);
    	to.push_back(y);
    	timei.insert(x);
    	timei.insert(y);
    }
    
    
    set<int>::iterator k;
    
    bool no_cows=true;
    int none=*timei.begin(),atone=*timei.begin(),max_no_cows=0,none_cows=0,max_some_cows=0,some_cows=0;
    for(k=timei.begin();k!=timei.end();k++)
    {
    	vector<int>::iterator i,j;
    	//printf("%d\t",*k);
		int one=*k,two;k++;
		if(k!=timei.end())
		two=*k;
		else
		break;
		
		no_cows=true;
		for(i=from.begin(),j=to.begin();i!=from.end();i++,j++)
		{
			if(one>=*i && two<=*j)
			{
				no_cows=false;
				if(atone==one)
				{
					some_cows+=(two-one);
					atone=two;
				}else
				{
					some_cows=(two-one);
					atone=two;
				}
				break;
			}
		}
		if(no_cows)
		{
				if(none==one)
				{
					none_cows+=(two-one);
					none=two;
				}else
				{
					none_cows=(two-one);
					none=two;
				}
				some_cows=0;
		}
		else
		{
			none_cows=0;
		}
		if(some_cows > max_some_cows)
		{
			max_some_cows=some_cows;
		}
		if(none_cows>max_no_cows)
		{
			max_no_cows=none_cows;
		}
		k--;
    }
    
    printf("%d %d\n",max_some_cows,max_no_cows);
    
    fclose(stdout);
    fclose(stdin);
    return 0;
}
