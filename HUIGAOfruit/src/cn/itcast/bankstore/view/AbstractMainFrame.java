//8-25
package cn.itcast.bankstore.view;
import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

@SuppressWarnings("serial")
public abstract class AbstractMainFrame extends JFrame
{
	private JLabel titleLabel = new JLabel(new ImageIcon("bank3.jpg"));
	private JButton btn = new JButton("管理员登录");
	
	public AbstractMainFrame()
	{
		this.Init();//初始化
		this.addComponent();//添加组件
		this.addListener();//添加监听器
	}
	
	//初始化操作
	private void Init()
	{
		//设置标题
		this.setTitle("中国邮政储蓄银行  欢迎您！");
		//设置窗体的大小与位置
		this.setSize(800,600);
		//窗体大小固定
		this.setResizable(false);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	//添加组件
	private void addComponent()
	{
		titleLabel.setBounds(0, 0, 1000,400);
		titleLabel.setLayout(null);
		this.add(this.titleLabel);
		//创建JPanel对象
		JPanel btnPanel = new JPanel();
		//清理布局，让JPanel中的组件可以自定义位置
		btnPanel.setLayout(null);
		//将JPanel对象添加到窗体中
		this.add(btnPanel);
		//定义边界位置
		btn.setBounds(310,455,150,50);
		//将按钮添加到JPanel对象中
		btnPanel.add(btn);
		//设置图片
		
		
		this.setVisible(true);
	}
	
	//添加监听器
	private void addListener()
	{
		btn.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				showAdminDialog();
			}
		});
	}
	
	//展示管理员界面方法
	public abstract void showAdminDialog();
}
