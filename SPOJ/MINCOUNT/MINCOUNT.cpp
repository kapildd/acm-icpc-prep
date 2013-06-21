#include <cstdio>
using namespace std;
inline long long fastRead(long long *a)
{
	 register char c=0;
	 register int count=0;
	
	 while (c<33) c=getchar_unlocked();
	 *a=0;
	 while (c>33)
	 {
	 count++;
	     *a=*a*10+c-'0';
	     c=getchar_unlocked();
	 }
	 return count;
}
int main()
{
	int T;
	scanf("%d", &T);

	for (int cs = 1; cs <= T; cs++) 
	{
		long long N;
		fastRead(&N);

		long long res = N*(N+1)/6;
		printf("%lld\n", res);
	}
}
