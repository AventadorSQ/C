package javawork;

import java.util.Scanner;

public class ѧ���ж���Ϣ
{
	public static void main(String[] args)
	{
		Scanner numscanner=new Scanner(System.in);
		String num=numscanner.nextLine();
		
		//�������ѧ���Ƿ�����
		if(num.length()==12)
		{
			for(int i=0;i<num.length();i++)
			{
				char x=num.charAt(i);
				if(x<'0'||x>'9')
				{
					System.out.println("ѧ����������!!!");
					break;
				}
			}
		}
		else
		{
			System.out.println("ѧ��λ����������!!!");
		}
		String changliang1="��ѧ����";
		String changliang2="��";
		String changliang3="��ѧ��";
		switch(num.substring(4, 6))
		{
		case "01" :
			System.out.print(changliang1+"�Ṥ��ѧ�빤��ѧԺ"+changliang2+num.substring(0, 4)+changliang3);
			break;
		case "02" :
			System.out.print(changliang1+"���Ͽ�ѧ�빤��ѧԺ"+changliang2+num.substring(0, 4)+changliang3);
			break;
		case "03" :
			System.out.print(changliang1+"������ѧ�빤��ѧԺ"+changliang2+num.substring(0, 4)+changliang3);
			break;
		case "04" :
			System.out.print(changliang1+"ʳƷ�����﹤��ѧԺ"+changliang2+num.substring(0, 4)+changliang3);
			break;
		case "05" :
			System.out.print(changliang1+"���繤��ѧԺ"+changliang2+num.substring(0, 4)+changliang3);
			break;
		case "06" :
			System.out.print(changliang1+"��������Ϣ����ѧԺ"+changliang2+num.substring(0, 4)+changliang3);
			break;
		case "07" :
			System.out.print(changliang1+"���������ѧԺ"+changliang2+num.substring(0, 4)+changliang3);
			break;
		case "08" :
			System.out.print(changliang1+"��ѧ�뻯��ѧԺ"+changliang2+num.substring(0, 4)+changliang3);
			break;
		case "09" :
			System.out.print(changliang1+"���������ѧԺ"+changliang2+num.substring(0, 4)+changliang3);
			break;
		case "10" :
			System.out.print(changliang1+"����ѧԺ"+changliang2+num.substring(0, 4)+changliang3);
			break;
		case "11" :
			System.out.print(changliang1+"ְҵ����ʦ��ѧԺ"+changliang2+num.substring(0, 4)+changliang3);
			break;
		default:
			System.out.println("�����ѧԺ���Ų���ȷ!!!");
			break;
		}
	}
}
