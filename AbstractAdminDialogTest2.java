package bankjiemian.test;
import javax.swing.table.DefaultTableModel;
import javax.swing.table.TableModel;
import 银行账户管理系统.AbstractAdminDialog;

@SuppressWarnings("serial")
public class AbstractAdminDialogTest2 extends AbstractAdminDialog
{
	//定义构造函数初始化数据
	public AbstractAdminDialogTest2()
	{
		super();
		queryBankItem();//测试
	}
	//加入测试table数据
	@Override
	public void queryBankItem()
	{
		String[] thead = new String[]
				{
				"信用卡号","用户余额（/元）","储蓄存款",",个人贷款"
				};
		String[][] tbody  = new String[][]
				{
				{"62179979000068681616","李白","60000000.0","50000000.0","0.0"}
				};
		TableModel data = new DefaultTableModel(tbody,thead);
		table.setModel(data);
	}
	@Override
	public void addBankItem()
	{
		
	}
	@Override
	public void updateBankItem()
	{
		
	}
	@Override
	public void delBankItem()
	{
		
	}
	//定义主函数
	public static void main(String[] args)
	{
		new AbstractAdminDialogTest2().setVisible(true);
	}
}
