/**
author:CodeKiller
输入X[],Y[]找到最长公共子序列，按顺序具有的相同元素的序列{A B C B D A B}与{B D C A B A}中{B C A}为其中一个子序列
思路:挨个比对，以X为基准比对Y中相等的数，遇到后进行下一个数字的比对，比对完成后若当前序列长于记录序列则记录
使用len来记录子序列长度，road来记录方向

*/
class LcsLength{
	public static void lcsLength(char []x,cahr []y,int [][]road){
		int xLen = x.length;
		int yLen = y.length;
		int sign = 0;
		char []len = new char[(xLen>yLen)?xLen:yLen];
		for(int i = 0;i < xLen;i++)
			for(int j = 0;j < yLen;j++){
				if(x[i] == y[j])
			}
	}
	public static void main(String args[]){
		
	}
}
