import java.util.Scanner;
public class ADDREV
{
	static int sum(int a,int b)
	{
		int ar,br;
		ar=new Integer(new StringBuffer(new Integer(a).toString()).reverse().toString());
		br=new Integer(new StringBuffer(new Integer(b).toString()).reverse().toString());
		return new Integer(new StringBuffer(new Integer(ar+br).toString()).reverse().toString());
	}
	public static void main(String args[])
	{
		Scanner s=new Scanner(System.in);
		int n,a,b;
		n=s.nextInt();
		while(n-->0)
		{
			a=s.nextInt();
			b=s.nextInt();
			System.out.println(sum(a,b));
		} 
	}
}
