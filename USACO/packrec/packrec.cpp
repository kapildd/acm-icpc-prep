/*
ID: kapiley1
PROG: packrec
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
struct Point {int x,y;
};
bool operator<(const Point &a,const Point &b)
{	
	return (a.x<b.x) || (a.x==b.x && a.y<b.y);
}
bool operator==(const Point &a,const Point &b)
{	
	return (a.x==b.x) && (a.y==b.y);
}
int area(Point p)
{
	return p.x*p.y;
}
vector<Point> sol;
void addSol(int x,int y)
{
	Point p;
	if(x<y)
	{
	p.x=x;
	p.y=y;
	}else
	{
	p.x=y;
	p.y=x;
	}
	if(!sol.empty() && area(sol[0])<area(p))
	{
		return;
	}else if(!sol.empty() && area(sol[0])>area(p))
	{
		sol.clear();
	}
	sol.push_back(p);
}
void layouts(Point p,Point q,Point r,Point s)
{
	addSol(p.x+q.x+r.x+s.x,max(p.y,max(q.y,max(r.y,s.y))));
	
	addSol(max(p.x,(q.x+r.x+s.x)),p.y+max(q.y,max(r.y,s.y)));
	
	addSol(max(p.x,max(q.x,r.x+s.x)),p.y+q.y+max(r.y,s.y));
	
	//addSol(max((p.x+q.x),(p.x+r.x+s.x)),max(p.y,max((q.y+r.y),(q.y+s.y))));
	//addSol(max((p.x+r.x),(p.x+q.x+s.x)),max(p.y,max((r.y+q.y),(r.y+s.y))));
	//addSol(max((p.x+s.x),(p.x+r.x+q.x)),max(p.y,max((s.y+r.y),(q.y+s.y))));
	
	//addSol(p.x+q.x+max(r.x,s.x),max((s.y+r.y),max(p.y,q.y)));
	
	//addSol(max(p.x,q.x)+max(r.x,s.x),max((p.y+r.y),(q.y+s.y)));
	
	//addSol(max(p.x+q.x,r.x+s.x),max(p.y+r.y,q.y+s.y));
	//addSol(max(p.x+q.x,r.x+s.x),max(p.y+s.y,q.y+r.y));
	
	addSol(max(p.x ,(q.x + r.x + s.x)), p.y + max(q.y, max(r.y, s.y)));

	addSol(p.x + max(q.x , (r.x + s.x)), max(p.y , (q.y + max(r.y , s.y))));

	addSol(p.x + max(q.x, r.x) + s.x, max(p.y , max((q.y + r.y), s.y)));
	
	if (q.x+s.x <= p.x+r.x &&
	    (q.x <= p.x || p.y >= r.y) &&
	    (s.x <= r.x || p.y <= r.y))
		addSol(p.x+r.x, max((p.y + q.y) , (r.y + s.y)));

}
Point trans(Point p)
{
	Point z;
	z.x=p.y;
	z.y=p.x;
	return z;
}
int main() {
    freopen("packrec.out","w",stdout);
    freopen("packrec.in","r",stdin);
	vector<Point> v(4);
	for(int i=0;i<4;i++)
	scanf("%d%d",&v[i].x,&v[i].y);
	sort(v.begin(),v.end());	
	do
	{
		/*vector<Point> w(v);
		layouts(w[0],w[1],w[2],w[3]);
		for(int i=0;i<4;i++)
		{
			w[i]=trans(w[i]);
			layouts(w[0],w[1],w[2],w[3]);
		}*/
		for (int z = 0; z < 16; z++) {
			vector<Point> w(v);
			for (int i = 0; i < 4; i++)
				if (z & (1 << i)) w[i] = trans(w[i]);
			layouts(w[0], w[1], w[2], w[3]);
		}
	}while(next_permutation(v.begin(),v.end()));
	printf("%d\n",area(sol[0]));
	sort(sol.begin(), sol.end());
	sol.erase(unique(sol.begin(), sol.end()), sol.end());

	for (int i = 0; i < sol.size(); i++)
		printf("%d %d\n", sol[i].x, sol[i].y);

    fclose(stdout);
    fclose(stdin);
    return 0;
}
