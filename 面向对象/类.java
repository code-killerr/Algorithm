//类中成员变量作用于整个类，储存于堆，对象存在成员变量存在
//局部变量作用于整个函数或者语句中，储存于栈
//拥有主函数的类代表该类可以独立运行，可以在本类中创建本类对象
class Car{
	private String color = "red";
	int num = 4;//成员变量,不写默认public
	void print(){
		System.out.println(color+" "+num);
	}
	
}
class Main{
	public static void main(String[] args){
		Car A = new Car();
		A.print();
		//A.color = "blue";//私有变量不可访问
		A.num = 5;//公有可以
		A.print();
		new Car().num = 6;//匿名对象
		new Car().print();//调用属性无意义，主要用来调用方法，匿名对象更换属性更换属性的对象无法调用所以无意义
	//当方法只调用一次时可以使用匿名对象,也可以当其为方法的参数传入
		show(new Car());
	}
	private static void show(Car B){
		B.num = 10;
		B.print();
	}
}