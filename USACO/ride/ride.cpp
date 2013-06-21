/*
ID: kapiley1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    freopen("ride.out","w",stdout);
    freopen("ride.in","r",stdin);
    int res1=1,res2=1,i=0;
    char c=getchar_unlocked();
    while(c!='\n')
    {
    	res1*=(c-'A'+1);
    	c=getchar_unlocked();
    }
    c=getchar_unlocked();
    while(c!='\n')
    {
    	res2*=(c-'A'+1);
    	c=getchar_unlocked();
    }
    if(res1%47==res2%47)
    cout << "GO" << endl;
    else
    cout << "STAY" << endl;
    
    fclose(stdout);
    fclose(stdin);
    return 0;
}
