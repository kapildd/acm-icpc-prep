/*
ID: kapiley1
PROG: barn1
LANG: JAVA
*/
import java.io.*;
import java.util.*;
class barn1
{
	static int findMaxDiff(int cowStalls[],int n,int max)
	{
		Vector ba=new Vector();
		//if(cowStalls[0]>1)
		//ba.add(new diff(1,cowStalls[0],cowStalls[0]-1));
		int pre=cowStalls[0];
		for(int i=1;i<cowStalls.length;i++)
		{
			ba.add(new diff(pre,cowStalls[i],cowStalls[i]-pre));
			pre=cowStalls[i];
		}
		
		//if(cowStalls[cowStalls.length-1]<max)
		//ba.add(new diff(cowStalls[cowStalls.length-1],max,max-cowStalls[cowStalls.length-1]));
		Collections.sort(ba,
		new Comparator()
		{
			public int compare(Object x,Object y)
			{
				diff a=(diff)x;
				diff b=(diff)y;
				if(a.val<b.val)
				return 1;
				else if(a.val>b.val)
				return -1;
				else 
				return 0;
			}
		}
		);
		char covered[]=new char[max+1];
		for(int i=0;i<covered.length;i++)
		covered[i]='X';
		for(int i=0;i<cowStalls[0];i++)
		covered[i]='O';
		for(int i=cowStalls[cowStalls.length-1]+1;i<=max;i++)
		covered[i]='O';
		
		
		for(int i=0;i<n-1 && i<ba.size();i++)
		{
			diff d=(diff)ba.get(i);
			for(int j=d.bef+1;j<d.aft;j++)
			covered[j]='O';
		}
		int count=0;
		for(int  i=1;i<=max;i++)
		if(covered[i]=='X')count++;
		return count;
	}
	public static void main(String args[]) throws IOException
	{
		BufferedReader br=new BufferedReader(new FileReader("barn1.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("barn1.out")));
		StringTokenizer stk=new StringTokenizer(br.readLine()," ");
		int n=new Integer(stk.nextToken());
		int s=new Integer(stk.nextToken());
		int c=new Integer(stk.nextToken());
		int cowStalls[]=new int[c];
		for(int i=0;i<c;i++)
		{
			cowStalls[i]=new Integer(br.readLine());
		}
		Arrays.sort(cowStalls);
		int count=findMaxDiff(cowStalls,n,s);
		out.write(count+"\n");
		out.close();
		System.exit(0);
	}
}
class diff
{
	public int bef,aft,val;
	diff(int b,int a,int v)
	{
		bef=b;
		aft=a;
		val=v;
	}
}
