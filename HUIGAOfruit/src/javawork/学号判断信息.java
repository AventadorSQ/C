package javawork;

import java.util.Scanner;

public class 学号判断信息
{
	public static void main(String[] args)
	{
		Scanner numscanner=new Scanner(System.in);
		String num=numscanner.nextLine();
		
		//检查输入学号是否有误
		if(num.length()==12)
		{
			for(int i=0;i<num.length();i++)
			{
				char x=num.charAt(i);
				if(x<'0'||x>'9')
				{
					System.out.println("学号输入有误!!!");
					break;
				}
			}
		}
		else
		{
			System.out.println("学号位数输入有误!!!");
		}
		String changliang1="此学生是";
		String changliang2="的";
		String changliang3="级学生";
		switch(num.substring(4, 6))
		{
		case "01" :
			System.out.print(changliang1+"轻工科学与工程学院"+changliang2+num.substring(0, 4)+changliang3);
			break;
		case "02" :
			System.out.print(changliang1+"材料科学与工程学院"+changliang2+num.substring(0, 4)+changliang3);
			break;
		case "03" :
			System.out.print(changliang1+"环境科学与工程学院"+changliang2+num.substring(0, 4)+changliang3);
			break;
		case "04" :
			System.out.print(changliang1+"食品与生物工程学院"+changliang2+num.substring(0, 4)+changliang3);
			break;
		case "05" :
			System.out.print(changliang1+"机电工程学院"+changliang2+num.substring(0, 4)+changliang3);
			break;
		case "06" :
			System.out.print(changliang1+"电气与信息工程学院"+changliang2+num.substring(0, 4)+changliang3);
			break;
		case "07" :
			System.out.print(changliang1+"经济与管理学院"+changliang2+num.substring(0, 4)+changliang3);
			break;
		case "08" :
			System.out.print(changliang1+"化学与化工学院"+changliang2+num.substring(0, 4)+changliang3);
			break;
		case "09" :
			System.out.print(changliang1+"设计与艺术学院"+changliang2+num.substring(0, 4)+changliang3);
			break;
		case "10" :
			System.out.print(changliang1+"文理学院"+changliang2+num.substring(0, 4)+changliang3);
			break;
		case "11" :
			System.out.print(changliang1+"职业教育师范学院"+changliang2+num.substring(0, 4)+changliang3);
			break;
		default:
			System.out.println("输入的学院代号不正确!!!");
			break;
		}
	}
}
