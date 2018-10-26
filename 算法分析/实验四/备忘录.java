class memoizedmatrixChain{
	int[] p = new int[7];
	public static int memoizedmatrixChain(int n){
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
				m[i][j] = 0;
		return lookupChain(1,n)
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
		
	}
}