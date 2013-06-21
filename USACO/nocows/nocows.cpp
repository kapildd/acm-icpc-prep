/*
ID: kapiley1
PROG: nocows
LANG: C++
*/
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std; 
long long dp[201][101];
int N,K;
 
void solve(){  
  for(int k=1;k<=K;k++) {  // loop on heights
    dp[1][k]=1;
    for(int n=2;n<=N;n++) { // loop on nodes
      dp[n][k]=0;
      for(int p=1;p<=n-2;p++) { // loop on previous nodes
        dp[n][k] += dp[p][k-1] * dp[n-1-p][k-1];
        dp[n][k] %= 9901;
      }
    }
  }
}
int main() {
  freopen("nocows.out","w",stdout);
  freopen("nocows.in","r",stdin);
 
  scanf("%d%d",&N,&K);  
  if (N%2 == 0) {
    printf("0\n");
    return 0;    
  }
  solve();
  
  int ans = ((dp[N][K]-dp[N][K-1]+9901)%9901);
   printf("%d\n",ans);
    
  return 0;
}
