class A{
	{
		System.out.println("a1");//�ȹ��캯�������
	}
	A(){
		System.out.println("a2");
	}
	static
	{
		System.out.println("a3");//��̬������һ��newʱִ�У��Ժ�ִ�У����ȼ����
	}
}
class B extends A{
	{
		System.out.println("b1");//�ȵ��ù�������Ȼ����ù��캯��
	}
	B(){
		System.out.println("b2");
	}
	static
	{
		System.out.println("b3");//���ظ���ʱ�ȴ�������أ�������ṹ������static
	}
}
class gouzao{
	public static void main(String agrs[]){
		A c;//��ʱ����������������
		c = new B();//���a3,b3,a1,a2,b1,b2,��C�����޹�
		c = new A();//���a1,a2
		A d = new A();//��̬�����ֻ�е�һ��ʱ����ʣ��ʱ��new�¶��󲻻����
		B e;
		e = new B();//���ø��๹������͸��๹�캯�����ٵ����Լ�
		
	}
}