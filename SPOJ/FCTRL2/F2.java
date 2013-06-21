import java.math.BigInteger;
import java.util.*;
class FCTRL2
{
	public static void main(String args[])
	{
		int t,n,i;
		Scanner s=new Scanner(System.in);
		t=s.nextInt();
                while(t-->0)
		{
			n=s.nextInt();
			BigInteger tmp=new BigInteger("1");
                        i=1;
                        i++;
                        while(i<=n)
                        {
                            tmp=tmp.multiply(new BigInteger(new Integer(i).toString()));
                            i++;
                        }
	                    System.out.println(tmp);
		}
	}
}


