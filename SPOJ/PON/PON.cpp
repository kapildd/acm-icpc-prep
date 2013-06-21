#include<stdio.h>
#include<math.h>
#include<stdlib.h>
long long mul(long long a,long long b,long long c){
    long long x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x%c+y%c)%c;
        }
        y = ((y%c)*2)%c;
        b /= 2;
    }
    return x%c;
}
long long modulo( long long a, long long b, long long c){
     long long x=1,y=a; // long long is taken to avoid overflow of intermediate results
    while(b > 0){
        if(b%2 == 1){
            x=mul(x,y,c);
        }
        y = mul(y,y,c); // squaring the base
        b /= 2;
    }
    return x%c;
}
bool Fermat( long long p,int iterations){
    if(p == 1){ // 1 isn't prime
        return false;
    }
    for(int i=0;i<iterations;i++){
        // choose a random integer between 1 and p-1 ( inclusive )
         long long a = rand()%(p-1)+1; 
        // modulo is the function we developed above for modular exponentiation.
        if(modulo(a,p-1,p) != 1){ 
            return false; /* p is definitely composite */
        }
    }
    return true; /* p is probably prime */
}

int main()
{
	int t;
	 long long n;
	scanf("%d",&t);
	while(t-->0)
	{
		scanf("%lld",&n);
		if(Fermat(n,2))
		printf("YES\n");
		else
		printf("NO\n");
	}
	return 0;
}
