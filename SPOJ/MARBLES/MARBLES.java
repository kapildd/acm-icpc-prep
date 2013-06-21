import java.util.*;
import java.math.*;

class MARBLES {
	static BigInteger combinations(int n,int k)
	{
		if (k < 0 || k > n) return BigInteger.ZERO;
        	if (n-k < k) k = n-k;

		BigInteger sum=BigInteger.ONE;
		
		for(int i=1;i<=k;i++)
		{
			sum=sum.multiply(new BigInteger(""+(n-i+1)));
			sum=sum.divide(new BigInteger(""+i));
		}
		return sum;
	}
    public static void main(String[] args) {
        int t;
        Scanner s=new Scanner(System.in);
        int n,k;
        t=s.nextInt();
        while(t-->0)
        {
        	n=(s.nextInt());
        	k=(s.nextInt());
        	System.out.println(combinations(n-1,k-1));
	}
    }
}
