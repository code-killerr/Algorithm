//staticһ�����ڹ������ݵĴ洢��ʡ�ڴ�ռ�,һ�����ڱ�������,���˱�������û����Ա���������
//��p.XX����
class A{
	String name;
	static String sta = "aaa";
	void print(){
		System.out.println(name + "->" + sta);
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