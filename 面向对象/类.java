//���г�Ա���������������࣬�����ڶѣ�������ڳ�Ա��������
//�ֲ���������������������������У�������ջ
//ӵ��������������������Զ������У������ڱ����д����������
class Car{
	private String color = "red";
	int num = 4;//��Ա����,��дĬ��public
	private String name;
	Car(){
		this.name = "С��";//this�������־ֲ������ͳ�Ա������this��ʾ��ǰ������
		this.num =10; 
	}//���캯��������������������Ӧ�Ĺ��캯��
	Car(int num){
		this.num = num;
	}
	Car(int num,String color){
		this.num = num;
		this.color = color;
	}
	{//�������飬һ���������У����ڹ��캯��, ��������������Ч
		this.name = "С��";
		
	}
	
	void print(){
		System.out.println(color+" "+num + name);
	}
	
}
class Main{
	public static void main(String[] args){
		Car A = new Car();//new Car()��ʾ�����乹�캯������û�й��캯������ôϵͳ��Ĭ�ϸ��������ղ����Ĺ��캯��
		//�������ϵͳ�����ᶨ����ع��캯�� ,���Բ������޲ι��캯��ʱ�����޲ι��캯���ᱨ�����캯����������
		//���캯��ֻ���ڶ�����ʱ����һ��
		A.print();
		Car B = new Car(32);
		B.print();
		//B.num = 7;
		//B.Car();//�޷����ã���ʾ�Ҳ����ú���
		//B.print();
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