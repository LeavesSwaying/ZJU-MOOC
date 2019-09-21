import java.util.*;
public class MaximumSubsequenceSum2{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int num=sc.nextInt();
		int[] ar=new int[num];
		int[] dp=new int[num];
		int[] pr=new int[num];
		boolean flag=false;
		for(int i=0;i<num;++i)
		{
			ar[i]=sc.nextInt();
			if(ar[i]>=0) flag=true;
		}
		sc.close();
		if(flag==false){
            System.out.printf("0 %d %d\n",ar[0],ar[num-1]);
            return;
        } 
		dp[0]=ar[0];
		for(int i=1;i<num;++i)
			if(dp[i-1]+ar[i]>ar[i]){
				dp[i]=ar[i]+dp[i-1];
                pr[i]=pr[i-1];
            }
			else{
				dp[i]=ar[i];
				pr[i]=i;
			}			
		int f=0;
		for(int i=1;i<num;++i)
		{
			if(dp[f]<dp[i]){
				f=i;
			} 
		}
		System.out.printf("%d %d %d\n",dp[f],ar[pr[f]],ar[f]);
	}
}
