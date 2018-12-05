package 窗口Test;

import java.awt.FlowLayout;
import javax.swing.*;

public class 窗口2 extends JFrame
{
	public 窗口2()
	{
		this.setTitle("JFrameTest");
		this.setSize(800,600);
		
		//定义一个按钮组件
		JButton bt = new JButton("按钮");
		this.setLayout(new FlowLayout());
		this.add(bt);
		//设置单击关闭按钮时的默认操作
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);
	}
	public static void main(String[] args)
	{
		new 窗口2();
	}

}
