package javawork;

import java.util.Scanner;

public class Is1998 
{
	public static void main(String[] args)
	{
		Scanner numscanner=new Scanner(System.in);
		String num=numscanner.nextLine();
		//�����������֤���Ƿ�����
				if(num.length()==18)
				{
					for(int i=0;i<num.length();i++)
					{
						char x=num.charAt(i);
						if(x<'0'||x>'9')
						{
							System.out.println("���֤����������!!!");
							break;
						}
					}
				}
				else
				{
					System.out.println("���֤��λ����������!!!");//18
				}
				
				/*1substring(a,b)*/
				/*
				switch(num.substring(6, 10))
				{
				case "1998" :
					System.out.println("������"+num.substring(6,10)+"�������");
					break;
				default:
					System.out.println("���˲���1998�������");
					break;
				}
				*/
				
				/*2�����ַ���*/
				/*
				String str="1998";
			    char[] charArray=str.toCharArray();
				for(int i=6;i<num.length()-8;i++)
				{
					if(num.charAt(i)!=charArray[i-6])
					{
						System.out.println("���˲���1998�������");
						break;
					}
					else if(i==9)
					{
						System.out.println("������1998�������");
					}
				}
				*/
				/*3contains("abc")*/
				
				if(num.contains("1998"))
				{
					System.out.println("������1998�������");
				}
				else
				{
					System.out.println("���˲���1998�������");
				}
			
	}

}
