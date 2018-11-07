/**
author:CodeKiller
����X[],Y[]�ҵ�����������У���˳����е���ͬԪ�ص�����{A B C B D A B}��{B D C A B A}��{B C A}Ϊ����һ��������
˼·:��̬�滮�������Ž⣬�滮�����ݵ�ͼmap[xlen][ylen],��·��ͼroad[xlen][ylen]
����ͼ���ʱ�Ա�x[i]��y[i]��ֵ��������ȡб�Ϸ���ֵ+1��¼�������road�粻����Ѱ�Ϸ������
���ֵȡ����ֵ����map[i][j]��¼�������road,�����road[i][j]��ʼ��¼�ӿ�ʼ�����Ϊ�����������
���з�������Ŀ��ָ�����Ž���road��������㶼��ָ�����·�������Ž�
б�Ϸ���1�Ϸ���2��߼�3
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
				if(x[i] == y[j]){//������ȡб�Ϸ���ֵ+1
					map[i + 1][j + 1] = map[i][j] + 1;
					road[i][j] = 1;//��ȡб�Ϸ�ֵ
				}
				else if(map[i][j + 1] > map[i + 1][j])//�ȶ��Ϸ�����ߵ�ֵ
				{//����Ϸ�ֵ��
					map[i + 1][j + 1] = map[i][j + 1];
					road[i][j] = 2;
				}
				else //���ֵ��
				{
					map[i + 1][j + 1] = map[i + 1][j];
					road[i][j] = 3;
				}
			}
			System.out.print("����Ϊ:"+map[xLen][yLen]+"\n"+"������Ϊ:");
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
