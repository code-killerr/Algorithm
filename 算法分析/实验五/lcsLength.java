/**
author:CodeKiller
输入X[],Y[]找到最长公共子序列，按顺序具有的相同元素的序列{A B C B D A B}与{B D C A B A}中{B C A}为其中一个子序列
思路:动态规划查找最优解，规划出数据地图map[xlen][ylen],和路径图road[xlen][ylen]
数据图填充时对比x[i]和y[i]的值，如果相等取斜上方数值+1记录方向放入road如不等找寻上方和左边
最大值取出数值放入map[i][j]记录方向放入road,输出从road[i][j]开始记录从开始输出即为最长公共子序列
所有方向最终目的指向最优解在road上任意起点都会指向可以路过的最优解
斜上方记1上方记2左边记3
*/
import java.util.*;
class LcsLength{
	private static void lcsLength(char []x,char []y){
		int xLen = x.length;
		int yLen = y.length;
		int sign = 0;
		int[][] map = new int[xLen + 1][yLen + 1];
		int[][] road = new int[xLen][yLen];
		for(int i = 0;i < xLen;i++)
			for(int j = 0;j < yLen;j++){
				if(x[i] == y[j]){//如果相等取斜上方数值+1
					map[i + 1][j + 1] = map[i][j] + 1;
					road[i][j] = 1;//记取斜上方值
				}
				else if(map[i][j + 1] > map[i + 1][j])//比对上方和左边的值
				{//如果上方值大
					map[i + 1][j + 1] = map[i][j + 1];
					road[i][j] = 2;
				}
				else //左边值大
				{
					map[i + 1][j + 1] = map[i + 1][j];
					road[i][j] = 3;
				}
			}
			System.out.print("长度为:"+map[xLen][yLen]+"\n"+"子序列为:");
			print(xLen - 1,yLen - 1,x,road);
	}
	public static void print(int i,int j,char x[],int road[][]){
		if(i < 0 || j < 0)
			return;
		if(road[i][j] == 1){
			print(i - 1,j - 1,x,road);
			System.out.print(x[i]);
		}
		else if(road[i][j] == 2)print(i - 1,j,x,road);
		else print(i,j - 1,x,road);
	}
	public static char[] scanf(){
		Scanner scan = new Scanner(System.in);
		String str = scan.next();
		char []data = str.toCharArray();
		return data;
	}
	public static void main(String args[]){
		char[] list1 = scanf();
		char[] list2 = scanf();
		lcsLength(list1,list2);
	}
}
