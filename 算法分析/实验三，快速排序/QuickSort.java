/**
author:CodeKiller
  题目：快速排序
  思路:取当前数组中第一个数作为基准，先从右边开始遍历记为标记二,在遇到第一个比基准数小的数时终止
		再从左边开始遍历记为标记一，在遇到第一个比基准数大的数时终止，交换标记一和标记二，标记二继续
		前进重复上述步骤，直到二者相遇终止遍历交换相遇处和第一个数的值,以相遇处为点断开，剩下两边
		继续重复上述遍历，直到left <= right时结束遍历
*/
import java.util.Scanner;
public class QuickSort{
	public static void quickSort(int data[],int left,int right){
		if(left >= right) return;
		int dataTemp = data[left];
		int temp = 0;
		int sign1 = left;
		int sign2 = right;
		while(sign2 != sign1){
			while(data[sign2] >= data[left]&&sign1 < sign2)
				sign2 --;
			while(data[sign1] <= data[left]&&sign1 < sign2)
				sign1 ++;
			temp = data[sign1];
			data[sign1] = data[sign2];
			data[sign2] = temp;
		}
		
		if(sign1 == sign2){
			data[left] = data[sign1];
			data[sign1] = dataTemp;
			quickSort(data,left,sign1-1);
			quickSort(data,sign1+1,right);
		}else{
			System.out.println("ERROR");
		}
		return;
	}
	public static void main(String[] args){
		Scanner cin = new Scanner(System.in);
		int len;//输入
		len = cin.nextInt();
		int[] number = new int[len];
		for(int i = 0;i <len ;i++)
			number[i] = cin.nextInt();
		quickSort(number,0,len-1);
		for(int i = 0;i <len ;i++)
			System.out.print(number[i]+" ");
	}
}