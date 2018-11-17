class A{
	private int num1;
	private int num2;
	A(int a){
		this.num1 = a;
	}
	A(int a,int b){
		this(a);//this用于构造函数间的调用，必须在构造函数第一行,防止更改传入的值
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
		this();//this用于构造函数间的调用，必须在构造函数第一行,防止更改传入的值
		this.num = a;
	}
	void print(){
		System.out.println(num);
	}
}