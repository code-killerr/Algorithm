//���г�Ա���������������࣬�����ڶѣ�������ڳ�Ա��������
//�ֲ���������������������������У�������ջ
//ӵ��������������������Զ������У������ڱ����д����������
class Car{
	private String color = "red";
	int num = 4;//��Ա����,��дĬ��public
	void print(){
		System.out.println(color+" "+num);
	}
	
}
class Main{
	public static void main(String[] args){
		Car A = new Car();
		A.print();
		//A.color = "blue";//˽�б������ɷ���
		A.num = 5;//���п���
		A.print();
		new Car().num = 6;//��������
		new Car().print();//�������������壬��Ҫ�������÷�������������������Ը������ԵĶ����޷���������������
	//������ֻ����һ��ʱ����ʹ����������,Ҳ���Ե���Ϊ�����Ĳ�������
		show(new Car());
	}
	private static void show(Car B){
		B.num = 10;
		B.print();
	}
}