/*
ID: kapiley1
PROG: dualpal
LANG: JAVA
*/
import java.io.*;
import java.util.*;
class dualpal
{
	static String getInBase(int n,int b)
	{
		String m="";
		while(n>0)
		{
			char c=(n%b<10)?((char)(n%b+48)):((char)((n%b-10)+65));
			m=c+m;
			n/=b;
		}
		return m;
	}
	static boolean palin(String str)
	{
		int count=0,l=str.length(),i;
		for(i=0;i<l/2 ;i++)
		if(str.charAt(i)!=str.charAt(l-i-1))
		count++;
		return count==0;
	}
	public static void main(String args[]) throws IOException
	{
		BufferedReader br=new BufferedReader(new FileReader("dualpal.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("dualpal.out")));
		StringTokenizer stk=new StringTokenizer(br.readLine()," ");
		int n=new Integer(stk.nextToken());
		int s=new Integer(stk.nextToken());
		for(int i=s+1;n>0;i++)
		{
			int count=0;
			for(int j=2;j<=10;j++)
			if(palin(getInBase(i,j)))
			{
				count++;
			}
			if(count>=2)
			{
				n--;
				out.write(i+"\n");
			}
		}
		out.close();
		System.exit(0);
	}
}
