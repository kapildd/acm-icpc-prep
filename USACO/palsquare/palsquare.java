/*
ID: kapiley1
PROG: palsquare
LANG: JAVA
*/
import java.io.*;
import java.util.*;
class palsquare
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
		BufferedReader br=new BufferedReader(new FileReader("palsquare.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("palsquare.out")));
		
		int b=new Integer(br.readLine());
		for(int i=1;i<=300;i++)
		{
			if(palin(getInBase(i*i,b)))
			{
				out.write(getInBase(i,b)+" "+getInBase(i*i,b)+"\n");
			}
		}
		out.close();
		System.exit(0);
	}
}
