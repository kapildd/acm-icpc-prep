import java.math.*;
import java.util.*;
//Uncle Jack problem is related to combinatorics
class UJ
{

	public static void main(String args[])	{
		Scanner s=new Scanner(System.in);
		int a,b,n,i;
		a=(s.nextInt());
		b=(s.nextInt());
		while((a!=0)) {
			BigInteger A=new  BigInteger(""+a);
			System.out.println(A.pow(b));
			a=s.nextInt();
			b=s.nextInt();
		}
	}
}
