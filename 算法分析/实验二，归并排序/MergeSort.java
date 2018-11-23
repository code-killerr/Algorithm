/**
author:CodeKiller
��Ŀ:�ϲ�����
˼·:1.�����������𿪷��飬ֱ���޷��ֿ�
      2.�����ķ������������Ϊ�����ֺ������ʽ
	  3.�ٽ��ֺõ�������,left i i+1 right  
		(1)��һ������data[left]>data[right] ����ż����
		(2)�ڶ����������������data[left] < data[right]&&data[mid+1] < data[mid]  ������������ϲ�
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
		int len;//����
		len = cin.nextInt();
		int[] number = new int[len];
		for(int i = 0;i <len ;i++)
			number[i] = cin.nextInt();
		mergeSort(number,0,len-1);
		for(int i = 0;i <len ;i++)
			System.out.print(number[i]+" ");
	}
}