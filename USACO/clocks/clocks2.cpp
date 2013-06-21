#include <cstdio>
using namespace std;

int type[9];
int moves[9][9] = {
{3,3,3,3,3,2,3,2,0},
{2,3,2,3,2,3,1,0,1},
{3,3,3,2,3,3,0,2,3},
{2,3,1,3,2,0,2,3,1},
{2,3,2,3,1,3,2,3,2},
{1,3,2,0,2,3,1,3,2},
{3,2,0,3,3,2,3,3,3},
{1,0,1,3,2,3,2,3,2},
{0,2,3,2,3,3,3,3,3}
};

int main() {
freopen("clocks.out","w",stdout);
freopen("clocks.in","r",stdin);
    
int i, j, k;
for(i=0;i<9;i++) {
scanf("%d",&k);
for(j=0;j<9;j++) type[j] = (type[j]+(4-k/3)*moves[i][j])%4;
}
bool init=false;
for(i=0;i<9;i++) {
for(j=0;j<type[i];j++) 
{
if(!init) {
printf("%d",i+1);
init=true;
}
else printf(" %d",i+1);
}
}
printf("\n");
	fclose(stdout);
    fclose(stdin);
return 0;
}
