/*
ID: kapiley1
PROG: castle
LANG: JAVA
*/

import java.io.*;
class WALL
{
	public boolean W,N,E,S;
}
 class castle
{
	static int M,N,MAX,MAXR,NCOMP=1,graph[][]=new int[53][53],comp[][]=new int[53][53],count[]=new int[2600];
	static WALL getWalls(int n)
	{
		WALL w=new WALL();
		if(n>=8)
		{n-=8;w.S=true;}
		if(n>=4)
		{n-=4;w.E=true;}
		if(n>=2)
		{n-=2;w.N=true;}
		if(n>=1)
		{n-=1;w.W=true;}
		return w;
	}
	static void floodfill()
	{
		int nvis=0;
		do
		{
			nvis=0;
			
			for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
			{
				if(comp[i][j]==-2)
				{
					nvis++;
					
					comp[i][j]=NCOMP;
					count[NCOMP]++;
					WALL w=getWalls(graph[i][j]);
					
					if(!w.W && comp[i][j-1]==-1)
					{
						comp[i][j-1]=-2;
					}
					if(!w.N && comp[i-1][j]==-1)
					{
						comp[i-1][j]=-2;
					}
					if(!w.E && comp[i][j+1]==-1)
					{
						comp[i][j+1]=-2;
					}
					if(!w.S && comp[i+1][j]==-1)
					{
						comp[i+1][j]=-2;
					}
				}
			}
		
		}while(nvis>0);
	}
	static void components()
	{
		for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
		{
			if(comp[i][j]==-1)
			{
				comp[i][j]=-2;
				floodfill();
				NCOMP++;
			}
		}
	}
	public static void main(String args[]) throws IOException
	{
		BufferedReader bf=new BufferedReader(new FileReader("castle.in"));
		PrintWriter pw=new PrintWriter(new File("castle.out"));
		
		String line=bf.readLine();
		String vals[]=line.split(" ");
		M=Integer.parseInt(vals[0]);
		N=Integer.parseInt(vals[1]);
		//input
		for(int i=0;i<N;i++)
		{
			line=bf.readLine();
			vals=line.split(" ");
			for(int j=0;j<M;j++)
			{
			graph[i][j]=Integer.parseInt(vals[j]);
			comp[i][j]=-1;
			}
		}
		//calculate components
		components();
		//largest room
		MAXR=1;
		for(int i=0;i<NCOMP;i++)
		{
			if(count[i]>MAXR)MAXR=count[i];
		}
		//remove wall
		MAX=1;
		int X=1,Y=1;
		WALL d=new WALL();
		d.E=d.N=false;
		for(int j=0;j<M;j++)
		for(int i=N-1;i>=0;i--)
		{
			int n;
			WALL w=new WALL();
			w=getWalls(graph[i][j]);
			if(i>0 && comp[i][j]!=comp[i-1][j])
			{
				n=count[comp[i][j]]+count[comp[i-1][j]];
				if(n>MAX)
				{
					MAX=n;
					X=i;
					Y=j;
					d.N=true;
					d.E=false;
				}
			}
			if(j<M-1 && comp[i][j]!=comp[i][j+1])
			{
				n=count[comp[i][j]]+count[comp[i][j+1]];
				if(n>MAX)
				{
					MAX=n;
					X=i;
					Y=j;
					d.N=false;
					d.E=true;
				}
			}
		}
		
		
		pw.write(NCOMP-1+"\n");
		pw.write(MAXR+"\n");
		pw.write(MAX+"\n");
		pw.write((X+1)+" "+(Y+1)+" "+(d.E?"E":"N")+"\n");
		
		pw.close();
	}
}
