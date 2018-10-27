class memoizedmatrixChain{
	static int[][] m = new int[7][7];
	static int[][] s = new int[7][7];
	static int[] p = new int[]{30,35,15,5,10,20,25};
	public static int memoizedmatrixChain(int n){
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
				m[i][j] = 0;
		return lookupChain(1,n);
	}
	
	private static int lookupChain(int i,int j)
	{
	if(m[i][j] > 0)return m[i][j];
	if(i == j)return 0;
	int u = lookupChain(i+1,j) + p[i - 1]*p[i]*p[j];
	s[i][j] = i;
	for(int k = i+1;k < j;k++){
		int t = lookupChain(i,k) + lookupChain(k+1,j) + p[i - 1]*p[k]*p[j];
		if(t < u){
			u = t;
			s[i][j] = k;
		}
	}
	m[i][j] = u;
	return u;
	}
	
	public static void main(String[] args){
		System.out.println(memoizedmatrixChain(6));
		for(int i = 1;i < 7;i++){
			for(int j = 1;j < 7;j++)
				System.out.print(m[i][j]+" ");
			System.out.println("\n");
		}
		System.out.println("-----------------------------------------------");
		for(int i = 1;i < 7;i++){
			for(int j = 1;j < 7;j++)
				System.out.print(s[i][j]+" ");
			System.out.println("\n");
		}
	}
}