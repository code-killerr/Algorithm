/**
��Ŀ:01�������⣬�Ӹ�����n����С������������ѡ������m�����ı���ʹ���ֵ���
author:CodeKiller
˼·:�󵥲������ٵ���������״̬ת�Ʒ���m[i][j] = m[i - 1][j-w[i]] + v[i]��
��ǰһ����״̬����Ŀǰ״̬���бȶԴﵽ��̬�滮��Ч��
����:1.���������������,���б�����ά���鴴��,���ܲ���:
������С����Ʒ�������飬��Ʒ��ֵ����,�������ļ�ֵ
2.�����жϺ��������б��Ƿ���뱳��,���ܲ�����
������ά���飬��Ʒ�������飬��Ʒ��ֵ���飬��ǰ����λ�ã��������飬�޷���ֵ��ֱ�ӽ����ݷ�������
3.���������������
4.����������
�����򻯷������������鶨Ϊȫ��--���ޣ��޷�������Ʒ�������屳��
**/
import java.util.Scanner;
class Backpack{
	static int[][] goods = new int[100][2];//��һ���������ڶ����Ǽ�ֵ
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
			System.out.println("������������");
		else System.out.println("����ֵΪ:"+backpack());
		
	}
}