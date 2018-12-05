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
	//定义组件
	private JLabel tableLabel = new JLabel("用户信息");//列表标题
	private JScrollPane tablePane = new JScrollPane();//滚动视口
	protected JTable table = new JTable();//用户列表
	private JLabel numberLabel = new JLabel("信用卡号");//编号标题
	private JLabel nameLabel = new JLabel("用户名称");
	private JLabel priceLabel = new JLabel("储蓄存款");//单价标题
	private JLabel unitLabel = new JLabel("个人贷款");//计价单位标题
	//添加功能组件
	protected JTextField addNumberText = new JTextField(10);//添加编号文本框
    protected JTextField addNameText = new JTextField(10);//添加名称文本框
    protected JTextField addPriceText = new JTextField(10);//添加单价文本框
    protected JTextField addUnitText = new JTextField(10);//添加计价单位文本框
    private JButton addBtn = new JButton("新增用户");//添加按钮
    //修改功能组件
    protected JTextField updateNumberText = new JTextField(10);//修改编号名称
    protected JTextField updateNameText = new JTextField(10);//修改名称文本框
    protected JTextField updatePriceText = new JTextField(10);//修改单价文本框
    protected JTextField updateUnitText = new JTextField(10);//修改单位文本框
    private JButton updateBtn = new JButton("修改用户");//修改按钮
    //删除功能组件
    protected JTextField delNumberText = new JTextField(6);//添加编号文本
    private JButton delBtn = new JButton("消除账户");//删除按钮
    //构造方法
    public AbstractAdminDialog(){
    	this(null,true);
    }
    public AbstractAdminDialog(Frame owner, boolean modal){
    	super(owner, modal);
    	this.init();//初始化操作
    	this.addCompontent();//添加组价
    	this.addListener();//添加监听器
    }
    //初始化操作
    private void init(){
    	this.setTitle("账户信息管理！");//标题
        this.setSize(800, 600);//窗体大小与位置（600 400）
//    	GUITools.center(this);//设置窗口在屏幕上的位置
    	this.setResizable(false);//窗体大小固定	
    }
    //添加组件
    private void addCompontent(){
    	//取消布局
    	this.setLayout(null);
    	//表格标题
    	tableLabel.setBounds(365, 15, 70, 25);//tableLabel.setBounds(265, 20, 70, 25);
    	this.add(tableLabel);
    	//表格
    	table.getTableHeader().setReorderingAllowed(true);//列不能移动
    	table.getTableHeader().setResizingAllowed(true);//不可拉动表格
    	table.setEnabled(true);//不可更改数据
    	tablePane.setBounds(45,40,670,300);//tablePane.setBounds(50,50,500,200);
    	tablePane.setViewportView(table);  //视口装入表格
    	this.add(tablePane);
    	//字段标题
    	numberLabel.setBounds(75, 350, 100, 35);//(50,250,70,25);
    	nameLabel.setBounds(205, 350, 100, 35);//(150,250,70,25);
    	priceLabel.setBounds(335, 350, 100, 35);//(250,250,70,25);
    	unitLabel.setBounds(465, 350, 100, 35);//(350,250,70,25);
    	this.add(numberLabel);
    	this.add(nameLabel);
    	this.add(priceLabel);
    	this.add(unitLabel);
    	//增加组件
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
    	//修改组件
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
        //删除组件
        delNumberText.setBounds(50, 500, 100, 35);//(50, 340, 80, 25);
        this.add(delNumberText);
        delBtn.setBounds(600, 500, 100, 40);//(460,340,90,25);
        this.add(delBtn);
    }
    //添加监听器
    private void addListener(){
    	//添加按钮监听
    	addBtn.addActionListener(new ActionListener(){
    		@Override
    		public void actionPerformed(ActionEvent e){
    			//调用添加方法
    			addBankItem();
    		}
    	});
    	//修改按钮监听
    	updateBtn.addActionListener(new ActionListener(){
    		@Override
    		public void actionPerformed(ActionEvent e){
    			//调用修改方法
    			System.out.print("123456");
    			updateBankItem();
    		}
    		
    	});
    	//删除按钮监听
    	delBtn.addActionListener(new ActionListener()
    	{
    		@Override
    		public void actionPerformed(ActionEvent e){
    			//调用删除方法
    			delBankItem();
    		}
    	});
    }
    //查询方法
    public abstract void queryBankItem();
    //添加方法
    public abstract void addBankItem();
    //修改方法
    public abstract void updateBankItem();
    //删除方法
    public abstract void delBankItem();
}

