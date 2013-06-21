import java.util.*;
class LASTDIG
{
	public static void main(String args[])
	{
		int i[][]={{0},{1},{6,2,4,8},{1,3,9,7},{6,4},{5},{6},{1,7,9,3},{6,8,4,2},{1,9}};
		Scanner s=new Scanner(System.in);
		int t=s.nextInt();
		int a,b,x,y;
		while(t-->0)
		{
			a=s.nextInt();
			b=s.nextInt();
			x=a%10;
			y=b%(i[x].length);
			System.out.println(i[x][y]);
		}
		
	}
}
