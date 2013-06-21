import java.io.*;
class EDGE
{
	public static void main(String args[]) throws IOException
	{
		DataInputStream dis=new DataInputStream(System.in);
		String str=dis.readLine();
		while(str!=null)
		{
			int dx=1,dy=0;
			System.out.println("300 420 moveto");
			int x=310,y=420;
			System.out.println("310 420 lineto");
			for(int i=0;i<str.length();i++)
			{
				if(str.charAt(i)=='A')
				{
					if(dx==1)
					{
						dx=0;
						dy=-1;
						y-=10;
					}else if(dx==-1)
					{
						dx=0;
						dy=1;
						y+=10;
					}else if(dy==1)
					{
						dy=0;
						dx=1;
						x+=10;
					}else
					{
						dy=0;
						dx=-1;
						x-=10;
					}
				}else
				{
					if(dx==1)
					{
						dx=0;
						dy=1;
						y+=10;
					}else if(dx==-1)
					{
						dx=0;
						dy=-1;
						y-=10;
					}else if(dy==1)
					{
						dy=0;
						dx=-1;
						x-=10;
					}else
					{
						dy=0;
						dx=1;
						x+=10;
					}
				}
				System.out.println(x+" "+y+" lineto");
			}
			System.out.println("stroke\nshowpage");
			str=dis.readLine();
		} 
	}
}
