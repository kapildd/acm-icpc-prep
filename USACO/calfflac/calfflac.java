/*
ID: kapiley1
PROG: calfflac
LANG: JAVA
*/
import java.io.*;
import java.util.*;
class PAL
{
	int len,mi,mj;
}
class calfflac
{
	static int maxPalLen=0;
	static char[] text;
	static char convert(char a)
	{
		if(a>=65 && a<=90)
		return (char)(a+32);
		return a;
	}
	static PAL maxPalFinder(int i,int j)
	{
		int cnt=0,mi=i,mj=j,odd=0;
		while(i>=0 && (text[i]<65 || (text[i]>90 && text[i]<97) || text[i]>122))
		i--;
		while(j<text.length && (text[j]<65 || (text[j]>90 && text[j]<97) || text[j]>122))
		j++;
		while(i>=0 && j<text.length && convert(text[i])==convert(text[j]))
		{
		mi=i;mj=j;
		if(i==j)
		odd=1;
		cnt++;
		i--;j++;
		while(i>=0 && (text[i]<65 || (text[i]>90 && text[i]<97) || text[i]>122))
		i--;
		while(j<text.length && (text[j]<65 || (text[j]>90 && text[j]<97) || text[j]>122))
		j++;
		}
		PAL t=new PAL();
		t.len=cnt*2-odd;
		t.mi=mi;
		t.mj=mj+1;
		return t;
	}
	static String ext="";
	public static void main(String args[]) throws IOException
	{
		BufferedReader br=new BufferedReader(new FileReader("calfflac.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("calfflac.out")));
		int c;
		while((c=br.read())!=-1)
		{
			ext+=(char)c;
		}
		text=ext.toCharArray();
		PAL maxPal=new PAL();
		maxPal.mi=0;
		maxPal.mj=0;
		maxPal.len=0;
		PAL tmp=new PAL();
		
		int i=0;
		while(i<text.length-1)
		{
			tmp=maxPalFinder(i,i);
			if(maxPal.len<tmp.len)
			maxPal=tmp;
			tmp=maxPalFinder(i,i+1);
			if(maxPal.len<tmp.len)
			maxPal=tmp;
			i++;
		}
		out.write(maxPal.len+"\n"+ext.substring(maxPal.mi,maxPal.mj)+"\n");
		out.close();
		System.exit(0);
	}
}
