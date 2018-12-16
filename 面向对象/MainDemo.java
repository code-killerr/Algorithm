class MainDemo{
	public static main(string abb[]){
		//args可以更改，仅为命名
		System.out.println(abb);
		System.out.println(abb.length)//可以给主函数传参，调用时不传参将默认为空
		String[] args ={"aaa","bbb"};
		MainDemo1.main(args);//可以调用其它类的主函数进行传参
	}
	public static main(string args[],int a){
		//主函数可以进行重载
	}
}
class MainDemo1{
	public static main(string args[]){
		for(int i;i<args.length;i++)
			System.out.println(args[i]);
	}
}