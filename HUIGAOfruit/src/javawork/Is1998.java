package javawork;

import java.util.Scanner;

public class Is1998 
{
	public static void main(String[] args)
	{
		Scanner numscanner=new Scanner(System.in);
		String num=numscanner.nextLine();
		//检查输入的身份证号是否有误
				if(num.length()==18)
				{
					for(int i=0;i<num.length();i++)
					{
						char x=num.charAt(i);
						if(x<'0'||x>'9')
						{
							System.out.println("身份证号输入有误!!!");
							break;
						}
					}
				}
				else
				{
					System.out.println("身份证号位数输入有误!!!");//18
				}
				
				/*1substring(a,b)*/
				/*
				switch(num.substring(6, 10))
				{
				case "1998" :
					System.out.println("此人是"+num.substring(6,10)+"年出生的");
					break;
				default:
					System.out.println("此人不是1998年出生的");
					break;
				}
				*/
				
				/*2利用字符串*/
				/*
				String str="1998";
			    char[] charArray=str.toCharArray();
				for(int i=6;i<num.length()-8;i++)
				{
					if(num.charAt(i)!=charArray[i-6])
					{
						System.out.println("此人不是1998年出生的");
						break;
					}
					else if(i==9)
					{
						System.out.println("此人是1998年出生的");
					}
				}
				*/
				/*3contains("abc")*/
				
				if(num.contains("1998"))
				{
					System.out.println("此人是1998年出生的");
				}
				else
				{
					System.out.println("此人不是1998年出生的");
				}
			
	}

}
