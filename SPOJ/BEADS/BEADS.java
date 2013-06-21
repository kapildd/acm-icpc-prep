import java.io.*;
import java.util.*;

class BEADS
{
	public static void main(String args[]) throws IOException
	{
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		int t;
		String s;
		t=Integer.parseInt(bf.readLine());
		while(t-->0)
		{
			s=bf.readLine();
			int l=s.length(),a=0;
			String min=s;
			s=s+s;
			
			for(int i=0;i<l;i++)
			{
				String sub=s.substring(i,i+l);
				if(min.compareTo(sub)>0)
				{
					min=sub;
					a=i;
				}
			}
			System.out.println((a+1));
		}
	}
}
