/**
author:CodeKiller
题目:合并排序
思路:1.将数组两两拆开分组，直到无法分开
      2.将最后的分组排序，数组变为两两分好组的形式
	  3.再将分好的组排序,left i i+1 right  
		(1)第一种输入data[left]>data[right] 分奇偶排序
		(2)第二种输入混合其它情况data[left] < data[right]&&data[mid+1] < data[mid]  遍历方法插入合并
*/
import java.util.Scanner;
class MergeSort{
	public static void mergeSort(int data[],int left,int right){
		int sum = left+right;
		int mid = sum/2;
		int mod = mid + sum % 2;
		if(left == right)
			return;
		if(left < right){
			mergeSort(data,mid+1,right);
			mergeSort(data,left,mid);
		}
		if(data[left] > data[right]){
			int temp = 0;
			if(sum%2 == 1)
				for(int i = 0;i < mid-left+1;i++){
					temp = data[left+i];
					data[left + i] = data[mod+i];
					data[mod + i] = temp;
				}
			else{
					for(int i = 0;i < mid - left;i++){
						temp = data[left+i];
						data[left + i] = data[mid + 1 + i];
						data[mid + 1 + i]  = temp;
					}
					temp = data[mid];
					for(int i = mid ; i < right ;i++)
						data[i] = data[i+1];
					data[right] = temp;
				}
		}
		else if(data[mid] > data[mid + 1]){
			int flag = 0,temp = 0;
			for(int j = 0;j < mid-left+1 ;j++){
				for(flag = left;flag < mod + j;flag++)
					if(data[flag] > data[mod + j]){
						temp = data[mod + j];
						for(int i = mod + j;i > flag;i--)
							if(i-1 >= 0)
								data[i] = data[i-1];
						data[flag] = temp;
					}
			}
		}
	}
	public static void main(String[] args){
		Scanner cin = new Scanner(System.in);
		int len;//输入
		len = cin.nextInt();
		int[] number = new int[len];
		for(int i = 0;i <len ;i++)
			number[i] = cin.nextInt();
		mergeSort(number,0,len-1);
		for(int i = 0;i <len ;i++)
			System.out.print(number[i]+" ");
	}
}