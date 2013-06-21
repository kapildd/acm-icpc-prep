import java.math.BigInteger;
import java.util.*;
class FCTRL2
{
	public static void main(String args[])
	{
		int t,n,i;
		HashMap hm=new HashMap();
                hm.put(0, new BigInteger("1"));
		Scanner s=new Scanner(System.in);
		t=s.nextInt();
                
		while(t-->0)
		{
			n=s.nextInt();
			i=n-1;
                        while(i>0)
                        {
                            if(hm.containsKey(i))
                                break;
                            i--;
                        }
                        BigInteger tmp=(BigInteger)hm.get(i);
                        i++;
                        while(i<=n)
                        {
                            tmp=tmp.multiply(new BigInteger(new Integer(i).toString()));
                            i++;
                        }
                        System.out.println(tmp);
                        hm.put(n, tmp);
		}
	}
}


