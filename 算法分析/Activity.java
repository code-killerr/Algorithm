 class demo7 {
	public static int INF = 999999;
	public static void dijkstra(int s,int mp[][]) {
		int qu[] = new int[mp.length];
		int fa[]=new int [mp.length];
		boolean f[]=new boolean[mp.length];
		for(int i=1;i<qu.length;i++) {
			qu[i]=mp[s][i];
			fa[i]=s;
			f[i]=false;
		}
		f[s]=true;qu[s]=0;
		for(int i=1;i<qu.length-1;i++) {
			int min=INF,index=0;
			for(int j=1;j<qu.length;j++) {
				if(f[j]) continue;
				if(qu[j]<min) {
					min=qu[j];index=j;
				}
			}
			f[index]=true;
			for(int j=1;j<qu.length;j++) {
				if(f[j]) continue;
				if(qu[j]>qu[index]+mp[index][j]) {
					qu[j]=qu[index]+mp[index][j];
					fa[j]=index;
				}
			}
		}
		System.out.println(s+" the distance to this point:");
		for(int i=1;i<=5;i++)
			System.out.print(qu[i]+" ");
		System.out.println();
		System.out.println("the point over this point:");
		for(int i=1;i<=5;i++)
			System.out.print(fa[i]+" ");
	}






	public static void main(String args[]){
		int mp[][] = new int[6][6];
		for(int i=1;i<=5;i++)
			for(int j=1;j<=5;j++)
				mp[i][j]=INF;
		mp[1][2]=10;mp[1][5]=100;mp[1][4]=30;
		mp[2][3]=50;mp[3][5]=10;mp[4][3]=20;mp[4][5]=60;
		dijkstra(1,mp);
	}
}