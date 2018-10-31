/**
题目:输入两组超过50位小于一千位的整数计算出差
author:CodeKiller
思路:检测输入数据的长度创建数组，二者相减从尾减到头，遇到负数向前借一，判断如果前面没有元素取负
输入：正数正数，正数负数，负数正数，负数负数,正数被减数小于正数减数，负数被减数绝对值小于减数,位数不一致
在new数组时候应以0位为符号位1位为进位
*/
import java.util.Scanner;
class BigNumberSub{
	//减法，只接受被减数大于减数
	private static int[] sub(int minuend[],int subtrahend[]){
		int mLen = minuend.length;
		int sLen = subtrahend.length;
		for(int i = mLen - 1,j = sLen - 1;i >= 2&&j >= 2;i--,j--)
		{
			minuend[i] = minuend[i] - subtrahend[j];
			while(minuend[i]<0)
				{
					minuend[i] += 10;
					minuend[i-1] -= 1;
				}
		}
		return minuend;
	}
	private static int[] add(int summand[],int addend[]){
		int sLen = summand.length;
		int aLen = addend.length;
		if(sLen > aLen){
			for(int i = sLen - 1,j = aLen - 1;i >= 2&&j >= 2;i--,j--)
			{
				summand[i] = summand[i] + addend[j];
				while(summand[i]>=10&&i-1>=0)
					{
						summand[i] -= 10;
						summand[i-1] += 1;
					}
			}
			return summand;
		}
		else{
			for(int i = aLen - 1,j = sLen - 1;i >= 2&&j >= 2;i--,j--)
			{
				addend[i] = summand[j] + addend[i];
				while(addend[i]>=10)
					{
						if(j-1>=0){
							addend[i] -= 10;
							addend[i-1] += 1;
						}
					}
			}
			return addend;
		}
	}
	private static int[] scanf(){
		Scanner cin = new Scanner(System.in);
            String data = cin.next();
			int[] num = new int[data.length() + 2];
			if(data.charAt(0) == '-'){//String不可变
				num[0] = 1;
			}
		for(int i = data.length()-1,j = num.length-1;i >=0;i--,j--)
			if(data.charAt(i)>='0'&&data.charAt(i)<='9')
				num[j] = (data.charAt(i) - '0');
		return num;
	}
	public static void print(int[] data){
		boolean flag = false;
		for(int i = 1;i < data.length;i++){
			if(data[i] !=0&&flag == false)
				flag = true;
			if(flag)
			System.out.print(data[i]);
		}
	}
	public static void main(String args[]){
		int[] num1 = scanf();
		int[] num2 = scanf();
		if(num1[0] == 0&&num2[0] == 0){
			if(num1.length < num2.length){
				System.out.print('-');
				print(sub(num2,num1));
				}
			else if(num1.length == num2.length)
			{
				int i =2;
				while(i<num1.length&&num1[i] == num2[i])
					i++;
				if(num1[i] < num2[i]){
					System.out.print('-');
					print(sub(num2,num1));
				}
				else
					print(sub(num1,num2));
			}
			else
				System.out.println(sub(num1,num2));
		}
		else if(num1[0] == 0&&num2[0] == 1)
			print(add(num1,num2));
		else if(num1[0] == 1&&num2[0] == 0){
			System.out.print("-");
			print(add(num1,num2));
		}
		else if(num1[0] == 1&&num2[0] == 1)
			if(num1.length < num2.length)
				print(sub(num2,num1));
			else if(num1.length == num2.length)
			{
				int i =2;
				while(i<num1.length&&num1[i] == num2[i])
					i++;
				if(num1[i] <num2[i])
					print(sub(num2,num1));
				else{
					System.out.print('-');
					print(sub(num1,num2));
				}
			}
			else{
				System.out.print('-');
				print(sub(num1,num2));
			}
	}
}