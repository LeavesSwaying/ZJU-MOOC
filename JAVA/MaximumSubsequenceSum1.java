import java.util.*;
public class MaximumSubsequenceSum1{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int num=sc.nextInt();
		int[] ar=new int[num+1];
		int[] dp=new int[num+1];
		for(int i=0;i<=num;++i)
		{
			dp[i]=0;
			if(i!=0) ar[i]=sc.nextInt();
		}
		sc.close();
		for(int i=1;i<=num;++i)
			if(dp[i-1]+ar[i]<ar[i])
				dp[i]=ar[i];
			else
				dp[i]=ar[i]+dp[i-1];
		int ans=-1;
		for(int i=1;i<=num;++i)
		{
			if(ans<dp[i]) ans=dp[i];
		}	
		System.out.printf("%d",ans);
	}
}
