/**
author:code-killer
������1.ʹ��Ͱ����
	  2.ʹ�ÿ�������
Ͱ����˼·:��Ѱ������������������������ֵ�������ʼ��Ϊ0��
			�������ֵ���������жϣ����Ϊ�����о���ֵ�����±���ڸ�ֵ������+1�����Ϊ��+2��
			�������ʱ������ֵ��һ���ٴ���ȼ�һ��
			��һ������������ֵΪ1��3�������±꣬�ڶ�������������ֵΪ2��3�������±�
 */
import java.lang.Math;
import java.lang.String;
import java.util.Arrays;
import java.util.Scanner;

class Sort{
	public static void bucketSort(int[] data){
		int max = data[0];
		int len = data.length;
		for(int i = 0;i < len;i++)//�ҳ�����ֵ������
			if(Math.abs(data[i]) > max)
			max = Math.abs(data[i]);
		int[] sort = new int[2*(max+1)];
		Arrays.fill(sort,0);//������0
		for(int i = 0;i < len;i++)
			if(data[i] >= 0)
				sort[max+data[i]+1] += 1;
			else//�������Ϊ�����Ĵ���ʽ
				sort[Math.abs(data[i])] += 1;
		print(sort,max);
	}
	public static void print(int[] sort,int max)
	{
		int len = sort.length;
		for(int i = max;i >= 0;i--)//�������
			for(int j = 0;j < sort[i];j++)
				System.out.print("-"+i + " ");		
		for(int i = max+1;i <len;i++)//�������
			for(int j = 0;j < sort[i];j++)
				System.out.print(i-(max+1) + " ");
	}
	public static void main(String[] args){
		Scanner cin = new Scanner(System.in);
		int len;//����
		len = cin.nextInt();
		int[] number = new int[len];
		for(int i = 0;i <len ;i++)
			number[i] = cin.nextInt();
		bucketSort(number);
	}
}