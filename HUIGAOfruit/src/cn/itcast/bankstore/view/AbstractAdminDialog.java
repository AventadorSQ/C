//8-28
package cn.itcast.bankstore.view;
import java.awt.Frame;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.JTextField;
//import cn.itcast.

public abstract class AbstractAdminDialog extends JDialog
{
	//�������
	private JLabel tableLabel = new JLabel("�û���Ϣ");//�б����
	private JScrollPane tablePane = new JScrollPane();//�����ӿ�
	protected JTable table = new JTable();//�û��б�
	private JLabel numberLabel = new JLabel("���ÿ���");//��ű���
	private JLabel nameLabel = new JLabel("�û�����");
	private JLabel priceLabel = new JLabel("������");//���۱���
	private JLabel unitLabel = new JLabel("���˴���");//�Ƽ۵�λ����
	//��ӹ������
	protected JTextField addNumberText = new JTextField(10);//��ӱ���ı���
    protected JTextField addNameText = new JTextField(10);//��������ı���
    protected JTextField addPriceText = new JTextField(10);//��ӵ����ı���
    protected JTextField addUnitText = new JTextField(10);//��ӼƼ۵�λ�ı���
    private JButton addBtn = new JButton("�����û�");//��Ӱ�ť
    //�޸Ĺ������
    protected JTextField updateNumberText = new JTextField(10);//�޸ı������
    protected JTextField updateNameText = new JTextField(10);//�޸������ı���
    protected JTextField updatePriceText = new JTextField(10);//�޸ĵ����ı���
    protected JTextField updateUnitText = new JTextField(10);//�޸ĵ�λ�ı���
    private JButton updateBtn = new JButton("�޸��û�");//�޸İ�ť
    //ɾ���������
    protected JTextField delNumberText = new JTextField(6);//��ӱ���ı�
    private JButton delBtn = new JButton("�����˻�");//ɾ����ť
    //���췽��
    public AbstractAdminDialog(){
    	this(null,true);
    }
    public AbstractAdminDialog(Frame owner, boolean modal){
    	super(owner, modal);
    	this.init();//��ʼ������
    	this.addCompontent();//������
    	this.addListener();//��Ӽ�����
    }
    //��ʼ������
    private void init(){
    	this.setTitle("�˻���Ϣ����");//����
        this.setSize(800, 600);//�����С��λ�ã�600 400��
//    	GUITools.center(this);//���ô�������Ļ�ϵ�λ��
    	this.setResizable(false);//�����С�̶�	
    }
    //������
    private void addCompontent(){
    	//ȡ������
    	this.setLayout(null);
    	//������
    	tableLabel.setBounds(365, 15, 70, 25);//tableLabel.setBounds(265, 20, 70, 25);
    	this.add(tableLabel);
    	//���
    	table.getTableHeader().setReorderingAllowed(true);//�в����ƶ�
    	table.getTableHeader().setResizingAllowed(true);//�����������
    	table.setEnabled(true);//���ɸ�������
    	tablePane.setBounds(45,40,670,300);//tablePane.setBounds(50,50,500,200);
    	tablePane.setViewportView(table);  //�ӿ�װ����
    	this.add(tablePane);
    	//�ֶα���
    	numberLabel.setBounds(75, 350, 100, 35);//(50,250,70,25);
    	nameLabel.setBounds(205, 350, 100, 35);//(150,250,70,25);
    	priceLabel.setBounds(335, 350, 100, 35);//(250,250,70,25);
    	unitLabel.setBounds(465, 350, 100, 35);//(350,250,70,25);
    	this.add(numberLabel);
    	this.add(nameLabel);
    	this.add(priceLabel);
    	this.add(unitLabel);
    	//�������
    	addNumberText.setBounds(50, 400, 100, 35);//(50, 280, 80, 25);
    	addNameText.setBounds(180, 400, 100, 35);//(150, 280, 80, 25);
    	addPriceText.setBounds(310, 400, 100, 35);//(250, 280, 80, 25);
    	addUnitText.setBounds(440, 400, 100, 35);//(350, 280, 80, 25);
    	this.add(addNumberText);
    	this.add(addNameText);
    	this.add(addPriceText);
    	this.add(addUnitText);
    	addBtn.setBounds(600, 400, 100, 40);//(460, 280, 90, 25);
    	this.add(addBtn);
    	//�޸����
    	updateNumberText.setBounds(50, 450, 100, 35);//(50, 310, 80, 25);
    	updateNameText.setBounds(180, 450, 100, 35);//(150, 310, 80, 25);
    	updatePriceText.setBounds(310, 450, 100, 35);//(250, 310, 80, 25);
        updateUnitText.setBounds(440, 450, 100, 35);//(350, 310, 80, 25);
        this.add(updateNumberText);
        this.add(updateNameText);
        this.add(updatePriceText);
        this.add(updateUnitText);
        updateBtn.setBounds(600, 450, 100, 40);//(460,310,90,25);
        this.add(updateBtn);
        //ɾ�����
        delNumberText.setBounds(50, 500, 100, 35);//(50, 340, 80, 25);
        this.add(delNumberText);
        delBtn.setBounds(600, 500, 100, 40);//(460,340,90,25);
        this.add(delBtn);
    }
    //��Ӽ�����
    private void addListener(){
    	//��Ӱ�ť����
    	addBtn.addActionListener(new ActionListener(){
    		@Override
    		public void actionPerformed(ActionEvent e){
    			//������ӷ���
    			addBankItem();
    		}
    	});
    	//�޸İ�ť����
    	updateBtn.addActionListener(new ActionListener(){
    		@Override
    		public void actionPerformed(ActionEvent e){
    			//�����޸ķ���
    			System.out.print("123456");
    			updateBankItem();
    		}
    		
    	});
    	//ɾ����ť����
    	delBtn.addActionListener(new ActionListener()
    	{
    		@Override
    		public void actionPerformed(ActionEvent e){
    			//����ɾ������
    			delBankItem();
    		}
    	});
    }
    //��ѯ����
    public abstract void queryBankItem();
    //��ӷ���
    public abstract void addBankItem();
    //�޸ķ���
    public abstract void updateBankItem();
    //ɾ������
    public abstract void delBankItem();
}

