/**
题目:01背包问题，从给出的n个大小重量的物体中选出放入m容量的背包使其价值最大
author:CodeKiller
思路:求单步最优再到整体最优状态转移方程m[i][j] = m[i - 1][j-w[i]] + v[i]，
用前一个的状态加上目前状态进行比对达到动态规划的效果
步骤:1.创建解决方案函数,进行背包二维数组创建,接受参数:
背包大小，物品质量数组，物品价值数组,返回最大的价值
2.创建判断函数用来判别是否加入背包,接受参数：
背包二维数组，物品质量数组，物品价值数组，当前所在位置，背包数组，无返回值，直接将数据放入数组
3.创建输入输出函数
4.创建主函数
参数简化方案，背包数组定为全局--局限：无法根据物品数量定义背包
**/
import java.util.Scanner;
class Backpack{
	static int[][] goods = new int[100][2];//第一个是重量第二个是价值
	static int goodsNum = 0;
	static int packContent = 0;
	
	public static int backpack(){
		int[][] backpack = new int[goodsNum][packContent+1];
		for(int j = 1;j <= packContent;j++)
			for(int i = 0;i < goodsNum;i++){
				if(i == 0)
					if(j > goods[i][0])backpack[i][j] = goods[i][1];
					else backpack[i][j] = 0;
				else calculate(j,i,backpack);
			}
		return backpack[goodsNum-1][packContent];
		
	}
	public static void calculate(int j,int i,int[][] pack){
		if(goods[i][0] > j) pack[i][j] = pack[i-1][j];
		else if((pack[i][j] = pack[i - 1][j - goods[i][0]] + goods[i][1]) < pack[i - 1][j])
			pack[i][j] = pack[i - 1][j];
	}
	public static int scan(){
		Scanner cin = new Scanner(System.in);
		int num = 0;
		if((num = cin.nextInt())>0)
			goodsNum = num;
		else return 0;
		num = 0;
		if((num = cin.nextInt())>0)
			packContent = num;
		else return 0;
		for(int i = 0;i < goodsNum;i++){
			
			if((goods[i][0] = cin.nextInt()) < 0)
				return 0;
			goods[i][1] = cin.nextInt();
		}
		return 1;
	}
	public static void main(String args[]){
		if(scan() == 0)
			System.out.println("输入数据有误");
		else System.out.println("最大价值为:"+backpack());
		
	}
}