/**
author:code-killer
方法：1.使用桶排序
	  2.使用快速排序
桶排序思路:找寻其中最大数，创建包含最大数值的数组初始化为0，
			将输入的值进行正负判断，如果为负进行绝对值处理将下标等于该值的数组+1如果不为负+2，
			出现相等时将数组值置一，再次相等加一，
			第一遍遍历倒序输出值为1和3的数组下标，第二次正序遍历输出值为2和3的数组下标
 */
import java.lang.Math;
import java.lang.String;
import java.util.Arrays;
import java.util.Scanner;

class Sort{
	public static void bucketSort(int[] data){
		int max = data[0];
		int len = data.length;
		for(int i = 0;i < len;i++)//找出绝对值最大的数
			if(Math.abs(data[i]) > max)
			max = Math.abs(data[i]);
		int[] sort = new int[2*(max+1)];
		Arrays.fill(sort,0);//数组置0
		for(int i = 0;i < len;i++)
			if(data[i] >= 0)
				sort[max+data[i]+1] += 1;
			else//如果数据为负数的处理方式
				sort[Math.abs(data[i])] += 1;
		print(sort,max);
	}
	public static void print(int[] sort,int max)
	{
		int len = sort.length;
		for(int i = max;i >= 0;i--)//负数输出
			for(int j = 0;j < sort[i];j++)
				System.out.print("-"+i + " ");		
		for(int i = max+1;i <len;i++)//正数输出
			for(int j = 0;j < sort[i];j++)
				System.out.print(i-(max+1) + " ");
	}
	public static void main(String[] args){
		Scanner cin = new Scanner(System.in);
		int len;//输入
		len = cin.nextInt();
		int[] number = new int[len];
		for(int i = 0;i <len ;i++)
			number[i] = cin.nextInt();
		bucketSort(number);
	}
}