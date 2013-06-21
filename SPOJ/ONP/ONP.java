import java.io.*;
import java.util.*;
class ONP
{
	public static void main(String args[]) throws IOException
	{
		Stack op=new Stack();
		int t,c;
		char ch;
		String outp;
		DataInputStream d=new DataInputStream(System.in);
		t=Integer.parseInt(d.readLine());
		while(t-->0)
		{
			outp="";
			while((c=d.read())<33);
			while(c>33)
			{
				ch=(char)c;
				if(ch=='(')
				{
					op.push(ch);
				}else if(ch==')')
				{
					while((ch=(op.pop().toString().charAt(0)))!='(')
					{
						outp+=ch;
					}
				}else if((ch>='a'&&c<='z')||(ch>='A'&&ch<='Z'))
				{
					outp+=ch;
				}else
				{
					op.push(ch);
				}
				c=d.read();
			}
			while(!op.empty())
			{
				outp+=op.pop().toString().charAt(0);
			}
			System.out.println(outp);
		}
	}
}
