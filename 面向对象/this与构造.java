class A{
	private int num1;
	private int num2;
	A(int a){
		this.num1 = a;
	}
	A(int a,int b){
		this(a);//this���ڹ��캯����ĵ��ã������ڹ��캯����һ��,��ֹ���Ĵ����ֵ
		this.num2 = b;
	}
	void print(){
		System.out.println(num);
	}
	public static void main(String args[]){
		A b = new A();
	}
}
class B{
	private int num;
	B(){
		this.num = 5;
	}
	B(int a){
		this();//this���ڹ��캯����ĵ��ã������ڹ��캯����һ��,��ֹ���Ĵ����ֵ
		this.num = a;
	}
	void print(){
		System.out.println(num);
	}
}