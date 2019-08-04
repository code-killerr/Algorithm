class A{
	{
		System.out.println("a1");//比构造函数早调用
	}
	A(){
		System.out.println("a2");
	}
	static
	{
		System.out.println("a3");//静态代码块第一次new时执行，以后不执行，优先级最高
	}
}
class B extends A{
	{
		System.out.println("b1");//先调用构造代码块然后调用构造函数
	}
	B(){
		System.out.println("b2");
	}
	static
	{
		System.out.println("b3");//加载该类时先从主类加载，遍历类结构，调用static
	}
}
class gouzao{
	public static void main(String agrs[]){
		A c;//此时三个函数都不调用
		c = new B();//输出a3,b3,a1,a2,b1,b2,和C类型无关
		c = new A();//输出a1,a2
		A d = new A();//静态代码块只有第一次时出现剩下时间new新对象不会出现
		B e;
		e = new B();//调用父类构造代码块和父类构造函数，再调用自己
		
	}
}