/*
ID: kapiley1
PROG: numtri
LANG: JAVA
*/
import java.io.*;
import java.util.*;
public class numtri
{
	public static void main(String args[]) throws IOException
	{
		BufferedReader d=new BufferedReader(new FileReader("numtri.in"));
		PrintWriter pw=new PrintWriter(new FileWriter("numtri.out"));
		int rows,i,j,n;
			rows=Integer.parseInt(d.readLine());
			Node tree[][]=new Node[rows][];
			i=0;
			while(i<rows)
			{
				String r=(d.readLine());
				String nums[]=r.split(" ");
				tree[i]=new Node[i+1];
				j=0;
				while(j<=i)
				{
					if(i!=0)
					{
					tree[i][j]=new Node(j,Integer.parseInt(nums[j]),tree[i-1]);
					tree[i][j].calcSum();
					}
					else
					{
					tree[i][j]=new Node(0,Integer.parseInt(nums[j]),null);
					tree[i][j].sum=tree[i][j].val;
					}
					j++;
				}
				i++;
			}
			int max=0;
			for(int k=0;k<rows;k++)
			if(max<tree[rows-1][k].sum)
			max=tree[rows-1][k].sum;
			pw.println(max);
			pw.close();
			d.close();
	}
}
class Node
{
	int val,sum,i;
	Node n[];
	Node(int i,int val,Node n[])
	{
	this.i=i;
	this.n=n;
	this.val=val;
	}
	void calcSum()
	{
		int max=0;
		for(int j=(i>0?i-1:0);(j<=i)&&(j<n.length);j++)
		{
			if(max<n[j].sum)
			max=n[j].sum;
		}
		sum=val+max;
	}
}
