package �����˻�����ϵͳ;
import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;


public abstract class Jiemian extends JFrame
{
	private JLabel titleLabel = new JLabel(new ImageIcon("bank3.jpg"));
	private JButton btn = new JButton("�������");
	
	public Jiemian()
	{
		this.Init();//��ʼ��
		this.addComponent();//������
		this.addListener();//��Ӽ�����
	}
	
	//��ʼ������
	private void Init()
	{
		//���ñ���
		this.setTitle("�й�������������  ��ӭ����");
		//���ô���Ĵ�С��λ��
		this.setSize(800,600);
		//�����С�̶�
		this.setResizable(false);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	//������
	private void addComponent()
	{
		titleLabel.setBounds(0, 0, 800,600);
		titleLabel.setLayout(null);
		this.add(this.titleLabel);
		//����JPanel����
		JPanel btnPanel = new JPanel();
		//�����֣���JPanel�е���������Զ���λ��
		btnPanel.setLayout(null);
		//��JPanel������ӵ�������
		this.add(btnPanel);
		//����߽�λ��
		btn.setBounds(310,400,150,50);
		//����ť��ӵ�JPanel������
		btnPanel.add(btn);
		//����ͼƬ
		
		
		this.setVisible(true);
	}
	
	//��Ӽ�����
	private void addListener()
	{
		btn.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e)
			{
				showguanliyuan();
			}
		});
	}
	
	//չʾ����Ա���淽��
	public abstract void showguanliyuan();
}
