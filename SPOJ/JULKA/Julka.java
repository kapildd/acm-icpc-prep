import java.io.*;
import java.math.BigInteger;
class Julka
{
	public static void main(String args[]) throws IOException
	{
		int t=10;
		BigInteger a,b;
		DataInputStream d=new DataInputStream(System.in);
		while(t-->0)
		{
			a=new BigInteger(d.readLine());
			b=new BigInteger(d.readLine());
			System.out.println(a.add(b).divide(new BigInteger("2")));
			System.out.println(a.subtract(b).divide(new BigInteger("2")));
		}
	}
}
