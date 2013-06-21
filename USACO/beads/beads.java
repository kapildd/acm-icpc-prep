/*
ID: kapiley1
PROG: beads
LANG: JAVA
*/
import java.io.*;
import java.util.*;
class beads
{
	static char getClosest(String bead)
	{
		char c='b';
		int i=0;
		while((i<bead.length()) && (c=bead.charAt(i++))=='w');
		return c;
	}
	static int ws(String bead)
	{
		int count=0,l=bead.length(),i;
		for(i=0;i<l ;i++)
		if(bead.charAt(i)=='w')
		count++;
		return count;
	}
	public static void main(String args[]) throws IOException
	{
		BufferedReader br=new BufferedReader(new FileReader("beads.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("beads.out")));
		String bead,rounded;
		br.readLine();
		bead=br.readLine();
		int l=bead.length(),max=0;
		for(int i=0;i<l;i++)
		{
			int r=l-1,b=l,cnt=0;
			rounded=bead+bead;
			char c;
			if(getClosest(bead)=='b')
			{
				r=l-1;b=l;
				while((r>=0)&&((c=rounded.charAt(r))=='r' || c=='w'))
				r--;
				while((b<2*l)&&((c=rounded.charAt(b))=='b' || c=='w'))
				b++;
				cnt=b-r-1;
				if(b-r-1 > l)
				{
				cnt-=ws(bead);
				}
			}else
			{
				r=l;b=l-1;
				while((b>=0)&&((c=rounded.charAt(b))=='b' || c=='w'))
				b--;
				while((r<2*l)&&((c=rounded.charAt(r))=='r' || c=='w'))
				r++;
				cnt=r-b-1;
				if(r-b-1 > l)
				{
				cnt-=ws(bead);
				}
			}
			if(cnt>max)
			max=cnt;
			c=bead.charAt(0);
			bead=bead.substring(1,l)+c;
		}
		out.write(""+max+"\n");
		out.close();
		System.exit(0);
	}
}
