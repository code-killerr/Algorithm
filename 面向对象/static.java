//staticһ�����ڹ������ݵĴ洢��ʡ�ڴ�ռ�,һ�����ڱ�������,���˱�������û����Ա���������
//��p.XX����,��̬����ֻ�ܵ��þ�̬��Ա���Ǿ�̬�������Ե��þ�̬��Ա�ͷǾ�̬��Ա�����������
//��̬��Ա�������ڹ�����ͬʱ���о�����
//�౻ж��ʱ����̬���������٣����ͷ��ڴ�ռ䡣static��������������ȡ���������������
//��̬�����洢�ڷ�����/������/������
class A{
	String name;
	static String sta = "aaa";
	void print(){
		System.out.println(name + "->" + sta);
	}
	static void prints(){
		//System.out.println(name + "->" + sta);�ᱨ���޷����÷Ǿ�̬��Աname
		System.out.println("sta="+sta);
	}
	
}
class Smain{
public static void main(String args[]){
	A aa = new A();
	aa.print();
	System.out.println(A.sta);//������侲̬��Ա
	aa.sta = "bbb";//һ�����ľ�̬��Ա�����Ժ����ɵĶ���þ�̬��Ա��Ϊ�ı���ֵ
	A bb = new A();
	bb.print();
}
}