package bankjiemian.test;
import javax.swing.table.DefaultTableModel;
import javax.swing.table.TableModel;
import �����˻�����ϵͳ.AbstractAdminDialog;

@SuppressWarnings("serial")
public class AbstractAdminDialogTest2 extends AbstractAdminDialog
{
	//���幹�캯����ʼ������
	public AbstractAdminDialogTest2()
	{
		super();
		queryBankItem();//����
	}
	//�������table����
	@Override
	public void queryBankItem()
	{
		String[] thead = new String[]
				{
				"���ÿ���","�û���/Ԫ��","������",",���˴���"
				};
		String[][] tbody  = new String[][]
				{
				{"62179979000068681616","���","60000000.0","50000000.0","0.0"}
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
	//����������
	public static void main(String[] args)
	{
		new AbstractAdminDialogTest2().setVisible(true);
	}
}
