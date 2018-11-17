//类中成员变量作用于整个类，储存于堆，对象存在成员变量存在
//局部变量作用于整个函数或者语句中，储存于栈
//拥有主函数的类代表该类可以独立运行，可以在本类中创建本类对象
class Car{
	private String color = "red";
	int num = 4;//成员变量,不写默认public
	private String name;
	Car(){
		this.name = "小白";//this用来区分局部变量和成员变量，this表示当前对象名
		this.num =10; 
	}//构造函数，当对象建立会调用相对应的构造函数
	Car(int num){
		this.num = num;
	}
	Car(int num,String color){
		this.num = num;
		this.color = color;
	}
	{//构造代码块，一建立就运行，先于构造函数, 对于所有属性有效
		this.name = "小黑";
		
	}
	
	void print(){
		System.out.println(color+" "+num + name);
	}
	
}
class Main{
	public static void main(String[] args){
		Car A = new Car();//new Car()表示调用其构造函数，当没有构造函数，那么系统会默认给该类加入空参数的构造函数
		//当定义后系统将不会定义相关构造函数 ,所以不存在无参构造函数时调用无参构造函数会报错，构造函数可以重载
		//构造函数只有在对象建立时调用一次
		A.print();
		Car B = new Car(32);
		B.print();
		//B.num = 7;
		//B.Car();//无法调用，显示找不到该函数
		//B.print();
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