//8-34

package cn.itcast.bankstore.controller;

import java.awt.Frame;
import java.util.ArrayList;
import javax.swing.JOptionPane;
import javax.swing.table.DefaultTableModel;
import javax.swing.table.TableModel;
import cn.itcast.bankstore.domain.BankItem;
import cn.itcast.bankstore.service.AdminService;
import cn.itcast.bankstore.view.AbstractAdminDialog;

/**

* ����Ա���������
*/

@SuppressWarnings("serial")

public class AdminDialogController extends AbstractAdminDialog{
//���������, �ṩ�������ܷ���
private AdminService adminService = new AdminService();

//���췽��

public AdminDialogController() {

super();
}
public AdminDialogController(Frame owner, boolean modal) {

super(owner,modal);

//��������ʱչʾ����

queryBankItem();
}

//��ѯ����

@Override

public void queryBankItem() {

//������ͷ

String[] thead = {"���ÿ���","�û�����","������","���˴���"};

//���� adminService �Ĳ�ѯ����

ArrayList<BankItem> dataList = adminService.queryBankItem();

//����List2Array ����, ����ѯ���ļ���תΪ����, ����ΪJTable��ֵ

String[][] tbody = list2Array(dataList);
//����ѯ���Ľ��Ϊtable��ֵ
TableModel dataModel = new DefaultTableModel(tbody,thead);
table.setModel(dataModel);
}
//��������תΪ��ά���鷽��
public String[][] list2Array(ArrayList<BankItem> list){
//����FruitItem��model�뼯�����ݶ���JTable�����ݶ�ά����
String[][] tbody = new String[list.size()][4];
for(int i=0;i<list.size();i++)
{ BankItem bankItem= list.get(i);
tbody[i][0]=bankItem.getNumber();
tbody[i][1]=bankItem.getName();
tbody[i][2] = bankItem.getPrice()+"";
tbody[i][3] = bankItem.getUnit();
}
return tbody;
}
//��ӷ���
@Override
public void addBankItem() {

//��ȡ����

String addNumber = addNumberText.getText();

String addName = addNameText.getText();

String addPrice = addPriceText.getText();

String addUnit = addUnitText.getText();

//���� adminService ����ӷ���

boolean addSuccess = adminService.addBankItem(addNumber, addName,

addPrice, addUnit);

//�����ӳɹ�

if(addSuccess) {

//��Ӻ�ˢ�±��

queryBankItem();

}else {

//û����ӳɹ�����������ʾ

JOptionPane.showMessageDialog(this,"��Ų����ظ�,��������!");
}
}
//�޸ķ���

@Override

public void updateBankItem() {

//��ȡ����

String updateNumber = updateNumberText.getText();

String updateName = updateNameText.getText();

String updatePrice =updatePriceText.getText();

String updateUnit = updateUnitText.getText();

//���� adminService ���޸ķ���

boolean updateSuccess = adminService.updateBankItem(updateNumber,updateName,updatePrice,updateUnit);

//����޸ĳɹ�

if(updateSuccess) {

//�޸ĺ�ˢ�±��

queryBankItem();

}else {

//û���޸ĳɹ�����������ʾ

JOptionPane.showMessageDialog(this,"û�������ŵ�,��������");
}
}
//ɾ������

@Override
public void delBankItem() {
//��ȡ����
String delNumber = delNumberText.getText();
//����adminService��ɾ������
boolean delSuccess = adminService.delBankItem(delNumber);
//���ɾ���ɹ�
if(delSuccess)
{//ɾ����ˢ�±��
queryBankItem();
}else{
//û��ɾ���ɹ�����������ʾ
JOptionPane.showMessageDialog(this,"û�������ŵģ���������");
}
}
}