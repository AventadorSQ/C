package ����Test;

import java.awt.FlowLayout;
import javax.swing.*;

public class ����2 extends JFrame
{
	public ����2()
	{
		this.setTitle("JFrameTest");
		this.setSize(800,600);
		
		//����һ����ť���
		JButton bt = new JButton("��ť");
		this.setLayout(new FlowLayout());
		this.add(bt);
		//���õ����رհ�ťʱ��Ĭ�ϲ���
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);
	}
	public static void main(String[] args)
	{
		new ����2();
	}

}
