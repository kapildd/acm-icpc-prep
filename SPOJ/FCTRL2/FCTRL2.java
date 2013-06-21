import java.util.*;
class FCTRL2
{
	public static void main(String args[])
	{
		int t,n,i;
		HashMap hm=new HashMap();
                hm.put(0, "1");
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
                        String tmp=hm.get(i).toString();
                        i++;
                        while(i<=n)
                        {
                            tmp=multiply(tmp,new Integer(i).toString());
                            hm.put(i,tmp);
                            i++;
                        }
                        System.out.println(tmp);
                        
		}
	}
        static String multiply(String a,String b)
        {
            StringBuffer c=new StringBuffer();
            for(int i=0;i<a.length()+b.length();i++)
            {
                c.append("0");
            }
            int res=0,carry=0,i,j;
            String results[][]=new String[a.length()][b.length()];
            for(j=0;j<b.length();j++)
            {
                for(i=0;i<a.length();i++)
                {

                        results[i][j]=new Integer((a.charAt(i)-48)*(b.charAt(j)-48)).toString();
                        while(results[i][j].length()<=1)
                        {
                            results[i][j]="0"+results[i][j];
                        }
                }
            }
            for(i=0;i<a.length();i++)
            {
                for(j=0;j<b.length();j++)
                {
                    for(int k=0;k<2;k++)
                    {
                        carry=0;
                        int z=i+j+k;
                        int l=(c.charAt(z)-48);
                        c.setCharAt(z,(char)((((results[i][j].charAt(k)-48)+l)%10)+48));
                        carry=(((results[i][j].charAt(k)-48)+l)/10);
                        while(carry>0)
                        {
                            z--;
                            l=(c.charAt(z)-48);
                            c.setCharAt(z,(char)(((l+carry)%10)+48));
                            carry=((l+carry)/10);
                        }
                    }
                }
            }
            i=0;
            String tmp=c.toString();
            while(i<tmp.length())
			{
				if(tmp.charAt(i)!='0')
					break;
				else
					tmp=tmp.substring(1, tmp.length());
			}
            return tmp;
        }
}
