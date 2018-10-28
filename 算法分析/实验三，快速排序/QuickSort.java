/**
author:CodeKiller
  ��Ŀ����������
  ˼·:ȡ��ǰ�����е�һ������Ϊ��׼���ȴ��ұ߿�ʼ������Ϊ��Ƕ�,��������һ���Ȼ�׼��С����ʱ��ֹ
		�ٴ���߿�ʼ������Ϊ���һ����������һ���Ȼ�׼�������ʱ��ֹ���������һ�ͱ�Ƕ�����Ƕ�����
		ǰ���ظ��������裬ֱ������������ֹ���������������͵�һ������ֵ,��������Ϊ��Ͽ���ʣ������
		�����ظ�����������ֱ��left <= rightʱ��������
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
		int len;//����
		len = cin.nextInt();
		int[] number = new int[len];
		for(int i = 0;i <len ;i++)
			number[i] = cin.nextInt();
		quickSort(number,0,len-1);
		for(int i = 0;i <len ;i++)
			System.out.print(number[i]+" ");
	}
}