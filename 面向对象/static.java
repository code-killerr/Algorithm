//static一般用于公共数据的存储节省内存空间,一般用于被对象共享,除了被对象调用还可以被类名调用
//用p.XX调用,静态函数只能调用静态成员，非静态函数可以调用静态成员和非静态成员，属于类变量
//静态成员生命周期过长，同时具有局限性
//类被卸载时，静态变量被销毁，并释放内存空间。static变量的生命周期取决于类的生命周期
//静态变量存储于方法区/共享区/数据区
class A{
	String name;
	static String sta = "aaa";
	void print(){
		System.out.println(name + "->" + sta);
	}
	static void prints(){
		//System.out.println(name + "->" + sta);会报错无法调用非静态成员name
		System.out.println("sta="+sta);
	}
	
}
class Smain{
public static void main(String args[]){
	A aa = new A();
	aa.print();
	System.out.println(A.sta);//类调用其静态成员
	aa.sta = "bbb";//一旦更改静态成员该类以后生成的对象该静态成员皆为改变后的值
	A bb = new A();
	bb.print();
}
}