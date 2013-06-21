#include<stdio.h>
inline void readInt(int *a)
{
		int sign=1; 
	 register char c=0;
	 while (c<33) c=getchar_unlocked();
	 *a=0;
	 while (c>33)
	 {
	 	if(c=='-')
	 	sign=-1;
	 	else
	    *a=*a*10+c-'0';
	     c=getchar_unlocked();
	 }
	 *a=sign*(*a);
}
int main()
{
     int n,k,i,j,max;
        readInt(&n);
        int arr[n];
        for(i=0;i<n;i++)        
        {
                readInt(&arr[i]);
        }
        readInt(&k);
        max=arr[0];
        for(i=0;;i++)        
        {
                if(i==0 || max==arr[i-1])
                {
		            max=arr[i];
		            for(j=i;j<i+k;j++)                        
		            {	if(arr[j]>max)
		                    max=arr[j];
		            }
                }
                else{
                        if(arr[i+k-1]>max)
                        max=arr[i+k-1];
                }
               
                printf("%d ",max);
                if(i+k>=n){
                        break;
                }
        }
        return 0;
}
