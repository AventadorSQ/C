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

* 管理员界面操作类
*/

@SuppressWarnings("serial")

public class AdminDialogController extends AbstractAdminDialog{
//定义服务类, 提供完整功能服务
private AdminService adminService = new AdminService();

//构造方法

public AdminDialogController() {

super();
}
public AdminDialogController(Frame owner, boolean modal) {

super(owner,modal);

//创建对象时展示数据

queryBankItem();
}

//查询方法

@Override

public void queryBankItem() {

//定义表格头

String[] thead = {"信用卡号","用户名称","储蓄存款","个人贷款"};

//调用 adminService 的查询服务

ArrayList<BankItem> dataList = adminService.queryBankItem();

//调用List2Array 方法, 将查询到的集合转为数组, 方便为JTable赋值

String[][] tbody = list2Array(dataList);
//将查询到的结果为table赋值
TableModel dataModel = new DefaultTableModel(tbody,thead);
table.setModel(dataModel);
}
//集合数据转为二维数组方法
public String[][] list2Array(ArrayList<BankItem> list){
//根据FruitItem的model与集合数据定义JTable的数据二维数组
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
//添加方法
@Override
public void addBankItem() {

//获取数据

String addNumber = addNumberText.getText();

String addName = addNameText.getText();

String addPrice = addPriceText.getText();

String addUnit = addUnitText.getText();

//调用 adminService 的添加服务

boolean addSuccess = adminService.addBankItem(addNumber, addName,

addPrice, addUnit);

//如果添加成功

if(addSuccess) {

//添加后刷新表格

queryBankItem();

}else {

//没有添加成功弹窗错误提示

JOptionPane.showMessageDialog(this,"编号不能重复,请检查数据!");
}
}
//修改方法

@Override

public void updateBankItem() {

//获取数据

String updateNumber = updateNumberText.getText();

String updateName = updateNameText.getText();

String updatePrice =updatePriceText.getText();

String updateUnit = updateUnitText.getText();

//调用 adminService 的修改服务

boolean updateSuccess = adminService.updateBankItem(updateNumber,updateName,updatePrice,updateUnit);

//如果修改成功

if(updateSuccess) {

//修改后刷新表格

queryBankItem();

}else {

//没有修改成功弹窗错误提示

JOptionPane.showMessageDialog(this,"没有这个编号的,请检查数据");
}
}
//删除方法

@Override
public void delBankItem() {
//获取数据
String delNumber = delNumberText.getText();
//调用adminService的删除服务
boolean delSuccess = adminService.delBankItem(delNumber);
//如果删除成功
if(delSuccess)
{//删除后刷新表格
queryBankItem();
}else{
//没有删除成功弹窗错误提示
JOptionPane.showMessageDialog(this,"没有这个编号的，请检查数据");
}
}
}