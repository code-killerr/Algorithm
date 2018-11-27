//static一般用于公共数据的存储节省内存空间,一般用于被对象共享,除了被对象调用还可以被类名调用
//用p.XX调用
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
	System.out.println(A.sta);//类调用其静态成员
	aa.sta = "bbb";//一旦更改静态成员该类以后生成的对象该静态成员皆为改变后的值
	A bb = new A();
	bb.print();
}
}