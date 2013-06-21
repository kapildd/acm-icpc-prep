/*
ID: kapiley1
PROG: prefix
LANG: JAVA
*/
import java.io.*;
import java.util.*;
class prefix
{
	public static void main(String args[]) throws IOException
	{
		BufferedReader dis=new BufferedReader(new FileReader("prefix.in"));
		PrintWriter pw=new PrintWriter(new File("prefix.out"));
		
		char s[]=new char[200225];
		char prim[][]=new char[208][15];
		int size[]=new int[208];
		int ch,plen=-1,c,slen=0;
		do
		{
			c=0;
			plen++;
			while((ch=dis.read())!=' ' && ch!='\n')
			{
				prim[plen][c]=(char)ch;
				c++;
			}
			size[plen]=c;
		}while(prim[plen][0]!='.');
		
		while((ch=dis.read())!=-1)
		{
			if(ch!='\n')
			s[slen++]=(char)ch;
		}
		int i,j,k;
		boolean start[]=new boolean[s.length+1];
		for(i=0;i<s.length;i++)
		start[i]=false;
		start[0]=true;
		int last=-1;
		for(i=0;i<slen;i++)
		{
			if(start[i])
			{
				for(j=0;j<plen;j++)
				{
					if(s[i]==prim[j][0])//if first char match,try to check remaining primitive
					{
						boolean valid=true;
						if(i+size[j]<=slen)
						{
							for(k=1;k<size[j];k++)
							{
								if(s[i+k]!=prim[j][k])
								{
									valid=false;
									break;
								}
							}
							if(valid)
							{
								start[i+size[j]]=true;
								last=last>i+size[j]-1?last:i+size[j]-1;
							}
						}
					}
				}
			}
		}
		pw.println(last+1);
		pw.close();
	}
}
