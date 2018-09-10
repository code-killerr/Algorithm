import java.util.*;
public class Search_F1 {
	
	
	
	public static void Swap(int num[],int index1,int index2)
	{
		int a = num[index1];
		num[index1] = num[index2];
		num[index2] = a;
	}
	
	
	
	public static void ChooseSort(int num[])
	{
		for(int i = 0;i<num.length;i++){
			for(int j = i ; j < num.length ; j++){
				if(num[i]>num[j]){
					Swap(num,i,j);
				}
			}
		}
	}
	
	
	
	
	public static void PopSort(int num[])
	{
		for(int i = 1 ; i < num.length ; i++)
		{
			for(int j = 0 ; j < num.length-i ; j++)
			{
				if(num[j]>num[j+1])
					Swap(num,j,j+1);
			}
		}
	}
	
	
	
	public static int Search(int num[],int key)
	{
		int left = 0 , right = num.length , mid = 0;
		while(left < right)
		{
			mid = (left+right)/2;
			if(key == num[mid])
				return mid;
			if(key < num[mid])
			{
				right = mid;
			}
			else{
				left = mid;
			}
			
		}
		return -1;
	}
	public static void Show(int num[])
	{
		for(int i = 0 ; i < num.length ; i++)
		{
			System.out.print(num[i]+" ");
		}
		System.out.println();
	}
	
	
	
	
	public static void main(String args[]){
		int[] Data = {34,534,23,123,543,21,2,3,4,64364,5,43,23};
		System.out.println("排序前");
		Show(Data);
		System.out.println("冒泡排序后");
		PopSort(Data);
		Show(Data);
		int[] Data2 = {213,231,23,4,121,223,4,55,12,13,312,34,23};
		System.out.println("排序前");
		Show(Data2);
		System.out.println("选择排序后");
		ChooseSort(Data2);
		Show(Data2);
		System.out.println("查找数字223");
		int flag = Search(Data2 , 223);
		System.out.println("数字位置为:"+flag);
	}

}
