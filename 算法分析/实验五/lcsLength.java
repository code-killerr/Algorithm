/**
author:CodeKiller
����X[],Y[]�ҵ�����������У���˳����е���ͬԪ�ص�����{A B C B D A B}��{B D C A B A}��{B C A}Ϊ����һ��������
˼·:�����ȶԣ���XΪ��׼�ȶ�Y����ȵ����������������һ�����ֵıȶԣ��ȶ���ɺ�����ǰ���г��ڼ�¼�������¼
ʹ��len����¼�����г��ȣ�road����¼����

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
