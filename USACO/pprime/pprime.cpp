/*
ID: kapiley1
PROG: pprime
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
int modulo(int a,int b,int c){
    long long x=1,y=a; // long long is taken to avoid overflow of intermediate results
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%c;
        }
        y = (y*y)%c; // squaring the base
        b /= 2;
    }
    return x%c;
}
long long mulmod(long long a,long long b,long long c){
    long long x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}
bool Miller(long long p,int iteration){
    if(p<2){
        return false;
    }
    if(p!=2 && p%2==0){
        return false;
    }
    long long s=p-1;
    while(s%2==0){
        s/=2;
    }
    for(int i=0;i<iteration;i++){
        long long a=rand()%(p-1)+1,temp=s;
        long long mod=modulo(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1){
            mod=mulmod(mod,mod,p);
            temp *= 2;
        }
        if(mod!=p-1 && temp%2==0){
            return false;
        }
    }
    return true;
}
bool isPrime(int n)
{
	return Miller(n,2);
}
void ppal(int da,int a,int db,int b)
{
	switch(da)
	{
		case 1:
		for(int i=2;i<8;i++)
		if(i>=a && i<=b && isPrime(i))printf("%d\n",i);
		if(1==db)break;
		case 2:
		for(int i=1;i<10;i+=2)
		if(i*10+i>=a && i*10+i<=b && isPrime(i*10+i))printf("%d\n",i*10+i);
		if(2==db)break;
		case 3:
		for(int i=1;i<10;i+=2)
		for(int j=0;j<10;j++)
		{
		int n=i*100+j*10+i;
		if(n>=a && n<=b && isPrime(n))printf("%d\n",n);
		}
		if(3==db)break;
		case 4:
		for(int i=1;i<10;i+=2)
		for(int j=0;j<10;j++)
		{
		int n=i*1000+j*100+j*10+i;
		if(n>=a && n<=b && isPrime(n))printf("%d\n",n);
		}
		if(4==db)break;
		case 5:
		for(int i=1;i<10;i+=2)
		for(int j=0;j<10;j++)
		for(int k=0;k<10;k++)
		{
		int n=i*10000+j*1000+k*100+j*10+i;
		if(n>=a && n<=b && isPrime(n))printf("%d\n",n);
		}
		if(5==db)break;
		case 6:
		for(int i=1;i<10;i+=2)
		for(int j=0;j<10;j++)
		for(int k=0;k<10;k++)
		{
		int n=i*100000+j*10000+k*1000+k*100+j*10+i;
		if(n>=a && n<=b && isPrime(n))printf("%d\n",n);
		}
		if(6==db)break;
		case 7:
		for(int i=1;i<10;i+=2)
		for(int j=0;j<10;j++)
		for(int k=0;k<10;k++)
		for(int l=0;l<10;l++)
		{
		int n=i*1000000+j*100000+k*10000+l*1000+k*100+j*10+i;
		if(n>=a && n<=b && isPrime(n))printf("%d\n",n);
		}
		if(7==db)break;
		case 8:
		for(int i=1;i<10;i+=2)
		for(int j=0;j<10;j++)
		for(int k=0;k<10;k++)
		for(int l=0;l<10;l++)
		{
		int n=i*10000000+j*1000000+k*100000+l*10000+l*1000+k*100+j*10+i;
		if(n>=a && n<=b && isPrime(n))printf("%d\n",n);
		}
	}
}
int main()
{
	freopen("pprime.in","r",stdin);
	freopen("pprime.out","w",stdout);
	
	char a[9],b[9];
	int aa,bb;
	scanf("%s %s",a,b);
	aa=atoi(a);
	bb=atoi(b);
	ppal(strlen(a),aa,strlen(b),bb);
	return 0;
}

