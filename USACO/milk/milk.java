/*
ID: kapiley1
PROG: milk
LANG: JAVA
*/
import java.io.*;
import java.util.*;
class milk
{
	static int choseLeast(int a[],int b[])
	{
		int min=100000000,ind=-1;
		for(int i=0;i<a.length;i++)
		{
			if(a[i]<min && b[i]>0)
			{
				min=a[i];
				ind=i;
			}
		}
		return ind;
	}
	public static void main(String args[]) throws IOException
	{
		BufferedReader br=new BufferedReader(new FileReader("milk.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("milk.out")));
		StringTokenizer stk=new StringTokenizer(br.readLine()," ");
		int n=new Integer(stk.nextToken());
		int m=new Integer(stk.nextToken());
		int mlk[]=new int[m];
		int prc[]=new int[m];
		for(int i=0;i<m;i++)
		{
			stk=new StringTokenizer(br.readLine()," ");
			prc[i]=new Integer(stk.nextToken());
			mlk[i]=new Integer(stk.nextToken());
		}
		int price=0,merry=0;
		while(merry<n)
		{
			int c=choseLeast(prc,mlk);
			int volMilk=Math.min(mlk[c],n-merry);
			price+=volMilk*prc[c];
			merry+=volMilk;
			mlk[c]-=volMilk;
		}
		out.write(price+"\n");
		out.close();
		System.exit(0);
	}
}
