#include <algorithm>
#include <cstdio>
using namespace std;
 
int grid[3][3];
int *A=&grid[0][0],*B=&grid[0][1],*C=&grid[0][2],*D=&grid[1][0],*E=&grid[1][1],*F=&grid[1][2],*G=&grid[2][0],*H=&grid[2][1],*I=&grid[2][2];
int *add[9][5]={{A,B,D,E},{A,B,C},{B,C,E,F},{A,D,G},{B,D,E,F,H},{C,F,I},{D,E,G,H},{G,H,I},{E,F,H,I}};
int adds[9]={4,3,4,3,5,3,4,3,4};
int action[40],bad;
 
bool dfsid(int moves,int z=0){
  // if (moves<=0 or z==9 or z==6 and ((*A)|(*B))) return moves==0 and not bad;
  if (moves<=0 or z==9) return moves==0 and not bad;
 
  for (int p=0; p<4; ++p){
    if (dfsid(moves-p,z+1)) {while (p--) action[moves-1-p]=z+1; return true;}
    for (int i=adds[z]; i--;) switch ((++*add[z][i])&=3) {case 0:--bad;break;case 1:++bad;}
  }
 
  return false;
}
 
int main(){
  for (int i=0; i<3; i++){
    for (int j=0; j<3; j++){
	  scanf("%d",&grid[i][j]), bad+=!!((grid[i][j])&=3);
    }
  }
  for (int i=0;; i++){
    if (dfsid(i)){
      for (int j=i; j--;) printf("%d%c",action[j],j?' ':'\n');
      break;
    }
  }
}
