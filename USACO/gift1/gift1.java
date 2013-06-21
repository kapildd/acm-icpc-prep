/*
ID: kapiley1
PROG: gift1
LANG: JAVA
*/
import java.io.*;
import java.util.*;
class gift1
{
	public static void main(String args[]) throws IOException
	{
		BufferedReader b=new BufferedReader(new FileReader("gift1.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("gift1.out")));
		int np;
		int amt[],init[];
		String names[];
		HashMap nmnp=new HashMap();
		np=Integer.parseInt(b.readLine());
		names=new String[np];
		amt=new int[np];
		init=new int[np];
		for(int i=0;i<np;i++)
		{
			names[i]=b.readLine();
			nmnp.put(names[i],i);
			amt[i]=0;
			init[i]=0;
		}
		for(int i=0;i<np;i++)
		{
			String nm=b.readLine();
			int j=Integer.parseInt(nmnp.get(nm).toString());
			StringTokenizer st=new StringTokenizer(b.readLine()," \n");
			int a=Integer.parseInt(st.nextToken());
			int n=Integer.parseInt(st.nextToken());
			int c=0;
			if(n!=0)
			{c=(a/n)*n;
			init[j]=c;
			}else
			{
			init[j]=a;
			}for(int k=0;k<n;k++)
			{
				String g=b.readLine();
				int z=Integer.parseInt(nmnp.get(g).toString());
				amt[z]=amt[z]+a/n;
			}
		}
		for(int i=0;i<np;i++)
		{
			out.println(names[i]+" "+(amt[i]-init[i]));
		}
		out.close();
		System.exit(0);
	}
}
