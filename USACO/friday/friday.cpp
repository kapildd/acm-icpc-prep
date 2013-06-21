/*
ID: kapiley1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool isLeapYear(int y)
{
	if(y%400==0)
	return true;
	if(y%100==0)
	return false;
	if(y%4==0)
	return true;
	else
	return false;
}
int main() {
    freopen("friday.out","w",stdout);
    freopen("friday.in","r",stdin);
    int n;
    scanf("%d",&n);
    
    int days[7]={0};
    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int cur=0;
    for(int i=0;i<n;i++)
    {
    	int d13=(cur+6)%7;
    	days[d13]++;
    	bool leap=isLeapYear(1900+i);
    	for(int j=1;j<12;j++)
    	{
    		d13=(d13+month[j-1])%7;
    		if(leap && j==2)
    		d13=(d13+1)%7;
    		days[d13]++;
    	}
    	if(leap)
    	{
    		cur++;
    	}
    	cur=(cur+1)%7;
    }
    for(int i=6;i!=5;i=(i+1)%7)
    printf("%d ",days[i]);
    printf("%d\n",days[5]);
    
    fclose(stdout);
    fclose(stdin);
    return 0;
}
