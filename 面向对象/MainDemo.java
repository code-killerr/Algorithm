class MainDemo{
	public static main(string abb[]){
		//args���Ը��ģ���Ϊ����
		System.out.println(abb);
		System.out.println(abb.length)//���Ը����������Σ�����ʱ�����ν�Ĭ��Ϊ��
		String[] args ={"aaa","bbb"};
		MainDemo1.main(args);//���Ե�������������������д���
	}
	public static main(string args[],int a){
		//���������Խ�������
	}
}
class MainDemo1{
	public static main(string args[]){
		for(int i;i<args.length;i++)
			System.out.println(args[i]);
	}
}